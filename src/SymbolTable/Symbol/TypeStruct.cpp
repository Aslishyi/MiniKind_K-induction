//
// Created by jack on 12/22/23.
//

#include "TypeStruct.h"

#include <utility>
#include "TypeDefSymbol.h"

TypeStruct::TypeStruct() {

}

TypeStruct::TypeStruct(std::vector<std::shared_ptr<TypeDefSymbol>> structVector) : structVector(std::move(
        structVector)) {

}

std::string TypeStruct::toAstString() const {
    std::stringstream ss;
    auto it = structVector.begin();
    auto end = structVector.end();
    while (it != end) {
        ss << "field(" << (*it)->toShortAstString() << ")";

        // 如果不是最后一个元素，则添加逗号
        if (std::next(it) != end)
            ss << ",";

        ++it;
    }
    return ss.str();
}

const std::vector<std::shared_ptr<TypeDefSymbol>> &TypeStruct::getStructSet() const {
    return structVector;
}

bool TypeStruct::isEqual(std::shared_ptr<TypeStruct> typeStruct) {

    if (structVector.size() != typeStruct->getStructSet().size()) {
        return false;
    }

    // 比较两个结构体类型中的每个成员
    for (int i = 0; i < structVector.size(); ++i) {
        auto test = typeStruct->getStructSet()[i];
        auto test2 = structVector[i];
        if (structVector[i]->getName() != typeStruct->getStructSet()[i]->getName()) {
            return false;
        }
        if (!(structVector[i]->isEqual(typeStruct->getStructSet()[i]))) {
            return false;
        }
    }
    return true;
}

std::string TypeStruct::toLusString() const {
    std::stringstream ss;
    auto it = structVector.begin();
    auto end = structVector.end();
    while (it != end) {
        ss << (*it)->toShortLusString();

        // 如果不是最后一个元素，则添加逗号
        if (std::next(it) != end)
            ss << " ; ";

        ++it;
    }
    return ss.str();
}

std::shared_ptr<TypeDefSymbol> TypeStruct::getFieldSymbolByName(const std::string& fieldName) {
    if (structVector.empty()){
        return nullptr;
    }
    auto it = structVector.begin();
    auto end = structVector.end();
    while (it != end) {
        if (it->get()->getName() == fieldName) {
            return *it;
        }
        ++it;
    }
    return nullptr;
}
