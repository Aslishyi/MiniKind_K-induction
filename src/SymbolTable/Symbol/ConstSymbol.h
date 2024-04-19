//
// Created by jack on 12/22/23.
//

#ifndef QL2C_CONSTSYMBOL_H
#define QL2C_CONSTSYMBOL_H


#include "Symbol.h"
#include "TypeDefSymbol.h"
#include "ConstArray.h"
#include "ConstStruct.h"
#include "ConstID.h"

class ConstSymbol : public Symbol {

public:
    ConstSymbol() = delete;

    //普通Symbol类型的构造函数
    ConstSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope);

    //一元，二元const类型的构造函数
    ConstSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope,
                std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType, varType constValueType,
                std::any constValue);

    //常量数组类型的构造函数
    ConstSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope,
                std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType,
                std::shared_ptr<ConstArray> constArray);

    //常量结构体类型的构造函数
    ConstSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope,
                std::shared_ptr<TypeDefSymbol> typeDefSymbol, Type defType, std::shared_ptr<ConstStruct> constStruct);

    //引用类型的构造函数
    ConstSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope,
                std::shared_ptr<TypeDefSymbol> typeDefSymbol, Type defType, std::shared_ptr<ConstID> constId);


    //打印具体的symbol类型：包括array，基础类型打印
    std::string toAstString() const override;

    std::string toShortAstString() const override;

    std::string getDefTypeString(Type defType) const;

    const Symbol::Type &getDefType() const;

    std::shared_ptr<TypeDefSymbol> getConstType() const;

    ConstSymbol &setConstType(std::shared_ptr<TypeDefSymbol> typeDefSymbol);

    const varType &getConstValueType() const;

    const std::any &getConstValue() const;

    std::shared_ptr<ConstArray> getConstArray() const;

    std::shared_ptr<ConstStruct> getConstStruct() const;

    std::shared_ptr<ConstID> getConstID() const;


protected:

    //type定义的类型：基础类型(BASETYPE)，数组类型(ARRAY)，结构体类型(STRUCT),引用类型(REFERENCE)
    Type defType;

    //const本身的类型
    std::shared_ptr<TypeDefSymbol> typeDefSymbol;

    //const中值的类型
    varType constValueType;
    //const中的值
    std::any constValue;

    // const 中的数组常量
    std::shared_ptr<ConstArray> constArray;

    // const 中的结构体常量
    std::shared_ptr<ConstStruct> constStruct;

    // const 中的结构体常量
    std::shared_ptr<ConstID> constID;


};


#endif //QL2C_CONSTSYMBOL_H
