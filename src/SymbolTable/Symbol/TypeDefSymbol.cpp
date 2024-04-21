//
// Created by jack on 11/22/23.
//

#include "TypeDefSymbol.h"
#include "TypeStruct.h"

#include <utility>


TypeDefSymbol::TypeDefSymbol() = default;

TypeDefSymbol::TypeDefSymbol(const std::string &name, std::shared_ptr<antlr4::Token> token,
                             std::shared_ptr<Scope> scope,
                             Type defType, std::shared_ptr<TypeArray> arraySymbol
) : Symbol(name, type, token, scope), arraySymbol(arraySymbol), defType(defType) {

}

TypeDefSymbol::TypeDefSymbol(const std::string &name,
                             std::shared_ptr<antlr4::Token> token, std::shared_ptr<Scope> scope) : Symbol(name,
                                                                                                          Symbol::TYPEDEF,
                                                                                                          token,
                                                                                                          scope) {

}

TypeDefSymbol::TypeDefSymbol(const std::string &name, std::shared_ptr<antlr4::Token> token,
                             std::shared_ptr<Scope> scope,
                             Type defType,
                             const TypeDefSymbol::varType variableType)
        : Symbol(name, Symbol::TYPEDEF, token, scope), variableType(variableType), defType(defType) {

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
            return "struct(" + structSymbol->toAstString() + ")";
        default:
            return Symbol::getTypeString(type);
    }
}

const std::vector<std::string> TypeDefSymbol::getArrayDimString() const {
    std::vector<std::string> dimStrings;

    if (!arraySymbol) {
        return dimStrings;
    }
    //递归找数组的下一个维度
    dimStrings = arraySymbol->getArrayDim();
    return dimStrings;
}

TypeDefSymbol::TypeDefSymbol(const std::string &name, std::shared_ptr<antlr4::Token> token,
                             std::shared_ptr<Scope> scope,
                             Symbol::Type defType, std::shared_ptr<TypeStruct> structSymbol) :
        Symbol(name, Symbol::TYPEDEF, token, scope), structSymbol(structSymbol), defType(defType) {

}

std::string TypeDefSymbol::toShortAstString() const {

    return std::string(name + "," + getDefTypeString(defType));
}

std::string TypeDefSymbol::toShortLusString() const {

    return std::string(name + " : " + getDefTypeLusString(defType));
}

TypeDefSymbol::TypeDefSymbol(const std::string &name, std::shared_ptr<antlr4::Token> token,
                             std::shared_ptr<Scope> scope,
                             Symbol::Type defType, std::shared_ptr<TypeId> typeId)
        : Symbol(name, Symbol::TYPEDEF, token, scope), defType(defType), typeID(std::move(typeId)) {

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
    this->defType = defType;
    return *this;
}

TypeDefSymbol &TypeDefSymbol::setVariableType(const Symbol::varType &variableType) {
    this->variableType = variableType;
    return *this;
}

TypeDefSymbol &TypeDefSymbol::setStructSymbol(std::shared_ptr<TypeStruct> structSymbol) {
    this->structSymbol = structSymbol;
    return *this;
}

TypeDefSymbol &TypeDefSymbol::setTypeID(std::shared_ptr<TypeId> typeID) {
    this->typeID = typeID;
    return *this;
}

TypeDefSymbol &TypeDefSymbol::setArraySymbol(std::shared_ptr<TypeArray> arraySymbol) {
    this->arraySymbol = arraySymbol;
    return *this;
}

bool TypeDefSymbol::isEqual(std::shared_ptr<TypeDefSymbol> typeDefSymbol) {


    // 根据不同的Type类型进行进一步的比较
    switch (defType) {
        case Type::BASETYPE:
            return variableType == typeDefSymbol->variableType;
        case Type::ARRAY:
            return (arraySymbol && typeDefSymbol->getArraySymbol()) && arraySymbol->isEqual(typeDefSymbol->arraySymbol);
        case Type::STRUCT:
            return (structSymbol && typeDefSymbol->getStructSymbol()) &&
                   structSymbol->isEqual(typeDefSymbol->getStructSymbol());
        case Type::REFERENCE:
            return (typeID && typeDefSymbol->getTypeID()) && typeID->isEqual(typeDefSymbol->typeID);
        default:
            return false;
    }
}

std::string TypeDefSymbol::toLusString() const {

    return std::string("type " + name + " = " + getDefTypeLusString(defType));
}

std::string TypeDefSymbol::getDefTypeLusString(Symbol::Type defType) const {
    switch (defType) {
        case ARRAY:
            return arraySymbol->toLusString();
        case BASETYPE:
            return getVarTypeString(variableType);
        case REFERENCE:
            return typeID->getTypeID();
        case STRUCT:
            return " { " + structSymbol->toLusString() + " } ";
        default:
            return Symbol::getTypeString(type);
    }
}

std::shared_ptr<TypeDefSymbol> TypeDefSymbol::getNextNestedSymbol() const {
    switch (defType) {
        case ARRAY:
            return arraySymbol->getTypeDefSymbol();
        case REFERENCE:
            return std::dynamic_pointer_cast<TypeDefSymbol>(typeID->getTypeIDSymbol());
            //TODO:
        case STRUCT:
//            return structSymbol->getFieldSymbolByName();
        default:
            return nullptr;
    }
}


