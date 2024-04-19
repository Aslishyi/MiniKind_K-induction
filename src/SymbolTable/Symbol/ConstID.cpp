//
// Created by jack on 12/26/23.
//

#include "ConstID.h"

#include <utility>

ConstID::ConstID(std::string constIDString, std::shared_ptr<Symbol> constIdSymbol) :constIDString(std::move(constIDString)),constIdSymbol(std::move(constIdSymbol)){

}

std::string ConstID::toAstString() const {

    if (constIdSymbol== nullptr){
        return "找不到引用的类型："+constIDString;
    }

    return constIdSymbol->toShortAstString();
}

const std::string &ConstID::getConstID() const {
    return constIDString;
}

std::shared_ptr<Symbol> ConstID::getConstIDSymbol() const {
    return constIdSymbol;
}


