//
// Created by jack on 3/5/24.
//

#include "BoolExprVisitor.h"
#include "../tool/LustreVisitorTool.h"
#include "../tool/SpdlogTool.h"
#include "../../SymbolTable/Symbol/VariableSymbol.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"

BoolExprVisitor::ListStruct listStruct = {};

BoolExprVisitor::BoolExprVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope)
        : myLustreVisitor(myLustreVisitor), currentScope(currentScope) {
}

std::any BoolExprVisitor::visitBool_expr(LustreParser::Bool_exprContext *ctx) {
    /* 测试输入代码
           function fun1(x1: bool^5)returns(y1: bool);
           let
               y1 = #(x1);
           tel
        */
    /* 期望输出结果1(创建全局变量函数)
        function bool_expr(const n:int;x1: bool^5) returns (res: bool);
        var tmp: int^n;
        let
            tmp[i] = if i = 0 then 0 + (if x1[i] = true then 1 else 0) else tmp[i-1] + (if x1[i] = true then 1 else 0);
            res = if tmp[n-1] >= 2 then false else true;
        tel

        function fun1(x1 : bool^(5)) returns (y1 : bool);
        let
            y1 = boolexpr(5,x1);
        tel

        期望输出结果2
        function fun1(x1 : bool^(5)) returns (y1 : bool);
        var tmp: int^5;
        let
            tmp[i] = if i = 0 then 0 + (if x1[i] = true then 1 else 0) else tmp[i-1] + (if x1[i] = true then 1 else 0);
            y1 = if tmp[5-1] >= 2 then false else true;
        tel
     * */

    std::string res;
    visit(ctx->list());
    std::string arrayName = listStruct.name;
    std::string arraySize = listStruct.size;  //arraySize代表bool数组长度

    /**
     * 构建处理函数
     */
    std::string funName = LustreVisitorTool::getNeverUsedName(currentScope, "bool_expr");
    std::vector<std::pair<std::string, std::string>> paramVector = {{"const n", "int"},
                                                                    {arrayName, "bool^" + arraySize}};

    std::vector<std::pair<std::string, std::string>> returnVector = {{"res", "bool"}};
    std::vector<std::string> varDecl = {"tmp:int^n;"};
    std::vector<std::string> letDecl;


    letDecl.emplace_back(
            "tmp[i] = if i = 0 then 0 + (if " + arrayName + "[i] = true then 1 else 0) else tmp[i-1] + (if " +
            arrayName + "[i] = true then 1 else 0);");
    letDecl.emplace_back("res = if tmp[n-1] >= 2 then false else true;");
    /**
     * 设置函数
     */
    myLustreVisitor.addFuncToEnd(funName,
            LustreVisitorTool::buildLusFunction(funName, paramVector, returnVector, varDecl, letDecl));

    //设置函数调用
    res.append(funName + "(" + arraySize + "," + arrayName + ")");
    return res;
}

std::any BoolExprVisitor::visitList(LustreParser::ListContext *ctx) {
    auto simpleExprList = ctx->simple_expr();
    if (simpleExprList.size() == 1) {
        //
        auto symbol = currentScope->resolve(simpleExprList[0]->getText());
        if (auto varSymbol = std::dynamic_pointer_cast<VariableSymbol>(symbol)) {
            auto arrayDim = varSymbol->getTypeDefSymbol()->getArrayDimString();
            listStruct = {simpleExprList[0]->getText(), arrayDim[0]};
        } else if (auto constSymbol = std::dynamic_pointer_cast<ConstSymbol>(symbol)) {
            auto arrayDim = constSymbol->getDefTypeSymbol()->getArrayDimString();
            listStruct = {simpleExprList[0]->getText(), arrayDim[0]};
        } else {
            SpdlogTool::logErr->error("line" + std::to_string(simpleExprList[0]->getStart()->getLine()) + ":" +
                                      simpleExprList[0]->getText() + "字符表转换失败");
        }
        return LustreVisitorTool::getFullText(ctx);
    } else if (simpleExprList.size() > 1) {
        /**
         * y1 = # (e1,e2,e3);
         * ==>
         * tempBoolExpr=[e1,e2,e3];
         * y1 = # tempBoolExpr
         */
        std::string res;
        //设置var的名字
        std::string varName = LustreVisitorTool::getNeverUsedName(currentScope, "tempBoolExpr");
        std::string varType = {"bool^" + std::to_string(simpleExprList.size())};
        //设置var
        myLustreVisitor.endOFVarVector.emplace_back(varName + " : " + varType + ";");
        //向主L2c转换中设置let语句
        std::string tempLet;
        tempLet.append(varName).append(" = ");
        tempLet.append("[");
        for (int i = 0; i < simpleExprList.size(); ++i) {
            tempLet.append(simpleExprList[i]->getText());
            if (i < simpleExprList.size() - 1) {
                tempLet.append(",");
            }
        }
        tempLet.append("];");
        myLustreVisitor.endOFLetVector.emplace_back(tempLet);
        //设置listStruct
        listStruct = {varName, std::to_string(simpleExprList.size())};
        return res;
    } else {
        SpdlogTool::logErr->error(
                "line" + std::to_string(ctx->getStart()->getLine()) + ":" + "'#'布尔表达式的参数不能为空");
        exit(1);
    }
    return LustreVisitorTool::getFullText(ctx);
}
