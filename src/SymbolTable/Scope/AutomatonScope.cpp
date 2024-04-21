//
// Created by jack on 3/23/24.
//

#include "AutomatonScope.h"

#include <utility>
#include "StateScope.h"
#include "../Symbol/VariableSymbol.h"
#include "../../lustre/tool/SpdlogTool.h"

const std::string &AutomatonScope::scopeName() const {
    return name;
}

void AutomatonScope::define(std::shared_ptr<Symbol> symbol) {
    auto item = std::make_pair(symbol->getName(), symbol);
    if (std::dynamic_pointer_cast<StateScope>(symbol)) {
        stateSymbols.push_back(item);
    } else if (std::dynamic_pointer_cast<VariableSymbol>(symbol)) {

        returnSymbols.push_back(item);
    } else {
        SpdlogTool::logErr->error(name + "中定义符号：" + symbol->getName() + "失败!");
        return;
    }
}

std::shared_ptr<Symbol> AutomatonScope::resolve(const std::string &name) const {
    //找state的参数列表
    for (const auto &ele: stateSymbols)
        if (ele.first == name)
            return ele.second;
    //找返回值的返回列表
    for (const auto &ele: returnSymbols)
        if (ele.first == name)
            return ele.second;
    if (enclosingScope)
        return enclosingScope->resolve(name);
    return nullptr;
}

std::shared_ptr<Symbol> AutomatonScope::resolveNested(const std::string &name) const {
    //找state的参数列表
    for (const auto &ele: stateSymbols)
        if (ele.first == name)
            return ele.second;
    //找返回值的返回列表
    for (const auto &ele: returnSymbols)
        if (ele.first == name)
            return ele.second;
    for (const auto &ele:nestedScopes) {
        if (ele->resolveNested(name)){
            return ele->resolveNested(name);
        }
    }
    return nullptr;
}

const std::string AutomatonScope::toString() const {
    std::stringstream ss;
    ss << "\n" << scopeName() << ":\n状态: ";
    for (auto &ele: stateSymbols)
        ss << ele.second->toAstString() << ", \n";
    ss << "返回值: ";
    for (auto &ele: returnSymbols)
        ss << ele.second->toAstString() << ", \n";
    ss << std::endl;
    return ss.str();
}


AutomatonScope::AutomatonScope(std::shared_ptr<Scope> enclosingScope, const std::string &name, Symbol::Type type,
                               const std::shared_ptr<antlr4::Token> &token,
                               std::shared_ptr<Scope> scope) : Symbol(name, type, token, scope),name(name),  Scope(enclosingScope) {

}
