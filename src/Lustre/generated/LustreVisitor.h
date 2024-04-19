
// Generated from Lustre.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "LustreParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LustreParser.
 */
class  LustreVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LustreParser.
   */
    virtual std::any visitProgram(LustreParser::ProgramContext *context) = 0;

    virtual std::any visitInclude(LustreParser::IncludeContext *context) = 0;

    virtual std::any visitPack_list(LustreParser::Pack_listContext *context) = 0;

    virtual std::any visitOne_park(LustreParser::One_parkContext *context) = 0;

    virtual std::any visitPack_decl(LustreParser::Pack_declContext *context) = 0;

    virtual std::any visitUses(LustreParser::UsesContext *context) = 0;

    virtual std::any visitPack_eq(LustreParser::Pack_eqContext *context) = 0;

    virtual std::any visitProvides(LustreParser::ProvidesContext *context) = 0;

    virtual std::any visitProvide(LustreParser::ProvideContext *context) = 0;

    virtual std::any visitModel_decl(LustreParser::Model_declContext *context) = 0;

    virtual std::any visitUser_op_provide(LustreParser::User_op_provideContext *context) = 0;

    virtual std::any visitDecls_type(LustreParser::Decls_typeContext *context) = 0;

    virtual std::any visitDecls_const(LustreParser::Decls_constContext *context) = 0;

    virtual std::any visitDecls_import_op(LustreParser::Decls_import_opContext *context) = 0;

    virtual std::any visitDecls_user_op(LustreParser::Decls_user_opContext *context) = 0;

    virtual std::any visitDecls_kind2(LustreParser::Decls_kind2Context *context) = 0;

    virtual std::any visitDecls_mode(LustreParser::Decls_modeContext *context) = 0;

    virtual std::any visitDecls_ghost_var(LustreParser::Decls_ghost_varContext *context) = 0;

    virtual std::any visitDecls_assume(LustreParser::Decls_assumeContext *context) = 0;

    virtual std::any visitDecls_guarantee(LustreParser::Decls_guaranteeContext *context) = 0;

    virtual std::any visitMode_decl(LustreParser::Mode_declContext *context) = 0;

    virtual std::any visitRequirement(LustreParser::RequirementContext *context) = 0;

    virtual std::any visitAssurance(LustreParser::AssuranceContext *context) = 0;

    virtual std::any visitVar_decl(LustreParser::Var_declContext *context) = 0;

    virtual std::any visitAssume_decl(LustreParser::Assume_declContext *context) = 0;

    virtual std::any visitGuarantee_decl(LustreParser::Guarantee_declContext *context) = 0;

    virtual std::any visitType_block(LustreParser::Type_blockContext *context) = 0;

    virtual std::any visitType_decl(LustreParser::Type_declContext *context) = 0;

    virtual std::any visitType_def_type(LustreParser::Type_def_typeContext *context) = 0;

    virtual std::any visitType_def_enum(LustreParser::Type_def_enumContext *context) = 0;

    virtual std::any visitType_real(LustreParser::Type_realContext *context) = 0;

    virtual std::any visitType_float(LustreParser::Type_floatContext *context) = 0;

    virtual std::any visitType_bool(LustreParser::Type_boolContext *context) = 0;

    virtual std::any visitType_array(LustreParser::Type_arrayContext *context) = 0;

    virtual std::any visitType_char(LustreParser::Type_charContext *context) = 0;

    virtual std::any visitType_id(LustreParser::Type_idContext *context) = 0;

    virtual std::any visitType_ushort(LustreParser::Type_ushortContext *context) = 0;

    virtual std::any visitType_uint(LustreParser::Type_uintContext *context) = 0;

    virtual std::any visitType_short(LustreParser::Type_shortContext *context) = 0;

    virtual std::any visitType_struct(LustreParser::Type_structContext *context) = 0;

    virtual std::any visitType_int(LustreParser::Type_intContext *context) = 0;

    virtual std::any visitField_decl(LustreParser::Field_declContext *context) = 0;

    virtual std::any visitConst_block(LustreParser::Const_blockContext *context) = 0;

    virtual std::any visitConst_decl(LustreParser::Const_declContext *context) = 0;

    virtual std::any visitConst_id(LustreParser::Const_idContext *context) = 0;

    virtual std::any visitConst_paren(LustreParser::Const_parenContext *context) = 0;

    virtual std::any visitConst_bin_relation(LustreParser::Const_bin_relationContext *context) = 0;

    virtual std::any visitConst_atom(LustreParser::Const_atomContext *context) = 0;

    virtual std::any visitConst_unary_arith(LustreParser::Const_unary_arithContext *context) = 0;

    virtual std::any visitConst_struct(LustreParser::Const_structContext *context) = 0;

    virtual std::any visitConst_bin_arith(LustreParser::Const_bin_arithContext *context) = 0;

    virtual std::any visitConst_bin_bool(LustreParser::Const_bin_boolContext *context) = 0;

    virtual std::any visitConst_array(LustreParser::Const_arrayContext *context) = 0;

    virtual std::any visitConst_list(LustreParser::Const_listContext *context) = 0;

    virtual std::any visitConst_label_expr(LustreParser::Const_label_exprContext *context) = 0;

    virtual std::any visitVar_decls(LustreParser::Var_declsContext *context) = 0;

    virtual std::any visitWhen_decl(LustreParser::When_declContext *context) = 0;

    virtual std::any visitClock_id(LustreParser::Clock_idContext *context) = 0;

    virtual std::any visitClock_not(LustreParser::Clock_notContext *context) = 0;

    virtual std::any visitLast_decl(LustreParser::Last_declContext *context) = 0;

    virtual std::any visitUser_op_decl(LustreParser::User_op_declContext *context) = 0;

    virtual std::any visitOp_kind_funtion(LustreParser::Op_kind_funtionContext *context) = 0;

    virtual std::any visitOp_kind_node(LustreParser::Op_kind_nodeContext *context) = 0;

    virtual std::any visitParams(LustreParser::ParamsContext *context) = 0;

    virtual std::any visitOp_body_null(LustreParser::Op_body_nullContext *context) = 0;

    virtual std::any visitOp_body_ctx(LustreParser::Op_body_ctxContext *context) = 0;

    virtual std::any visitContract_statement(LustreParser::Contract_statementContext *context) = 0;

    virtual std::any visitMerge_decl(LustreParser::Merge_declContext *context) = 0;

    virtual std::any visitLet_block_equation(LustreParser::Let_block_equationContext *context) = 0;

    virtual std::any visitLet_block_kind2_kind2_Statement(LustreParser::Let_block_kind2_kind2_StatementContext *context) = 0;

    virtual std::any visitLet_block_kind2_frame_block(LustreParser::Let_block_kind2_frame_blockContext *context) = 0;

    virtual std::any visitLocal_block(LustreParser::Local_blockContext *context) = 0;

    virtual std::any visitKind2_Statement(LustreParser::Kind2_StatementContext *context) = 0;

    virtual std::any visitMainStatement(LustreParser::MainStatementContext *context) = 0;

    virtual std::any visitPropertyStatement(LustreParser::PropertyStatementContext *context) = 0;

    virtual std::any visitCheckStatement(LustreParser::CheckStatementContext *context) = 0;

    virtual std::any visitFrame_block(LustreParser::Frame_blockContext *context) = 0;

    virtual std::any visitFrame_init(LustreParser::Frame_initContext *context) = 0;

    virtual std::any visitFrame_body(LustreParser::Frame_bodyContext *context) = 0;

    virtual std::any visitImport_op_decl(LustreParser::Import_op_declContext *context) = 0;

    virtual std::any visitEquation_expr(LustreParser::Equation_exprContext *context) = 0;

    virtual std::any visitEquation_state_machine(LustreParser::Equation_state_machineContext *context) = 0;

    virtual std::any visitLhs_pair(LustreParser::Lhs_pairContext *context) = 0;

    virtual std::any visitLhs_id_list(LustreParser::Lhs_id_listContext *context) = 0;

    virtual std::any visitReturn(LustreParser::ReturnContext *context) = 0;

    virtual std::any visitReturns_var(LustreParser::Returns_varContext *context) = 0;

    virtual std::any visitState_machine(LustreParser::State_machineContext *context) = 0;

    virtual std::any visitState_decl(LustreParser::State_declContext *context) = 0;

    virtual std::any visitState_machine_data_def_equation(LustreParser::State_machine_data_def_equationContext *context) = 0;

    virtual std::any visitState_machine_data_def_local_block(LustreParser::State_machine_data_def_local_blockContext *context) = 0;

    virtual std::any visitState_machine_transition_resume(LustreParser::State_machine_transition_resumeContext *context) = 0;

    virtual std::any visitState_machine_transition_restart(LustreParser::State_machine_transition_restartContext *context) = 0;

    virtual std::any visitExpr_simple_expr(LustreParser::Expr_simple_exprContext *context) = 0;

    virtual std::any visitExpr_last_decl(LustreParser::Expr_last_declContext *context) = 0;

    virtual std::any visitExpr_tempo_expr(LustreParser::Expr_tempo_exprContext *context) = 0;

    virtual std::any visitExpr_bool_expr(LustreParser::Expr_bool_exprContext *context) = 0;

    virtual std::any visitExpr_array_expr(LustreParser::Expr_array_exprContext *context) = 0;

    virtual std::any visitExpr_struct_expr(LustreParser::Expr_struct_exprContext *context) = 0;

    virtual std::any visitExpr_mixed_constructor(LustreParser::Expr_mixed_constructorContext *context) = 0;

    virtual std::any visitExpr_switch_expr(LustreParser::Expr_switch_exprContext *context) = 0;

    virtual std::any visitExpr_paren(LustreParser::Expr_parenContext *context) = 0;

    virtual std::any visitExpr_apply_expr(LustreParser::Expr_apply_exprContext *context) = 0;

    virtual std::any visitExpr_kind2(LustreParser::Expr_kind2Context *context) = 0;

    virtual std::any visitList(LustreParser::ListContext *context) = 0;

    virtual std::any visitKind2_expr(LustreParser::Kind2_exprContext *context) = 0;

    virtual std::any visitActivate_expr(LustreParser::Activate_exprContext *context) = 0;

    virtual std::any visitRestart_expr(LustreParser::Restart_exprContext *context) = 0;

    virtual std::any visitTempo_expr_pre(LustreParser::Tempo_expr_preContext *context) = 0;

    virtual std::any visitTempo_expr_arrow_tempo(LustreParser::Tempo_expr_arrow_tempoContext *context) = 0;

    virtual std::any visitTempo_expr_arrow(LustreParser::Tempo_expr_arrowContext *context) = 0;

    virtual std::any visitTempo_expr_fby(LustreParser::Tempo_expr_fbyContext *context) = 0;

    virtual std::any visitTempo_expr_fby_noconst(LustreParser::Tempo_expr_fby_noconstContext *context) = 0;

    virtual std::any visitTempo_expr_when(LustreParser::Tempo_expr_whenContext *context) = 0;

    virtual std::any visitTempo_expr_merge(LustreParser::Tempo_expr_mergeContext *context) = 0;

    virtual std::any visitBool_expr(LustreParser::Bool_exprContext *context) = 0;

    virtual std::any visitArray_expr_split(LustreParser::Array_expr_splitContext *context) = 0;

    virtual std::any visitArray_expr_dynamic(LustreParser::Array_expr_dynamicContext *context) = 0;

    virtual std::any visitArray_expr_and(LustreParser::Array_expr_andContext *context) = 0;

    virtual std::any visitArray_expr_list(LustreParser::Array_expr_listContext *context) = 0;

    virtual std::any visitStruct_expr(LustreParser::Struct_exprContext *context) = 0;

    virtual std::any visitMixed_constructor(LustreParser::Mixed_constructorContext *context) = 0;

    virtual std::any visitLabel_expr(LustreParser::Label_exprContext *context) = 0;

    virtual std::any visitIndex(LustreParser::IndexContext *context) = 0;

    virtual std::any visitMix_label(LustreParser::Mix_labelContext *context) = 0;

    virtual std::any visitMix_index(LustreParser::Mix_indexContext *context) = 0;

    virtual std::any visitSwitch_expr_ifelse(LustreParser::Switch_expr_ifelseContext *context) = 0;

    virtual std::any visitSwitch_expr_case(LustreParser::Switch_expr_caseContext *context) = 0;

    virtual std::any visitCase_expr(LustreParser::Case_exprContext *context) = 0;

    virtual std::any visitPattern(LustreParser::PatternContext *context) = 0;

    virtual std::any visitApply_prefix(LustreParser::Apply_prefixContext *context) = 0;

    virtual std::any visitApply_iterator(LustreParser::Apply_iteratorContext *context) = 0;

    virtual std::any visitApply_iterator_lv6(LustreParser::Apply_iterator_lv6Context *context) = 0;

    virtual std::any visitApply_mapw(LustreParser::Apply_mapwContext *context) = 0;

    virtual std::any visitApply_mapwI(LustreParser::Apply_mapwIContext *context) = 0;

    virtual std::any visitApply_foldw(LustreParser::Apply_foldwContext *context) = 0;

    virtual std::any visitApply_foldwi(LustreParser::Apply_foldwiContext *context) = 0;

    virtual std::any visitPerfix_ID(LustreParser::Perfix_IDContext *context) = 0;

    virtual std::any visitPrefix_unary(LustreParser::Prefix_unaryContext *context) = 0;

    virtual std::any visitPrefix_binary(LustreParser::Prefix_binaryContext *context) = 0;

    virtual std::any visitPerfix_make(LustreParser::Perfix_makeContext *context) = 0;

    virtual std::any visitPerfix_flatten(LustreParser::Perfix_flattenContext *context) = 0;

    virtual std::any visitPrefix_unary_operator(LustreParser::Prefix_unary_operatorContext *context) = 0;

    virtual std::any visitPrefix_binary_operator(LustreParser::Prefix_binary_operatorContext *context) = 0;

    virtual std::any visitIterator_map(LustreParser::Iterator_mapContext *context) = 0;

    virtual std::any visitIterator_fold(LustreParser::Iterator_foldContext *context) = 0;

    virtual std::any visitIterator_mapi(LustreParser::Iterator_mapiContext *context) = 0;

    virtual std::any visitIterator_foldi(LustreParser::Iterator_foldiContext *context) = 0;

    virtual std::any visitIterator_mapfold(LustreParser::Iterator_mapfoldContext *context) = 0;

    virtual std::any visitIterator_red(LustreParser::Iterator_redContext *context) = 0;

    virtual std::any visitIterator_fill(LustreParser::Iterator_fillContext *context) = 0;

    virtual std::any visitIterator_fillred(LustreParser::Iterator_fillredContext *context) = 0;

    virtual std::any visitIterator_boolred(LustreParser::Iterator_boolredContext *context) = 0;

    virtual std::any visitIterator_lv6_red(LustreParser::Iterator_lv6_redContext *context) = 0;

    virtual std::any visitIterator_lv6_fill(LustreParser::Iterator_lv6_fillContext *context) = 0;

    virtual std::any visitIterator_lv6_fillred(LustreParser::Iterator_lv6_fillredContext *context) = 0;

    virtual std::any visitIterator_lv6_boolred(LustreParser::Iterator_lv6_boolredContext *context) = 0;

    virtual std::any visitSimple_expr_unary_arith(LustreParser::Simple_expr_unary_arithContext *context) = 0;

    virtual std::any visitSimple_expr_paren(LustreParser::Simple_expr_parenContext *context) = 0;

    virtual std::any visitSimple_expr_type(LustreParser::Simple_expr_typeContext *context) = 0;

    virtual std::any visitSimple_expr_struct(LustreParser::Simple_expr_structContext *context) = 0;

    virtual std::any visitSimple_expr_bin_relation(LustreParser::Simple_expr_bin_relationContext *context) = 0;

    virtual std::any visitSimple_expr_atom(LustreParser::Simple_expr_atomContext *context) = 0;

    virtual std::any visitSimple_expr_bin_bool(LustreParser::Simple_expr_bin_boolContext *context) = 0;

    virtual std::any visitSimple_expr_id(LustreParser::Simple_expr_idContext *context) = 0;

    virtual std::any visitSimple_expr_bin_arith(LustreParser::Simple_expr_bin_arithContext *context) = 0;

    virtual std::any visitSimple_expr_array(LustreParser::Simple_expr_arrayContext *context) = 0;

    virtual std::any visitUnary_arith_op_sub(LustreParser::Unary_arith_op_subContext *context) = 0;

    virtual std::any visitUnary_arith_op_add(LustreParser::Unary_arith_op_addContext *context) = 0;

    virtual std::any visitUnary_arith_op_not(LustreParser::Unary_arith_op_notContext *context) = 0;

    virtual std::any visitBin_arith_op_add(LustreParser::Bin_arith_op_addContext *context) = 0;

    virtual std::any visitBin_arith_op_sub(LustreParser::Bin_arith_op_subContext *context) = 0;

    virtual std::any visitBin_arith_op_mul(LustreParser::Bin_arith_op_mulContext *context) = 0;

    virtual std::any visitBin_arith_op_divided(LustreParser::Bin_arith_op_dividedContext *context) = 0;

    virtual std::any visitBin_arith_op_mod(LustreParser::Bin_arith_op_modContext *context) = 0;

    virtual std::any visitBin_arith_op_div(LustreParser::Bin_arith_op_divContext *context) = 0;

    virtual std::any visitBin_relation_op(LustreParser::Bin_relation_opContext *context) = 0;

    virtual std::any visitBin_bool_op(LustreParser::Bin_bool_opContext *context) = 0;

    virtual std::any visitAtom_BOOL(LustreParser::Atom_BOOLContext *context) = 0;

    virtual std::any visitAtom_CHAR(LustreParser::Atom_CHARContext *context) = 0;

    virtual std::any visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *context) = 0;

    virtual std::any visitAtom_UINT(LustreParser::Atom_UINTContext *context) = 0;

    virtual std::any visitAtom_FLOAT(LustreParser::Atom_FLOATContext *context) = 0;

    virtual std::any visitAtom_REAL(LustreParser::Atom_REALContext *context) = 0;

    virtual std::any visitAtom_USHORT(LustreParser::Atom_USHORTContext *context) = 0;

    virtual std::any visitAtom_SHORT(LustreParser::Atom_SHORTContext *context) = 0;


};

