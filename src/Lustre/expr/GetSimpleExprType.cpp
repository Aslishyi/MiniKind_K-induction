//
// Created by jack on 3/22/24.
//

#include "GetSimpleExprType.h"
#include "../../SymbolTable/Symbol/VariableSymbol.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"
#include "../../SymbolTable/Symbol/EnumSymbol.h"
#include "../tool/SpdlogTool.h"
#include "../tool/LustreVisitorTool.h"
#include "../typeBlock/GetTypesType.h"

GetSimpleExprType::GetSimpleExprType(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope)
        : myLustreVisitor(myLustreVisitor), currentScope(currentScope) {

}

std::any GetSimpleExprType::visitSimple_expr_id(LustreParser::Simple_expr_idContext *ctx) {
    return std::string(LustreVisitorTool::getIDType(currentScope, ctx->ID()->getText()));
}

std::any GetSimpleExprType::visitSimple_expr_atom(LustreParser::Simple_expr_atomContext *ctx) {
    return visit(ctx->atom());
}

std::any GetSimpleExprType::visitSimple_expr_array(LustreParser::Simple_expr_arrayContext *ctx) {
    /**
     * 删除最后一个^和它后面的字符，如int ^34^9823^2 ==>int ^34^9823
     */
    std::string result = std::any_cast<std::string>(ctx->simple_expr());
    size_t found = result.find_last_of('^');
    if (found != std::string::npos) {
        result = result.substr(0, found);
    }
    return result;
}

std::any GetSimpleExprType::visitSimple_expr_struct(LustreParser::Simple_expr_structContext *ctx) {
    auto refName = std::any_cast<std::string>(ctx->simple_expr());
    auto symbol = currentScope->resolve(refName);
    if (auto typeSymbol = std::dynamic_pointer_cast<TypeDefSymbol>(symbol)) {
        if (!typeSymbol->getStructSymbol()) {
            SpdlogTool::logErr->error(refName + "不是结构体类型");
            return std::string("");
        }
        //如果能找到这个结构体的子元素
        if (auto fieldSymbol = typeSymbol->getStructSymbol()->getFieldSymbolByName(ctx->ID()->getText())) {
            return fieldSymbol->getDefTypeLusString(fieldSymbol->getDefType());
        }
        SpdlogTool::logErr->error(refName + "中的" + ctx->ID()->getText() + "类型错误");
    }
    return std::string("");
}

std::any GetSimpleExprType::visitSimple_expr_unary_arith(LustreParser::Simple_expr_unary_arithContext *ctx) {

    return visit(ctx->simple_expr());
}

std::any GetSimpleExprType::visitSimple_expr_bin_arith(LustreParser::Simple_expr_bin_arithContext *ctx) {
    //TODO:当两个类型不同
    return visit(ctx->simple_expr()[0]);
}

std::any GetSimpleExprType::visitSimple_expr_bin_bool(LustreParser::Simple_expr_bin_boolContext *ctx) {

    return visit(ctx->simple_expr()[0]);
}

std::any GetSimpleExprType::visitSimple_expr_bin_relation(LustreParser::Simple_expr_bin_relationContext *ctx) {
    return std::string("bool");
}

std::any GetSimpleExprType::visitSimple_expr_type(LustreParser::Simple_expr_typeContext *ctx) {
    auto getTypesType = std::make_shared<GetTypesType>(myLustreVisitor, currentScope);
    return getTypesType->visit(ctx->type());
}

std::any GetSimpleExprType::visitSimple_expr_paren(LustreParser::Simple_expr_parenContext *ctx) {
    //TODO:不确定什么类型
    return visit(ctx->simple_expr()[0]);
}

std::any GetSimpleExprType::visitSimple_kind2_expr(LustreParser::Simple_kind2_exprContext *ctx) {
    return std::string("bool");
}

std::any GetSimpleExprType::visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) {
    return std::string("bool");

}

std::any GetSimpleExprType::visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) {
    return std::string("real");
}

std::any GetSimpleExprType::visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) {
    //此处char转为int
    return std::string("int");

}

std::any GetSimpleExprType::visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) {
    return std::string("int");
}

std::any GetSimpleExprType::visitAtom_REAL(LustreParser::Atom_REALContext *ctx) {
    return std::string("real");
}

std::any GetSimpleExprType::visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) {
    return std::string("int16");
}

std::any GetSimpleExprType::visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) {
    return std::string("uint32");
}

std::any GetSimpleExprType::visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) {
    return std::string("uint16");
}
