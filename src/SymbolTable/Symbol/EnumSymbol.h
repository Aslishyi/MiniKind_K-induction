//
// Created by jack on 12/26/23.
//

#ifndef QL2C_ENUMSYMBOL_H
#define QL2C_ENUMSYMBOL_H


#include "Symbol.h"

class EnumSymbol : public Symbol {


public:
    EnumSymbol() = delete;

    ~EnumSymbol() override;

    //普通Symbol类型的构造函数
    EnumSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope,
               std::unordered_map<std::string, std::shared_ptr<antlr4::Token>> enumMap);

    //打印具体的symbol类型：包括array，基础类型打印
    std::string toAstString() const override;

    std::string toShortAstString() const override;


    const std::unordered_map<std::string, std::shared_ptr<antlr4::Token>> &getEnumMap() const;

protected:
    std::unordered_map<std::string, std::shared_ptr<antlr4::Token>> enumMap;

};


#endif //QL2C_ENUMSYMBOL_H
