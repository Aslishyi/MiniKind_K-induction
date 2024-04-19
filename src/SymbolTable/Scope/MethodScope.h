//
// Created by jack on 11/22/23.
//

#ifndef SYMBOL_METHODSYMBOL_H
#define SYMBOL_METHODSYMBOL_H

#include "../Symbol/Symbol.h"
#include "Scope.h"

class MethodScope : public Symbol, public Scope, public std::enable_shared_from_this<MethodScope> {
public:
    MethodScope() = delete;

    MethodScope(const std::string &name, Symbol::Type type, const std::shared_ptr<antlr4::Token> &token,
                std::shared_ptr<Scope> scope);

//    MethodScope(string &&name, shared_ptr<SymbolTable::Type> token, shared_ptr<Scope> scope);
    MethodScope(const MethodScope &) = delete;

    MethodScope &operator=(const MethodScope &) = delete;

    ~MethodScope();

    const std::string &scopeName() const override;

    std::shared_ptr<Scope> getEnclosingScope() const override;

    void define(std::shared_ptr<Symbol> symbol) override;

    std::shared_ptr<Symbol> resolve(const std::string &name) const override;

    const std::string toString() const override;

private:
    std::vector<std::pair<std::string, std::shared_ptr<Symbol>>> orderedArgs;
    std::shared_ptr<Scope> enclosingScope;
};

#endif //SYMBOL_METHODSYMBOL_H
