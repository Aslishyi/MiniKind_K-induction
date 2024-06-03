

#ifndef SYMBOL_GLOBALSYMBOL_H
#define SYMBOL_GLOBALSYMBOL_H


#include "Scope.h"
#include "../Symbol/Symbol.h"

class GlobalScope : public Scope {


public:
    GlobalScope();

    ~GlobalScope();

    GlobalScope(const GlobalScope &) = delete;

    GlobalScope &operator=(const GlobalScope &) = delete;

    const std::string &scopeName() const override;

    std::shared_ptr<Scope> getEnclosingScope() const override;

    void define(std::shared_ptr<Symbol> symbol) override;

    std::shared_ptr<Symbol> resolve(const std::string &name) const override;

    const std::string toString() const;

    std::unordered_map<std::string, std::shared_ptr<Symbol>> getAllSymbols();

    GlobalScope &setSymbolBySymbolName(std::shared_ptr<Symbol> symbol);

    std::shared_ptr<Symbol> resolveNested(const std::string &name) const override;

private:
    std::string name = "Global";

    std::shared_ptr<std::unordered_map<std::string, std::shared_ptr<Symbol>>>
            symbols;

};


#endif //SYMBOL_GLOBALSYMBOL_H
