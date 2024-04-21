//
// Created by jack on 1/15/24.
//

#include "EquationExprVisitor.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"
#include "../../SymbolTable/Symbol/VariableSymbol.h"
#include "../visitor/MyLustreVisitor.h"
#include "../tool/LustreVisitorTool.h"

#define _tab "    "
//拆分运算的flag标记
bool splitFlag;


std::any EquationExprVisitor::visitEquation_expr(LustreParser::Equation_exprContext *ctx) {

    std::string res;
    auto mixExpr = dynamic_cast<LustreParser::Expr_mixed_constructorContext *>(ctx->expr());
    auto ArrayExpr = dynamic_cast<LustreParser::Expr_array_exprContext *>(ctx->expr());
    auto structExpr = dynamic_cast<LustreParser::Expr_struct_exprContext *>(ctx->expr());


    auto lhsIdList = dynamic_cast<LustreParser::Lhs_id_listContext *>(ctx->lhs());
    auto lhsPairList = dynamic_cast<LustreParser::Lhs_pairContext *>(ctx->lhs());
    if (lhsPairList) {
        //当使用左值定义时
        res.append(std::any_cast<std::string>(myLustreVisitor.visit(ctx->lhs())));
        res.append(" = ");
        return res.append(std::any_cast<std::string>(myLustreVisitor.visit(ctx->expr())));
    }

    auto IDList = lhsIdList->ID();
    auto exprString = std::any_cast<std::string>(myLustreVisitor.visit(ctx->expr()));
    /**
     * 调用函数这类不需要拆分等式左侧
     */
    visit(ctx->expr());
    if (!splitFlag) {
        res.append(LustreVisitorTool::getLineAnnotation(ctx));
        //如果表达式无需分开列举，暂时只有高阶表达式和函数调用
        res.append(_tab + LustreVisitorTool::getFullText(ctx->lhs()));
        res.append(" = ");
        res.append(exprString);
        return res;
    }
    /**
     * 采用for循环原因：
     * _L3,_L5=100;在kind2不支持,得改成
     * _L3 = 100;
     *_L5 = 100;
     *
     */
    for (int i = 0; i < IDList.size(); i++) {
        /**
         * 1.先完成ID本身的转换
         * ID本身的转换主要分为两种，一种是id无需更改，一种是数组类型。如二维数组:id==>id[i0][i1]
         */
        res.append(IDList[i]->getText());
        //如果是mix运算
//        if (mixIndex) {
//            res.append(mixOperator(ctx, IDList[i]->getText()));
//        //如果是数组运算
//        } else
        if (ArrayExpr) {
            //如果是数组运算中的切片运算
            if (auto arraySlice = dynamic_cast<LustreParser::Array_expr_splitContext *>(ArrayExpr->array_expr())) {
                res.append(mixOperator(ctx, IDList[i]->getText()));
            }
        }
        /**
         * 2.完成等号后面的转换,主要是对当前id的初始值进行定义
         */
        res.append(" = ");

        //对所有的id判断是否定义了初始值，定义了就设置初始值
        res.append(lastOperator(ctx, IDList[i]->getText()));
        /**
         * 3.完成表达式的转换
         */
        //匿名结构体处理
        if (structExpr) {
            //如果是匿名结构体运算
            if (auto variableSymbol = std::dynamic_pointer_cast<VariableSymbol>(
                    currentScope->resolve(IDList[i]->getText()))) {
                //把结构体的本身类型存入全局变量，后面嵌套结构体将会使用到
                MyLustreVisitor::structDefType = std::dynamic_pointer_cast<TypeDefSymbol>(
                        variableSymbol->getTypeDefSymbol()->getTypeID()->getTypeIDSymbol());
                //在struct的大括号前插入引用的结构体类型
                res.append(variableSymbol->getTypeDefSymbol()->getTypeID()->getTypeID());
            }

        }
        //表达式处理
        res.append(exprString);
        //当这个id的所有子类访问完毕后重置structDefType
        MyLustreVisitor::structDefType = nullptr;
        //在最后加换行和tab
        if (i < IDList.size() - 1) {
            res.append(";\n");
            res.append(_tab);
        }
    }
    return res;
}

