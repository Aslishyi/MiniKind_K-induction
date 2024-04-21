//
// Created by jack on 11/22/23.
//

#include <iostream>
#include <sstream>
#include <utility>
#include "MethodScope.h"



const std::string &MethodScope::scopeName() const {
    return name;
}


void MethodScope::define(std::shared_ptr<Symbol> symbol) {
    auto item = std::make_pair(symbol->getName(), symbol);
    orderedArgs.push_back(item);
    symbol->setScope(shared_from_this());
}

std::shared_ptr<Symbol> MethodScope::resolve(const std::string &name) const {
    //找函数的参数列表
    for (const auto &ele: orderedArgs)
        if (ele.first == name)
            return ele.second;
    //找函数的返回列表
    for (const auto &ele: orderedReturns)
        if (ele.first == name)
            return ele.second;
    if (enclosingScope)
        return enclosingScope->resolve(name);
    return nullptr;
}

std::shared_ptr<Symbol> MethodScope::resolveNested(const std::string &name) const {
    //找函数的参数列表
    for (const auto &ele: orderedArgs)
        if (ele.first == name)
            return ele.second;
    //找函数的返回列表
    for (const auto &ele: orderedReturns)
        if (ele.first == name)
            return ele.second;
    for (const auto &ele:nestedScopes) {
        if (ele->resolveNested(name)){
            return ele->resolveNested(name);
        }
    }
    return nullptr;
}

const std::string MethodScope::toString() const {
    std::stringstream ss;
    ss << "\n" << scopeName() << ":\nARGS: ";
    for (auto &ele: orderedArgs)
        ss << ele.second->toAstString() << ", \n";
    ss << "RETURN: ";
    for (auto &ele: orderedReturns)
        ss << ele.second->toAstString() << ", \n";
    ss << std::endl;
    return ss.str();
//    std::cout<<"MethodScope.toString"<<std::endl;
//    return std::string();
}

MethodScope::MethodScope(std::shared_ptr<Scope> enclosingScope, const std::string &name, Symbol::Type type,
                         const std::shared_ptr<antlr4::Token> &token, std::shared_ptr<Scope> scope)
        : Scope(enclosingScope), Symbol(name, type, token, scope) {

}

void MethodScope::defineReturns(std::shared_ptr<Symbol> symbol) {
    auto item = std::make_pair(symbol->getName(), symbol);
    orderedReturns.push_back(item);
    symbol->setScope(shared_from_this());
}

const std::vector<std::pair<std::string, std::shared_ptr<Symbol>>> &MethodScope::getArgs() {
    return orderedArgs;
}

const std::vector<std::pair<std::string, std::shared_ptr<Symbol>>> &MethodScope::getReturns() {
    return orderedReturns;
}

