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
                         Symbol::varType constValueType, std::any constValue) : Symbol(
        name, type, token, scope), typeDefSymbol(typeDefSymbol), defType(defType), constValueType(constValueType),
                                                                                constValue(std::move(constValue)) {

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
                   "(" + LustreVisitorTool::properTypeToString(constValue) + ")";
        case REFERENCE:
            return "ref(" + constID->toAstString() + ")";
        case STRUCT:
            return constStruct->toAstString();
        default:
            return Symbol::getTypeString(type);
    }
}

std::string ConstSymbol::toShortAstString() const {


    return name + "," + (typeDefSymbol ? typeDefSymbol->getDefTypeString(typeDefSymbol->getDefType()) : "") +
           "," + getDefTypeString(defType);
}


ConstSymbol::ConstSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                         std::shared_ptr<Scope> scope,
                         std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType,
                         std::shared_ptr<ConstArray> constArray) : Symbol(
        name, type, token, scope), typeDefSymbol(typeDefSymbol), defType(defType), constArray(constArray) {

}

ConstSymbol::ConstSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                         std::shared_ptr<Scope> scope,
                         std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType,
                         std::shared_ptr<ConstStruct> constArray) : Symbol(
        name, type, token, scope), typeDefSymbol(typeDefSymbol), defType(defType), constStruct(constArray) {

}

ConstSymbol::ConstSymbol(const std::string &name, Symbol::Type type, std::shared_ptr<antlr4::Token> token,
                         std::shared_ptr<Scope> scope,
                         std::shared_ptr<TypeDefSymbol> typeDefSymbol, Symbol::Type defType,
                         std::shared_ptr<ConstID> constId) : Symbol(
        name, type, token, scope), typeDefSymbol(typeDefSymbol), defType(defType), constID(constId) {

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
    this-> typeDefSymbol=typeDefSymbol;
    return *this;
}



