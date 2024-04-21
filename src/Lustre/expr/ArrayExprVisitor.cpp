//
// Created by jack on 1/14/24.
//

#include "ArrayExprVisitor.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"
#include "../../SymbolTable/Symbol/VariableSymbol.h"
#include "../tool/SpdlogTool.h"

#define _tab "    "

std::any ArrayExprVisitor::visitArray_expr_dynamic(LustreParser::Array_expr_dynamicContext *ctx) {

    std::string res;
    res.append("if");
    res.append(" ");
    //获取simple的符号
    auto leftExpr = myLustreVisitor.visit(ctx->simple_expr()[0]);
    auto leftSymbol = currentScope->resolve(std::any_cast<std::string>(leftExpr));
    auto rightExpr = myLustreVisitor.visit(ctx->simple_expr()[1]);

    std::vector<std::string> indexVector;
    for (int i = 0; i < ctx->index().size(); ++i) {
        auto indexVisitor = myLustreVisitor.visit(ctx->index()[i]);
        indexVector.push_back(std::any_cast<std::string>(indexVisitor));
    }
    if (auto constSymbol = std::dynamic_pointer_cast<ConstSymbol>(leftSymbol)) {
        // 处理 ConstSymbol 类型
        // 可以访问 constSymbol 的成员和方法
        std::vector<std::string> dimVector = constSymbol->getDefTypeSymbol()->getArrayDimString();
        res.append(generateArrayProjection(indexVector, dimVector, std::any_cast<std::string>(leftExpr)));
        res.append("else " + std::any_cast<std::string>(rightExpr));;

    } else if (auto varSymbol = std::dynamic_pointer_cast<VariableSymbol>(leftSymbol)) {
        // 处理 VariableSymbol 类型
        // 可以访问 varSymbol 的成员和方法
        std::vector<std::string> dimVector = varSymbol->getTypeDefSymbol()->getArrayDimString();
        res.append(generateArrayProjection(indexVector, dimVector, std::any_cast<std::string>(leftExpr)));
        res.append("else " + std::any_cast<std::string>(rightExpr));;

    } else {
        // 其他类型的处理
        SpdlogTool::logErr->error("数组投影运算出现未定义数据");
    }
    return res;
}

std::string ArrayExprVisitor::generateArrayProjection(const std::vector<std::string> &indexVector,
                                                      const std::vector<std::string> &dimVector,
                                                      const std::string &leftExpr) {
    std::string res;
    res.append("( ");
    for (int i = 0; i < indexVector.size(); i++) {
        res.append(indexVector[i] + " > 0" + " and " + indexVector[i] + " < " + dimVector[i]);
        if (i < indexVector.size() - 1) {
            res.append(" and ");
        }
    }
    res.append(" ) then");
    res.append("\n");
    res.append(_tab _tab _tab);
    res.append(leftExpr);
    for (const auto &i: indexVector) {
        res.append("[" + i + "]");
    }
    res.append("\n");
    res.append(_tab _tab);
    return res;
}

ArrayExprVisitor::ArrayExprVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope)
        : myLustreVisitor(myLustreVisitor), currentScope(currentScope) {

}




