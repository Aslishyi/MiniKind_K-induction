//
// Created by jack on 12/21/23.
//

#include "TypeArray.h"

#include <utility>
#include "TypeDefSymbol.h"
#include "ConstSymbol.h"
#include "../../lustre/tool/LustreVisitorTool.h"


std::string TypeArray::toAstString() const {
    return   arrayType->getDefTypeString(arrayType->getDefType()) + "," + toDimString();
}

std::string TypeArray::toDimString() const {
    return constSymbol->getDefTypeLusString(constSymbol->getDefType());
}

TypeArray::TypeArray(std::shared_ptr<TypeDefSymbol> arrayType, std::shared_ptr<ConstSymbol> constSymbol):arrayType(std::move(arrayType)),constSymbol(std::move(constSymbol)) {

}

std::shared_ptr<ConstSymbol> TypeArray::getConstSymbol() const {
    return constSymbol;
}

const std::vector<std::string> TypeArray::getArrayDim() const {
    //递归找当前数组下一个维度
    std::vector<std::string> dimStrings = arrayType->getArrayDimString();
    dimStrings.push_back( constSymbol->getConstValueString());
    return dimStrings;
}

bool TypeArray::isEqual(std::shared_ptr<TypeArray> typeArray) {
    //TODO:值需要判断相同
    return arrayType->isEqual(typeArray->arrayType) ;
}

std::string TypeArray::toLusString() const {

    return   arrayType->getDefTypeLusString(arrayType->getDefType()) + "^" + toDimString();
}

std::shared_ptr<TypeDefSymbol> TypeArray::getTypeDefSymbol() const {
    return arrayType;
}

