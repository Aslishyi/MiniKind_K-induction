//
// Created by jack on 11/22/23.
//

#include <iostream>
#include <sstream>
#include "GlobalScope.h"

GlobalScope::GlobalScope()
        : Scope(nullptr), symbols(std::make_shared<std::unordered_map<std::string, std::shared_ptr<Symbol>>>()) {}

GlobalScope::~GlobalScope() {}

const std::string &GlobalScope::scopeName() const {
    return name;
}

std::shared_ptr<Scope> GlobalScope::getEnclosingScope() const {
    return nullptr;
}

void GlobalScope::define(std::shared_ptr<Symbol> symbol) {
    symbols->insert(std::make_pair(symbol->getName(), symbol));
}

std::shared_ptr<Symbol> GlobalScope::resolve(const std::string &name) const {
    auto iter = symbols->find(name);
    if (iter != symbols->end())
        return iter->second;
    else
        return nullptr;
}

std::shared_ptr<Symbol> GlobalScope::resolveNested(const std::string &name) const {
    auto iter = symbols->find(name);
    if (iter != symbols->end())
        return iter->second;
    for (const auto &ele:nestedScopes) {
        if (ele->resolveNested(name)){
            return ele->resolveNested(name);
        }
    }
    return nullptr;
}

const std::string GlobalScope::toString() const {
    std::stringstream ss;
    ss << scopeName() << ": ";
    for (auto &ele: *symbols)
        ss << ele.second->toAstString() << ",\n";
    ss << std::endl;
    return ss.str();
}

std::unordered_map<std::string, std::shared_ptr<Symbol>> GlobalScope::getAllSymbols() {
    return *symbols;
}

GlobalScope &GlobalScope::setSymbolBySymbolName(std::shared_ptr<Symbol> symbol) {
    auto it = symbols->begin();
    auto end = symbols->end();
    while (it != end) {
        if ((*it).second->getName() == symbol->getName()) {
            it->second = symbol;
        }
        it++;
    }
    return *this;
}


