//
// Created by jack on 23-11-16.
//

#include <spdlog/spdlog.h>
#include "MyLustreVisitor.h"
#include "SecondSymbolVisitor.h"
#include "../tool/LustreVisitorTool.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"
#include "../../SymbolTable/Symbol/VariableSymbol.h"
#include "../expr/ArrayExprVisitor.h"
#include "../expr/MixExprVisitor.h"
#include "../expr/EquationExprVisitor.h"
#include "../tool/SpdlogTool.h"
#include "../../SymbolTable/Scope/MethodScope.h"
#include "../constBlock/ConstValueVisitor.h"
#include "../expr/BoolExprVisitor.h"
#include "../expr/ApplyExprVisitor.h"
#include "../expr/GetSimpleExprType.h"


std::shared_ptr<TypeDefSymbol> MyLustreVisitor::structDefType = std::make_shared<TypeDefSymbol>();
//暂存当前要用的lhs名字
std::vector<std::string> lhsIDVector={};

MyLustreVisitor::MyLustreVisitor(std::shared_ptr<antlr4::tree::ParseTreeProperty<std::shared_ptr<Scope>>> scopes,
                                 std::shared_ptr<GlobalScope> globals) : scopes(std::move(scopes)),
                                                                         globals(std::move(globals)) {
    endOFVisitorString={};
    endOFVarVector={};
    endOFLetVector={};
}

#define _tab "    "
#define myvis(x) std::any_cast<std::string>(visit(x))

std::any MyLustreVisitor::visitProgram(LustreParser::ProgramContext *ctx) {
    //Program对下面的所有返回值做输出保存工作
    //  设置当前scope为globals
    currentScope = globals;
    std::string declsString;
    /**
   * 对创建的temp结构体类型进行定义
   * 通过SecondSymbolVisitor::structVector存储的需要定义的名字找到Symbol
   * 通过TypeDefSymbol中的toLusString获得定义的字符串
   */
    auto it = SecondSymbolVisitor::structVector.begin();
    while (it != SecondSymbolVisitor::structVector.end()) {
        const auto &name = *it;
        auto symbol = currentScope->resolve(name);
        if (auto typeSymbol = std::dynamic_pointer_cast<TypeDefSymbol>(symbol)) {
            declsString.append(typeSymbol->toLusString()).append(";\n");
        }
        it = SecondSymbolVisitor::structVector.erase(it);
    }
    for (auto decl: ctx->decls()) {
        auto declVisitor = LustreBaseVisitor::visit(decl);

        declsString.append(std::any_cast<std::string>(declVisitor));

    }
    declsString.append("\n" + endOFVisitorString);
    endOFVisitorString.clear();
    //打印符号表
//    std::cout << "globals: " << globals->toString() << std::endl;
    //符号表测试使用：
    //    auto testResole=currentScope->resolve("c1");
    //    std::cout<<"******************************\n";
    //    std::cout<<testResole->getToken()->getLine();
    //    std::cout<<testResole->toAstString();
    //
    //    std::cout<<"\n******************************";

    return std::string(declsString);
}

std::any MyLustreVisitor::visitDecls_type(LustreParser::Decls_typeContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->type_block()));
}

std::any MyLustreVisitor::visitDecls_const(LustreParser::Decls_constContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->const_block()));
}

