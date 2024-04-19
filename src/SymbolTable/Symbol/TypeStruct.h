//
// Created by jack on 12/22/23.
//

#ifndef QL2C_TYPESTRUCT_H
#define QL2C_TYPESTRUCT_H


#include "Symbol.h"

class TypeDefSymbol;
class TypeStruct {


public:
    TypeStruct();

    //array类型的构造函数
     explicit TypeStruct(std::unordered_set<std::shared_ptr<TypeDefSymbol>> structVector);

    //打印具体的symbol类型：包括array，基础类型打印
    std::string toAstString() const;


    const std::unordered_set<std::shared_ptr<TypeDefSymbol>> &getStructSet() const;
protected:
    std::unordered_set<std::shared_ptr<TypeDefSymbol>> structSet;

};



#endif //QL2C_TYPESTRUCT_H
