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

#include "../../lustre/generated/LustreParser.h"

class ConstSymbol : public Symbol {

public:
    ConstSymbol() = default;

    //普通Symbol类型的构造函数
    ConstSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope);

    //一元，二元const类型的构造函数
    ConstSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope,
                std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType, varType constValueType,
                std::any constValue,bool isValueVerify,LustreParser::Const_declContext * constCtx);

    //常量数组类型的构造函数
    ConstSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope,
                std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType,
                std::shared_ptr<ConstArray> constArray,bool isValueVerify,LustreParser::Const_declContext * constCtx);

    //常量结构体类型的构造函数
    ConstSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope,
                std::shared_ptr<TypeDefSymbol> typeDefSymbol, Type defType, std::shared_ptr<ConstStruct> constStruct,bool isValueVerify,LustreParser::Const_declContext * constCtx);

    //引用类型的构造函数
    ConstSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope,
                std::shared_ptr<TypeDefSymbol> typeDefSymbol, Type defType, std::shared_ptr<ConstID> constId,bool isValueVerify,LustreParser::Const_declContext * constCtx);


    //打印具体的symbol类型：包括array，基础类型打印
    std::string toAstString() const override;

    std::string toLusString() const override;

    std::string toShortAstString() const override;

    std::string toShortLusString() const ;

    std::string getDefTypeString(Type defType) const;

    std::string getDefTypeLusString(Type defType) const;

    std::shared_ptr<TypeDefSymbol> getDefTypeSymbol() const;

    const Symbol::Type &getDefType() const;
    ConstSymbol &setDefType(Symbol::Type type);

    std::shared_ptr<TypeDefSymbol> getConstType() const;

    ConstSymbol &setConstType(std::shared_ptr<TypeDefSymbol> typeDefSymbol);

    const varType &getConstValueType() const;
    ConstSymbol &setConstValueType(varType constValueType);

    const std::any &getConstValue() const;
    ConstSymbol &setConstValue(std::any constValue);

    const bool &getIsValueVerify() const;

    LustreParser::Const_declContext *const getConstCtx() const;

    ConstSymbol &setConstCtx(LustreParser::Const_declContext *constCtx);

    ConstSymbol &setIsValueVerify(bool isValueVerify);

    std::string getConstValueString() const;

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
    //标识：判断Value是否被确定
    bool isValueVerify;
    //const中的值
    std::any constValue;

    //保存当前const的上下文无关语法
    LustreParser::Const_declContext * constCtx;

    // const 中的数组常量
    std::shared_ptr<ConstArray> constArray;

    // const 中的结构体常量
    std::shared_ptr<ConstStruct> constStruct;

    // const 中的结构体常量
    std::shared_ptr<ConstID> constID;


};


#endif //QL2C_CONSTSYMBOL_H
