//
// Created by jack on 3/22/24.
//

#include "GetTypesType.h"
#include "../../SymbolTable/Symbol/VariableSymbol.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"
#include "../../SymbolTable/Symbol/EnumSymbol.h"
#include "../tool/SpdlogTool.h"
#include "GetTypesType.h"
#include "../constBlock/ConstValueVisitor.h"
#include "../tool/LustreVisitorTool.h"

GetTypesType::GetTypesType(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope)
        : myLustreVisitor(myLustreVisitor), currentScope(currentScope) {

}

std::any GetTypesType::visitType_int(LustreParser::Type_intContext *ctx) {
    return std::string("int");
}

std::any GetTypesType::visitType_bool(LustreParser::Type_boolContext *ctx) {
    return std::string("bool");
}

std::any GetTypesType::visitType_char(LustreParser::Type_charContext *ctx) {
    return std::string("int");
}

std::any GetTypesType::visitType_short(LustreParser::Type_shortContext *ctx) {
    return std::string("int16");
}

std::any GetTypesType::visitType_ushort(LustreParser::Type_ushortContext *ctx) {
    return std::string("uint16");
}

std::any GetTypesType::visitType_uint(LustreParser::Type_uintContext *ctx) {
    return std::string("uint32");
}

std::any GetTypesType::visitType_float(LustreParser::Type_floatContext *ctx) {
    return std::string("real");
}

std::any GetTypesType::visitType_real(LustreParser::Type_realContext *ctx) {
    return std::string("real");
}

std::any GetTypesType::visitType_id(LustreParser::Type_idContext *ctx) {
    return LustreVisitorTool::getIDType(currentScope, ctx->ID()->getText());
}

std::any GetTypesType::visitType_struct(LustreParser::Type_structContext *ctx) {
    //TODO:结构体类型
    return std::string("");
}

std::any GetTypesType::visitType_array(LustreParser::Type_arrayContext *ctx) {
    auto constValueVisitor = std::make_shared<ConstValueVisitor>(myLustreVisitor, currentScope);
    auto constValue = constValueVisitor->visit(ctx->const_expr());
    int constExpr = LustreVisitorTool::anyConverter<int>(constValue);
    return std::string(std::any_cast<std::string>(ctx->type()) + " ^ " + std::to_string(constExpr));
}
