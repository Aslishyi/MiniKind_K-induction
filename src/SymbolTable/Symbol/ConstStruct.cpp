//
// Created by jack on 12/24/23.
//

#include "ConstStruct.h"

#include <utility>
#include "ConstSymbol.h"


std::string ConstStruct::toAstString() const {
    std::stringstream ss;
    auto it = structSet.begin();
    auto end = structSet.end();
    while (it != end) {
        ss << "field(" << (*it)->getName() << "," << (*it)->getDefTypeString((*it)->getDefType()) << ")";

        // 如果不是最后一个元素，则添加逗号
        if (std::next(it) != end)
            ss << ",";

        ++it;
    }
    return ss.str();
}

ConstStruct::ConstStruct(std::unordered_set<std::shared_ptr<ConstSymbol>> structVector) : structSet(
        std::move(structVector)) {

}

std::string ConstStruct::toLusString() const {
    std::stringstream ss;
    auto it = structSet.begin();
    auto end = structSet.end();
    while (it != end) {
        ss <<  (*it)->getName() << " = " << (*it)->getDefTypeLusString((*it)->getDefType());

        // 如果不是最后一个元素，则添加逗号
        if (std::next(it) != end)
            ss << " ; ";
        ++it;
    }
    return ss.str();
}
