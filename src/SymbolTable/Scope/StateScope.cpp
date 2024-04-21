//
// Created by jack on 3/23/24.
//

#include "StateScope.h"
#include "../Symbol/VariableSymbol.h"
#include "../Symbol/TransitionSymbol.h"
#include "../../lustre/tool/SpdlogTool.h"


const std::string &StateScope::scopeName() const {
    return name;
}


void StateScope::define(std::shared_ptr<Symbol> symbol) {
    auto item = std::make_pair(symbol->getName(), symbol);
//    if (std::dynamic_pointer_cast<VariableSymbol>(symbol)) {
//
//        varSymbol.push_back(item);
//    } else
    if (std::dynamic_pointer_cast<TransitionSymbol>(symbol)) {

        transitionSymbols.push_back(item);
    } else {
        SpdlogTool::logErr->error(this->getName() + "中定义符号：" + symbol->getName() + "失败!");
        return;
    }
    symbol->setScope(shared_from_this());
}

std::shared_ptr<Symbol> StateScope::resolve(const std::string &name) const {
    //找函数的参数列表
    for (const auto &ele: transitionSymbols)
        if (ele.first == name)
            return ele.second;
    if (enclosingScope)
        return enclosingScope->resolve(name);
    return nullptr;
}

const std::string StateScope::toString() const {
    std::stringstream ss;
    ss << "\n" << scopeName() << ":\n转换条件: ";
    for (auto &ele: transitionSymbols)
        ss << ele.second->toAstString() << ", \n";
    ss << std::endl;
    return ss.str();

}

StateScope::StateScope(std::shared_ptr<Scope> enclosingScope,
                       const std::string &name, Symbol::Type type, const std::shared_ptr<antlr4::Token> &token,
                       std::shared_ptr<Scope> scope, bool initial, bool final)
        : Scope(enclosingScope), Symbol(name, type, token, scope), initial(initial), final(final) {

}

std::shared_ptr<Symbol> StateScope::resolveNested(const std::string &name) const {
    //找函数的参数列表
    for (const auto &ele: transitionSymbols)
        if (ele.first == name)
            return ele.second;
    for (const auto &ele:nestedScopes) {
        if (ele->resolveNested(name)){
            return ele->resolveNested(name);
        }
    }
    return nullptr;
}