//
// Created by jack on 12/26/23.
//

#ifndef QL2C_TYPEID_H
#define QL2C_TYPEID_H


#include <string>
#include <memory>
#include "Symbol.h"

class TypeId {


public:
    TypeId() = delete;

    //array类型的构造函数
    explicit TypeId(std::string typeIDString, std::shared_ptr<Symbol> typeIdSymbol);

//    TypeDefSymbol(string &&name, shared_ptr <SymbolTable::Type> type);
    //打印具体的symbol类型：包括array，基础类型打印
    std::string toAstString() const;

    const std::string &getTypeID() const;

    std::shared_ptr<Symbol> getTypeIDSymbol() const;

protected:
    std::string typeIDString;
    std::shared_ptr<Symbol> typeIdSymbol;
};


#endif //QL2C_TYPEID_H
