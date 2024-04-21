//
// Created by jack on 3/23/24.
//

#ifndef QKIND_AUTOMATONSCOPE_H
#define QKIND_AUTOMATONSCOPE_H


#include "Scope.h"

class AutomatonScope : public Symbol, public Scope {


public:

    AutomatonScope(std::shared_ptr<Scope> enclosingScope, const std::string &name, Symbol::Type type,
                   const std::shared_ptr<antlr4::Token> &token,
                   std::shared_ptr<Scope> scope);

    ~AutomatonScope() = default;

    AutomatonScope &operator=(const AutomatonScope &) = delete;

    const std::string &scopeName() const override;

    void define(std::shared_ptr<Symbol> symbol) override;

    std::shared_ptr<Symbol> resolve(const std::string &name) const override;

    const std::string toString() const override;

    std::shared_ptr<Symbol> resolveNested(const std::string &name) const override;

private:

    std::string name = "Automaton";
    std::vector<std::pair<std::string, std::shared_ptr<Symbol>>> stateSymbols;
    std::vector<std::pair<std::string, std::shared_ptr<Symbol>>> returnSymbols;

};


#endif //QKIND_AUTOMATONSCOPE_H
