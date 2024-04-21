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

    std::string toLusString() const;

    //打印每个维度
    std::string toDimString() const;

    //获取type中const类型
    std::shared_ptr<ConstSymbol> getConstSymbol() const;

    std::shared_ptr<TypeDefSymbol> getTypeDefSymbol() const;

    //获取数组的维度,并以数组形式返回
    const std::vector<std::string> getArrayDim() const;

    bool isEqual(std::shared_ptr<TypeArray> typeArray);


protected:
    //array类型的符号的类型
    std::shared_ptr<TypeDefSymbol> arrayType;
    //array的值
    std::shared_ptr<ConstSymbol> constSymbol;
};


#endif //QL2C_TYPEARRAY_H