//导入节点无需改动，原样返回
std::any MyLustreVisitor::visitDecls_import_op(LustreParser::Decls_import_opContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitDecls_user_op(LustreParser::Decls_user_opContext *ctx) {
    return myvis(ctx->user_op_decl());
}

std::any MyLustreVisitor::visitDecls_contract_node(LustreParser::Decls_contract_nodeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}


std::any MyLustreVisitor::visitType_block(LustreParser::Type_blockContext *ctx) {
    std::string declsString;
    for (auto decl: ctx->type_decl()) {
        auto declVisitor = LustreBaseVisitor::visit(decl);
        declsString.append(std::any_cast<std::string>(declVisitor));
        declsString.append("\n");
    }

    return declsString;
}

std::any MyLustreVisitor::visitType_decl(LustreParser::Type_declContext *ctx) {
    std::string declString;
    auto idString = ctx->ID()->getText();
    if (ctx->type_def()) {

        //如果是struct定义的话，就从符号表构建语法
        if (auto pTypeContext = dynamic_cast<LustreParser::Type_def_typeContext *>(ctx->type_def())) {
            if (auto pTypeStructContext = dynamic_cast<LustreParser::Type_structContext *>(pTypeContext->type())) {
                // 访问 ChildType 的成员
                auto symbol = currentScope->resolve(idString);
                if (auto typeSymbol = std::dynamic_pointer_cast<TypeDefSymbol>(symbol)) {
                    declString.append(typeSymbol->toLusString());
                }

                declString.append(";");
                return declString;
            }
        }

        declString.append("type ");
        declString.append(idString + " = ");
        //设置structType以供子类visit使用，如：array
        auto defSymbol = std::dynamic_pointer_cast<TypeDefSymbol>(
                currentScope->resolve(ctx->ID()->getText()));
        /**
         * 设置array的结构体类型:
         * 设置structType以供type_array的visit使用，如:
         * 如 type Output2 = {label : int}^1  ;
         * 输出:type Output2 : =tempStruct^1;
         */
        structDefType = defSymbol;
        auto declVisitor = LustreBaseVisitor::visit(ctx->type_def());
        declString.append(std::any_cast<std::string>(declVisitor));
        structDefType = nullptr;
        declString.append(";");
    }

    return declString;
}

std::any MyLustreVisitor::visitType_def_type(LustreParser::Type_def_typeContext *ctx) {
    return myvis(ctx->type());
}

std::any MyLustreVisitor::visitType_def_enum(LustreParser::Type_def_enumContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_int(LustreParser::Type_intContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_bool(LustreParser::Type_boolContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_char(LustreParser::Type_charContext *ctx) {
    return std::string("int");
}

std::any MyLustreVisitor::visitType_short(LustreParser::Type_shortContext *ctx) {
    return std::string("int16");
}

std::any MyLustreVisitor::visitType_ushort(LustreParser::Type_ushortContext *ctx) {
    return std::string("uint16");
}

std::any MyLustreVisitor::visitType_uint(LustreParser::Type_uintContext *ctx) {
    return std::string("uint32");
}

std::any MyLustreVisitor::visitType_float(LustreParser::Type_floatContext *ctx) {
    //TODO
    return std::string("real");
}

std::any MyLustreVisitor::visitType_real(LustreParser::Type_realContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_id(LustreParser::Type_idContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_struct(LustreParser::Type_structContext *ctx) {
    //把结构体中的逗号改为分号
    std::string res;
    res.append("{");
    for (int i = 0; i < ctx->field_decl().size(); ++i) {
        res.append(std::any_cast<std::string>(visit(ctx->field_decl()[i])));

        if (i < ctx->field_decl().size() - 1) {
            res.append(";");
        }
    }
    res.append("}");
    return res;
}

std::any MyLustreVisitor::visitType_array(LustreParser::Type_arrayContext *ctx) {
    std::string res;
    if (structDefType->getArraySymbol()) {
        structDefType = structDefType->getArraySymbol()->getTypeDefSymbol();
        if (structDefType->getDefType() == Symbol::REFERENCE) {
            res.append(structDefType->getTypeID()->getTypeID());

        } else {
            res.append(std::any_cast<std::string>(visit(ctx->type())));
        }
    } else {
        res.append(std::any_cast<std::string>(visit(ctx->type())));
    }
    res.append("^(");
    res.append(std::any_cast<std::string>(visit(ctx->const_expr())));
    res.append(")");
    return res;
}

std::any MyLustreVisitor::visitConst_block(LustreParser::Const_blockContext *ctx) {
    std::string declString("const\n");
    for (auto decl: ctx->const_decl()) {
        auto declVisitor = LustreBaseVisitor::visit(decl);
        declString.append(_tab);
        declString.append(std::any_cast<std::string>(declVisitor));
        declString.append("\n");
    }
    return declString;
}

std::any MyLustreVisitor::visitConst_decl(LustreParser::Const_declContext *ctx) {
    std::string declString;
    auto idString = ctx->ID()->getText();
    declString.append(idString);
    /**
     * 给typeArray存入暂存的结构体,设置structType以供子类visit使用，如：array
     * 如：const Output2 : {label : int} ^1 ;
     */
    auto tempSymbol = std::dynamic_pointer_cast<ConstSymbol>(
            currentScope->resolve(ctx->ID()->getText()));
    structDefType = tempSymbol->getDefTypeSymbol();
    auto typeVisitor = visit(ctx->type());
    structDefType = nullptr;
    // 把结构体的定义去掉
    auto structType = dynamic_cast<LustreParser::Type_structContext *>(ctx->type());
    if (!structType) {
        declString.append(" : ");
        declString.append(std::any_cast<std::string>(typeVisitor));
    }
    if (ctx->const_expr()) {
        declString.append(" = ");
        /**
         * 在struct中值的大括号前插入引用的结构体类型
         * 如：const Output2 : {label : int} ={label:1} ;
         * 输出:const Output2 :{上面处理过} =tempStruct{label=1};
         */
        //如果是匿名结构体类型
        auto structExpr = dynamic_cast<LustreParser::Const_structContext*>(ctx->const_expr());
        auto constSymbol = std::dynamic_pointer_cast<ConstSymbol>(currentScope->resolve(idString));
        if (structExpr && constSymbol) {
            //把结构体的本身类型存入全局变量，后面嵌套结构体将会使用到
            if (constSymbol->getDefTypeSymbol()->getTypeID()) {

                structDefType = std::dynamic_pointer_cast<TypeDefSymbol>(
                        constSymbol->getDefTypeSymbol()->getTypeID()->getTypeIDSymbol());
                if (structDefType) {

                    //在struct的大括号前插入引用的结构体类型
                    declString.append(constSymbol->getDefTypeSymbol()->getTypeID()->getTypeID());
                }
            }

        }
        /**
         * 嵌套结构体的处理：给const_Array存入暂存的结构体,设置structType以供子类visit使用，如:
         * 如：const Output2 : {label : {label2:int}} ={label:{label:1}} ;
         * 输出:const Output2 :{上面处理过} =tempStruct1{label=tempStruct2{label=1}};
         */
        auto constExprVisitor = visit(ctx->const_expr());
        declString.append(std::any_cast<std::string>(constExprVisitor));
        structDefType = nullptr;
    }
    declString.append(";");
    return declString;
}

std::any MyLustreVisitor::visitConst_id(LustreParser::Const_idContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitConst_atom(LustreParser::Const_atomContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->atom()));
}

std::any MyLustreVisitor::visitConst_unary_arith(LustreParser::Const_unary_arithContext *ctx) {
    if (ctx->unary_arith_op()->getText()[0] == '+') {        //省略一元运算符的 +
        return std::string(std::any_cast<std::string>(visit(ctx->const_expr())));
    } else {
        return std::string(LustreVisitorTool::getFullText(ctx));
    }
}

std::any MyLustreVisitor::visitConst_paren(LustreParser::Const_parenContext *ctx) {
    return std::string("( " + std::any_cast<std::string>(visit(ctx->const_expr())) + ")");
}

std::any MyLustreVisitor::visitConst_bin_arith(LustreParser::Const_bin_arithContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[0]))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->bin_arith_op()))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[1]))));
    return res;
}

std::any MyLustreVisitor::visitConst_bin_bool(LustreParser::Const_bin_boolContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[0]))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->bin_bool_op()))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[1]))));
    return res;
}

std::any MyLustreVisitor::visitConst_bin_relation(LustreParser::Const_bin_relationContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[0]))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->bin_relation_op()))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[1]))));
    return res;
}

std::any MyLustreVisitor::visitConst_array(LustreParser::Const_arrayContext *ctx) {
    return "[" + myvis(ctx->const_list()) + "]";
}

std::any MyLustreVisitor::visitConst_struct(LustreParser::Const_structContext *ctx) {
    std::string res;
    res.append(" { ");
    for (int i = 0; i < ctx->const_label_expr().size(); ++i) {

        res.append(myvis(ctx->const_label_expr()[i]));
        if (i < ctx->const_label_expr().size() - 1) {
            res.append(" ; ");
        }
    }
    res.append(" } ");
    return res;
}

std::any MyLustreVisitor::visitVar_decls(LustreParser::Var_declsContext *ctx) {
    std::string res;
    for (auto id: ctx->ID()) {
        res.append(id->getText()).append(",");
    }
    res.pop_back();
    res.append(" : ");
    auto structType = dynamic_cast<LustreParser::Type_structContext *>(ctx->type());

    //如果是匿名结构体类型
    if (structType) {
        if (auto varSymbol = std::dynamic_pointer_cast<VariableSymbol>(
                currentScope->resolve(ctx->ID()[0]->getText()))) {
            //在struct的大括号前插入引用的结构体类型
            res.append(varSymbol->getTypeDefSymbol()->getTypeID()->getTypeID());
        }
    } else {
        auto varSymbol = std::dynamic_pointer_cast<VariableSymbol>(
                currentScope->resolve(ctx->ID()[0]->getText()));
        /**
         * 设置array的结构体类型:
         * 设置structType以供type_array的visit使用，如:
         * 如 var Output2 : {label : int}^1  ;
         * 输出:var Output2 : tempStruct^1;
         */
        //设置structType以供子类visit使用，如：array
        structDefType = varSymbol->getTypeDefSymbol();
        res.append(std::any_cast<std::string>(visit(ctx->type())));
        structDefType = nullptr;
    }
    //TODO:whenDecl
//    if (ctx->when_decl()) {
//        res.append(" ").append(std::any_cast<std::string>(visit(ctx->when_decl())));
//    }
    //last已经在下文实现，此处无需定义last；
    return res;
}

