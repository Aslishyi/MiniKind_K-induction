//
// Created by jack on 11/22/23.
//

#include "LocalScope.h"

const std::string &LocalScope::scopeName() const {
    return name;
}

void LocalScope::define(std::shared_ptr<Symbol> symbol) {

    symbols->insert(std::make_pair(symbol->getName(), symbol));
}

std::shared_ptr<Symbol> LocalScope::resolve(const std::string &name) const {
    //在当前范围内查找是否存在
    auto it = symbols->find(name);
    if (it != symbols->end()) {
        return it->second;
    }
    //如果当前范围不存在在父节点寻找
    if (enclosingScope != nullptr) {
        return enclosingScope->resolve(name);
    }
    return nullptr;
}

std::shared_ptr<Symbol> LocalScope::resolveNested(const std::string &name) const {
    //在当前范围内查找是否存在
    auto it = symbols->find(name);
    if (it != symbols->end()) {
        return it->second;
    }
    for (const auto &ele:nestedScopes) {
        if (ele->resolveNested(name)){
            return ele->resolveNested(name);
        }
    }
    return nullptr;
}

const std::string LocalScope::toString() const {
    std::stringstream ss;
    ss << scopeName() << ": ";
    for (auto &ele: *symbols)
        ss << ele.second->toAstString() << ",\n";
    ss << std::endl;
    return ss.str();

}

LocalScope::LocalScope(std::shared_ptr<Scope> enclosingScope) : symbols(
        std::make_shared<std::unordered_map<std::string, std::shared_ptr<Symbol>>>()), Scope(enclosingScope) {

}

LocalScope::~LocalScope() {

}
