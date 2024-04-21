//
// Created by jack on 12/22/23.
//

#ifndef QL2C_VARIABLESYMBOL_H
#define QL2C_VARIABLESYMBOL_H


#include "TypeDefSymbol.h"

class VariableSymbol : public Symbol {


public:
    VariableSymbol() = delete;


    //普通Symbol类型的构造函数
    VariableSymbol(const std::string &name, std::shared_ptr<antlr4::Token> token,
                   std::shared_ptr<Scope> scope);

    //变量类型的构造函数
    VariableSymbol(const std::string &name,  std::shared_ptr<antlr4::Token> token,
                   std::shared_ptr<Scope> scope, std::shared_ptr<TypeDefSymbol> typeDefSymbol,
                   std::pair<bool, std::string> clockID,std::shared_ptr<ConstSymbol> lastSymbol);


    //打印具体的symbol类型
    std::string toAstString() const override;

    virtual std::string getVarDeclString() const;

    std::shared_ptr<TypeDefSymbol> getTypeDefSymbol() const;

    VariableSymbol &setTypeDefSymbol(std::shared_ptr<TypeDefSymbol> typeDefSymbol);

    //when关键字
    const std::pair<bool, std::string> &getClockID() const;

    //last关键字
    std::shared_ptr<ConstSymbol> getLastSymbol() const;

    //获得last字段的lus
    std::string getLastLus() const;

protected:
    //变量的类型
    std::shared_ptr<TypeDefSymbol> typeDefSymbol;

//    when_decl
    std::pair<bool, std::string> clockID;
//    last_decl
    std::shared_ptr<ConstSymbol> lastSymbol;

    std::string toTypeAstString() const;
    std::string toLastAstString() const;
    std::string toClockAstString() const;

};

#endif //QL2C_VARIABLESYMBOL_H
