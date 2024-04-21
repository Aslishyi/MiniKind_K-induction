//
// Created by jack on 3/22/24.
//

#ifndef QKIND_GETSIMPLEEXPRTYPE_H
#define QKIND_GETSIMPLEEXPRTYPE_H


#include "../generated/LustreBaseVisitor.h"
#include "../../SymbolTable/Scope/Scope.h"
#include "../visitor/MyLustreVisitor.h"

/**
 * 用来获取simple_expr的类型
 * 返回值：int，int16，uint16，bool ……
 */
class GetSimpleExprType : public LustreBaseVisitor {

public:
    explicit GetSimpleExprType(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope);

    std::any visitSimple_expr_id(LustreParser::Simple_expr_idContext *ctx) override;

    std::any visitSimple_expr_atom(LustreParser::Simple_expr_atomContext *ctx) override;

    std::any visitSimple_expr_array(LustreParser::Simple_expr_arrayContext *ctx) override;

    std::any visitSimple_expr_struct(LustreParser::Simple_expr_structContext *ctx) override;

    std::any visitSimple_expr_unary_arith(LustreParser::Simple_expr_unary_arithContext *ctx) override;

    std::any visitSimple_expr_bin_arith(LustreParser::Simple_expr_bin_arithContext *ctx) override;

    std::any visitSimple_expr_bin_bool(LustreParser::Simple_expr_bin_boolContext *ctx) override;

    std::any visitSimple_expr_bin_relation(LustreParser::Simple_expr_bin_relationContext *ctx) override;

    std::any visitSimple_expr_type(LustreParser::Simple_expr_typeContext *ctx) override;

    std::any visitSimple_expr_paren(LustreParser::Simple_expr_parenContext *ctx) override;

    std::any visitSimple_kind2_expr(LustreParser::Simple_kind2_exprContext *ctx) override;

    std::any visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) override;

    std::any visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) override;

    std::any visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) override;

    std::any visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) override;

    std::any visitAtom_REAL(LustreParser::Atom_REALContext *ctx) override;

    std::any visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) override;

    std::any visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) override;

    std::any visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) override;

private:
    std::shared_ptr<Scope> currentScope;
    MyLustreVisitor &myLustreVisitor;

};


#endif //QKIND_GETSIMPLEEXPRTYPE_H
