//
// Created by jack on 12/22/23.
//

#include "ConstSymbol.h"

#include "../../lustre/tool/LustreVisitorTool.h"

ConstSymbol::ConstSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                         std::shared_ptr<Scope> scope)
        : Symbol(name, type, token, scope) {

}

ConstSymbol::ConstSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                         std::shared_ptr<Scope> scope,
                         std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType,
                         Symbol::varType constValueType, std::any constValue,
                         bool isValueVerify, LustreParser::Const_declContext *constCtx) :
        Symbol(name, type, token, scope), typeDefSymbol(typeDefSymbol), defType(defType),
        constValueType(constValueType),
        constValue(std::move(constValue)), constCtx(constCtx), isValueVerify(isValueVerify) {

}

std::string ConstSymbol::toAstString() const {

    return "const(" + toShortAstString() + ")";


}


std::string ConstSymbol::getDefTypeString(Type defType) const {
    switch (defType) {
        case ARRAY:
            return constArray->toAstString();
        case BASETYPE:
            return getTypeStringInCaps(constValueType) +
                   "(" + getConstValueString() + ")";
        case REFERENCE:
            return "ref(" + constID->toAstString() + ")";
        case STRUCT:
            return "structValue(" + constStruct->toAstString() + ")";
        default:
            return Symbol::getTypeString(type);
    }
}

std::string ConstSymbol::toShortAstString() const {


    return name + "," + (typeDefSymbol ? typeDefSymbol->getDefTypeString(typeDefSymbol->getDefType()) : "") +
           "," + getDefTypeString(defType);
}

std::string ConstSymbol::toShortLusString() const {


    return name + " : " + (typeDefSymbol ? typeDefSymbol->getDefTypeLusString(typeDefSymbol->getDefType()) : "") +
           "=" + getDefTypeLusString(defType);
}


ConstSymbol::ConstSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                         std::shared_ptr<Scope> scope,
                         std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType,
                         std::shared_ptr<ConstArray> constArray, bool isValueVerify,
                         LustreParser::Const_declContext *constCtx) : Symbol(
        name, type, token, scope), typeDefSymbol(typeDefSymbol), defType(defType), constArray(constArray),
                                                                      isValueVerify(isValueVerify), constCtx(constCtx) {

}

ConstSymbol::ConstSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                         std::shared_ptr<Scope> scope,
                         std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType,
                         std::shared_ptr<ConstStruct> constArray, bool isValueVerify,
                         LustreParser::Const_declContext *constCtx) : Symbol(
        name, type, token, scope), typeDefSymbol(typeDefSymbol), defType(defType), constStruct(constArray),
                                                                      isValueVerify(isValueVerify), constCtx(constCtx) {

}

ConstSymbol::ConstSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                         std::shared_ptr<Scope> scope,
                         std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType,
                         std::shared_ptr<ConstID> constId, bool isValueVerify,
                         LustreParser::Const_declContext *constCtx) : Symbol(
        name, type, token, scope), typeDefSymbol(typeDefSymbol), defType(defType), constID(constId),
                                                                      isValueVerify(isValueVerify), constCtx(constCtx) {

}

const Symbol::Type &ConstSymbol::getDefType() const {
    return defType;
}

std::shared_ptr<TypeDefSymbol> ConstSymbol::getConstType() const {
    return typeDefSymbol;
}

const Symbol::varType &ConstSymbol::getConstValueType() const {
    return constValueType;
}

const std::any &ConstSymbol::getConstValue() const {
    return constValue;
}

std::shared_ptr<ConstArray> ConstSymbol::getConstArray() const {
    return constArray;
}

std::shared_ptr<ConstStruct> ConstSymbol::getConstStruct() const {
    return constStruct;
}

std::shared_ptr<ConstID> ConstSymbol::getConstID() const {
    return constID;
}

ConstSymbol &ConstSymbol::setConstType(std::shared_ptr<TypeDefSymbol> typeDefSymbol) {
    this->typeDefSymbol = typeDefSymbol;
    return *this;
}

std::string ConstSymbol::getConstValueString() const {
    return LustreVisitorTool::properTypeToString(constValue);
}

std::shared_ptr<TypeDefSymbol> ConstSymbol::getDefTypeSymbol() const {
    return typeDefSymbol;
}

const bool &ConstSymbol::getIsValueVerify() const {
    return isValueVerify;
}

ConstSymbol &ConstSymbol::setIsValueVerify(bool isValueVerify) {
    this->isValueVerify = isValueVerify;
    return *this;
}

LustreParser::Const_declContext *const ConstSymbol::getConstCtx() const {
    return constCtx;
}

ConstSymbol &ConstSymbol::setConstCtx(LustreParser::Const_declContext *constCtx) {
    this->constCtx = constCtx;
    return *this;
}

ConstSymbol &ConstSymbol::setConstValue(std::any constValue) {
    this->constValue = constValue;
    return *this;
}

ConstSymbol &ConstSymbol::setConstValueType(varType constValueType) {
    this->constValueType = constValueType;
    return *this;
}

ConstSymbol &ConstSymbol::setDefType(Symbol::Type type) {
    this->defType = type;
    return *this;
}

std::string ConstSymbol::getDefTypeLusString(Symbol::Type defType) const {
    switch (defType) {
        case ARRAY:
            return " [ "+ constArray->toLusString() +" ] ";
        case BASETYPE:
            return getConstValueString();
        case REFERENCE:
            return  constID->getConstID() ;
        case STRUCT:
            return " { " + constStruct->toLusString() + " } ";
        default:
            return Symbol::getTypeString(type);
    }
}

std::string ConstSymbol::toLusString() const {
    return "const " + toShortLusString() ;

}





