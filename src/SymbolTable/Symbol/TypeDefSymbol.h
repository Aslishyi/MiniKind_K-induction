//
// Created by jack on 11/22/23.
//

#ifndef SYMBOL_VARSYMBOL_H
#define SYMBOL_VARSYMBOL_H


#include <any>
#include "Symbol.h"
#include "TypeArray.h"
#include "TypeStruct.h"
#include "TypeId.h"

//class TypeStruct;
//TypeDefSymbol：变量符号
class TypeDefSymbol : public Symbol {


public:
    TypeDefSymbol();
    ~TypeDefSymbol() override;


    //普通Symbol类型的构造函数
    TypeDefSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token,std::shared_ptr<Scope> scope);

    //array类型的构造函数
    TypeDefSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope,Type defType,std::shared_ptr<TypeArray> arraySymbol);

    //struct类型的构造函数
    TypeDefSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token,std::shared_ptr<Scope> scope, Type defType,std::shared_ptr<TypeStruct> structSymbol );

    //普通Type类型的构造函数
    TypeDefSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token,std::shared_ptr<Scope> scope, Type defType,varType variableType );

    //引用类型的构造函数
    TypeDefSymbol(const std::string &name, Type type, std::shared_ptr<antlr4::Token> token,std::shared_ptr<Scope> scope, Type defType,std::shared_ptr<TypeId> typeId );


    //打印具体的symbol类型：包括array，基础类型打印
    virtual std::string toAstString() const override;

    virtual std::string toShortAstString() const override;
    virtual  std::string getDefTypeString(Type defType) const ;

    const Symbol::Type &getDefType() const;
    TypeDefSymbol & setDefType( const Symbol::Type& defType) ;
    const Symbol::varType & getVariableType() const;

    TypeDefSymbol & setVariableType( const Symbol::varType& variableType) ;
    std::shared_ptr<TypeArray> getArraySymbol() const;
    std::shared_ptr<TypeStruct> getStructSymbol() const;
    std::shared_ptr<TypeId> getTypeID() const;

protected:
    //普通变量
    //type定义的类型：基础类型(BASETYPE)，数组类型(ARRAY)，结构体类型(STRUCT),引用类型(REFERENCE)
    Type defType;
    //变量的类型：int,bool,char,short,ushort,uint,float,real;
    varType variableType;

    //数组类型
    std::shared_ptr<TypeArray> arraySymbol;
    //结构体类型
    std::shared_ptr<TypeStruct> structSymbol;
    //引用类型
    std::shared_ptr<TypeId> typeID;


};


#endif //SYMBOL_VARSYMBOL_H