std::any MyLustreVisitor::visitClock_id(LustreParser::Clock_idContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitClock_not(LustreParser::Clock_notContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitUser_op_decl(LustreParser::User_op_declContext *ctx) {
    //符号表进入节点,要把visit放在进入和退出符号表之间
    currentScope = scopes->get(ctx);
    std::string res = ctx->op_kind()->getText();
    res.append(" ");
    res.append(ctx->ID()->getText());
    //    if(ctx->static_parameters()) {
    //        res.append(" ");
    //        res.append(std::any_cast<std::string>(ctx->static_parameters()));
    //        res.append(" ");
    //    }
    auto in_params = LustreBaseVisitor::visit(ctx->params()[0]);
    res.append(std::any_cast<std::string>(in_params));
    res.append(" returns ");
    auto out_params = LustreBaseVisitor::visit(ctx->params()[1]);
    res.append(std::any_cast<std::string>(out_params));
    res.append(";\n");
    res.append(std::any_cast<std::string>(visit(ctx->op_body())));
    //std::cout <<"? : "<< res << std::endl;

    //符号表退出节点
    currentScope = currentScope->getEnclosingScope();
    return res;
}

std::any MyLustreVisitor::visitOp_kind_funtion(LustreParser::Op_kind_funtionContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitOp_kind_node(LustreParser::Op_kind_nodeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitParams(LustreParser::ParamsContext *ctx) {
    std::string res = "(";
    for (int i = 0; i < ctx->var_decls().size(); ++i) {
        res.append(std::any_cast<std::string>(visit(ctx->var_decls()[i])));
        if (i < ctx->var_decls().size() - 1) {
            res.append("; ");
        }
    }
    res.append(")");
    return res;
}

std::any MyLustreVisitor::visitOp_body_null(LustreParser::Op_body_nullContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitOp_body_ctx(LustreParser::Op_body_ctxContext *ctx) {

    std::string res;
    std::string tempLet;
    std::string tempVar;
    /**
     * 先遍历var和函数体，取得里面的值。因为有些后来处理过的表达式或var定义需要加在函数体中
     */
    if(ctx->contract()) {
        res.append(myvis(ctx->contract()));
    }
    if (ctx->local_block()){
        //符号表进入局部变量
        currentScope = scopes->get(ctx->local_block());
        tempVar.append(std::any_cast<std::string>(visit(ctx->local_block())));
    }
    var_cnt.clear();
    for (auto let_block: ctx->let_block()) {
        tempLet.append(_tab);
        auto ss = myvis(let_block);
        tempLet.append(ss);
        tempLet.append(";\n");
    }
    for(const auto& it: var_cnt) {
        std::string var = it.first;
        int cnt = it.second;
//        std::cout << "var_cnt: " << var << ' '  << cnt << std::endl;
        if(cnt == 0 || (cnt == 1 && tempLet.find(var + "_1") == -1)) {
            auto tv = var;
            var += "_0";
            int idx;
            while(idx = tempLet.find(var), idx != -1) {
                tempLet = tempLet.substr(0, idx) +tv+ tempLet.substr(idx + var.length());
            }
        } else {
            auto ss = currentScope->resolve(var);
            auto typeDefSymbol=std::dynamic_pointer_cast<VariableSymbol>(ss)->getTypeDefSymbol();
            std::string type = typeDefSymbol->getDefTypeLusString(typeDefSymbol->getDefType());
            tempLet.append(_tab).append(var + " = " + var + "_" + std::to_string(cnt-1)).append(";\n");
            //endOFVarVector.emplace_back("y_0, y_1, y_2, y_3, y_4, y_5 : int;");

            for(int i = 0 ; i < cnt ; i ++) {
                std::string t;
                t.append(var).append("_").append(std::to_string(i)).append(" : ").append(type).append(";");
                endOFVarVector.push_back(t);
            }
        }
    }
    /**
     * 对函数体进行拼接
     */
    if (ctx->local_block()) {

        res.append(tempVar);
        for (const auto & varDecl:endOFVarVector) {
            res.append(_tab);
            res.append(varDecl);
            res.append("\n");
        }
        endOFVarVector.clear();
    } else if(!(ctx->local_block()) && !(endOFVarVector.empty())){
        res.append("var\n");
        for (const auto & varDecl:endOFVarVector) {
            res.append(_tab);
            res.append(varDecl);
            res.append("\n");
        }
        endOFVarVector.clear();
    }
    res.append("let\n");
    res.append(tempLet);
    //拼接自定义的let语句
    for (const auto& letDecl:endOFLetVector) {
        res.append(_tab);
        res.append(letDecl);
        res.append("\n");
    }
    endOFLetVector.clear();
    res.append("tel;\n");
    if (ctx->local_block()) {
        //符号表退出局部变量
        currentScope = currentScope->getEnclosingScope();
    }
    return res;
}

std::any MyLustreVisitor::visitLet_block_equation(LustreParser::Let_block_equationContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->equation()));
}

std::any MyLustreVisitor::visitLet_block_k2_property(LustreParser::Let_block_k2_propertyContext *ctx) {

    std::string res(LustreVisitorTool::getLineAnnotation(ctx->kind2_property()));
    res.append(_tab + std::string(LustreVisitorTool::getFullText(ctx)));
    return res;
}
std::any MyLustreVisitor::visitLet_block_k2_if_block(LustreParser::Let_block_k2_if_blockContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitLet_block_k2_frame_block(LustreParser::Let_block_k2_frame_blockContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitEquation_expr(LustreParser::Equation_exprContext *ctx) {
    auto expr = myvis(ctx->expr());
    auto lhs = myvis(ctx->lhs());
    return lhs + " = " + expr;
}

std::any MyLustreVisitor::visitEquation_state_machine(LustreParser::Equation_state_machineContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitLhs_pair(LustreParser::Lhs_pairContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitLhs_id_list(LustreParser::Lhs_id_listContext *ctx) {
    std::string res;
    for(auto id: ctx->ID()) {
        auto id_s = id->getText();
        res += id_s + "_" + std::to_string(var_cnt[id_s]++) + ",";
    }
    res.pop_back();
    return res;
}

std::any MyLustreVisitor::visitState_machine_data_def_equation(LustreParser::State_machine_data_def_equationContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitState_machine_data_def_local_block(
        LustreParser::State_machine_data_def_local_blockContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitState_machine_transition_resume(LustreParser::State_machine_transition_resumeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitState_machine_transition_restart(LustreParser::State_machine_transition_restartContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitExpr_simple_expr(LustreParser::Expr_simple_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->simple_expr()));
}

std::any MyLustreVisitor::visitExpr_last_decl(LustreParser::Expr_last_declContext *ctx) {
    /**
     * 实现last运算符，此处last运算和kind所支持的pre类似
     * 但需要给个初始值，如果没有初始值，kind2可能会警告
     * 如果用last定义的变量作为初始值，可能会出现循环依赖问题，这时用last定义的变量的初始值作为初始值
     * 如：
     * L2C:
     *       Local1 : float last = i2;
     *       O1 = last 'Local1;
     * Kind2:
     *       O1 = i2 -> pre(Local1);
     *
     */

    std::string res;
    auto IDSymbol = currentScope->resolve(ctx->ID()->getText());
    if (auto varSymbol = std::dynamic_pointer_cast<VariableSymbol>(IDSymbol)) {
        if (varSymbol->getLastSymbol()) {
            res.append(varSymbol->getLastSymbol()->getConstID()->getConstID());
            res.append(" -> ");
        }
    }
    /**
     * TODO:当此处的ID没有定义过初始值时，程序会不通过if，而导致此处的pre前没有给他定义初始值，然后kind验证会不通过
     *
     * 测试文件：../test/optimizevars/last_unopt/last_unopt.Lustre
     * kind2:
     * 有问题的情况:
     *      O1 =  pre(Local1);
     *      --%PROPERTY O1 = ( pre(Local1));  --此处验证是不可满足的
     * 有初始值的情况：
     *      O1 = i2 -> pre(Local1);
     *      --%PROPERTY O1 = (i2-> pre(Local1));  --此处验证是可满足的
     */
    res.append("pre(" + ctx->ID()->getText() + ")");
    return res;
}

std::any MyLustreVisitor::visitExpr_tempo_expr(LustreParser::Expr_tempo_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->tempo_expr()));
}


std::any MyLustreVisitor::visitExpr_bool_expr(LustreParser::Expr_bool_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->bool_expr()));
}

std::any MyLustreVisitor::visitExpr_array_expr(LustreParser::Expr_array_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->array_expr()));
}

std::any MyLustreVisitor::visitExpr_struct_expr(LustreParser::Expr_struct_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->struct_expr()));
}


std::any MyLustreVisitor::visitExpr_switch_expr(LustreParser::Expr_switch_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->switch_expr()));
}

