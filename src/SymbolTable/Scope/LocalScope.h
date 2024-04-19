//
// Created by jack on 11/22/23.
//

#ifndef LUSTRETOL2C_LOCALSCOPE_H
#define LUSTRETOL2C_LOCALSCOPE_H


#include "../Symbol/Symbol.h"

#include "Scope.h"

class LocalScope :public Scope{


public:
    LocalScope(std::shared_ptr<Scope> enclosingScope);

    ~LocalScope();


    LocalScope &operator=(const LocalScope &) = delete;

    const std::string &scopeName() const override;

    std::shared_ptr <Scope> getEnclosingScope() const override;

    void define(std::shared_ptr <Symbol> symbol) override;

    std::shared_ptr <Symbol> resolve(const std::string &name) const override;

    const std::string toString() const override;


private:

    std::string name = "Local";
    std::shared_ptr<std::unordered_map<std::string, std::shared_ptr<Symbol>>> symbols;
    std::shared_ptr<Scope> enclosingScope;
};


#endif //LUSTRETOL2C_LOCALSCOPE_H
