//
// Created by jack on 12/26/23.
//

#include "TypeId.h"

#include <utility>

TypeId::TypeId(std::string typeIDString, std::shared_ptr<Symbol> typeIdSymbol) : typeIDString(std::move(typeIDString)),
                                                                                 typeIdSymbol(std::move(typeIdSymbol)) {

}

std::string TypeId::toAstString() const {
    if (typeIdSymbol == nullptr) {
        return "找不到引用的类型：" + typeIDString;
    }

    return typeIdSymbol->toShortAstString();
}

const std::string &TypeId::getTypeID() const {
    return typeIDString;
}

std::shared_ptr<Symbol> TypeId::getTypeIDSymbol() const {
    return typeIdSymbol;
}