std::any MyLustreVisitor::visitExpr_paren(LustreParser::Expr_parenContext *ctx) {
    return std::string("(" + myvis(ctx->expr()) + ")");
}

std::any MyLustreVisitor::visitExpr_apply_expr(LustreParser::Expr_apply_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->apply_expr()));
}

std::any MyLustreVisitor::visitExpr_kind2_expr(LustreParser::Expr_kind2_exprContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitList(LustreParser::ListContext *ctx){
    std::string res;
    for(int i = 0 ; i < ctx->simple_expr().size() ; i ++) {
        if(i != 0) {
            res.append(", ");
        }
        res.append(myvis(ctx->simple_expr()[i]));
    }
    return res;
}

std::any MyLustreVisitor::visitTempo_expr_pre(LustreParser::Tempo_expr_preContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitTempo_expr_arrow(LustreParser::Tempo_expr_arrowContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitTempo_expr_fby(LustreParser::Tempo_expr_fbyContext *ctx) {
    /**
     * fby (b; n; a)
     * ==>
     * a → pre fby(b; n – 1; a)
     */
    std::string result={};
    //获取const数值
    auto constValueVisitor = std::make_shared<ConstValueVisitor>(*this, currentScope);
    auto constValue=constValueVisitor->visit(ctx->const_expr());
    int constExpr=LustreVisitorTool::anyConverter<int>(constValue);
    auto leftExpr=std::any_cast<std::string>(visit(ctx->simple_expr()[0]));
    auto rightExpr=std::any_cast<std::string>(visit(ctx->simple_expr()[1]));
    result = leftExpr;

    //实现递归的pre
    for (int i = 0; i < constExpr; ++i) {
        std::string tempExpr = rightExpr;
        tempExpr += " -> pre(";
        tempExpr += result;
        tempExpr += ")";
        result = tempExpr;
    }

    return result;
}

std::any MyLustreVisitor::visitTempo_expr_fby_noconst(LustreParser::Tempo_expr_fby_noconstContext *ctx) {
    /**
     *  0 fby n:初始时刻为0，后面每个时刻都为n
     *  ==>
     *  0->pre(n)
     */
    std::string result={};
    auto leftExpr=std::any_cast<std::string>(visit(ctx->simple_expr()[0]));
    auto rightExpr=std::any_cast<std::string>(visit(ctx->simple_expr()[1]));
    result.append(leftExpr);
    result.append(" -> pre(");
    result.append(rightExpr);
    result.append(")");
    return result;
}

std::any MyLustreVisitor::visitTempo_expr_when(LustreParser::Tempo_expr_whenContext *ctx) {
    /**
     * c=a when x;
     * ==>
     * c = merge(x;a ;pre c);
     */
    std::string result={"merge("};
    auto clockID = dynamic_cast<LustreParser::Clock_idContext *>(ctx->clock_expr());
    auto clockNotID = dynamic_cast<LustreParser::Clock_notContext *>(ctx->clock_expr());
    auto simple_expr=std::any_cast<std::string>(visit(ctx->simple_expr()));
    /**
     *  因为kind2中merge的第一个参数不能为not，所以要分类
     */
    if (clockID) {
        auto clock_expr = std::any_cast<std::string>(visit(ctx->clock_expr()));
        result.append(clock_expr).append(" ; ");
        result.append(simple_expr).append(" ; ");
//        //配置初始值
//        auto symbol = currentScope->resolve(clockID->ID()->getText());
//        if (auto varSymbol=std::dynamic_pointer_cast<VariableSymbol>(symbol)){
//            result.append(varSymbol->getLastLus());
//
//        }else{
            result.append("0");
//        }
        result.append(" -> ");
        result.append("pre(").append(lhsIDVector[0]).append(")");


    } else if (clockNotID) {
        auto clock_expr = std::any_cast<std::string>(clockNotID->ID()->getText());
        result.append(clock_expr).append(" ; ");

//        //配置初始值
//        auto symbol = currentScope->resolve(clockNotID->ID()->getText());
//        if (auto varSymbol=std::dynamic_pointer_cast<VariableSymbol>(symbol)){
//            result.append(varSymbol->getLastLus());
//
//        }else{
            result.append("0");
//        }
        result.append(" -> ");
        result.append("pre(").append(lhsIDVector[0]).append(")").append(" ; ");
        result.append(simple_expr);
    }
    result.append(")");
    return result;
}

std::any MyLustreVisitor::visitTempo_expr_merge(LustreParser::Tempo_expr_mergeContext *ctx) {
    std::string result={"merge("};
    result.append(ctx->ID()->getText()).append(" ; ");
    result.append(std::any_cast<std::string>(visit(ctx->simple_expr()[0]))).append(" ; ");
    result.append(std::any_cast<std::string>(visit(ctx->simple_expr()[1])));
    result.append(")");

    return result;
}

std::any MyLustreVisitor::visitTempo_kind2_merge(LustreParser::Tempo_kind2_mergeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitArray_expr_split(LustreParser::Array_expr_splitContext *ctx) {
    /**
     * 数组切片运算，kind2不支持,有两种办法,此处采用法二实现
     * L2C:
     * --_L120 = _L121[1 .. 2];
     *
     * Kind2:
     * 法一： --_L120 = [_L121[1], _L121[2],_L121[3],_L121[4]];
     * 法二： _L120[i0] =if i0+1>=1 and i0+1<=2 then _L121[i0+1] else  _L121[i0+1];
     *      注：法二的else语句应该永远不会被执行，因为L2C的语法定义中表达式左侧是ID，所以ID的数组大小应该和切片的大小相同
     */
    std::string res;
    auto leftInt = std::any_cast<std::string>(ctx->INTEGER()[0]->getText());
    auto rightInt = std::any_cast<std::string>(ctx->INTEGER()[1]->getText());
    std::string leftIndex("i0+" + leftInt);
    res.append("if ");
    //此处根据语法文件，只需支持一位数组切片
    res.append(leftIndex + " >= " + leftInt);
    res.append(" and ");
    res.append(leftIndex + " <= " + rightInt);
    std::string exprIndex(std::any_cast<std::string>(visit(ctx->simple_expr())) + "[" + leftIndex + "]");
    res.append(" then " + exprIndex);
    res.append(" else " + exprIndex);
    return res;





//    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitArray_expr_dynamic(LustreParser::Array_expr_dynamicContext *ctx) {
    auto arrayExprVisitor = std::make_shared<ArrayExprVisitor>(*this, currentScope);
    return arrayExprVisitor->visitArray_expr_dynamic(ctx);

}

std::any MyLustreVisitor::visitArray_expr_and(LustreParser::Array_expr_andContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitArray_expr_list(LustreParser::Array_expr_listContext *ctx) {
    std::string res;
    for (int i = 0; i < ctx->list().size(); ++i) {
        res.append("[" + myvis(ctx->list()[i]) + "]");
        if (i < ctx->list().size()-1){
            res.append(" , ");
        }
    }
    return res;
//    return std::string(LustreVisitorTool::getFullText(ctx));
}


std::any MyLustreVisitor::visitSwitch_expr_ifelse(LustreParser::Switch_expr_ifelseContext *ctx) {
    std::string res;
    res.append("if ").append(myvis(ctx->simple_expr()[0]));
    res.append(" then ").append(myvis(ctx->simple_expr()[1]));
    res.append(" else ").append(myvis(ctx->simple_expr()[2]));
    return res;
}

std::any MyLustreVisitor::visitSwitch_expr_case(LustreParser::Switch_expr_caseContext *ctx) {
    /**
     *   output1 =
	(case var1 of
	| 1 : 97
	| 2 : 98
	| 3 : 99
	| _ : 100);
 改写为:
      output1=if var1=1 then 97 else if var1=2 then 98 else if var1=-3 then 99 else output1;
     */
    std::string res;
    auto simpleExpr = myvis(ctx->simple_expr());

    std::vector<std::pair<std::string, std::string>> casePairVector;
    std::pair<std::string, std::string> defaultPair;
    for (auto caseExpr: ctx->case_expr()) {
        auto casePair = std::any_cast<std::pair<std::string, std::string>>(visit(caseExpr));
        //暂存case中的默认分支
        if (casePair.first == "_") {
            defaultPair = casePair;
        } else {
            casePairVector.push_back(casePair);
        }
    }

    //把默认的case分支放在最后作为else；
    if (!defaultPair.first.empty()) {
        casePairVector.push_back(defaultPair);
    } else {
        SpdlogTool::logErr->warn(
                "'case " + simpleExpr + " of'语句中没有默认分支，这可能会出现问题，请添加默认分支:'_'\n");
    }

    for (int i = 0; i < casePairVector.size(); ++i) {
        auto pattern = casePairVector[i].first;
        auto expr = casePairVector[i].second;
        /**
          * 这里采用了偷懒写法:测试集的case分支会穷尽所有可能，
          * 上面已经把默认分支放在了最后，所以不管有无默认分支，都把最后一项作为else打印出来
          * 注：这种实现方式可能在具体生产中有些问题,所以当没有默认分支时会打印警告信息
          */
        if (i == casePairVector.size() - 1) {
            res.append(expr);
            break;
        }
        res.append("if ").append(simpleExpr).append(" = ").append(pattern).append(" then ").append(expr).append(
                " else ");
    }

    return res;
}

std::any MyLustreVisitor::visitCase_expr(LustreParser::Case_exprContext *ctx) {
//    返回一个pair类型，（pattern，simple_expr）
    return std::make_pair<std::string, std::string>(myvis(ctx->pattern()), myvis(ctx->simple_expr()));
}

std::any MyLustreVisitor::visitApply_prefix(LustreParser::Apply_prefixContext *ctx) {
    auto pMakeContext = dynamic_cast<LustreParser::Perfix_makeContext *>(ctx->prefix_operator());
    auto pFlattenContext = dynamic_cast<LustreParser::Perfix_flattenContext *>(ctx->prefix_operator());
    auto pListContext = dynamic_cast<LustreParser::ListContext *>(ctx->list());
    /*
     * 实现make转换
     */
    if (pMakeContext){
        auto IDTypeDefSymbol=LustreVisitorTool::getIDTypeSymbol(currentScope,pMakeContext->ID()->getText());
        if (!IDTypeDefSymbol->getStructSymbol()){
            SpdlogTool::logErr->error(pMakeContext->ID()->getText()+"不是结构体类型，不能执行make操作");
            return "";
        }
        //函数名
        auto funName = LustreVisitorTool::getNeverUsedName(currentScope,"prefix_make");
        std::vector<std::pair<std::string,std::string>> paramVector;
        std::vector<std::pair<std::string,std::string>> returnVector;
        std::vector<std::string> varDecl,letDecl;
        //设置函数的形参
        auto simpleExprVector = pListContext->simple_expr();
        auto getSimpleExprType = std::make_shared<GetSimpleExprType>(*this, currentScope);
        paramVector.reserve(simpleExprVector.size());
        for (int i=0; i<simpleExprVector.size(); i++) {

            auto string1=LustreVisitorTool::getFullText(simpleExprVector[i]);
            paramVector.emplace_back(
                    "input" + std::to_string(i+1),std::any_cast<std::string>(getSimpleExprType->visit(simpleExprVector[i]))
                           );
        }

        //设置函数的返回值
        returnVector.emplace_back(
               "output",pMakeContext->ID()->getText());
        //设置函数的内容
        std::string letString(returnVector[0].first + " = " + pMakeContext->ID()->getText() + "{ ");
        auto fieldTypeSymbol=IDTypeDefSymbol->getStructSymbol()->getStructSet();
        for (int i = 0; i < fieldTypeSymbol.size(); ++i) {
            letString.append(fieldTypeSymbol[i]->getName()+" = "+paramVector[i].first);
            if (i<fieldTypeSymbol.size()-1){
                letString.append("; ");
            }
        }
        letString.append(" };");
        letDecl.emplace_back(letString);
        //把make的方法放到全局
        endOFVisitorString.append(
                LustreVisitorTool::buildLusFunction(funName,paramVector,returnVector,varDecl,letDecl));
        //设置make方法的调用
        return funName+"("+ myvis(ctx->list())+")";
    } else if (pFlattenContext){//实现flatten转换
        /**
         * 实现flatten转换
         */
        //函数名
        auto funName = LustreVisitorTool::getNeverUsedName(currentScope,"prefix_flatten");
        std::vector<std::pair<std::string,std::string>> paramVector;
        std::vector<std::pair<std::string,std::string>> returnVector;
        std::vector<std::string> varDecl,letDecl;
        //设置函数的形参
        auto simpleExprVector = pListContext->simple_expr();
        auto getSimpleExprType = std::make_shared<GetSimpleExprType>(*this, currentScope);

        auto string1=LustreVisitorTool::getFullText(simpleExprVector[0]);
        paramVector.emplace_back("input1" ,pFlattenContext->ID()->getText());

        //设置函数的返回值
        auto IDTypeSymbol = LustreVisitorTool::getIDTypeSymbol(currentScope,pFlattenContext->ID()->getText());
        /*
         * 结构体的flatten
         */
        if (auto structSymbol = IDTypeSymbol->getStructSymbol()){
            auto fieldSet = structSymbol->getStructSet();
            for (int i = 0; i <fieldSet.size(); ++i) {
                returnVector.emplace_back(
                        "output"+std::to_string(i+1),fieldSet[i]->getDefTypeLusString(fieldSet[i]->getDefType())
                        );

                //设置函数内容
                std::string letString(returnVector[i].first + " = " + paramVector[0].first + "." + fieldSet[i]->getName() + ";");
                letDecl.emplace_back(letString);
            }

        } else if (auto arraySymbol = IDTypeSymbol->getArraySymbol()){
            /**
             * 数组的flatten
             */
            std::any constValue=arraySymbol->getConstSymbol()->getConstValue();
            auto constValueInt=LustreVisitorTool::anyConverter<int>(constValue);
            for (int i = 0; i < constValueInt; ++i) {
                returnVector.emplace_back(
                       "output"+std::to_string(i+1),arraySymbol->getTypeDefSymbol()->getDefTypeLusString(arraySymbol->getTypeDefSymbol()->getDefType())
                       );
                //设置函数内容
                std::string letString(returnVector[i].first + " = " + paramVector[0].first + "[" + std::to_string(i) + "]" + ";" );
                letDecl.emplace_back(letString);
            }
        }

        //把flatten的方法放到全局
        endOFVisitorString.append(
                LustreVisitorTool::buildLusFunction(funName,paramVector,returnVector,varDecl,letDecl));
        //返回flatten方法的调用
        return funName+"("+ myvis(ctx->list())+")";
    }
    /**
     * 实现其他算子
     */
    std::string op =  std::any_cast<std::pair<std::string, std::string>>(visit(ctx->prefix_operator())).second;
    if(dynamic_cast<LustreParser::Prefix_unaryContext *>(ctx->prefix_operator())) { //一元前置
        return op + "(" +
               myvis(ctx->list()) + ")";
    } else {        //二元
        return myvis(ctx->list()->simple_expr()[0]) + " " + op + " " + myvis(ctx->list()->simple_expr()[1]);
    }
//    return myvis(ctx->prefix_operator()) + "(" + myvis(ctx->list()) + ")";
}


std::any MyLustreVisitor::visitApply_map(LustreParser::Apply_mapContext *ctx) {
    auto applyExprVisitor = std::make_shared<ApplyExprVisitor>(*this, currentScope);
    return applyExprVisitor->visitApply_map(ctx);
}

std::any MyLustreVisitor::visitApply_fold(LustreParser::Apply_foldContext *ctx) {
    auto applyExprVisitor = std::make_shared<ApplyExprVisitor>(*this, currentScope);
    return applyExprVisitor->visitApply_fold(ctx);
}

std::any MyLustreVisitor::visitApply_mapi(LustreParser::Apply_mapiContext *ctx) {
    auto applyExprVisitor = std::make_shared<ApplyExprVisitor>(*this, currentScope);
    return applyExprVisitor->visitApply_mapi(ctx);
}
std::any MyLustreVisitor::visitApply_foldi(LustreParser::Apply_foldiContext *ctx) {
    auto applyExprVisitor = std::make_shared<ApplyExprVisitor>(*this, currentScope);
    return applyExprVisitor->visitApply_foldi(ctx);
}
std::any MyLustreVisitor::visitApply_mapfold(LustreParser::Apply_mapfoldContext *ctx) {
    auto applyExprVisitor = std::make_shared<ApplyExprVisitor>(*this, currentScope);
    return applyExprVisitor->visitApply_mapfold(ctx);
}

std::any MyLustreVisitor::visitApply_mapw(LustreParser::Apply_mapwContext *ctx) {
    auto applyExprVisitor = std::make_shared<ApplyExprVisitor>(*this, currentScope);
    return applyExprVisitor->visitApply_mapw(ctx);
}

std::any MyLustreVisitor::visitApply_mapwi(LustreParser::Apply_mapwiContext *ctx) {
    auto applyExprVisitor = std::make_shared<ApplyExprVisitor>(*this, currentScope);
    return applyExprVisitor->visitApply_mapwi(ctx);
}

std::any MyLustreVisitor::visitApply_foldw(LustreParser::Apply_foldwContext *ctx) {
    auto applyExprVisitor = std::make_shared<ApplyExprVisitor>(*this, currentScope);
    return applyExprVisitor->visitApply_foldw(ctx);
}

std::any MyLustreVisitor::visitApply_foldwi(LustreParser::Apply_foldwiContext *ctx) {
    auto applyExprVisitor = std::make_shared<ApplyExprVisitor>(*this, currentScope);
    return applyExprVisitor->visitApply_foldwi(ctx);
}

// 返回值为函数的参数列表以及返回值列表的变量类型，在参数列表最后再额外存储函数名
std::any MyLustreVisitor::visitPerfix_ID(LustreParser::Perfix_IDContext *ctx) {
    auto symbol= currentScope->resolve(ctx->getText());
    std::vector<std::string> params, returns;
    if (auto methodSymbol=std::dynamic_pointer_cast<MethodScope>(symbol)){
        std::vector<std::pair<std::string, std::shared_ptr<Symbol>>> func_params = methodSymbol->getArgs();     //make和flatten可以用类似的结构
        std::vector<std::pair<std::string, std::shared_ptr<Symbol>>> func_returns = methodSymbol->getReturns();
        for(int i = 0 ; i < func_params.size() ; i ++) {
            std::string type;
            if (auto varSymbol=std::dynamic_pointer_cast<VariableSymbol>(func_params[i].second)){
                type=varSymbol->getTypeDefSymbol()->getDefTypeLusString(varSymbol->getTypeDefSymbol()->getDefType());
            }
            params.emplace_back(type);
        }
        for(int i = 0 ; i < func_returns.size() ; i ++) {
            std::string type;
            if (auto varSymbol=std::dynamic_pointer_cast<VariableSymbol>(func_returns[i].second)){
                type=varSymbol->getTypeDefSymbol()->getDefTypeLusString(varSymbol->getTypeDefSymbol()->getDefType());
            }
            returns.emplace_back(type);
        }
    }
    params.emplace_back(ctx->ID()->getText());
    return std::make_pair(params, returns);
}

// prefix_unary_operator : '+$' | '-$' | 'not$' | 'short$' | 'int$' | 'float$' | 'real$';
// 返回值为实现的辅助函数名称以及原始符号
std::any MyLustreVisitor::visitPrefix_unary(LustreParser::Prefix_unaryContext *ctx) {
    std::string text = ctx->getText();
    text.pop_back();        //去掉最后的 $
    std::pair<std::string, std::string> res = std::make_pair("", text);
    if(text == "+") {
        res.first = "unary_add";
    } else if(text == "-") {
        res.first = "unary_minus";
    } else {
        res.first = "unary_" + text;
    }
    return res;
}

//prefix_binary_operator : '$+$' | '$-$' | '$*$' | '$/$' | '$mod$' | '$div$' | '$=$' | '$<>$'
//                         | '$<$' | '$>$' | '$<=$' | '$>=$' | '$and$' | '$or$' | '$xor$';
// 返回值为函数名称以及原始符号
std::any MyLustreVisitor::visitPrefix_binary(LustreParser::Prefix_binaryContext *ctx) {
    std::string text = ctx->getText();
    text = text.substr(1, text.size()-2);       //去掉首尾的 $
    std::pair<std::string, std::string> res = std::make_pair("", text);
    if(text == "+") {
        res.first = "binary_add";
    } else if(text == "-") {
        res.first = "binary_minus";
    } else if(text == "*") {
        res.first = "binary_multiply";
    } else if(text == "/") {
        res.first = "binary_divide";
    } else if(text == "=") {
        res.first = "binary_equal";
    } else if(text == "<>") {
        res.first = "binary_unequal";
    } else if(text == "<") {
        res.first = "binary_less";
    } else if(text == ">") {
        res.first = "binary_more";
    } else if(text == "<=") {
        res.first = "binary_leq";
    } else if(text == ">=") {
        res.first = "binary_req";
    } else {
        res.first = "binary_" + text;
    }
    return res;
}

// 返回值为函数的参数列表以及返回值列表的变量类型, 在参数列表最后再额外存储函数名
std::any MyLustreVisitor::visitPerfix_make(LustreParser::Perfix_makeContext *ctx) {
    //将不会执行这个方法
    return std::string("");
//    std::vector<std::string> params, returns;
//    params.emplace_back("make_" + ctx->ID()->getText());
//    return std::make_pair(params, returns);
}

std::any MyLustreVisitor::visitPerfix_flatten(LustreParser::Perfix_flattenContext *ctx) {
    //将不会执行这个方法
    return std::string("");
//    std::vector<std::string> params, returns;
//
//    params.emplace_back("flatten_" + ctx->ID()->getText());
//    return std::make_pair(params, returns);
}


//std::any MyLustreVisitor::visitIterator_map(LustreParser::Iterator_mapContext *ctx) {
//    return std::string(LustreVisitorTool::getFullText(ctx));
//}
//
//std::any MyLustreVisitor::visitIterator_fold(LustreParser::Iterator_foldContext *ctx) {
//    return std::string(LustreVisitorTool::getFullText(ctx));
//}
//
//std::any MyLustreVisitor::visitIterator_mapi(LustreParser::Iterator_mapiContext *ctx) {
//    return std::string(LustreVisitorTool::getFullText(ctx));
//}
//
//std::any MyLustreVisitor::visitIterator_foldi(LustreParser::Iterator_foldiContext *ctx) {
//    return std::string(LustreVisitorTool::getFullText(ctx));
//}
//
//std::any MyLustreVisitor::visitIterator_mapfold(LustreParser::Iterator_mapfoldContext *ctx) {
//    return std::string(LustreVisitorTool::getFullText(ctx));
//}


std::any MyLustreVisitor::visitSimple_expr_id(LustreParser::Simple_expr_idContext *ctx) {
    auto id =  std::string(LustreVisitorTool::getFullText(ctx));
    if(var_cnt.count(id))
        return id + "_" + std::to_string(var_cnt[id]-1);
    else
        return id;
}

std::any MyLustreVisitor::visitSimple_expr_atom(LustreParser::Simple_expr_atomContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->atom()));
}

std::any MyLustreVisitor::visitSimple_expr_paren(LustreParser::Simple_expr_parenContext *ctx) {
    std::string res("(");
    for (auto sim_expr: ctx->simple_expr()) {
        res.append(myvis(sim_expr)).append(", ");
    }
    res.pop_back();
    res.pop_back();  //去除最后多余的 ", "
    res.append(")");
    return res;
}

std::any MyLustreVisitor::visitSimple_expr_array(LustreParser::Simple_expr_arrayContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->simple_expr()))));
    res.append("[");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()))));
    res.append("]");
    return res;
}

