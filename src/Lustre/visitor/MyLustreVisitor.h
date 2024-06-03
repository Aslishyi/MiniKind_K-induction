
#ifndef LUSTRETOL2C_MYLUSTREVISITOR_H
#define LUSTRETOL2C_MYLUSTREVISITOR_H

#include "../generated/LustreBaseVisitor.h"
#include "../../SymbolTable/Scope/Scope.h"
#include "../../SymbolTable/Scope/GlobalScope.h"
#include "../../SymbolTable/Symbol/TypeDefSymbol.h"

class MyLustreVisitor : public LustreBaseVisitor {

public:
//    MyLustreVisitor();

    MyLustreVisitor(std::shared_ptr<antlr4::tree::ParseTreeProperty<std::shared_ptr<Scope>>> scopes,
                    std::shared_ptr<GlobalScope> globals);

    MyLustreVisitor()=default;

    std::shared_ptr<antlr4::tree::ParseTreeProperty<std::shared_ptr<Scope>>> scopes;
    std::shared_ptr<GlobalScope> globals;
    std::shared_ptr<Scope> currentScope;

    std::any visitProgram(LustreParser::ProgramContext *ctx) override;
    std::any visitDecls_type(LustreParser::Decls_typeContext *ctx) override;
    std::any visitDecls_const(LustreParser::Decls_constContext *ctx) override;
    std::any visitDecls_import_op(LustreParser::Decls_import_opContext *ctx) override;
    std::any visitDecls_user_op(LustreParser::Decls_user_opContext *ctx) override;
    std::any visitDecls_contract_node(LustreParser::Decls_contract_nodeContext *ctx) override;


    std::any visitType_block(LustreParser::Type_blockContext *ctx) override;
    std::any visitType_decl(LustreParser::Type_declContext *ctx) override;
    std::any visitType_def_type(LustreParser::Type_def_typeContext *ctx) override;
    std::any visitType_def_enum(LustreParser::Type_def_enumContext *ctx) override;
    std::any visitType_int(LustreParser::Type_intContext *ctx) override;
    std::any visitType_bool(LustreParser::Type_boolContext *ctx) override;
    std::any visitType_char(LustreParser::Type_charContext *ctx) override;
    std::any visitType_short(LustreParser::Type_shortContext *ctx) override;
    std::any visitType_ushort(LustreParser::Type_ushortContext *ctx) override;
    std::any visitType_uint(LustreParser::Type_uintContext *ctx) override;
    std::any visitType_float(LustreParser::Type_floatContext *ctx) override;
    std::any visitType_real(LustreParser::Type_realContext *ctx) override;
    std::any visitType_id(LustreParser::Type_idContext *ctx) override;
    std::any visitType_struct(LustreParser::Type_structContext *ctx) override;
    std::any visitType_array(LustreParser::Type_arrayContext *ctx) override;
    std::any visitField_decl(LustreParser::Field_declContext *ctx) override;

    std::any visitConst_block(LustreParser::Const_blockContext *ctx) override;
    std::any visitConst_decl(LustreParser::Const_declContext *ctx) override;
    std::any visitConst_id(LustreParser::Const_idContext *ctx) override;
    std::any visitConst_atom(LustreParser::Const_atomContext *ctx) override;
    std::any visitConst_unary_arith(LustreParser::Const_unary_arithContext *ctx) override;
    std::any visitConst_paren(LustreParser::Const_parenContext *ctx) override;
    std::any visitConst_bin_arith(LustreParser::Const_bin_arithContext *ctx) override;
    std::any visitConst_bin_bool(LustreParser::Const_bin_boolContext *ctx) override;
    std::any visitConst_bin_relation(LustreParser::Const_bin_relationContext *ctx) override;
    std::any visitConst_array(LustreParser::Const_arrayContext *ctx) override;
    std::any visitConst_list(LustreParser::Const_listContext *ctx) override;
    std::any visitConst_struct(LustreParser::Const_structContext *ctx) override;
    std::any visitConst_label_expr(LustreParser::Const_label_exprContext *ctx) override;

    std::any visitVar_decls(LustreParser::Var_declsContext *ctx) override;

    std::any visitClock_id(LustreParser::Clock_idContext *ctx) override;
    std::any visitClock_not(LustreParser::Clock_notContext *ctx) override;

    std::any visitUser_op_decl(LustreParser::User_op_declContext *ctx) override;

    std::any visitOp_kind_funtion(LustreParser::Op_kind_funtionContext *ctx) override;
    std::any visitOp_kind_node(LustreParser::Op_kind_nodeContext *ctx) override;

    std::any visitParams(LustreParser::ParamsContext *ctx) override;

    std::any visitOp_body_null(LustreParser::Op_body_nullContext *ctx) override;
    std::any visitOp_body_ctx(LustreParser::Op_body_ctxContext *ctx) override;
    std::any visitLocal_block(LustreParser::Local_blockContext *ctx) override;
    std::any visitContract(LustreParser::ContractContext *ctx) override;

