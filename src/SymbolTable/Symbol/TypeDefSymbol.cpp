//
// Created by jack on 11/22/23.
//

#include "TypeDefSymbol.h"
#include "TypeStruct.h"

#include <utility>


TypeDefSymbol::TypeDefSymbol() = default;

TypeDefSymbol::TypeDefSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,std::shared_ptr<Scope> scope,
                             Type defType, std::shared_ptr<TypeArray> arraySymbol
) : Symbol(name, type, token,scope), arraySymbol(arraySymbol), defType(defType) {

}

TypeDefSymbol::TypeDefSymbol(const std::string &name, Symbol::Type type,
                             std::shared_ptr<antlr4::Token> token,std::shared_ptr<Scope> scope) : Symbol(name, type, token,scope) {

}

TypeDefSymbol::TypeDefSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,std::shared_ptr<Scope> scope,
                             Type defType,
                             const TypeDefSymbol::varType variableType)
        : Symbol(name, type, token,scope), variableType(variableType), defType(defType) {

}



std::string TypeDefSymbol::toAstString() const {
    return std::string("type(" + toShortAstString() + ")");
}


TypeDefSymbol::~TypeDefSymbol() {

}

std::string TypeDefSymbol::getDefTypeString(Type defType) const {
    switch (defType) {
        case ARRAY:
            return "array(" + arraySymbol->toAstString() + ")";
        case BASETYPE:
            return getVarTypeString(variableType);
        case REFERENCE:
            return "ref(" + typeID->toAstString() + ")";
        case STRUCT:
            return "construct(" + structSymbol->toAstString() + ")";
        default:
            return Symbol::getTypeString(type);
    }
}

TypeDefSymbol::TypeDefSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,std::shared_ptr<Scope> scope,
                             Symbol::Type defType, std::shared_ptr<TypeStruct> structSymbol) :
        Symbol(name, type, token,scope), structSymbol(structSymbol), defType(defType) {

}

std::string TypeDefSymbol::toShortAstString() const {

    return std::string(name + "," + getDefTypeString(defType));
}

TypeDefSymbol::TypeDefSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,std::shared_ptr<Scope> scope,
                             Symbol::Type defType, std::shared_ptr<TypeId> typeId)
        : Symbol(name, type, token,scope), defType(defType), typeID(std::move(typeId)) {

}

const Symbol::Type &TypeDefSymbol::getDefType() const {
    return defType;
}

const Symbol::varType &TypeDefSymbol::getVariableType() const {
    return variableType;
}

std::shared_ptr<TypeArray> TypeDefSymbol::getArraySymbol() const {
    return arraySymbol;
}

std::shared_ptr<TypeStruct> TypeDefSymbol::getStructSymbol() const {
    return structSymbol;
}

std::shared_ptr<TypeId> TypeDefSymbol::getTypeID() const {
    return typeID;
}

TypeDefSymbol &TypeDefSymbol::setDefType(const Symbol::Type &defType) {
    this->defType=defType;
    return *this;
}

TypeDefSymbol &TypeDefSymbol::setVariableType(const Symbol::varType &variableType) {
    this-> variableType=variableType;
    return *this;
}