std::string EquationExprVisitor::mixOperator(LustreParser::Equation_exprContext *ctx, const std::string &id) {
    std::string res;
    auto IDSymbol = currentScope->resolve(id);
    if (auto constSymbol = std::dynamic_pointer_cast<ConstSymbol>(IDSymbol)) {
        std::vector<std::string> dimVector = constSymbol->getDefTypeSymbol()->getArrayDimString();
        for (int j = 0; j < dimVector.size(); j++) {
            res.append("[i" + std::to_string(j) + "]");
        }
    } else if (auto varSymbol = std::dynamic_pointer_cast<VariableSymbol>(IDSymbol)) {
        std::vector<std::string> dimVector = varSymbol->getTypeDefSymbol()->getArrayDimString();
        for (int j = 0; j < dimVector.size(); j++) {
            res.append("[i" + std::to_string(j) + "]");
        }
    }
    return res;
}

std::string EquationExprVisitor::lastOperator(LustreParser::Equation_exprContext *ctx, const std::string &id) {
    //定义一个已完成last字段的集合，避免重复定义last字段
    static std::unordered_set<std::string> lastSolvedSet;
    std::string res;
    auto lhsSymbol = currentScope->resolve(id);
    if (auto varSymbol = std::dynamic_pointer_cast<VariableSymbol>(lhsSymbol)) {
        if (varSymbol->getLastSymbol() &&
            lastSolvedSet.find(id) == lastSolvedSet.end()) {
            res.append(varSymbol->getLastLus());
            res.append(" -> ");
            lastSolvedSet.insert(id);
        }
    }
    return res;
}

EquationExprVisitor::EquationExprVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope)
        : myLustreVisitor(
        myLustreVisitor), currentScope(currentScope) {
    splitFlag = true;

}

std::any EquationExprVisitor::visitExpr_simple_expr(LustreParser::Expr_simple_exprContext *ctx) {
    return LustreBaseVisitor::visitExpr_simple_expr(ctx);
}

std::any EquationExprVisitor::visitExpr_last_decl(LustreParser::Expr_last_declContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitExpr_tempo_expr(LustreParser::Expr_tempo_exprContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitExpr_bool_expr(LustreParser::Expr_bool_exprContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitExpr_array_expr(LustreParser::Expr_array_exprContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitExpr_struct_expr(LustreParser::Expr_struct_exprContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitExpr_mixed_constructor(LustreParser::Expr_mixed_constructorContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitExpr_switch_expr(LustreParser::Expr_switch_exprContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitExpr_paren(LustreParser::Expr_parenContext *ctx) {
    splitFlag = false;
    return {};
}

std::any EquationExprVisitor::visitExpr_apply_expr(LustreParser::Expr_apply_exprContext *ctx) {
    splitFlag = false;
    return {};
}

std::any EquationExprVisitor::visitSimple_expr_id(LustreParser::Simple_expr_idContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitSimple_expr_atom(LustreParser::Simple_expr_atomContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitSimple_expr_paren(LustreParser::Simple_expr_parenContext *ctx) {
    splitFlag = false;
    return {};
}

std::any EquationExprVisitor::visitSimple_expr_array(LustreParser::Simple_expr_arrayContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitSimple_expr_struct(LustreParser::Simple_expr_structContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitSimple_expr_unary_arith(LustreParser::Simple_expr_unary_arithContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitSimple_expr_bin_arith(LustreParser::Simple_expr_bin_arithContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitSimple_expr_bin_bool(LustreParser::Simple_expr_bin_boolContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitSimple_expr_bin_relation(LustreParser::Simple_expr_bin_relationContext *ctx) {
    return {};
}

std::any EquationExprVisitor::visitSimple_expr_type(LustreParser::Simple_expr_typeContext *ctx) {
    if (auto simple_paren = dynamic_cast<LustreParser::Simple_expr_parenContext *>(ctx->simple_expr())) {
        splitFlag = false;
    }
    return {};
}

std::any EquationExprVisitor::visitExpr_kind2_expr(LustreParser::Expr_kind2_exprContext *ctx) {
    return {};
}
