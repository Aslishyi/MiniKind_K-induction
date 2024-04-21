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


/*
 * Type接口用于定义数据类型，如int、float等
 * Type接口定义后用于区分自定义类型与普通程序类型
 * Symbol中的属性引用Type接口中数据类型
 * */
//class TypeStruct;
//TypeDefSymbol：变量符号
class TypeDefSymbol : public Symbol {


public:
    TypeDefSymbol();

    ~TypeDefSymbol() override;


    //普通Symbol类型的构造函数
    TypeDefSymbol(const std::string &name, std::shared_ptr<antlr4::Token> token,
                  std::shared_ptr<Scope> scope);

    //array类型的构造函数
    TypeDefSymbol(const std::string &name,  std::shared_ptr<antlr4::Token> token,
                  std::shared_ptr<Scope> scope, Type defType, std::shared_ptr<TypeArray> arraySymbol);

    //struct类型的构造函数
    TypeDefSymbol(const std::string &name,  std::shared_ptr<antlr4::Token> token,
                  std::shared_ptr<Scope> scope, Type defType, std::shared_ptr<TypeStruct> structSymbol);

    //普通Type类型的构造函数
    TypeDefSymbol(const std::string &name,  std::shared_ptr<antlr4::Token> token,
                  std::shared_ptr<Scope> scope, Type defType, varType variableType);

    //引用类型的构造函数
    TypeDefSymbol(const std::string &name,  std::shared_ptr<antlr4::Token> token,
                  std::shared_ptr<Scope> scope, Type defType, std::shared_ptr<TypeId> typeId);


    //打印具体的symbol类型：包括array，基础类型打印
    virtual std::string toAstString() const override;

    virtual std::string toLusString() const override;
    virtual std::string getDefTypeLusString(Type defType) const;

    virtual std::string toShortAstString() const override;

    virtual std::string toShortLusString() const ;

    virtual std::string getDefTypeString(Type defType) const;

    //获取下一个嵌套的TypeDefSymobl
    virtual std::shared_ptr<TypeDefSymbol> getNextNestedSymbol() const;

    const Symbol::Type &getDefType() const;

    TypeDefSymbol &setDefType(const Symbol::Type &defType);

    const Symbol::varType &getVariableType() const;

    TypeDefSymbol &setVariableType(const Symbol::varType &variableType);

    std::shared_ptr<TypeArray> getArraySymbol() const;

    TypeDefSymbol &setArraySymbol(std::shared_ptr<TypeArray> arraySymbol);

    std::shared_ptr<TypeStruct> getStructSymbol() const;

    TypeDefSymbol &setStructSymbol(std::shared_ptr<TypeStruct> structSymbol);

    std::shared_ptr<TypeId> getTypeID() const;

    TypeDefSymbol &setTypeID(std::shared_ptr<TypeId> typeID);


    //以数组的方式存储Array的各个维度
    const std::vector<std::string> getArrayDimString() const;

    bool isEqual(std::shared_ptr<TypeDefSymbol> typeDefSymbol) ;

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
