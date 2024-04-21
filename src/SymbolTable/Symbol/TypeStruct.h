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
     explicit TypeStruct(std::vector<std::shared_ptr<TypeDefSymbol>> structVector);

    //打印具体的symbol类型：包括array，基础类型打印
    std::string toAstString() const;

    std::string toLusString() const;

    bool isEqual(std::shared_ptr<TypeStruct> typeStruct);
    std::shared_ptr<TypeDefSymbol> getFieldSymbolByName(const std::string& fieldName);


    const std::vector<std::shared_ptr<TypeDefSymbol>> &getStructSet() const;
protected:
    std::vector<std::shared_ptr<TypeDefSymbol>> structVector;

};



#endif //QL2C_TYPESTRUCT_H