    std::any visitLet_block_equation(LustreParser::Let_block_equationContext *ctx) override;

    std::any visitLet_block_k2_property(LustreParser::Let_block_k2_propertyContext *ctx) override;
    std::any visitLet_block_k2_if_block(LustreParser::Let_block_k2_if_blockContext *ctx) override;
    std::any visitLet_block_k2_frame_block(LustreParser::Let_block_k2_frame_blockContext *ctx) override;
    std::any visitEquation_expr(LustreParser::Equation_exprContext *ctx) override;
    std::any visitEquation_state_machine(LustreParser::Equation_state_machineContext *ctx) override;

    std::any visitLhs_pair(LustreParser::Lhs_pairContext *ctx) override;
    std::any visitLhs_id_list(LustreParser::Lhs_id_listContext *ctx) override;

    std::any visitState_machine_data_def_equation(LustreParser::State_machine_data_def_equationContext *ctx) override;
    std::any visitState_machine_data_def_local_block(LustreParser::State_machine_data_def_local_blockContext *ctx) override;
    std::any visitState_machine_transition_resume(LustreParser::State_machine_transition_resumeContext *ctx) override;
    std::any visitState_machine_transition_restart(LustreParser::State_machine_transition_restartContext *ctx) override;

    std::any visitExpr_simple_expr(LustreParser::Expr_simple_exprContext *ctx) override;
    std::any visitExpr_last_decl(LustreParser::Expr_last_declContext *ctx) override;
    std::any visitExpr_tempo_expr(LustreParser::Expr_tempo_exprContext *ctx) override;
    std::any visitExpr_bool_expr(LustreParser::Expr_bool_exprContext *ctx) override;
    std::any visitBool_expr(LustreParser::Bool_exprContext *ctx) override;
    std::any visitExpr_array_expr(LustreParser::Expr_array_exprContext *ctx) override;
    std::any visitExpr_struct_expr(LustreParser::Expr_struct_exprContext *ctx) override;
//    std::any visitExpr_mixed_constructor(LustreParser::Expr_mixed_constructorContext *ctx) override;
    std::any visitExpr_switch_expr(LustreParser::Expr_switch_exprContext *ctx) override;
    std::any visitExpr_paren(LustreParser::Expr_parenContext *ctx) override;
    std::any visitExpr_apply_expr(LustreParser::Expr_apply_exprContext *ctx) override;
    std::any visitExpr_kind2_expr(LustreParser::Expr_kind2_exprContext *ctx) override;

    std::any visitList(LustreParser::ListContext *ctx) override;

    std::any visitStruct_expr(LustreParser::Struct_exprContext *ctx) override;

    std::any visitTempo_expr_pre(LustreParser::Tempo_expr_preContext *ctx) override;
    std::any visitTempo_expr_arrow(LustreParser::Tempo_expr_arrowContext *ctx) override;
    std::any visitTempo_expr_fby(LustreParser::Tempo_expr_fbyContext *ctx) override;
    std::any visitTempo_expr_fby_noconst(LustreParser::Tempo_expr_fby_noconstContext *ctx) override;
    std::any visitTempo_expr_arrow_tempo(LustreParser::Tempo_expr_arrow_tempoContext *ctx) override;
    std::any visitTempo_expr_when(LustreParser::Tempo_expr_whenContext *ctx) override;
    std::any visitTempo_expr_merge(LustreParser::Tempo_expr_mergeContext *ctx) override;
    std::any visitTempo_kind2_merge(LustreParser::Tempo_kind2_mergeContext *ctx) override;

    std::any visitArray_expr_split(LustreParser::Array_expr_splitContext *ctx) override;
    std::any visitArray_expr_dynamic(LustreParser::Array_expr_dynamicContext *ctx) override;
    std::any visitArray_expr_and(LustreParser::Array_expr_andContext *ctx) override;
    std::any visitArray_expr_list(LustreParser::Array_expr_listContext *ctx) override;

    std::any visitExpr_mixed_constructor(LustreParser::Expr_mixed_constructorContext *ctx) override;
    std::any visitMixed_constructor(LustreParser::Mixed_constructorContext *ctx) override;
    std::any visitMix_index(LustreParser::Mix_indexContext *ctx) override;
    std::any visitMix_label(LustreParser::Mix_labelContext *ctx) override;
//    std::any visitMix_label(LustreParser::Mix_labelContext *ctx) override;
//    std::any visitMix_index(LustreParser::Mix_indexContext *ctx) override;
//    std::any visitExpr_mixed_index_constructor(LustreParser::Expr_mixed_index_constructorContext *ctx) override;
//    std::any visitExpr_mixed_label_constructor(LustreParser::Expr_mixed_label_constructorContext *ctx) override;
//    std::any visitMixed_index_constructor(LustreParser::Mixed_index_constructorContext *ctx) override;