std::any MyLustreVisitor::visitSimple_expr_struct(LustreParser::Simple_expr_structContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitSimple_expr_unary_arith(LustreParser::Simple_expr_unary_arithContext *ctx) {
    if (ctx->unary_arith_op()->getText()[0] == '+') {        //省略一元运算符的 +
        return std::string(std::any_cast<std::string>(visit(ctx->simple_expr())));
    } else {
        return std::string(LustreVisitorTool::getFullText(ctx));
    }
}

std::any MyLustreVisitor::visitSimple_expr_bin_arith(LustreParser::Simple_expr_bin_arithContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->simple_expr()[0]))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->bin_arith_op()))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->simple_expr()[1]))));
    return res;
}

std::any MyLustreVisitor::visitSimple_expr_bin_bool(LustreParser::Simple_expr_bin_boolContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->simple_expr()[0]))));
    res.append(" ");
    res.append(ctx->bin_bool_op()->getText());      //and、or、xor
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->simple_expr()[1]))));
    return res;
}

std::any MyLustreVisitor::visitSimple_expr_bin_relation(LustreParser::Simple_expr_bin_relationContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitSimple_expr_type(LustreParser::Simple_expr_typeContext *ctx) {
    return myvis(ctx->type()) + " " + myvis(ctx->simple_expr());
}

std::any MyLustreVisitor::visitSimple_kind2_expr(LustreParser::Simple_kind2_exprContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitUnary_arith_op_sub(LustreParser::Unary_arith_op_subContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitUnary_arith_op_add(LustreParser::Unary_arith_op_addContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitUnary_arith_op_not(LustreParser::Unary_arith_op_notContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_add(LustreParser::Bin_arith_op_addContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_sub(LustreParser::Bin_arith_op_subContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_mul(LustreParser::Bin_arith_op_mulContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_divided(LustreParser::Bin_arith_op_dividedContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_mod(LustreParser::Bin_arith_op_modContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_div(LustreParser::Bin_arith_op_divContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) {
    int ch = ctx->getText()[1];
    return std::to_string(ch);
}

std::any MyLustreVisitor::visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) {
    std::string res = LustreVisitorTool::getFullText(ctx);
    res.pop_back();     //删除结尾的u
    return std::string("(uint32 " + res + ")");
}

std::any MyLustreVisitor::visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) {
    //TODO 目前实现为转换成real
    std::string res = LustreVisitorTool::getFullText(ctx);
    res.pop_back();     //删除结尾的f
    return res;
}

std::any MyLustreVisitor::visitAtom_REAL(LustreParser::Atom_REALContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) {
    std::string res = LustreVisitorTool::getFullText(ctx);
    res.pop_back();
    res.pop_back();    //删除结尾的us
    return std::string("(uint16 " + res + ")");
}

std::any MyLustreVisitor::visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) {
    std::string res = LustreVisitorTool::getFullText(ctx);
    res.pop_back();      //删除结尾的s
    return std::string("(int16 " + res + ")");
}

std::any MyLustreVisitor::visitLocal_block(LustreParser::Local_blockContext *ctx) {

    std::string res;
    res.append("var").append("\n");
    for (int i = 0; i < ctx->var_decls().size(); ++i) {
        res.append(_tab);
        res.append(std::any_cast<std::string>(visit(ctx->var_decls()[i])));

        res.append(";").append("\n");
    }

    return res;
}

std::any MyLustreVisitor::visitContract(LustreParser::ContractContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
};


std::any MyLustreVisitor::visitIndex(LustreParser::IndexContext *ctx) {
//    两个中括号去掉了
    return std::string(LustreVisitorTool::getFullText(ctx->simple_expr()));
}

//std::any
//MyLustreVisitor::visitExpr_mixed_index_constructor(LustreParser::Expr_mixed_index_constructorContext *ctx) {
//    return std::any_cast<std::string>(visit(ctx->mixed_index_constructor()));
//}
//
//std::any
//MyLustreVisitor::visitExpr_mixed_label_constructor(LustreParser::Expr_mixed_label_constructorContext *ctx) {
//    return std::string(LustreVisitorTool::getFullText(ctx));
//}
//
//std::any MyLustreVisitor::visitMixed_index_constructor(LustreParser::Mixed_index_constructorContext *ctx) {
//
//    auto mixExprVisitor = std::make_shared<MixExprVisitor>(*this, currentScope);
//    return mixExprVisitor->visitMixed_index_constructor(ctx);
//}

std::any MyLustreVisitor::visitField_decl(LustreParser::Field_declContext *ctx) {
    return ctx->ID()->getText() + " : " + myvis(ctx->type());
}

std::any MyLustreVisitor::visitPattern(LustreParser::PatternContext *ctx) {
    if(ctx->CHAR()) {
        int ch = ctx->getText()[1];
        return std::to_string(ch);
    }
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitStruct_expr(LustreParser::Struct_exprContext *ctx) {

    std::string res;
    res.append(" { ");
    for (int i = 0; i < ctx->label_expr().size(); ++i) {

        res.append(myvis(ctx->label_expr()[i]));
        if (i < ctx->label_expr().size() - 1) {
            res.append(" ; ");
        }
    }
    res.append(" } ");
    return res;
}

std::any MyLustreVisitor::visitConst_label_expr(LustreParser::Const_label_exprContext *ctx) {
    std::string res;
    res.append(ctx->ID()->getText()).append(" = ");
    /**
     * 嵌套结构体的处理
     */
    if (auto constStructContext = dynamic_cast<LustreParser::Const_structContext *>(ctx->const_expr())) {
        structDefType = structDefType->getStructSymbol()->getFieldSymbolByName(ctx->ID()->getText());
        res.append(structDefType->getTypeID()->getTypeID());
        //如果它下层还有引用其他结构体，就获得这个结构体类型符号
        if (structDefType->getTypeID()->getTypeIDSymbol()) {
            structDefType = std::dynamic_pointer_cast<TypeDefSymbol>(structDefType->getTypeID()->getTypeIDSymbol());
        }
    }
    res.append(myvis(ctx->const_expr()));
    return res;
}

std::any MyLustreVisitor::visitLabel_expr(LustreParser::Label_exprContext *ctx) {
    std::string res;
    res.append(ctx->ID()->getText()).append(" = ");
    /**
     * 嵌套结构体的处理
     */
    if (dynamic_cast<LustreParser::Expr_struct_exprContext *>(ctx->simple_expr())) {
        structDefType = structDefType->getStructSymbol()->getFieldSymbolByName(ctx->ID()->getText());
        res.append(structDefType->getTypeID()->getTypeID());
        //如果它下层还有引用其他结构体，就获得这个结构体类型符号
        if (structDefType->getTypeID()->getTypeIDSymbol()) {
            structDefType = std::dynamic_pointer_cast<TypeDefSymbol>(structDefType->getTypeID()->getTypeIDSymbol());
        }
    }
    res.append(myvis(ctx->simple_expr()));
    return res;
}

std::any MyLustreVisitor::visitExpr_mixed_constructor(LustreParser::Expr_mixed_constructorContext *ctx) {
    return LustreBaseVisitor::visitExpr_mixed_constructor(ctx);
}

std::any MyLustreVisitor::visitMixed_constructor(LustreParser::Mixed_constructorContext *ctx) {
    std::vector<std::string> mixNestedPath;
    for (int i = 0; i < ctx->label_or_index().size(); ++i) {
        mixNestedPath.push_back(std::any_cast<std::string>(visit(ctx->label_or_index()[i])));
    }
    auto equationExprVisitor = std::make_shared<MixExprVisitor>(*this, currentScope, mixNestedPath);
    return equationExprVisitor->visitMixed_constructor(ctx);
}

std::any MyLustreVisitor::visitMix_index(LustreParser::Mix_indexContext *ctx) {
    return visit(ctx->index());
}

std::any MyLustreVisitor::visitMix_label(LustreParser::Mix_labelContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitTempo_expr_arrow_tempo(LustreParser::Tempo_expr_arrow_tempoContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBool_expr(LustreParser::Bool_exprContext *ctx) {
    auto boolExprVisitor = std::make_shared<BoolExprVisitor>(*this, currentScope);
    return boolExprVisitor->visitBool_expr(ctx);
}

std::any MyLustreVisitor::visitConst_list(LustreParser::Const_listContext *ctx) {
    std::string res;
    for (int i = 0; i < ctx->const_expr().size(); ++i) {
       res.append(myvis(ctx->const_expr()[i]));
        if (i<ctx->const_expr().size()-1){
            res.append(" , ");
        }
    }

    return res;
}
