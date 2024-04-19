//
// Created by jack on 12/22/23.
//

#include "TypeStruct.h"

#include <utility>
#include "TypeDefSymbol.h"

TypeStruct::TypeStruct() {

}

TypeStruct::TypeStruct(std::unordered_set<std::shared_ptr<TypeDefSymbol>> structVector) : structSet(std::move(
        structVector)) {

}

std::string TypeStruct::toAstString() const {
    std::stringstream ss;
    auto it = structSet.begin();
    auto end = structSet.end();
    while (it != end) {
        ss << "field(" << (*it)->toShortAstString() << ")";

        // 如果不是最后一个元素，则添加逗号
        if (std::next(it) != end)
            ss << ",";

        ++it;
    }
    return ss.str();
}

const std::unordered_set<std::shared_ptr<TypeDefSymbol>> &TypeStruct::getStructSet() const{
    return structSet;
}
