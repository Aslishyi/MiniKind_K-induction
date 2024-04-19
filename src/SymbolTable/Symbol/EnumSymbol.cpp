//
// Created by jack on 12/26/23.
//

#include "EnumSymbol.h"

#include <utility>


std::string EnumSymbol::toAstString() const {
    return "type(" + name + "," + toShortAstString() + ")";
}

std::string EnumSymbol::toShortAstString() const {
    std::stringstream ss;
    auto it = enumMap.begin();
    auto end = enumMap.end();
    ss << "(";
    while (it != end) {
        ss << (*it).first;

        // 如果不是最后一个元素，则添加逗号
        if (std::next(it) != end)
            ss << ",";

        ++it;
    }
    ss << ")";
    return ss.str();
}

EnumSymbol::~EnumSymbol() = default;

EnumSymbol::EnumSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                       std::shared_ptr<Scope> scope,
                       std::unordered_map<std::string, std::shared_ptr<antlr4::Token>> enumMap)
        : Symbol(name, type, std::move(token), std::move(scope)), enumMap(std::move(enumMap)) {

}

const std::unordered_map<std::string, std::shared_ptr<antlr4::Token>> &EnumSymbol::getEnumMap() const {
    return enumMap;
}
