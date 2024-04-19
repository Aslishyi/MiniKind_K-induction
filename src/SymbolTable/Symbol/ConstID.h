//
// Created by jack on 12/26/23.
//

#ifndef QL2C_CONSTID_H
#define QL2C_CONSTID_H


#include <string>
#include <memory>
#include "Symbol.h"

class ConstSymbol;

class ConstID {


public:
    ConstID() = delete;

    //array类型的构造函数
    explicit ConstID(std::string constIDString,std::shared_ptr<Symbol> constIdSymbol);

//    TypeDefSymbol(string &&name, shared_ptr <SymbolTable::Type> type);
    //打印具体的symbol类型：包括array，基础类型打印
    std::string toAstString() const;
    const std::string & getConstID() const;
    std::shared_ptr<Symbol> getConstIDSymbol() const;

protected:

    std::string constIDString;
    std::shared_ptr<Symbol> constIdSymbol;
};


#endif //QL2C_CONSTID_H
