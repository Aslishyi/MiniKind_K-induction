
// Generated from ./Lustre.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "LustreVisitor.h"


/**
 * This class provides an empty implementation of LustreVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LustreBaseVisitor : public LustreVisitor {
public:

  virtual std::any visitProgram(LustreParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInclude(LustreParser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPack_list(LustreParser::Pack_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOne_park(LustreParser::One_parkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPack_decl(LustreParser::Pack_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUses(LustreParser::UsesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPack_eq(LustreParser::Pack_eqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProvides(LustreParser::ProvidesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProvide(LustreParser::ProvideContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModel_decl(LustreParser::Model_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUser_op_provide(LustreParser::User_op_provideContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_type(LustreParser::Decls_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_const(LustreParser::Decls_constContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_import_op(LustreParser::Decls_import_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_user_op(LustreParser::Decls_user_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_contract_node(LustreParser::Decls_contract_nodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_block(LustreParser::Type_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_decl(LustreParser::Type_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_def_type(LustreParser::Type_def_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_def_enum(LustreParser::Type_def_enumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_real(LustreParser::Type_realContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_float(LustreParser::Type_floatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_bool(LustreParser::Type_boolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_array(LustreParser::Type_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_char(LustreParser::Type_charContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_id(LustreParser::Type_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_ushort(LustreParser::Type_ushortContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_uint(LustreParser::Type_uintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_short(LustreParser::Type_shortContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_struct(LustreParser::Type_structContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_int(LustreParser::Type_intContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitField_decl(LustreParser::Field_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_block(LustreParser::Const_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_decl(LustreParser::Const_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_id(LustreParser::Const_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_paren(LustreParser::Const_parenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_bin_relation(LustreParser::Const_bin_relationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_atom(LustreParser::Const_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_unary_arith(LustreParser::Const_unary_arithContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_struct(LustreParser::Const_structContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_bin_arith(LustreParser::Const_bin_arithContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_bin_bool(LustreParser::Const_bin_boolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_array(LustreParser::Const_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_list(LustreParser::Const_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_label_expr(LustreParser::Const_label_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_decls(LustreParser::Var_declsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhen_decl(LustreParser::When_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClock_id(LustreParser::Clock_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClock_not(LustreParser::Clock_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLast_decl(LustreParser::Last_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUser_op_decl(LustreParser::User_op_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_kind_funtion(LustreParser::Op_kind_funtionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_kind_node(LustreParser::Op_kind_nodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(LustreParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_body_null(LustreParser::Op_body_nullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_body_ctx(LustreParser::Op_body_ctxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContract(LustreParser::ContractContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocal_block(LustreParser::Local_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLet_block_equation(LustreParser::Let_block_equationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLet_block_k2_property(LustreParser::Let_block_k2_propertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLet_block_k2_if_block(LustreParser::Let_block_k2_if_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLet_block_k2_frame_block(LustreParser::Let_block_k2_frame_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternal_contract(LustreParser::External_contractContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContract_body(LustreParser::Contract_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_mode(LustreParser::Decls_modeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_const_ghost_var(LustreParser::Decls_const_ghost_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_ghost_var(LustreParser::Decls_ghost_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_assume(LustreParser::Decls_assumeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_guarantee(LustreParser::Decls_guaranteeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls_imports(LustreParser::Decls_importsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMode_decl(LustreParser::Mode_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMode_body(LustreParser::Mode_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRequirement(LustreParser::RequirementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssurance(LustreParser::AssuranceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind2_const_item(LustreParser::Kind2_const_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind2_var_item(LustreParser::Kind2_var_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssume_item(LustreParser::Assume_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGuarantee_item(LustreParser::Guarantee_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_item(LustreParser::Import_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind2_if_block(LustreParser::Kind2_if_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind2_if_body(LustreParser::Kind2_if_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind2_statement_main(LustreParser::Kind2_statement_mainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind2_statement_property(LustreParser::Kind2_statement_propertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind2_statement_check(LustreParser::Kind2_statement_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind2_frame_block(LustreParser::Kind2_frame_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFrame_init(LustreParser::Frame_initContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFrame_body(LustreParser::Frame_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_op_decl(LustreParser::Import_op_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEquation_expr(LustreParser::Equation_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEquation_state_machine(LustreParser::Equation_state_machineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLhs_pair(LustreParser::Lhs_pairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLhs_id_list(LustreParser::Lhs_id_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn(LustreParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturns_var(LustreParser::Returns_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitState_machine(LustreParser::State_machineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitState_decl(LustreParser::State_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitState_machine_data_def_equation(LustreParser::State_machine_data_def_equationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitState_machine_data_def_local_block(LustreParser::State_machine_data_def_local_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnless_tran(LustreParser::Unless_tranContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUntil_tran(LustreParser::Until_tranContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitState_machine_transition_resume(LustreParser::State_machine_transition_resumeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitState_machine_transition_restart(LustreParser::State_machine_transition_restartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_simple_expr(LustreParser::Expr_simple_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_last_decl(LustreParser::Expr_last_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_tempo_expr(LustreParser::Expr_tempo_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_bool_expr(LustreParser::Expr_bool_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_array_expr(LustreParser::Expr_array_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_struct_expr(LustreParser::Expr_struct_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_mixed_constructor(LustreParser::Expr_mixed_constructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_switch_expr(LustreParser::Expr_switch_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_paren(LustreParser::Expr_parenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_apply_expr(LustreParser::Expr_apply_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_kind2_expr(LustreParser::Expr_kind2_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitList(LustreParser::ListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind2_expr(LustreParser::Kind2_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitActivate_expr(LustreParser::Activate_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRestart_expr(LustreParser::Restart_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind2_param(LustreParser::Kind2_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitActivate(LustreParser::ActivateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRestart(LustreParser::RestartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTempo_expr_pre(LustreParser::Tempo_expr_preContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTempo_expr_arrow_tempo(LustreParser::Tempo_expr_arrow_tempoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTempo_expr_arrow(LustreParser::Tempo_expr_arrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTempo_expr_fby(LustreParser::Tempo_expr_fbyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTempo_expr_fby_noconst(LustreParser::Tempo_expr_fby_noconstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTempo_expr_when(LustreParser::Tempo_expr_whenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTempo_expr_merge(LustreParser::Tempo_expr_mergeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTempo_kind2_merge(LustreParser::Tempo_kind2_mergeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBool_expr(LustreParser::Bool_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_expr_split(LustreParser::Array_expr_splitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_expr_dynamic(LustreParser::Array_expr_dynamicContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_expr_and(LustreParser::Array_expr_andContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_expr_list(LustreParser::Array_expr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStruct_expr(LustreParser::Struct_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMixed_constructor(LustreParser::Mixed_constructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabel_expr(LustreParser::Label_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndex(LustreParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMix_label(LustreParser::Mix_labelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMix_index(LustreParser::Mix_indexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_expr_ifelse(LustreParser::Switch_expr_ifelseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_expr_case(LustreParser::Switch_expr_caseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCase_expr(LustreParser::Case_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPattern(LustreParser::PatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply_prefix(LustreParser::Apply_prefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply_map(LustreParser::Apply_mapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply_fold(LustreParser::Apply_foldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply_mapi(LustreParser::Apply_mapiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply_foldi(LustreParser::Apply_foldiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply_mapfold(LustreParser::Apply_mapfoldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply_mapw(LustreParser::Apply_mapwContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply_mapwi(LustreParser::Apply_mapwiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply_foldw(LustreParser::Apply_foldwContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply_foldwi(LustreParser::Apply_foldwiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPerfix_ID(LustreParser::Perfix_IDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefix_unary(LustreParser::Prefix_unaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefix_binary(LustreParser::Prefix_binaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPerfix_make(LustreParser::Perfix_makeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPerfix_flatten(LustreParser::Perfix_flattenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefix_unary_operator(LustreParser::Prefix_unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefix_binary_operator(LustreParser::Prefix_binary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expr_unary_arith(LustreParser::Simple_expr_unary_arithContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_kind2_expr(LustreParser::Simple_kind2_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expr_paren(LustreParser::Simple_expr_parenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expr_type(LustreParser::Simple_expr_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expr_struct(LustreParser::Simple_expr_structContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expr_bin_relation(LustreParser::Simple_expr_bin_relationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expr_atom(LustreParser::Simple_expr_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expr_bin_bool(LustreParser::Simple_expr_bin_boolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expr_id(LustreParser::Simple_expr_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expr_bin_arith(LustreParser::Simple_expr_bin_arithContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expr_array(LustreParser::Simple_expr_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_arith_op_sub(LustreParser::Unary_arith_op_subContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_arith_op_add(LustreParser::Unary_arith_op_addContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_arith_op_not(LustreParser::Unary_arith_op_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBin_arith_op_add(LustreParser::Bin_arith_op_addContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBin_arith_op_sub(LustreParser::Bin_arith_op_subContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBin_arith_op_mul(LustreParser::Bin_arith_op_mulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBin_arith_op_divided(LustreParser::Bin_arith_op_dividedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBin_arith_op_mod(LustreParser::Bin_arith_op_modContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBin_arith_op_div(LustreParser::Bin_arith_op_divContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBin_relation_op(LustreParser::Bin_relation_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBin_bool_op(LustreParser::Bin_bool_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_REAL(LustreParser::Atom_REALContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMerge_expr(LustreParser::Merge_exprContext *ctx) override {
    return visitChildren(ctx);
  }


};

