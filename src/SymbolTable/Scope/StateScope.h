//
// Created by jack on 3/23/24.
//

#ifndef QKIND_STATESCOPE_H
#define QKIND_STATESCOPE_H


#include "Scope.h"

class StateScope : public Symbol, public Scope {
public:
    StateScope() = delete;

    StateScope(std::shared_ptr<Scope> enclosingScope,
               const std::string &name, Symbol::Type type, const std::shared_ptr<antlr4::Token> &token,
               std::shared_ptr<Scope> scope, bool initial, bool final);

//    MethodScope(string &&name, shared_ptr<SymbolTable::Type> token, shared_ptr<Scope> scope);
    StateScope(const StateScope &) = delete;

    StateScope &operator=(const StateScope &) = delete;

    ~StateScope() = default;

    const std::string &scopeName() const override;

    void define(std::shared_ptr<Symbol> symbol);

    std::shared_ptr<Symbol> resolve(const std::string &name) const override;

    std::shared_ptr<Symbol> resolveNested(const std::string &name) const override;

    const std::string toString() const override;


private:
//    std::vector<std::pair<std::string, std::shared_ptr<Symbol>>> varSymbol;
    std::vector<std::pair<std::string, std::shared_ptr<Symbol>>> transitionSymbols;
    bool initial;
    bool final;

//    std::shared_ptr<Symbol> resolveInside(const std::string &name) const;
};


#endif //QKIND_STATESCOPE_H
