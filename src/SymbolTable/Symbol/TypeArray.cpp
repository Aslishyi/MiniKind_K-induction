//
// Created by jack on 12/21/23.
//

#include "TypeArray.h"

#include <utility>
#include "TypeDefSymbol.h"
#include "ConstSymbol.h"


std::string TypeArray::toAstString() const {
    return   arrayType->getDefTypeString(arrayType->getDefType()) + "," + toDimString();
}

std::string TypeArray::toDimString() const {
    return constSymbol->getDefTypeString(constSymbol->getDefType());
}

TypeArray::TypeArray(std::shared_ptr<TypeDefSymbol> arrayType, std::shared_ptr<ConstSymbol> constSymbol):arrayType(std::move(arrayType)),constSymbol(std::move(constSymbol)) {

}

