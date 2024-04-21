//
// Created by jack on 2/28/24.
//

#include "ConstValueVisitor.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"
#include "../tool/LustreVisitorTool.h"

ConstValueVisitor::ConstValueVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope)
        : myLustreVisitor(myLustreVisitor), currentScope(currentScope) {

}

std::any ConstValueVisitor::visitConst_id(LustreParser::Const_idContext *ctx) {

    auto IDString = ctx->ID()->getText();
    auto IDSymbol = currentScope->resolve(IDString);
    std::shared_ptr<ConstSymbol> refConstSymbol = std::dynamic_pointer_cast<ConstSymbol>(IDSymbol);

    //如果是const类型
    if (refConstSymbol) {
            return refConstSymbol->getConstValue();
    }
    return int(0);
}

std::any ConstValueVisitor::visitConst_atom(LustreParser::Const_atomContext *ctx) {
    return LustreBaseVisitor::visitConst_atom(ctx);
}

std::any ConstValueVisitor::visitConst_unary_arith(LustreParser::Const_unary_arithContext *ctx) {

    std::string op = ctx->unary_arith_op()->getText();

    auto constExprValue = LustreVisitorTool::classifyPropertyType(visit(ctx->const_expr()), op);
    return constExprValue;
}

std::any ConstValueVisitor::visitConst_paren(LustreParser::Const_parenContext *ctx) {
    return LustreBaseVisitor::visit(ctx->const_expr());
}

std::any ConstValueVisitor::visitConst_bin_arith(LustreParser::Const_bin_arithContext *ctx) {
    //获取左侧的Symbol
    auto left = visit(ctx->const_expr(0));

    //获取右侧的Symbol
    auto right = visit(ctx->const_expr(1));
    std::string op = ctx->bin_arith_op()->getText();

    return LustreVisitorTool::classifyPropertyType(left, right, op, false);
}

std::any ConstValueVisitor::visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) {
    int result = std::stoi(ctx->INTEGER()->getText());
    return std::any(result);
}

std::any ConstValueVisitor::visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) {
    float result = std::stof(ctx->FLOAT()->getText());
    return std::any{result};
}


std::any ConstValueVisitor::visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) {
    unsigned short result = std::stoul(ctx->USHORT()->getText());
    return std::any{result};
}

std::any ConstValueVisitor::visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) {
    short result = static_cast<short>(std::stoi(ctx->SHORT()->getText()));
    return std::any{result};
}

std::any ConstValueVisitor::visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) {
    unsigned int result = std::stoul(ctx->UINT()->getText());
    return std::any{result};
}


std::any ConstValueVisitor::visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) {
    char result = ctx->CHAR()->getText()[0];
    return std::any{result};
}

std::any ConstValueVisitor::visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) {

    bool result = ctx->BOOL()->getText() == "true";
    return std::any{result};
}

std::any ConstValueVisitor::visitAtom_REAL(LustreParser::Atom_REALContext *ctx) {
    double result = std::stod(ctx->REAL()->getText());
    return std::any{result};

}