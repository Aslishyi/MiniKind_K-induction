//
// Created by jack on 12/22/23.
//

#include "VariableSymbol.h"
#include "ConstSymbol.h"

#include <utility>

std::string VariableSymbol::toAstString() const {
    switch (type) {
        case Symbol::PARAMETER:
            return "params(" + getVarDeclString() + ")";
        case Symbol::VARIABLE:
            return getVarDeclString();
        default:
            return Symbol::getTypeString(type);

    }
}

VariableSymbol::VariableSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                               std::shared_ptr<Scope> scope)
        : Symbol(name, type, std::move(token), scope) {

}


std::string VariableSymbol::getVarDeclString() const {
    return "var_decls(vars(" + name + ")," + +"," + toTypeAstString() + "," + "clock(" + toClockAstString() + ")," +
           "last(" + toLastAstString() + ")" + ")";
}

VariableSymbol::VariableSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                               std::shared_ptr<Scope> scope, std::shared_ptr<TypeDefSymbol> typeDefSymbol,
                               std::pair<bool, std::string> clockID, std::shared_ptr<ConstSymbol> lastSymbol)
        : Symbol(name, type, std::move(token), scope), typeDefSymbol(std::move(typeDefSymbol)),
          clockID(std::move(clockID)), lastSymbol(std::move(lastSymbol)) {

}

std::shared_ptr<TypeDefSymbol> VariableSymbol::getTypeDefSymbol() const {
    return typeDefSymbol;
}

const std::pair<bool, std::string> &VariableSymbol::getClockID() const {
    return clockID;
}

std::shared_ptr<ConstSymbol> VariableSymbol::getLastSymbol() const {
    return lastSymbol;
}

std::string VariableSymbol::toTypeAstString() const {
    return typeDefSymbol->getDefTypeString(typeDefSymbol->getDefType());
}

std::string VariableSymbol::toLastAstString() const {
    if (!lastSymbol) {
        return "";
    }
    return lastSymbol->getDefTypeString(lastSymbol->getDefType());
}

std::string VariableSymbol::toClockAstString() const {
    if (!clockID.first && clockID.second.empty()) {
        return "";
    }
    std::stringstream ss{};
    ss << (clockID.first ? "" : "not ");
    ss << clockID.second;
    return ss.str();
}
