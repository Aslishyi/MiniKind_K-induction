//
// Created by jack on 1/15/24.
//

#include "MixExprVisitor.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"
#include "../../SymbolTable/Symbol/VariableSymbol.h"
#include "../tool/LustreVisitorTool.h"
#include "../tool/SpdlogTool.h"

#define _tab "    "

MixExprVisitor::MixFunction mf;
MixExprVisitor::MixTypeNestedPath mixTypeNestedPath;

static int mixFunNameIndex(0);

std::pair<std::string, std::string> mixIDPair;

/**
 * 参数设置
 */
//设置变量的名字
std::string varName("tempMixVar");

// 设置函数名
std::string functionName("mixExpr");

//设置函数返回值名称
std::string functionReturnName("output");

//获取生成函数的第二个类型参数
std::string functionParam2("int");

std::any MixExprVisitor::visitMixed_constructor(LustreParser::Mixed_constructorContext *ctx) {
    /**
     * 定义等式右侧的表达式的值
     * 返回给myLustreVisitor
     */
    //定义一个int，表示已经命名过的函数名下标值
    for (int i = 0; i < ctx->label_or_index().size(); ++i) {
        label_or_indexQueue.push(ctx->label_or_index()[i]);
    }
    mixTypeDefSymbol = getParamTypeSymbol(ctx->ID()->getText());

    mixIDPair = {ctx->ID()->getText(), LustreVisitorTool::getFullText(ctx->simple_expr())};

    //设置生成的函数的前两个形参（这两个参数必定存在）
    int inputNum = 0;
    paramVector.emplace_back(getUndefinedName("input", inputNum), getParamTypeString(ctx->ID()->getText()));
    paramVector.emplace_back(getUndefinedName("input", inputNum), functionParam2);
    //进入栈进行递归
    visit(label_or_indexQueue.front());
    paramVector[1].second = functionParam2;
    /**
     * 定义返回的方法体,放在myLustreVisitor的最后
     */
    functionName = getUndefinedName(functionName, mixFunNameIndex);

    //设置函数的返回值
    std::vector<std::pair<std::string, std::string>> returnVector{
            std::make_pair(functionReturnName, getParamTypeString(ctx->ID()->getText()))};


    //设置mix方法的返回值
    std::string returnString;
    returnString.append(functionName + " ( ");
    returnString.append(ctx->ID()->getText() + " , " +
                        std::any_cast<std::string>(myLustreVisitor.visit(ctx->simple_expr())));
    //设置生成的函数的除前两个参数外的其他形参（这些参数不一定存在）
    for (auto &mixPath: mixTypeNestedPath.path) {
        if (auto typeSymbol = getParamTypeSymbol(mixPath)) {
            paramVector.emplace_back(mixPath, typeSymbol->getDefTypeLusString(typeSymbol->getDefType()));
            returnString.append(" , " + mixPath);
        }

    }

    //生成函数
    myLustreVisitor.addFuncToEnd(functionName,
            LustreVisitorTool::buildLusFunction(functionName, paramVector, returnVector, mf.varDecl, mf.letDecl));


    returnString.append(" ) ");
    return returnString;
}

std::any MixExprVisitor::visitMix_label(LustreParser::Mix_labelContext *ctx) {
    auto tempVar = getUndefinedName(varName, tempMixVarIndex);

    //设置tempVar的type定义
    std::string varType(mixTypeDefSymbol->getDefTypeLusString(mixTypeDefSymbol->getDefType()));
    //获得嵌套的结构体Symbol
    mixTypeDefSymbol = mixTypeDefSymbol->getNextNestedSymbol();
    //配置当前嵌套位置的第一个形参的结构体路径如：input1.label1[1].label1[i]
    std::string elseString(paramVector[0].first);
    for (int j = 0; j < mixTypeNestedPath.index; ++j) {
        if (mixTypeNestedPath.path[j].substr(0, 1) == std::string(".")) {
            // 字符串以 '.' 开头:是label类型
            elseString.append(mixTypeNestedPath.path[j]);
        } else {
            elseString.append("[" + mixTypeNestedPath.path[j] + "]");

        };
    }


    //当是第一个值的时候，用output存储
    if (mixTypeNestedPath.index == 0) {
        tempVar = functionReturnName;
    } else {
        mf.varDecl.push_back(tempVar + " : " + varType + ";");
    }

    //获取当前mix定义的label名称
    std::string tempLabelName = mixTypeNestedPath.path[mixTypeNestedPath.index].substr(1);

    //设置结构体的名字
    std::string structIDName(mixTypeDefSymbol->getName());
    //获取结构体的label数组
    auto labelSymbolVector = mixTypeDefSymbol->getStructSymbol()->getStructSet();

    //设置生成的函数的第二个形参的类型
    for (auto & i : labelSymbolVector) {
        auto structLabelName = i->getName();
        if (structLabelName == tempLabelName) {
            functionParam2=i->getDefTypeLusString(i->getDefType());
        }
    }
    std::string labelValue(paramVector[1].first);
    /**
     *  递归退出条件
     *  这个队列中为空
     */
    //弹出队列，使递归进入下一层
    label_or_indexQueue.pop();
    if (!label_or_indexQueue.empty()) {
        // 队列后面还有其他的
        //设置嵌套的路径
        mixTypeNestedPath.index++;
        //获得嵌套label中的Symbol
        mixTypeDefSymbol = mixTypeDefSymbol->getStructSymbol()->getFieldSymbolByName(tempLabelName);
        labelValue = std::any_cast<std::string>(visit(label_or_indexQueue.front()));
    }


    //设置方法体中let中的表达式,构建一个结构体
    std::stringstream res;
    std::stringstream labelRes;
    for (int i = 0; i < labelSymbolVector.size(); ++i) {
        auto structLabelName = labelSymbolVector[i]->getName();
        if (structLabelName == tempLabelName) {
            labelRes << structLabelName << " = " << labelValue;
        } else {
            labelRes << structLabelName << " = " << elseString << "." << structLabelName;

        }

        if (i < labelSymbolVector.size() - 1) {
            labelRes << "; ";
        }
    }

    res << tempVar << " = " << structIDName << " { " << labelRes.str() << " };";

    //定义的方法体中加入这个temp变量的定义
    mf.letDecl.push_back(res.str());

    return tempVar;
}

