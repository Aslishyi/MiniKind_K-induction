
// Generated from Lustre.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "LustreListener.h"


/**
 * This class provides an empty implementation of LustreListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LustreBaseListener : public LustreListener {
public:

  virtual void enterProgram(LustreParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(LustreParser::ProgramContext * /*ctx*/) override { }

  virtual void enterInclude(LustreParser::IncludeContext * /*ctx*/) override { }
  virtual void exitInclude(LustreParser::IncludeContext * /*ctx*/) override { }

  virtual void enterPack_list(LustreParser::Pack_listContext * /*ctx*/) override { }
  virtual void exitPack_list(LustreParser::Pack_listContext * /*ctx*/) override { }

  virtual void enterOne_park(LustreParser::One_parkContext * /*ctx*/) override { }
  virtual void exitOne_park(LustreParser::One_parkContext * /*ctx*/) override { }

  virtual void enterPack_decl(LustreParser::Pack_declContext * /*ctx*/) override { }
  virtual void exitPack_decl(LustreParser::Pack_declContext * /*ctx*/) override { }

  virtual void enterUses(LustreParser::UsesContext * /*ctx*/) override { }
  virtual void exitUses(LustreParser::UsesContext * /*ctx*/) override { }

  virtual void enterPack_eq(LustreParser::Pack_eqContext * /*ctx*/) override { }
  virtual void exitPack_eq(LustreParser::Pack_eqContext * /*ctx*/) override { }

  virtual void enterProvides(LustreParser::ProvidesContext * /*ctx*/) override { }
  virtual void exitProvides(LustreParser::ProvidesContext * /*ctx*/) override { }

  virtual void enterProvide(LustreParser::ProvideContext * /*ctx*/) override { }
  virtual void exitProvide(LustreParser::ProvideContext * /*ctx*/) override { }

  virtual void enterModel_decl(LustreParser::Model_declContext * /*ctx*/) override { }
  virtual void exitModel_decl(LustreParser::Model_declContext * /*ctx*/) override { }

  virtual void enterUser_op_provide(LustreParser::User_op_provideContext * /*ctx*/) override { }
  virtual void exitUser_op_provide(LustreParser::User_op_provideContext * /*ctx*/) override { }

  virtual void enterDecls_type(LustreParser::Decls_typeContext * /*ctx*/) override { }
  virtual void exitDecls_type(LustreParser::Decls_typeContext * /*ctx*/) override { }

  virtual void enterDecls_const(LustreParser::Decls_constContext * /*ctx*/) override { }
  virtual void exitDecls_const(LustreParser::Decls_constContext * /*ctx*/) override { }

  virtual void enterDecls_import_op(LustreParser::Decls_import_opContext * /*ctx*/) override { }
  virtual void exitDecls_import_op(LustreParser::Decls_import_opContext * /*ctx*/) override { }

  virtual void enterDecls_user_op(LustreParser::Decls_user_opContext * /*ctx*/) override { }
  virtual void exitDecls_user_op(LustreParser::Decls_user_opContext * /*ctx*/) override { }

  virtual void enterDecls_kind2(LustreParser::Decls_kind2Context * /*ctx*/) override { }
  virtual void exitDecls_kind2(LustreParser::Decls_kind2Context * /*ctx*/) override { }

  virtual void enterDecls_mode(LustreParser::Decls_modeContext * /*ctx*/) override { }
  virtual void exitDecls_mode(LustreParser::Decls_modeContext * /*ctx*/) override { }

  virtual void enterDecls_ghost_var(LustreParser::Decls_ghost_varContext * /*ctx*/) override { }
  virtual void exitDecls_ghost_var(LustreParser::Decls_ghost_varContext * /*ctx*/) override { }

  virtual void enterDecls_assume(LustreParser::Decls_assumeContext * /*ctx*/) override { }
  virtual void exitDecls_assume(LustreParser::Decls_assumeContext * /*ctx*/) override { }

  virtual void enterDecls_guarantee(LustreParser::Decls_guaranteeContext * /*ctx*/) override { }
  virtual void exitDecls_guarantee(LustreParser::Decls_guaranteeContext * /*ctx*/) override { }

  virtual void enterMode_decl(LustreParser::Mode_declContext * /*ctx*/) override { }
  virtual void exitMode_decl(LustreParser::Mode_declContext * /*ctx*/) override { }

  virtual void enterRequirement(LustreParser::RequirementContext * /*ctx*/) override { }
  virtual void exitRequirement(LustreParser::RequirementContext * /*ctx*/) override { }

  virtual void enterAssurance(LustreParser::AssuranceContext * /*ctx*/) override { }
  virtual void exitAssurance(LustreParser::AssuranceContext * /*ctx*/) override { }

  virtual void enterVar_decl(LustreParser::Var_declContext * /*ctx*/) override { }
  virtual void exitVar_decl(LustreParser::Var_declContext * /*ctx*/) override { }

  virtual void enterAssume_decl(LustreParser::Assume_declContext * /*ctx*/) override { }
  virtual void exitAssume_decl(LustreParser::Assume_declContext * /*ctx*/) override { }

  virtual void enterGuarantee_decl(LustreParser::Guarantee_declContext * /*ctx*/) override { }
  virtual void exitGuarantee_decl(LustreParser::Guarantee_declContext * /*ctx*/) override { }

  virtual void enterType_block(LustreParser::Type_blockContext * /*ctx*/) override { }
  virtual void exitType_block(LustreParser::Type_blockContext * /*ctx*/) override { }

  virtual void enterType_decl(LustreParser::Type_declContext * /*ctx*/) override { }
  virtual void exitType_decl(LustreParser::Type_declContext * /*ctx*/) override { }

  virtual void enterType_def_type(LustreParser::Type_def_typeContext * /*ctx*/) override { }
  virtual void exitType_def_type(LustreParser::Type_def_typeContext * /*ctx*/) override { }

  virtual void enterType_def_enum(LustreParser::Type_def_enumContext * /*ctx*/) override { }
  virtual void exitType_def_enum(LustreParser::Type_def_enumContext * /*ctx*/) override { }

  virtual void enterType_real(LustreParser::Type_realContext * /*ctx*/) override { }
  virtual void exitType_real(LustreParser::Type_realContext * /*ctx*/) override { }

  virtual void enterType_float(LustreParser::Type_floatContext * /*ctx*/) override { }
  virtual void exitType_float(LustreParser::Type_floatContext * /*ctx*/) override { }

  virtual void enterType_bool(LustreParser::Type_boolContext * /*ctx*/) override { }
  virtual void exitType_bool(LustreParser::Type_boolContext * /*ctx*/) override { }

  virtual void enterType_array(LustreParser::Type_arrayContext * /*ctx*/) override { }
  virtual void exitType_array(LustreParser::Type_arrayContext * /*ctx*/) override { }

  virtual void enterType_char(LustreParser::Type_charContext * /*ctx*/) override { }
  virtual void exitType_char(LustreParser::Type_charContext * /*ctx*/) override { }

  virtual void enterType_id(LustreParser::Type_idContext * /*ctx*/) override { }
  virtual void exitType_id(LustreParser::Type_idContext * /*ctx*/) override { }

  virtual void enterType_ushort(LustreParser::Type_ushortContext * /*ctx*/) override { }
  virtual void exitType_ushort(LustreParser::Type_ushortContext * /*ctx*/) override { }

  virtual void enterType_uint(LustreParser::Type_uintContext * /*ctx*/) override { }
  virtual void exitType_uint(LustreParser::Type_uintContext * /*ctx*/) override { }

  virtual void enterType_short(LustreParser::Type_shortContext * /*ctx*/) override { }
  virtual void exitType_short(LustreParser::Type_shortContext * /*ctx*/) override { }

  virtual void enterType_struct(LustreParser::Type_structContext * /*ctx*/) override { }
  virtual void exitType_struct(LustreParser::Type_structContext * /*ctx*/) override { }

  virtual void enterType_int(LustreParser::Type_intContext * /*ctx*/) override { }
  virtual void exitType_int(LustreParser::Type_intContext * /*ctx*/) override { }

  virtual void enterField_decl(LustreParser::Field_declContext * /*ctx*/) override { }
  virtual void exitField_decl(LustreParser::Field_declContext * /*ctx*/) override { }

  virtual void enterConst_block(LustreParser::Const_blockContext * /*ctx*/) override { }
  virtual void exitConst_block(LustreParser::Const_blockContext * /*ctx*/) override { }

  virtual void enterConst_decl(LustreParser::Const_declContext * /*ctx*/) override { }
  virtual void exitConst_decl(LustreParser::Const_declContext * /*ctx*/) override { }

  virtual void enterConst_id(LustreParser::Const_idContext * /*ctx*/) override { }
  virtual void exitConst_id(LustreParser::Const_idContext * /*ctx*/) override { }

  virtual void enterConst_paren(LustreParser::Const_parenContext * /*ctx*/) override { }
  virtual void exitConst_paren(LustreParser::Const_parenContext * /*ctx*/) override { }

  virtual void enterConst_bin_relation(LustreParser::Const_bin_relationContext * /*ctx*/) override { }
  virtual void exitConst_bin_relation(LustreParser::Const_bin_relationContext * /*ctx*/) override { }

  virtual void enterConst_atom(LustreParser::Const_atomContext * /*ctx*/) override { }
  virtual void exitConst_atom(LustreParser::Const_atomContext * /*ctx*/) override { }

  virtual void enterConst_unary_arith(LustreParser::Const_unary_arithContext * /*ctx*/) override { }
  virtual void exitConst_unary_arith(LustreParser::Const_unary_arithContext * /*ctx*/) override { }

  virtual void enterConst_struct(LustreParser::Const_structContext * /*ctx*/) override { }
  virtual void exitConst_struct(LustreParser::Const_structContext * /*ctx*/) override { }

  virtual void enterConst_bin_arith(LustreParser::Const_bin_arithContext * /*ctx*/) override { }
  virtual void exitConst_bin_arith(LustreParser::Const_bin_arithContext * /*ctx*/) override { }

  virtual void enterConst_bin_bool(LustreParser::Const_bin_boolContext * /*ctx*/) override { }
  virtual void exitConst_bin_bool(LustreParser::Const_bin_boolContext * /*ctx*/) override { }

  virtual void enterConst_array(LustreParser::Const_arrayContext * /*ctx*/) override { }
  virtual void exitConst_array(LustreParser::Const_arrayContext * /*ctx*/) override { }

  virtual void enterConst_list(LustreParser::Const_listContext * /*ctx*/) override { }
  virtual void exitConst_list(LustreParser::Const_listContext * /*ctx*/) override { }

  virtual void enterConst_label_expr(LustreParser::Const_label_exprContext * /*ctx*/) override { }
  virtual void exitConst_label_expr(LustreParser::Const_label_exprContext * /*ctx*/) override { }

  virtual void enterVar_decls(LustreParser::Var_declsContext * /*ctx*/) override { }
  virtual void exitVar_decls(LustreParser::Var_declsContext * /*ctx*/) override { }

  virtual void enterWhen_decl(LustreParser::When_declContext * /*ctx*/) override { }
  virtual void exitWhen_decl(LustreParser::When_declContext * /*ctx*/) override { }

  virtual void enterClock_id(LustreParser::Clock_idContext * /*ctx*/) override { }
  virtual void exitClock_id(LustreParser::Clock_idContext * /*ctx*/) override { }

  virtual void enterClock_not(LustreParser::Clock_notContext * /*ctx*/) override { }
  virtual void exitClock_not(LustreParser::Clock_notContext * /*ctx*/) override { }

  virtual void enterLast_decl(LustreParser::Last_declContext * /*ctx*/) override { }
  virtual void exitLast_decl(LustreParser::Last_declContext * /*ctx*/) override { }

  virtual void enterUser_op_decl(LustreParser::User_op_declContext * /*ctx*/) override { }
  virtual void exitUser_op_decl(LustreParser::User_op_declContext * /*ctx*/) override { }

  virtual void enterOp_kind_funtion(LustreParser::Op_kind_funtionContext * /*ctx*/) override { }
  virtual void exitOp_kind_funtion(LustreParser::Op_kind_funtionContext * /*ctx*/) override { }

  virtual void enterOp_kind_node(LustreParser::Op_kind_nodeContext * /*ctx*/) override { }
  virtual void exitOp_kind_node(LustreParser::Op_kind_nodeContext * /*ctx*/) override { }

  virtual void enterParams(LustreParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(LustreParser::ParamsContext * /*ctx*/) override { }

  virtual void enterOp_body_null(LustreParser::Op_body_nullContext * /*ctx*/) override { }
  virtual void exitOp_body_null(LustreParser::Op_body_nullContext * /*ctx*/) override { }

  virtual void enterOp_body_ctx(LustreParser::Op_body_ctxContext * /*ctx*/) override { }
  virtual void exitOp_body_ctx(LustreParser::Op_body_ctxContext * /*ctx*/) override { }

  virtual void enterContract_statement(LustreParser::Contract_statementContext * /*ctx*/) override { }
  virtual void exitContract_statement(LustreParser::Contract_statementContext * /*ctx*/) override { }

  virtual void enterMerge_decl(LustreParser::Merge_declContext * /*ctx*/) override { }
  virtual void exitMerge_decl(LustreParser::Merge_declContext * /*ctx*/) override { }

  virtual void enterLet_block_equation(LustreParser::Let_block_equationContext * /*ctx*/) override { }
  virtual void exitLet_block_equation(LustreParser::Let_block_equationContext * /*ctx*/) override { }

  virtual void enterLet_block_kind2_kind2_Statement(LustreParser::Let_block_kind2_kind2_StatementContext * /*ctx*/) override { }
  virtual void exitLet_block_kind2_kind2_Statement(LustreParser::Let_block_kind2_kind2_StatementContext * /*ctx*/) override { }

  virtual void enterLet_block_kind2_frame_block(LustreParser::Let_block_kind2_frame_blockContext * /*ctx*/) override { }
  virtual void exitLet_block_kind2_frame_block(LustreParser::Let_block_kind2_frame_blockContext * /*ctx*/) override { }

  virtual void enterLocal_block(LustreParser::Local_blockContext * /*ctx*/) override { }
  virtual void exitLocal_block(LustreParser::Local_blockContext * /*ctx*/) override { }

  virtual void enterKind2_Statement(LustreParser::Kind2_StatementContext * /*ctx*/) override { }
  virtual void exitKind2_Statement(LustreParser::Kind2_StatementContext * /*ctx*/) override { }

  virtual void enterMainStatement(LustreParser::MainStatementContext * /*ctx*/) override { }
  virtual void exitMainStatement(LustreParser::MainStatementContext * /*ctx*/) override { }

  virtual void enterPropertyStatement(LustreParser::PropertyStatementContext * /*ctx*/) override { }
  virtual void exitPropertyStatement(LustreParser::PropertyStatementContext * /*ctx*/) override { }

  virtual void enterCheckStatement(LustreParser::CheckStatementContext * /*ctx*/) override { }
  virtual void exitCheckStatement(LustreParser::CheckStatementContext * /*ctx*/) override { }

  virtual void enterFrame_block(LustreParser::Frame_blockContext * /*ctx*/) override { }
  virtual void exitFrame_block(LustreParser::Frame_blockContext * /*ctx*/) override { }

  virtual void enterFrame_init(LustreParser::Frame_initContext * /*ctx*/) override { }
  virtual void exitFrame_init(LustreParser::Frame_initContext * /*ctx*/) override { }

  virtual void enterFrame_body(LustreParser::Frame_bodyContext * /*ctx*/) override { }
  virtual void exitFrame_body(LustreParser::Frame_bodyContext * /*ctx*/) override { }

  virtual void enterImport_op_decl(LustreParser::Import_op_declContext * /*ctx*/) override { }
  virtual void exitImport_op_decl(LustreParser::Import_op_declContext * /*ctx*/) override { }

  virtual void enterEquation_expr(LustreParser::Equation_exprContext * /*ctx*/) override { }
  virtual void exitEquation_expr(LustreParser::Equation_exprContext * /*ctx*/) override { }

  virtual void enterEquation_state_machine(LustreParser::Equation_state_machineContext * /*ctx*/) override { }
  virtual void exitEquation_state_machine(LustreParser::Equation_state_machineContext * /*ctx*/) override { }

  virtual void enterLhs_pair(LustreParser::Lhs_pairContext * /*ctx*/) override { }
  virtual void exitLhs_pair(LustreParser::Lhs_pairContext * /*ctx*/) override { }

  virtual void enterLhs_id_list(LustreParser::Lhs_id_listContext * /*ctx*/) override { }
  virtual void exitLhs_id_list(LustreParser::Lhs_id_listContext * /*ctx*/) override { }

  virtual void enterReturn(LustreParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(LustreParser::ReturnContext * /*ctx*/) override { }

  virtual void enterReturns_var(LustreParser::Returns_varContext * /*ctx*/) override { }
  virtual void exitReturns_var(LustreParser::Returns_varContext * /*ctx*/) override { }

  virtual void enterState_machine(LustreParser::State_machineContext * /*ctx*/) override { }
  virtual void exitState_machine(LustreParser::State_machineContext * /*ctx*/) override { }

  virtual void enterState_decl(LustreParser::State_declContext * /*ctx*/) override { }
  virtual void exitState_decl(LustreParser::State_declContext * /*ctx*/) override { }

  virtual void enterState_machine_data_def_equation(LustreParser::State_machine_data_def_equationContext * /*ctx*/) override { }
  virtual void exitState_machine_data_def_equation(LustreParser::State_machine_data_def_equationContext * /*ctx*/) override { }

  virtual void enterState_machine_data_def_local_block(LustreParser::State_machine_data_def_local_blockContext * /*ctx*/) override { }
  virtual void exitState_machine_data_def_local_block(LustreParser::State_machine_data_def_local_blockContext * /*ctx*/) override { }

  virtual void enterState_machine_transition_resume(LustreParser::State_machine_transition_resumeContext * /*ctx*/) override { }
  virtual void exitState_machine_transition_resume(LustreParser::State_machine_transition_resumeContext * /*ctx*/) override { }

  virtual void enterState_machine_transition_restart(LustreParser::State_machine_transition_restartContext * /*ctx*/) override { }
  virtual void exitState_machine_transition_restart(LustreParser::State_machine_transition_restartContext * /*ctx*/) override { }

  virtual void enterExpr_simple_expr(LustreParser::Expr_simple_exprContext * /*ctx*/) override { }
  virtual void exitExpr_simple_expr(LustreParser::Expr_simple_exprContext * /*ctx*/) override { }

  virtual void enterExpr_last_decl(LustreParser::Expr_last_declContext * /*ctx*/) override { }
  virtual void exitExpr_last_decl(LustreParser::Expr_last_declContext * /*ctx*/) override { }

  virtual void enterExpr_tempo_expr(LustreParser::Expr_tempo_exprContext * /*ctx*/) override { }
  virtual void exitExpr_tempo_expr(LustreParser::Expr_tempo_exprContext * /*ctx*/) override { }

  virtual void enterExpr_bool_expr(LustreParser::Expr_bool_exprContext * /*ctx*/) override { }
  virtual void exitExpr_bool_expr(LustreParser::Expr_bool_exprContext * /*ctx*/) override { }

  virtual void enterExpr_array_expr(LustreParser::Expr_array_exprContext * /*ctx*/) override { }
  virtual void exitExpr_array_expr(LustreParser::Expr_array_exprContext * /*ctx*/) override { }

  virtual void enterExpr_struct_expr(LustreParser::Expr_struct_exprContext * /*ctx*/) override { }
  virtual void exitExpr_struct_expr(LustreParser::Expr_struct_exprContext * /*ctx*/) override { }

  virtual void enterExpr_mixed_constructor(LustreParser::Expr_mixed_constructorContext * /*ctx*/) override { }
  virtual void exitExpr_mixed_constructor(LustreParser::Expr_mixed_constructorContext * /*ctx*/) override { }

  virtual void enterExpr_switch_expr(LustreParser::Expr_switch_exprContext * /*ctx*/) override { }
  virtual void exitExpr_switch_expr(LustreParser::Expr_switch_exprContext * /*ctx*/) override { }

  virtual void enterExpr_paren(LustreParser::Expr_parenContext * /*ctx*/) override { }
  virtual void exitExpr_paren(LustreParser::Expr_parenContext * /*ctx*/) override { }

  virtual void enterExpr_apply_expr(LustreParser::Expr_apply_exprContext * /*ctx*/) override { }
  virtual void exitExpr_apply_expr(LustreParser::Expr_apply_exprContext * /*ctx*/) override { }

  virtual void enterExpr_kind2(LustreParser::Expr_kind2Context * /*ctx*/) override { }
  virtual void exitExpr_kind2(LustreParser::Expr_kind2Context * /*ctx*/) override { }

  virtual void enterList(LustreParser::ListContext * /*ctx*/) override { }
  virtual void exitList(LustreParser::ListContext * /*ctx*/) override { }

  virtual void enterKind2_expr(LustreParser::Kind2_exprContext * /*ctx*/) override { }
  virtual void exitKind2_expr(LustreParser::Kind2_exprContext * /*ctx*/) override { }

  virtual void enterActivate_expr(LustreParser::Activate_exprContext * /*ctx*/) override { }
  virtual void exitActivate_expr(LustreParser::Activate_exprContext * /*ctx*/) override { }

  virtual void enterRestart_expr(LustreParser::Restart_exprContext * /*ctx*/) override { }
  virtual void exitRestart_expr(LustreParser::Restart_exprContext * /*ctx*/) override { }

  virtual void enterTempo_expr_pre(LustreParser::Tempo_expr_preContext * /*ctx*/) override { }
  virtual void exitTempo_expr_pre(LustreParser::Tempo_expr_preContext * /*ctx*/) override { }

  virtual void enterTempo_expr_arrow_tempo(LustreParser::Tempo_expr_arrow_tempoContext * /*ctx*/) override { }
  virtual void exitTempo_expr_arrow_tempo(LustreParser::Tempo_expr_arrow_tempoContext * /*ctx*/) override { }

  virtual void enterTempo_expr_arrow(LustreParser::Tempo_expr_arrowContext * /*ctx*/) override { }
  virtual void exitTempo_expr_arrow(LustreParser::Tempo_expr_arrowContext * /*ctx*/) override { }

  virtual void enterTempo_expr_fby(LustreParser::Tempo_expr_fbyContext * /*ctx*/) override { }
  virtual void exitTempo_expr_fby(LustreParser::Tempo_expr_fbyContext * /*ctx*/) override { }

  virtual void enterTempo_expr_fby_noconst(LustreParser::Tempo_expr_fby_noconstContext * /*ctx*/) override { }
  virtual void exitTempo_expr_fby_noconst(LustreParser::Tempo_expr_fby_noconstContext * /*ctx*/) override { }

  virtual void enterTempo_expr_when(LustreParser::Tempo_expr_whenContext * /*ctx*/) override { }
  virtual void exitTempo_expr_when(LustreParser::Tempo_expr_whenContext * /*ctx*/) override { }

  virtual void enterTempo_expr_merge(LustreParser::Tempo_expr_mergeContext * /*ctx*/) override { }
  virtual void exitTempo_expr_merge(LustreParser::Tempo_expr_mergeContext * /*ctx*/) override { }

  virtual void enterBool_expr(LustreParser::Bool_exprContext * /*ctx*/) override { }
  virtual void exitBool_expr(LustreParser::Bool_exprContext * /*ctx*/) override { }

  virtual void enterArray_expr_split(LustreParser::Array_expr_splitContext * /*ctx*/) override { }
  virtual void exitArray_expr_split(LustreParser::Array_expr_splitContext * /*ctx*/) override { }

  virtual void enterArray_expr_dynamic(LustreParser::Array_expr_dynamicContext * /*ctx*/) override { }
  virtual void exitArray_expr_dynamic(LustreParser::Array_expr_dynamicContext * /*ctx*/) override { }

  virtual void enterArray_expr_and(LustreParser::Array_expr_andContext * /*ctx*/) override { }
  virtual void exitArray_expr_and(LustreParser::Array_expr_andContext * /*ctx*/) override { }

  virtual void enterArray_expr_list(LustreParser::Array_expr_listContext * /*ctx*/) override { }
  virtual void exitArray_expr_list(LustreParser::Array_expr_listContext * /*ctx*/) override { }

  virtual void enterStruct_expr(LustreParser::Struct_exprContext * /*ctx*/) override { }
  virtual void exitStruct_expr(LustreParser::Struct_exprContext * /*ctx*/) override { }

  virtual void enterMixed_constructor(LustreParser::Mixed_constructorContext * /*ctx*/) override { }
  virtual void exitMixed_constructor(LustreParser::Mixed_constructorContext * /*ctx*/) override { }

  virtual void enterLabel_expr(LustreParser::Label_exprContext * /*ctx*/) override { }
  virtual void exitLabel_expr(LustreParser::Label_exprContext * /*ctx*/) override { }

  virtual void enterIndex(LustreParser::IndexContext * /*ctx*/) override { }
  virtual void exitIndex(LustreParser::IndexContext * /*ctx*/) override { }

  virtual void enterMix_label(LustreParser::Mix_labelContext * /*ctx*/) override { }
  virtual void exitMix_label(LustreParser::Mix_labelContext * /*ctx*/) override { }

  virtual void enterMix_index(LustreParser::Mix_indexContext * /*ctx*/) override { }
  virtual void exitMix_index(LustreParser::Mix_indexContext * /*ctx*/) override { }

  virtual void enterSwitch_expr_ifelse(LustreParser::Switch_expr_ifelseContext * /*ctx*/) override { }
  virtual void exitSwitch_expr_ifelse(LustreParser::Switch_expr_ifelseContext * /*ctx*/) override { }

  virtual void enterSwitch_expr_case(LustreParser::Switch_expr_caseContext * /*ctx*/) override { }
  virtual void exitSwitch_expr_case(LustreParser::Switch_expr_caseContext * /*ctx*/) override { }

  virtual void enterCase_expr(LustreParser::Case_exprContext * /*ctx*/) override { }
  virtual void exitCase_expr(LustreParser::Case_exprContext * /*ctx*/) override { }

  virtual void enterPattern(LustreParser::PatternContext * /*ctx*/) override { }
  virtual void exitPattern(LustreParser::PatternContext * /*ctx*/) override { }

  virtual void enterApply_prefix(LustreParser::Apply_prefixContext * /*ctx*/) override { }
  virtual void exitApply_prefix(LustreParser::Apply_prefixContext * /*ctx*/) override { }

  virtual void enterApply_iterator(LustreParser::Apply_iteratorContext * /*ctx*/) override { }
  virtual void exitApply_iterator(LustreParser::Apply_iteratorContext * /*ctx*/) override { }

  virtual void enterApply_iterator_lv6(LustreParser::Apply_iterator_lv6Context * /*ctx*/) override { }
  virtual void exitApply_iterator_lv6(LustreParser::Apply_iterator_lv6Context * /*ctx*/) override { }

  virtual void enterApply_mapw(LustreParser::Apply_mapwContext * /*ctx*/) override { }
  virtual void exitApply_mapw(LustreParser::Apply_mapwContext * /*ctx*/) override { }

  virtual void enterApply_mapwI(LustreParser::Apply_mapwIContext * /*ctx*/) override { }
  virtual void exitApply_mapwI(LustreParser::Apply_mapwIContext * /*ctx*/) override { }

  virtual void enterApply_foldw(LustreParser::Apply_foldwContext * /*ctx*/) override { }
  virtual void exitApply_foldw(LustreParser::Apply_foldwContext * /*ctx*/) override { }

  virtual void enterApply_foldwi(LustreParser::Apply_foldwiContext * /*ctx*/) override { }
  virtual void exitApply_foldwi(LustreParser::Apply_foldwiContext * /*ctx*/) override { }

  virtual void enterPerfix_ID(LustreParser::Perfix_IDContext * /*ctx*/) override { }
  virtual void exitPerfix_ID(LustreParser::Perfix_IDContext * /*ctx*/) override { }

  virtual void enterPrefix_unary(LustreParser::Prefix_unaryContext * /*ctx*/) override { }
  virtual void exitPrefix_unary(LustreParser::Prefix_unaryContext * /*ctx*/) override { }

  virtual void enterPrefix_binary(LustreParser::Prefix_binaryContext * /*ctx*/) override { }
  virtual void exitPrefix_binary(LustreParser::Prefix_binaryContext * /*ctx*/) override { }

  virtual void enterPerfix_make(LustreParser::Perfix_makeContext * /*ctx*/) override { }
  virtual void exitPerfix_make(LustreParser::Perfix_makeContext * /*ctx*/) override { }

  virtual void enterPerfix_flatten(LustreParser::Perfix_flattenContext * /*ctx*/) override { }
  virtual void exitPerfix_flatten(LustreParser::Perfix_flattenContext * /*ctx*/) override { }

  virtual void enterPrefix_unary_operator(LustreParser::Prefix_unary_operatorContext * /*ctx*/) override { }
  virtual void exitPrefix_unary_operator(LustreParser::Prefix_unary_operatorContext * /*ctx*/) override { }

  virtual void enterPrefix_binary_operator(LustreParser::Prefix_binary_operatorContext * /*ctx*/) override { }
  virtual void exitPrefix_binary_operator(LustreParser::Prefix_binary_operatorContext * /*ctx*/) override { }

  virtual void enterIterator_map(LustreParser::Iterator_mapContext * /*ctx*/) override { }
  virtual void exitIterator_map(LustreParser::Iterator_mapContext * /*ctx*/) override { }

  virtual void enterIterator_fold(LustreParser::Iterator_foldContext * /*ctx*/) override { }
  virtual void exitIterator_fold(LustreParser::Iterator_foldContext * /*ctx*/) override { }

  virtual void enterIterator_mapi(LustreParser::Iterator_mapiContext * /*ctx*/) override { }
  virtual void exitIterator_mapi(LustreParser::Iterator_mapiContext * /*ctx*/) override { }

  virtual void enterIterator_foldi(LustreParser::Iterator_foldiContext * /*ctx*/) override { }
  virtual void exitIterator_foldi(LustreParser::Iterator_foldiContext * /*ctx*/) override { }

  virtual void enterIterator_mapfold(LustreParser::Iterator_mapfoldContext * /*ctx*/) override { }
  virtual void exitIterator_mapfold(LustreParser::Iterator_mapfoldContext * /*ctx*/) override { }

  virtual void enterIterator_red(LustreParser::Iterator_redContext * /*ctx*/) override { }
  virtual void exitIterator_red(LustreParser::Iterator_redContext * /*ctx*/) override { }

  virtual void enterIterator_fill(LustreParser::Iterator_fillContext * /*ctx*/) override { }
  virtual void exitIterator_fill(LustreParser::Iterator_fillContext * /*ctx*/) override { }

  virtual void enterIterator_fillred(LustreParser::Iterator_fillredContext * /*ctx*/) override { }
  virtual void exitIterator_fillred(LustreParser::Iterator_fillredContext * /*ctx*/) override { }

  virtual void enterIterator_boolred(LustreParser::Iterator_boolredContext * /*ctx*/) override { }
  virtual void exitIterator_boolred(LustreParser::Iterator_boolredContext * /*ctx*/) override { }

  virtual void enterIterator_lv6_red(LustreParser::Iterator_lv6_redContext * /*ctx*/) override { }
  virtual void exitIterator_lv6_red(LustreParser::Iterator_lv6_redContext * /*ctx*/) override { }

  virtual void enterIterator_lv6_fill(LustreParser::Iterator_lv6_fillContext * /*ctx*/) override { }
  virtual void exitIterator_lv6_fill(LustreParser::Iterator_lv6_fillContext * /*ctx*/) override { }

  virtual void enterIterator_lv6_fillred(LustreParser::Iterator_lv6_fillredContext * /*ctx*/) override { }
  virtual void exitIterator_lv6_fillred(LustreParser::Iterator_lv6_fillredContext * /*ctx*/) override { }

  virtual void enterIterator_lv6_boolred(LustreParser::Iterator_lv6_boolredContext * /*ctx*/) override { }
  virtual void exitIterator_lv6_boolred(LustreParser::Iterator_lv6_boolredContext * /*ctx*/) override { }

  virtual void enterSimple_expr_unary_arith(LustreParser::Simple_expr_unary_arithContext * /*ctx*/) override { }
  virtual void exitSimple_expr_unary_arith(LustreParser::Simple_expr_unary_arithContext * /*ctx*/) override { }

  virtual void enterSimple_expr_paren(LustreParser::Simple_expr_parenContext * /*ctx*/) override { }
  virtual void exitSimple_expr_paren(LustreParser::Simple_expr_parenContext * /*ctx*/) override { }

  virtual void enterSimple_expr_type(LustreParser::Simple_expr_typeContext * /*ctx*/) override { }
  virtual void exitSimple_expr_type(LustreParser::Simple_expr_typeContext * /*ctx*/) override { }

  virtual void enterSimple_expr_struct(LustreParser::Simple_expr_structContext * /*ctx*/) override { }
  virtual void exitSimple_expr_struct(LustreParser::Simple_expr_structContext * /*ctx*/) override { }

  virtual void enterSimple_expr_bin_relation(LustreParser::Simple_expr_bin_relationContext * /*ctx*/) override { }
  virtual void exitSimple_expr_bin_relation(LustreParser::Simple_expr_bin_relationContext * /*ctx*/) override { }

  virtual void enterSimple_expr_atom(LustreParser::Simple_expr_atomContext * /*ctx*/) override { }
  virtual void exitSimple_expr_atom(LustreParser::Simple_expr_atomContext * /*ctx*/) override { }

  virtual void enterSimple_expr_bin_bool(LustreParser::Simple_expr_bin_boolContext * /*ctx*/) override { }
  virtual void exitSimple_expr_bin_bool(LustreParser::Simple_expr_bin_boolContext * /*ctx*/) override { }

  virtual void enterSimple_expr_id(LustreParser::Simple_expr_idContext * /*ctx*/) override { }
  virtual void exitSimple_expr_id(LustreParser::Simple_expr_idContext * /*ctx*/) override { }

  virtual void enterSimple_expr_bin_arith(LustreParser::Simple_expr_bin_arithContext * /*ctx*/) override { }
  virtual void exitSimple_expr_bin_arith(LustreParser::Simple_expr_bin_arithContext * /*ctx*/) override { }

  virtual void enterSimple_expr_array(LustreParser::Simple_expr_arrayContext * /*ctx*/) override { }
  virtual void exitSimple_expr_array(LustreParser::Simple_expr_arrayContext * /*ctx*/) override { }

  virtual void enterUnary_arith_op_sub(LustreParser::Unary_arith_op_subContext * /*ctx*/) override { }
  virtual void exitUnary_arith_op_sub(LustreParser::Unary_arith_op_subContext * /*ctx*/) override { }

  virtual void enterUnary_arith_op_add(LustreParser::Unary_arith_op_addContext * /*ctx*/) override { }
  virtual void exitUnary_arith_op_add(LustreParser::Unary_arith_op_addContext * /*ctx*/) override { }

  virtual void enterUnary_arith_op_not(LustreParser::Unary_arith_op_notContext * /*ctx*/) override { }
  virtual void exitUnary_arith_op_not(LustreParser::Unary_arith_op_notContext * /*ctx*/) override { }

  virtual void enterBin_arith_op_add(LustreParser::Bin_arith_op_addContext * /*ctx*/) override { }
  virtual void exitBin_arith_op_add(LustreParser::Bin_arith_op_addContext * /*ctx*/) override { }

  virtual void enterBin_arith_op_sub(LustreParser::Bin_arith_op_subContext * /*ctx*/) override { }
  virtual void exitBin_arith_op_sub(LustreParser::Bin_arith_op_subContext * /*ctx*/) override { }

  virtual void enterBin_arith_op_mul(LustreParser::Bin_arith_op_mulContext * /*ctx*/) override { }
  virtual void exitBin_arith_op_mul(LustreParser::Bin_arith_op_mulContext * /*ctx*/) override { }

  virtual void enterBin_arith_op_divided(LustreParser::Bin_arith_op_dividedContext * /*ctx*/) override { }
  virtual void exitBin_arith_op_divided(LustreParser::Bin_arith_op_dividedContext * /*ctx*/) override { }

  virtual void enterBin_arith_op_mod(LustreParser::Bin_arith_op_modContext * /*ctx*/) override { }
  virtual void exitBin_arith_op_mod(LustreParser::Bin_arith_op_modContext * /*ctx*/) override { }

  virtual void enterBin_arith_op_div(LustreParser::Bin_arith_op_divContext * /*ctx*/) override { }
  virtual void exitBin_arith_op_div(LustreParser::Bin_arith_op_divContext * /*ctx*/) override { }

  virtual void enterBin_relation_op(LustreParser::Bin_relation_opContext * /*ctx*/) override { }
  virtual void exitBin_relation_op(LustreParser::Bin_relation_opContext * /*ctx*/) override { }

  virtual void enterBin_bool_op(LustreParser::Bin_bool_opContext * /*ctx*/) override { }
  virtual void exitBin_bool_op(LustreParser::Bin_bool_opContext * /*ctx*/) override { }

  virtual void enterAtom_BOOL(LustreParser::Atom_BOOLContext * /*ctx*/) override { }
  virtual void exitAtom_BOOL(LustreParser::Atom_BOOLContext * /*ctx*/) override { }

  virtual void enterAtom_CHAR(LustreParser::Atom_CHARContext * /*ctx*/) override { }
  virtual void exitAtom_CHAR(LustreParser::Atom_CHARContext * /*ctx*/) override { }

  virtual void enterAtom_INTEGER(LustreParser::Atom_INTEGERContext * /*ctx*/) override { }
  virtual void exitAtom_INTEGER(LustreParser::Atom_INTEGERContext * /*ctx*/) override { }

  virtual void enterAtom_UINT(LustreParser::Atom_UINTContext * /*ctx*/) override { }
  virtual void exitAtom_UINT(LustreParser::Atom_UINTContext * /*ctx*/) override { }

  virtual void enterAtom_FLOAT(LustreParser::Atom_FLOATContext * /*ctx*/) override { }
  virtual void exitAtom_FLOAT(LustreParser::Atom_FLOATContext * /*ctx*/) override { }

  virtual void enterAtom_REAL(LustreParser::Atom_REALContext * /*ctx*/) override { }
  virtual void exitAtom_REAL(LustreParser::Atom_REALContext * /*ctx*/) override { }

  virtual void enterAtom_USHORT(LustreParser::Atom_USHORTContext * /*ctx*/) override { }
  virtual void exitAtom_USHORT(LustreParser::Atom_USHORTContext * /*ctx*/) override { }

  virtual void enterAtom_SHORT(LustreParser::Atom_SHORTContext * /*ctx*/) override { }
  virtual void exitAtom_SHORT(LustreParser::Atom_SHORTContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

