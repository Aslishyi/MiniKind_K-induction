//
// Created by jack on 11/22/23.
//

#include "Scope.h"

Scope::~Scope() {}


std::shared_ptr<Scope> Scope::getEnclosingScope() const {
    return enclosingScope;
}

std::vector<std::shared_ptr<Scope>> Scope::getNestedScope() const {
    return nestedScopes;
}

Scope::Scope(std::shared_ptr<Scope> enclosingScope) : enclosingScope(enclosingScope) {

}

std::shared_ptr<Scope> Scope::addNestedScopes(std::shared_ptr<Scope> scope) {
    nestedScopes.emplace_back(scope);
    return shared_from_this();
}
