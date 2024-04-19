//
// Created by jack on 12/21/23.
//

#ifndef QL2C_TYPEARRAY_H
#define QL2C_TYPEARRAY_H


#include "Symbol.h"

//数组类型符号
class ConstSymbol;
class TypeDefSymbol;
class TypeArray {

public:
    TypeArray()=delete;

    //array类型的构造函数
    TypeArray(std::shared_ptr<TypeDefSymbol> arrayType,std::shared_ptr<ConstSymbol> constSymbol);

    //打印具体的symbol类型：包括array，基础类型打印
    std::string toAstString() const;

    //打印每个维度
    std::string toDimString() const;


protected:
    //array类型的符号的类型
    std::shared_ptr<TypeDefSymbol> arrayType;
    //array的值
    std::shared_ptr<ConstSymbol> constSymbol;
};


#endif //QL2C_TYPEARRAY_H