    std::any visitSwitch_expr_ifelse(LustreParser::Switch_expr_ifelseContext *ctx) override;
    std::any visitSwitch_expr_case(LustreParser::Switch_expr_caseContext *ctx) override;
    std::any visitCase_expr(LustreParser::Case_exprContext *ctx) override;
    std::any visitPattern(LustreParser::PatternContext *ctx) override;

    std::any visitApply_prefix(LustreParser::Apply_prefixContext *ctx) override;
//    std::any visitApply_iterator(LustreParser::Apply_iteratorContext *ctx) override;
//    std::any visitApply_boolred(LustreParser::Apply_boolredContext *ctx) override;
    std::any visitApply_map(LustreParser::Apply_mapContext *ctx) override;
    std::any visitApply_fold(LustreParser::Apply_foldContext *ctx) override;
    std::any visitApply_mapi(LustreParser::Apply_mapiContext *ctx) override;
    std::any visitApply_foldi(LustreParser::Apply_foldiContext *ctx) override;
    std::any visitApply_mapfold(LustreParser::Apply_mapfoldContext *ctx) override;
    std::any visitApply_mapw(LustreParser::Apply_mapwContext *ctx) override;
    std::any visitApply_mapwi(LustreParser::Apply_mapwiContext *ctx) override;
    std::any visitApply_foldw(LustreParser::Apply_foldwContext *ctx) override;
    std::any visitApply_foldwi(LustreParser::Apply_foldwiContext *ctx) override;

    std::any visitPerfix_ID(LustreParser::Perfix_IDContext *ctx) override;
    std::any visitPrefix_unary(LustreParser::Prefix_unaryContext *ctx) override;
    std::any visitPrefix_binary(LustreParser::Prefix_binaryContext *ctx) override;
    std::any visitPerfix_make(LustreParser::Perfix_makeContext *ctx) override;
    std::any visitPerfix_flatten(LustreParser::Perfix_flattenContext *ctx) override;

//    std::any visitIterator_map(LustreParser::Iterator_mapContext *ctx) override;
//    std::any visitIterator_fold(LustreParser::Iterator_foldContext *ctx) override;
//    std::any visitIterator_mapi(LustreParser::Iterator_mapiContext *ctx) override;
//    std::any visitIterator_foldi(LustreParser::Iterator_foldiContext *ctx) override;
//    std::any visitIterator_mapfold(LustreParser::Iterator_mapfoldContext *ctx) override;
//    std::any visitIterator_red(LustreParser::Iterator_redContext *ctx) override;
//    std::any visitIterator_fill(LustreParser::Iterator_fillContext *ctx) override;
//    std::any visitIterator_fillred(LustreParser::Iterator_fillredContext *ctx) override;

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
    std::any visitSimple_kind2_expr(LustreParser::Simple_kind2_exprContext *ctx) override;

    std::any visitLabel_expr(LustreParser::Label_exprContext *ctx) override;

    std::any visitUnary_arith_op_sub(LustreParser::Unary_arith_op_subContext *ctx) override;
    std::any visitUnary_arith_op_add(LustreParser::Unary_arith_op_addContext *ctx) override;
    std::any visitUnary_arith_op_not(LustreParser::Unary_arith_op_notContext *ctx) override;

    std::any visitBin_arith_op_add(LustreParser::Bin_arith_op_addContext *ctx) override;
    std::any visitBin_arith_op_sub(LustreParser::Bin_arith_op_subContext *ctx) override;
    std::any visitBin_arith_op_mul(LustreParser::Bin_arith_op_mulContext *ctx) override;
    std::any visitBin_arith_op_divided(LustreParser::Bin_arith_op_dividedContext *ctx) override;
    std::any visitBin_arith_op_mod(LustreParser::Bin_arith_op_modContext *ctx) override;
    std::any visitBin_arith_op_div(LustreParser::Bin_arith_op_divContext *ctx) override;

    std::any visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) override;
    std::any visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) override;
    std::any visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) override;
    std::any visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) override;
    std::any visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) override;
    std::any visitAtom_REAL(LustreParser::Atom_REALContext *ctx) override;
    std::any visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) override;
    std::any visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) override;

    std::any visitIndex(LustreParser::IndexContext *ctx) override;


    //用来辅助struct生成值的时候生成struct的名字
    static std::shared_ptr<TypeDefSymbol> structDefType;

    //在程序的最后拼接这个string
    std::string endOFVisitorString;
    //在当前的节点中拼接var定义
    std::vector<std::string> endOFVarVector;
    //在当前节点中拼接let定义
    std::vector<std::string> endOFLetVector;

    std::set<std::string> funcs;
    //防止重复生成函数，传参为函数名及函数文本
    void addFuncToEnd(std::string funcName, std::string funcText) {
        if(funcs.count(funcName)) return;
        funcs.insert(funcName);
        endOFVisitorString.append(funcText);
    }

    std::map<std::string, int> var_cnt;
};


#endif //LUSTRETOL2C_MYLUSTREVISITOR_H
