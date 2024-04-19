//
// Created by jack on 11/22/23.
//

#include <iostream>
#include <sstream>
#include <utility>
#include "MethodScope.h"



//MethodScope::MethodScope(string &&name, SymbolTable::Type type, shared_ptr<Scope> scope)
//        : SymbolTable(name, std::move(type)), enclosingScope(std::move(scope))
//{ }

MethodScope::~MethodScope()
{ }

const std::string& MethodScope::scopeName() const
{
    return name;
}

std::shared_ptr<Scope> MethodScope::getEnclosingScope() const
{
    return enclosingScope;
}

void MethodScope::define(std::shared_ptr<Symbol> symbol)
{
    auto item = std::make_pair(symbol->getName(), symbol);
    orderedArgs.push_back(item);
    symbol->setScope(shared_from_this());
}

std::shared_ptr<Symbol> MethodScope::resolve(const std::string &name) const
{
    for (const auto &ele : orderedArgs)
        if (ele.first == name)
            return ele.second;
    if (enclosingScope)
        return enclosingScope->resolve(name);
    return nullptr;
}

const std::string MethodScope::toString() const {
    std::stringstream ss;
    ss << scopeName() << ": ";
    for (auto &ele : orderedArgs)
        ss << ele.second->toAstString() << ", ";
    ss << std::endl;
    return ss.str();
//    std::cout<<"MethodScope.toString"<<std::endl;
//    return std::string();
}

MethodScope::MethodScope(const std::string &name, Symbol::Type type,const std::shared_ptr<antlr4::Token> &token, std::shared_ptr<Scope> scope) :Symbol(name,type,token,scope),enclosingScope(scope){

}

