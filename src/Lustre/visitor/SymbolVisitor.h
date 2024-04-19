//
// Created by jack on 11/22/23.
//

#ifndef LUSTRETOL2C_SYMBOLVISITOR_H
#define LUSTRETOL2C_SYMBOLVISITOR_H


#include "../generated/LustreBaseVisitor.h"
#include "../../SymbolTable/Scope/Scope.h"
#include "../../SymbolTable/Scope/GlobalScope.h"
#include "../../SymbolTable/Symbol/TypeDefSymbol.h"
#include "../../SymbolTable/Symbol/VariableSymbol.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"
#include "../../SymbolTable/Symbol/EnumSymbol.h"


class SymbolVisitor : public LustreBaseVisitor {

public:
    std::shared_ptr<antlr4::tree::ParseTreeProperty<std::shared_ptr<Scope>>> scopes;
    //全局
    std::shared_ptr<GlobalScope> globals;
    std::shared_ptr<Scope> currentScope;

    SymbolVisitor();


    std::any visitProgram(LustreParser::ProgramContext *ctx) override;

    void saveScope(antlr4::ParserRuleContext *ctx, std::shared_ptr<Scope> s);


    std::any visitType_decl(LustreParser::Type_declContext *ctx) override;

    std::any visitType_def_type(LustreParser::Type_def_typeContext *ctx) override;

    std::any visitType_float(LustreParser::Type_floatContext *ctx) override;

    std::any visitType_int(LustreParser::Type_intContext *ctx) override;

    std::any visitType_bool(LustreParser::Type_boolContext *ctx) override;

    std::any visitType_real(LustreParser::Type_realContext *ctx) override;

    std::any visitType_char(LustreParser::Type_charContext *ctx) override;

    std::any visitType_short(LustreParser::Type_shortContext *ctx) override;

    std::any visitType_ushort(LustreParser::Type_ushortContext *ctx) override;

    std::any visitType_uint(LustreParser::Type_uintContext *ctx) override;

    std::any visitType_array(LustreParser::Type_arrayContext *ctx) override;

    std::any visitType_id(LustreParser::Type_idContext *ctx) override;

    std::any visitConst_bin_arith(LustreParser::Const_bin_arithContext *ctx) override;

    std::any visitAtom_REAL(LustreParser::Atom_REALContext *ctx) override;

    std::any visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) override;

    std::any visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) override;

    std::any visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) override;

    std::any visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) override;

    std::any visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) override;

    std::any visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) override;

    std::any visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) override;

    std::any visitConst_decl(LustreParser::Const_declContext *ctx) override;

    std::any visitConst_unary_arith(LustreParser::Const_unary_arithContext *ctx) override;

    std::any visitConst_paren(LustreParser::Const_parenContext *ctx) override;

    std::any visitUser_op_decl(LustreParser::User_op_declContext *ctx) override;

    std::any visitParams(LustreParser::ParamsContext *ctx) override;

    std::any visitVar_decls(LustreParser::Var_declsContext *ctx) override;

    std::any visitLocal_block(LustreParser::Local_blockContext *ctx) override;

    std::any visitType_struct(LustreParser::Type_structContext *ctx) override;

    std::any visitWhen_decl(LustreParser::When_declContext *ctx) override;

    std::any visitClock_id(LustreParser::Clock_idContext *ctx) override;

    std::any visitClock_not(LustreParser::Clock_notContext *ctx) override;
    std::any visitField_decl(LustreParser::Field_declContext *ctx) override;
    std::any visitConst_bin_bool(LustreParser::Const_bin_boolContext *ctx) override;
    std::any visitConst_bin_relation(LustreParser::Const_bin_relationContext *ctx) override;
    std::any visitConst_atom(LustreParser::Const_atomContext *ctx) override;
    std::any visitConst_array(LustreParser::Const_arrayContext *ctx) override;
    std::any visitConst_list(LustreParser::Const_listContext *ctx) override;
    std::any visitConst_struct(LustreParser::Const_structContext *ctx) override;
    std::any visitConst_label_expr(LustreParser::Const_label_exprContext *ctx) override;
    std::any visitConst_id(LustreParser::Const_idContext *ctx) override;
    std::any visitType_def_enum(LustreParser::Type_def_enumContext *ctx) override;


    void defineType( std::shared_ptr<TypeDefSymbol> typeDefSymbol);

    void defineVar(const std::shared_ptr<VariableSymbol>& variableSymbol);

    void defineParam(const std::shared_ptr<VariableSymbol> &variableSymbol);

    void defineConst(std::shared_ptr<ConstSymbol> constSymbol);

    void defineEnum(std::shared_ptr<EnumSymbol> enumSymbol);
};


#endif //LUSTRETOL2C_SYMBOLVISITOR_H
