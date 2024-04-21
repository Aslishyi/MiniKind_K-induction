//
// Created by jack on 1/15/24.
//

#ifndef QL2C_EQUATIONEXPRVISITOR_H
#define QL2C_EQUATIONEXPRVISITOR_H


#include "../generated/LustreBaseVisitor.h"
#include "../../SymbolTable/Scope/Scope.h"

class MyLustreVisitor;
class EquationExprVisitor : public LustreBaseVisitor {

public:
    EquationExprVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope

    );

    std::any visitEquation_expr(LustreParser::Equation_exprContext *ctx) override;

    /**
     * mix字段实现,只需要实现数组的mix字段，结构体的mix，kind2支持
     */
    std::string mixOperator(LustreParser::Equation_exprContext *ctx, const std::string &id);

    /**
    * 在默认的左侧生成的基础上加入last字段实现：
    * 如果前面定义这个变量是有last操作符，则需要使用->操作符 ;
    * L2C:   var   Local1 : float last = i2;
    *        let      Local1 = _L4;      tel
    *
    * kind2: Local1 =  i2 ->_L4;
    */
    std::string lastOperator(LustreParser::Equation_exprContext *ctx, const std::string &id);

private:
    std::shared_ptr<Scope> currentScope;
    MyLustreVisitor &myLustreVisitor;
    std::any visitExpr_simple_expr(LustreParser::Expr_simple_exprContext *ctx) override;
    std::any visitExpr_last_decl(LustreParser::Expr_last_declContext *ctx) override;
    std::any visitExpr_tempo_expr(LustreParser::Expr_tempo_exprContext *ctx) override;
    std::any visitExpr_bool_expr(LustreParser::Expr_bool_exprContext *ctx) override;
    std::any visitExpr_array_expr(LustreParser::Expr_array_exprContext *ctx) override;
    std::any visitExpr_struct_expr(LustreParser::Expr_struct_exprContext *ctx) override;
    std::any visitExpr_mixed_constructor(LustreParser::Expr_mixed_constructorContext *ctx) override;
    std::any visitExpr_switch_expr(LustreParser::Expr_switch_exprContext *ctx) override;
    std::any visitExpr_paren(LustreParser::Expr_parenContext *ctx) override;
    std::any visitExpr_apply_expr(LustreParser::Expr_apply_exprContext *ctx) override;
    std::any visitExpr_kind2_expr(LustreParser::Expr_kind2_exprContext *ctx) override;

    std::any visitSimple_expr_id(LustreParser::Simple_expr_idContext *ctx) override;
    std::any visitSimple_expr_atom(LustreParser::Simple_expr_atomContext *ctx) override;
    std::any visitSimple_expr_paren(LustreParser::Simple_expr_parenContext *ctx) override;
    std::any visitSimple_expr_array(LustreParser::Simple_expr_arrayContext *ctx) override;
    std::any visitSimple_expr_struct(LustreParser::Simple_expr_structContext *ctx) override;
    std::any visitSimple_expr_unary_arith(LustreParser::Simple_expr_unary_arithContext *ctx) override;
    std::any visitSimple_expr_bin_arith(LustreParser::Simple_expr_bin_arithContext *ctx) override;
    std::any visitSimple_expr_bin_bool(LustreParser::Simple_expr_bin_boolContext *ctx) override;
    std::any visitSimple_expr_bin_relation(LustreParser::Simple_expr_bin_relationContext *ctx) override;
    std::any visitSimple_expr_type(LustreParser::Simple_expr_typeContext *ctx) override;
};


#endif //QL2C_EQUATIONEXPRVISITOR_H
