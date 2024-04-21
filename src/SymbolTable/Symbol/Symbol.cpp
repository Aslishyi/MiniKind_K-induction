#include <iostream>
#include <utility>
#include "Symbol.h"

using std::stringstream;

Symbol::~Symbol() = default;

Symbol::Symbol(std::string name, Type type,
               std::shared_ptr<antlr4::Token> token, const std::shared_ptr<Scope> &scope) : name(std::move(name)),
                                                                                            type(type),
                                                                                            token(std::move(token)),
                                                                                            scope(scope) {
}

std::shared_ptr<antlr4::Token> Symbol::getToken() const {
    return token;
}


std::string Symbol::getTypeString() const {
    return getTypeString(type);
}

std::string Symbol::toAstString() const {
    return getTypeString();
}


std::string Symbol::toLusString() const {
    return getTypeString();
}

Symbol::Symbol() = default;


std::string Symbol::getTypeString(Type type1) const {
    switch (type1) {

        case FUNCTION:
            return "function:" + name;
        case AUTOMATON:
            return "Automaton:" + name;
        case STATE:
            return "State:" + name;
        default:
            return "unknown:" + name;

    }
}

std::string Symbol::getVarTypeString(varType varType) {
    switch (varType) {
        case INTEGER:
            return "int";
        case UINT:
            return "uint32";
        case REAL:
            return "real";
        case FLOAT:
            return "real";
        case SHORT:
            return "int16";
        case USHORT:
            return "uint16";
        case CHAR:
            return "char";
        case BOOL:
            return "bool";
        default:
            return "unknown";

    }
}


std::string Symbol::getTypeStringInCaps(varType valType) {
    std::string uppercaseString;

    for (char c: getVarTypeString(valType)) {
        uppercaseString += std::toupper(c);
    }
    return uppercaseString;
}

std::string Symbol::toShortAstString() const {

    return getTypeString();
}

Symbol &Symbol::setName(const std::string &name) {
    this->name = name;
    return *this;
}

Symbol &Symbol::setType(const Symbol::Type &type) {
    this->type = type;
    return *this;
}

Symbol &Symbol::setToken(std::shared_ptr<antlr4::Token> token) {
    this->token = std::move(token);
    return *this;

}

Symbol &Symbol::setScope(std::shared_ptr<Scope> scope) {
    this->scope = scope;
    return *this;
}

const std::string &Symbol::getName() const {
    return name;
}

const Symbol::Type &Symbol::getType() const {
    return type;
}

std::weak_ptr<Scope> Symbol::getScope() const {
    return scope;
}

bool Symbol::isEqual(std::shared_ptr<Symbol> symbol) {
    //TODO:
    return false;
}