std::any MixExprVisitor::visitMix_index(LustreParser::Mix_indexContext *ctx) {
    auto tempVar = getUndefinedName(varName, tempMixVarIndex);
    auto index(std::any_cast<std::string>(visit(ctx->index())));

    //设置tempVar的type定义
    std::string varType(mixTypeDefSymbol->getDefTypeLusString(mixTypeDefSymbol->getDefType()));

    //设置else和then
    std::string elseString(paramVector[0].first);
    std::string thenString(paramVector[1].first);
    for (int i = 0; i < mixTypeNestedPath.index; ++i) {
        if (mixTypeNestedPath.path[i].substr(0, 1) == std::string(".")) {
            // 字符串以 '.' 开头:是label类型
            elseString.append(mixTypeNestedPath.path[i]);
        } else {
            elseString.append("[" + mixTypeNestedPath.path[i] + "]");
        }
    }
    elseString.append("[i]");

    //当是第一个值的时候，用output存储
    if (mixTypeNestedPath.index == 0) {
        tempVar = functionReturnName;
    } else {
        mf.varDecl.push_back(tempVar + " : " + varType + ";");
    }

    //设置生成的函数的第二个形参的类型
    functionParam2 = mixTypeDefSymbol->getNextNestedSymbol()->getDefTypeLusString(
            mixTypeDefSymbol->getNextNestedSymbol()->getDefType());

    /**
     *  递归退出条件
     *  这个队列中为空
     */
    //弹出队列，使递归进入下一层
    label_or_indexQueue.pop();
    if (!label_or_indexQueue.empty()) {
        // 队列后面还有其他的
        //获得嵌套的Symbol
        mixTypeDefSymbol = mixTypeDefSymbol->getNextNestedSymbol();
        //设置嵌套的路径
        mixTypeNestedPath.index++;
        thenString = std::any_cast<std::string>(visit(label_or_indexQueue.front()));
    }

    //设置方法体中let中的表达式
    std::stringstream res;
    res << tempVar << "[i] =" << " if " << "i" << " = " << " ( " << index << " ) " << " then " << thenString;
    res << " else " << elseString << ";";

    //定义的方法体中加入这个temp变量的定义
    mf.letDecl.push_back(res.str());

    return tempVar;
}

MixExprVisitor::MixExprVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope,
                               std::vector<std::string> mixNestedPath) : myLustreVisitor(
        myLustreVisitor), currentScope(currentScope) {
    tempMixVarIndex = 0;
    mf = {};
    mixTypeDefSymbol = nullptr;
    mixTypeNestedPath = {std::move(mixNestedPath), 0};
    paramVector = {};

}

std::string MixExprVisitor::getParamTypeString(const std::string &paramString) {
    auto typeDefSymbol = getParamTypeSymbol(paramString);
    return typeDefSymbol->getDefTypeLusString(typeDefSymbol->getDefType());
}

std::string MixExprVisitor::getUndefinedName(std::string name, int &index) {
    while (index < 1000) {
        index++;
        if (!currentScope->resolve(name + std::to_string(index))) {
            break;
        }
    }
    return std::string(name + std::to_string(index));
}

std::any MixExprVisitor::visitIndex(LustreParser::IndexContext *ctx) {
//    两个中括号去掉了
    return std::string(LustreVisitorTool::getFullText(ctx->simple_expr()));
}

std::shared_ptr<TypeDefSymbol> MixExprVisitor::getParamTypeSymbol(const std::string &paramString) {
    auto paramType = currentScope->resolve(paramString);
    if (!paramType) {
        SpdlogTool::logErr->info("在MixExpr中转换中未找到符号表字段：" + paramString);
        return nullptr;
    }
    std::shared_ptr<TypeDefSymbol> typeDefSymbol = nullptr;
    if (auto varSymbol = std::dynamic_pointer_cast<VariableSymbol>(paramType)) {
        typeDefSymbol = varSymbol->getTypeDefSymbol();
    } else if (auto constSymbol = std::dynamic_pointer_cast<ConstSymbol>(paramType)) {
        typeDefSymbol = constSymbol->getDefTypeSymbol();
    } else {
        SpdlogTool::logErr->error("在MixExpr中转换变量" + paramString + "失败！");
    }
    return typeDefSymbol;
}




