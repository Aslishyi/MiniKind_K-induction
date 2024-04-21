// Generated from /home/blcm/Qkind/Ql2c/src/lustre/Lustre.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link LustreParser}.
 */
public interface LustreListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link LustreParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(LustreParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(LustreParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#include}.
	 * @param ctx the parse tree
	 */
	void enterInclude(LustreParser.IncludeContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#include}.
	 * @param ctx the parse tree
	 */
	void exitInclude(LustreParser.IncludeContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#pack_list}.
	 * @param ctx the parse tree
	 */
	void enterPack_list(LustreParser.Pack_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#pack_list}.
	 * @param ctx the parse tree
	 */
	void exitPack_list(LustreParser.Pack_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#one_park}.
	 * @param ctx the parse tree
	 */
	void enterOne_park(LustreParser.One_parkContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#one_park}.
	 * @param ctx the parse tree
	 */
	void exitOne_park(LustreParser.One_parkContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#pack_decl}.
	 * @param ctx the parse tree
	 */
	void enterPack_decl(LustreParser.Pack_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#pack_decl}.
	 * @param ctx the parse tree
	 */
	void exitPack_decl(LustreParser.Pack_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#uses}.
	 * @param ctx the parse tree
	 */
	void enterUses(LustreParser.UsesContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#uses}.
	 * @param ctx the parse tree
	 */
	void exitUses(LustreParser.UsesContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#pack_eq}.
	 * @param ctx the parse tree
	 */
	void enterPack_eq(LustreParser.Pack_eqContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#pack_eq}.
	 * @param ctx the parse tree
	 */
	void exitPack_eq(LustreParser.Pack_eqContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#provides}.
	 * @param ctx the parse tree
	 */
	void enterProvides(LustreParser.ProvidesContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#provides}.
	 * @param ctx the parse tree
	 */
	void exitProvides(LustreParser.ProvidesContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#provide}.
	 * @param ctx the parse tree
	 */
	void enterProvide(LustreParser.ProvideContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#provide}.
	 * @param ctx the parse tree
	 */
	void exitProvide(LustreParser.ProvideContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#model_decl}.
	 * @param ctx the parse tree
	 */
	void enterModel_decl(LustreParser.Model_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#model_decl}.
	 * @param ctx the parse tree
	 */
	void exitModel_decl(LustreParser.Model_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#user_op_provide}.
	 * @param ctx the parse tree
	 */
	void enterUser_op_provide(LustreParser.User_op_provideContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#user_op_provide}.
	 * @param ctx the parse tree
	 */
	void exitUser_op_provide(LustreParser.User_op_provideContext ctx);
	/**
	 * Enter a parse tree produced by the {@code decls_type}
	 * labeled alternative in {@link LustreParser#decls}.
	 * @param ctx the parse tree
	 */
	void enterDecls_type(LustreParser.Decls_typeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code decls_type}
	 * labeled alternative in {@link LustreParser#decls}.
	 * @param ctx the parse tree
	 */
	void exitDecls_type(LustreParser.Decls_typeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code decls_const}
	 * labeled alternative in {@link LustreParser#decls}.
	 * @param ctx the parse tree
	 */
	void enterDecls_const(LustreParser.Decls_constContext ctx);
	/**
	 * Exit a parse tree produced by the {@code decls_const}
	 * labeled alternative in {@link LustreParser#decls}.
	 * @param ctx the parse tree
	 */
	void exitDecls_const(LustreParser.Decls_constContext ctx);
	/**
	 * Enter a parse tree produced by the {@code decls_import_op}
	 * labeled alternative in {@link LustreParser#decls}.
	 * @param ctx the parse tree
	 */
	void enterDecls_import_op(LustreParser.Decls_import_opContext ctx);
	/**
	 * Exit a parse tree produced by the {@code decls_import_op}
	 * labeled alternative in {@link LustreParser#decls}.
	 * @param ctx the parse tree
	 */
	void exitDecls_import_op(LustreParser.Decls_import_opContext ctx);
	/**
	 * Enter a parse tree produced by the {@code decls_user_op}
	 * labeled alternative in {@link LustreParser#decls}.
	 * @param ctx the parse tree
	 */
	void enterDecls_user_op(LustreParser.Decls_user_opContext ctx);
	/**
	 * Exit a parse tree produced by the {@code decls_user_op}
	 * labeled alternative in {@link LustreParser#decls}.
	 * @param ctx the parse tree
	 */
	void exitDecls_user_op(LustreParser.Decls_user_opContext ctx);
	/**
	 * Enter a parse tree produced by the {@code decls_kind2}
	 * labeled alternative in {@link LustreParser#decls}.
	 * @param ctx the parse tree
	 */
	void enterDecls_kind2(LustreParser.Decls_kind2Context ctx);
	/**
	 * Exit a parse tree produced by the {@code decls_kind2}
	 * labeled alternative in {@link LustreParser#decls}.
	 * @param ctx the parse tree
	 */
	void exitDecls_kind2(LustreParser.Decls_kind2Context ctx);
	/**
	 * Enter a parse tree produced by the {@code decls_mode}
	 * labeled alternative in {@link LustreParser#kind2_decl}.
	 * @param ctx the parse tree
	 */
	void enterDecls_mode(LustreParser.Decls_modeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code decls_mode}
	 * labeled alternative in {@link LustreParser#kind2_decl}.
	 * @param ctx the parse tree
	 */
	void exitDecls_mode(LustreParser.Decls_modeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code decls_ghost_var}
	 * labeled alternative in {@link LustreParser#kind2_decl}.
	 * @param ctx the parse tree
	 */
	void enterDecls_ghost_var(LustreParser.Decls_ghost_varContext ctx);
	/**
	 * Exit a parse tree produced by the {@code decls_ghost_var}
	 * labeled alternative in {@link LustreParser#kind2_decl}.
	 * @param ctx the parse tree
	 */
	void exitDecls_ghost_var(LustreParser.Decls_ghost_varContext ctx);
	/**
	 * Enter a parse tree produced by the {@code decls_assume}
	 * labeled alternative in {@link LustreParser#kind2_decl}.
	 * @param ctx the parse tree
	 */
	void enterDecls_assume(LustreParser.Decls_assumeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code decls_assume}
	 * labeled alternative in {@link LustreParser#kind2_decl}.
	 * @param ctx the parse tree
	 */
	void exitDecls_assume(LustreParser.Decls_assumeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code decls_guarantee}
	 * labeled alternative in {@link LustreParser#kind2_decl}.
	 * @param ctx the parse tree
	 */
	void enterDecls_guarantee(LustreParser.Decls_guaranteeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code decls_guarantee}
	 * labeled alternative in {@link LustreParser#kind2_decl}.
	 * @param ctx the parse tree
	 */
	void exitDecls_guarantee(LustreParser.Decls_guaranteeContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#mode_decl}.
	 * @param ctx the parse tree
	 */
	void enterMode_decl(LustreParser.Mode_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#mode_decl}.
	 * @param ctx the parse tree
	 */
	void exitMode_decl(LustreParser.Mode_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#requirement}.
	 * @param ctx the parse tree
	 */
	void enterRequirement(LustreParser.RequirementContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#requirement}.
	 * @param ctx the parse tree
	 */
	void exitRequirement(LustreParser.RequirementContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#assurance}.
	 * @param ctx the parse tree
	 */
	void enterAssurance(LustreParser.AssuranceContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#assurance}.
	 * @param ctx the parse tree
	 */
	void exitAssurance(LustreParser.AssuranceContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#var_decl}.
	 * @param ctx the parse tree
	 */
	void enterVar_decl(LustreParser.Var_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#var_decl}.
	 * @param ctx the parse tree
	 */
	void exitVar_decl(LustreParser.Var_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#assume_decl}.
	 * @param ctx the parse tree
	 */
	void enterAssume_decl(LustreParser.Assume_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#assume_decl}.
	 * @param ctx the parse tree
	 */
	void exitAssume_decl(LustreParser.Assume_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#guarantee_decl}.
	 * @param ctx the parse tree
	 */
	void enterGuarantee_decl(LustreParser.Guarantee_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#guarantee_decl}.
	 * @param ctx the parse tree
	 */
	void exitGuarantee_decl(LustreParser.Guarantee_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#type_block}.
	 * @param ctx the parse tree
	 */
	void enterType_block(LustreParser.Type_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#type_block}.
	 * @param ctx the parse tree
	 */
	void exitType_block(LustreParser.Type_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#type_decl}.
	 * @param ctx the parse tree
	 */
	void enterType_decl(LustreParser.Type_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#type_decl}.
	 * @param ctx the parse tree
	 */
	void exitType_decl(LustreParser.Type_declContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_def_type}
	 * labeled alternative in {@link LustreParser#type_def}.
	 * @param ctx the parse tree
	 */
	void enterType_def_type(LustreParser.Type_def_typeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_def_type}
	 * labeled alternative in {@link LustreParser#type_def}.
	 * @param ctx the parse tree
	 */
	void exitType_def_type(LustreParser.Type_def_typeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_def_enum}
	 * labeled alternative in {@link LustreParser#type_def}.
	 * @param ctx the parse tree
	 */
	void enterType_def_enum(LustreParser.Type_def_enumContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_def_enum}
	 * labeled alternative in {@link LustreParser#type_def}.
	 * @param ctx the parse tree
	 */
	void exitType_def_enum(LustreParser.Type_def_enumContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_real}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_real(LustreParser.Type_realContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_real}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_real(LustreParser.Type_realContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_float}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_float(LustreParser.Type_floatContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_float}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_float(LustreParser.Type_floatContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_bool}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_bool(LustreParser.Type_boolContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_bool}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_bool(LustreParser.Type_boolContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_array}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_array(LustreParser.Type_arrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_array}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_array(LustreParser.Type_arrayContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_char}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_char(LustreParser.Type_charContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_char}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_char(LustreParser.Type_charContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_id}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_id(LustreParser.Type_idContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_id}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_id(LustreParser.Type_idContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_ushort}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_ushort(LustreParser.Type_ushortContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_ushort}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_ushort(LustreParser.Type_ushortContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_uint}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_uint(LustreParser.Type_uintContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_uint}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_uint(LustreParser.Type_uintContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_short}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_short(LustreParser.Type_shortContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_short}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_short(LustreParser.Type_shortContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_struct}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_struct(LustreParser.Type_structContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_struct}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_struct(LustreParser.Type_structContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_int}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType_int(LustreParser.Type_intContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_int}
	 * labeled alternative in {@link LustreParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType_int(LustreParser.Type_intContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#field_decl}.
	 * @param ctx the parse tree
	 */
	void enterField_decl(LustreParser.Field_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#field_decl}.
	 * @param ctx the parse tree
	 */
	void exitField_decl(LustreParser.Field_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#const_block}.
	 * @param ctx the parse tree
	 */
	void enterConst_block(LustreParser.Const_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#const_block}.
	 * @param ctx the parse tree
	 */
	void exitConst_block(LustreParser.Const_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#const_decl}.
	 * @param ctx the parse tree
	 */
	void enterConst_decl(LustreParser.Const_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#const_decl}.
	 * @param ctx the parse tree
	 */
	void exitConst_decl(LustreParser.Const_declContext ctx);
	/**
	 * Enter a parse tree produced by the {@code const_id}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_id(LustreParser.Const_idContext ctx);
	/**
	 * Exit a parse tree produced by the {@code const_id}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_id(LustreParser.Const_idContext ctx);
	/**
	 * Enter a parse tree produced by the {@code const_paren}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_paren(LustreParser.Const_parenContext ctx);
	/**
	 * Exit a parse tree produced by the {@code const_paren}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_paren(LustreParser.Const_parenContext ctx);
	/**
	 * Enter a parse tree produced by the {@code const_bin_relation}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_bin_relation(LustreParser.Const_bin_relationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code const_bin_relation}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_bin_relation(LustreParser.Const_bin_relationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code const_atom}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_atom(LustreParser.Const_atomContext ctx);
	/**
	 * Exit a parse tree produced by the {@code const_atom}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_atom(LustreParser.Const_atomContext ctx);
	/**
	 * Enter a parse tree produced by the {@code const_unary_arith}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_unary_arith(LustreParser.Const_unary_arithContext ctx);
	/**
	 * Exit a parse tree produced by the {@code const_unary_arith}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_unary_arith(LustreParser.Const_unary_arithContext ctx);
	/**
	 * Enter a parse tree produced by the {@code const_struct}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_struct(LustreParser.Const_structContext ctx);
	/**
	 * Exit a parse tree produced by the {@code const_struct}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_struct(LustreParser.Const_structContext ctx);
	/**
	 * Enter a parse tree produced by the {@code const_bin_arith}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_bin_arith(LustreParser.Const_bin_arithContext ctx);
	/**
	 * Exit a parse tree produced by the {@code const_bin_arith}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_bin_arith(LustreParser.Const_bin_arithContext ctx);
	/**
	 * Enter a parse tree produced by the {@code const_bin_bool}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_bin_bool(LustreParser.Const_bin_boolContext ctx);
	/**
	 * Exit a parse tree produced by the {@code const_bin_bool}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_bin_bool(LustreParser.Const_bin_boolContext ctx);
	/**
	 * Enter a parse tree produced by the {@code const_array}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_array(LustreParser.Const_arrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code const_array}
	 * labeled alternative in {@link LustreParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_array(LustreParser.Const_arrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#const_list}.
	 * @param ctx the parse tree
	 */
	void enterConst_list(LustreParser.Const_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#const_list}.
	 * @param ctx the parse tree
	 */
	void exitConst_list(LustreParser.Const_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#const_label_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_label_expr(LustreParser.Const_label_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#const_label_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_label_expr(LustreParser.Const_label_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#var_decls}.
	 * @param ctx the parse tree
	 */
	void enterVar_decls(LustreParser.Var_declsContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#var_decls}.
	 * @param ctx the parse tree
	 */
	void exitVar_decls(LustreParser.Var_declsContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#when_decl}.
	 * @param ctx the parse tree
	 */
	void enterWhen_decl(LustreParser.When_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#when_decl}.
	 * @param ctx the parse tree
	 */
	void exitWhen_decl(LustreParser.When_declContext ctx);
	/**
	 * Enter a parse tree produced by the {@code clock_id}
	 * labeled alternative in {@link LustreParser#clock_expr}.
	 * @param ctx the parse tree
	 */
	void enterClock_id(LustreParser.Clock_idContext ctx);
	/**
	 * Exit a parse tree produced by the {@code clock_id}
	 * labeled alternative in {@link LustreParser#clock_expr}.
	 * @param ctx the parse tree
	 */
	void exitClock_id(LustreParser.Clock_idContext ctx);
	/**
	 * Enter a parse tree produced by the {@code clock_not}
	 * labeled alternative in {@link LustreParser#clock_expr}.
	 * @param ctx the parse tree
	 */
	void enterClock_not(LustreParser.Clock_notContext ctx);
	/**
	 * Exit a parse tree produced by the {@code clock_not}
	 * labeled alternative in {@link LustreParser#clock_expr}.
	 * @param ctx the parse tree
	 */
	void exitClock_not(LustreParser.Clock_notContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#last_decl}.
	 * @param ctx the parse tree
	 */
	void enterLast_decl(LustreParser.Last_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#last_decl}.
	 * @param ctx the parse tree
	 */
	void exitLast_decl(LustreParser.Last_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#user_op_decl}.
	 * @param ctx the parse tree
	 */
	void enterUser_op_decl(LustreParser.User_op_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#user_op_decl}.
	 * @param ctx the parse tree
	 */
	void exitUser_op_decl(LustreParser.User_op_declContext ctx);
	/**
	 * Enter a parse tree produced by the {@code op_kind_funtion}
	 * labeled alternative in {@link LustreParser#op_kind}.
	 * @param ctx the parse tree
	 */
	void enterOp_kind_funtion(LustreParser.Op_kind_funtionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code op_kind_funtion}
	 * labeled alternative in {@link LustreParser#op_kind}.
	 * @param ctx the parse tree
	 */
	void exitOp_kind_funtion(LustreParser.Op_kind_funtionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code op_kind_node}
	 * labeled alternative in {@link LustreParser#op_kind}.
	 * @param ctx the parse tree
	 */
	void enterOp_kind_node(LustreParser.Op_kind_nodeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code op_kind_node}
	 * labeled alternative in {@link LustreParser#op_kind}.
	 * @param ctx the parse tree
	 */
	void exitOp_kind_node(LustreParser.Op_kind_nodeContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#params}.
	 * @param ctx the parse tree
	 */
	void enterParams(LustreParser.ParamsContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#params}.
	 * @param ctx the parse tree
	 */
	void exitParams(LustreParser.ParamsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code op_body_null}
	 * labeled alternative in {@link LustreParser#op_body}.
	 * @param ctx the parse tree
	 */
	void enterOp_body_null(LustreParser.Op_body_nullContext ctx);
	/**
	 * Exit a parse tree produced by the {@code op_body_null}
	 * labeled alternative in {@link LustreParser#op_body}.
	 * @param ctx the parse tree
	 */
	void exitOp_body_null(LustreParser.Op_body_nullContext ctx);
	/**
	 * Enter a parse tree produced by the {@code op_body_ctx}
	 * labeled alternative in {@link LustreParser#op_body}.
	 * @param ctx the parse tree
	 */
	void enterOp_body_ctx(LustreParser.Op_body_ctxContext ctx);
	/**
	 * Exit a parse tree produced by the {@code op_body_ctx}
	 * labeled alternative in {@link LustreParser#op_body}.
	 * @param ctx the parse tree
	 */
	void exitOp_body_ctx(LustreParser.Op_body_ctxContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#contract_statement}.
	 * @param ctx the parse tree
	 */
	void enterContract_statement(LustreParser.Contract_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#contract_statement}.
	 * @param ctx the parse tree
	 */
	void exitContract_statement(LustreParser.Contract_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#merge_decl}.
	 * @param ctx the parse tree
	 */
	void enterMerge_decl(LustreParser.Merge_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#merge_decl}.
	 * @param ctx the parse tree
	 */
	void exitMerge_decl(LustreParser.Merge_declContext ctx);
	/**
	 * Enter a parse tree produced by the {@code let_block_equation}
	 * labeled alternative in {@link LustreParser#let_block}.
	 * @param ctx the parse tree
	 */
	void enterLet_block_equation(LustreParser.Let_block_equationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code let_block_equation}
	 * labeled alternative in {@link LustreParser#let_block}.
	 * @param ctx the parse tree
	 */
	void exitLet_block_equation(LustreParser.Let_block_equationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code let_block_kind2_kind2_Statement}
	 * labeled alternative in {@link LustreParser#let_block}.
	 * @param ctx the parse tree
	 */
	void enterLet_block_kind2_kind2_Statement(LustreParser.Let_block_kind2_kind2_StatementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code let_block_kind2_kind2_Statement}
	 * labeled alternative in {@link LustreParser#let_block}.
	 * @param ctx the parse tree
	 */
	void exitLet_block_kind2_kind2_Statement(LustreParser.Let_block_kind2_kind2_StatementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code let_block_kind2_frame_block}
	 * labeled alternative in {@link LustreParser#let_block}.
	 * @param ctx the parse tree
	 */
	void enterLet_block_kind2_frame_block(LustreParser.Let_block_kind2_frame_blockContext ctx);
	/**
	 * Exit a parse tree produced by the {@code let_block_kind2_frame_block}
	 * labeled alternative in {@link LustreParser#let_block}.
	 * @param ctx the parse tree
	 */
	void exitLet_block_kind2_frame_block(LustreParser.Let_block_kind2_frame_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#local_block}.
	 * @param ctx the parse tree
	 */
	void enterLocal_block(LustreParser.Local_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#local_block}.
	 * @param ctx the parse tree
	 */
	void exitLocal_block(LustreParser.Local_blockContext ctx);
	/**
	 * Enter a parse tree produced by the {@code kind2_Statement_main}
	 * labeled alternative in {@link LustreParser#kind2_Statement}.
	 * @param ctx the parse tree
	 */
	void enterKind2_Statement_main(LustreParser.Kind2_Statement_mainContext ctx);
	/**
	 * Exit a parse tree produced by the {@code kind2_Statement_main}
	 * labeled alternative in {@link LustreParser#kind2_Statement}.
	 * @param ctx the parse tree
	 */
	void exitKind2_Statement_main(LustreParser.Kind2_Statement_mainContext ctx);
	/**
	 * Enter a parse tree produced by the {@code kind2_Statement_property}
	 * labeled alternative in {@link LustreParser#kind2_Statement}.
	 * @param ctx the parse tree
	 */
	void enterKind2_Statement_property(LustreParser.Kind2_Statement_propertyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code kind2_Statement_property}
	 * labeled alternative in {@link LustreParser#kind2_Statement}.
	 * @param ctx the parse tree
	 */
	void exitKind2_Statement_property(LustreParser.Kind2_Statement_propertyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code kind2_Statement_check}
	 * labeled alternative in {@link LustreParser#kind2_Statement}.
	 * @param ctx the parse tree
	 */
	void enterKind2_Statement_check(LustreParser.Kind2_Statement_checkContext ctx);
	/**
	 * Exit a parse tree produced by the {@code kind2_Statement_check}
	 * labeled alternative in {@link LustreParser#kind2_Statement}.
	 * @param ctx the parse tree
	 */
	void exitKind2_Statement_check(LustreParser.Kind2_Statement_checkContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#frame_block}.
	 * @param ctx the parse tree
	 */
	void enterFrame_block(LustreParser.Frame_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#frame_block}.
	 * @param ctx the parse tree
	 */
	void exitFrame_block(LustreParser.Frame_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#frame_init}.
	 * @param ctx the parse tree
	 */
	void enterFrame_init(LustreParser.Frame_initContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#frame_init}.
	 * @param ctx the parse tree
	 */
	void exitFrame_init(LustreParser.Frame_initContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#frame_body}.
	 * @param ctx the parse tree
	 */
	void enterFrame_body(LustreParser.Frame_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#frame_body}.
	 * @param ctx the parse tree
	 */
	void exitFrame_body(LustreParser.Frame_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#import_op_decl}.
	 * @param ctx the parse tree
	 */
	void enterImport_op_decl(LustreParser.Import_op_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#import_op_decl}.
	 * @param ctx the parse tree
	 */
	void exitImport_op_decl(LustreParser.Import_op_declContext ctx);
	/**
	 * Enter a parse tree produced by the {@code equation_expr}
	 * labeled alternative in {@link LustreParser#equation}.
	 * @param ctx the parse tree
	 */
	void enterEquation_expr(LustreParser.Equation_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code equation_expr}
	 * labeled alternative in {@link LustreParser#equation}.
	 * @param ctx the parse tree
	 */
	void exitEquation_expr(LustreParser.Equation_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code equation_state_machine}
	 * labeled alternative in {@link LustreParser#equation}.
	 * @param ctx the parse tree
	 */
	void enterEquation_state_machine(LustreParser.Equation_state_machineContext ctx);
	/**
	 * Exit a parse tree produced by the {@code equation_state_machine}
	 * labeled alternative in {@link LustreParser#equation}.
	 * @param ctx the parse tree
	 */
	void exitEquation_state_machine(LustreParser.Equation_state_machineContext ctx);
	/**
	 * Enter a parse tree produced by the {@code lhs_pair}
	 * labeled alternative in {@link LustreParser#lhs}.
	 * @param ctx the parse tree
	 */
	void enterLhs_pair(LustreParser.Lhs_pairContext ctx);
	/**
	 * Exit a parse tree produced by the {@code lhs_pair}
	 * labeled alternative in {@link LustreParser#lhs}.
	 * @param ctx the parse tree
	 */
	void exitLhs_pair(LustreParser.Lhs_pairContext ctx);
	/**
	 * Enter a parse tree produced by the {@code lhs_id_list}
	 * labeled alternative in {@link LustreParser#lhs}.
	 * @param ctx the parse tree
	 */
	void enterLhs_id_list(LustreParser.Lhs_id_listContext ctx);
	/**
	 * Exit a parse tree produced by the {@code lhs_id_list}
	 * labeled alternative in {@link LustreParser#lhs}.
	 * @param ctx the parse tree
	 */
	void exitLhs_id_list(LustreParser.Lhs_id_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#return}.
	 * @param ctx the parse tree
	 */
	void enterReturn(LustreParser.ReturnContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#return}.
	 * @param ctx the parse tree
	 */
	void exitReturn(LustreParser.ReturnContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#returns_var}.
	 * @param ctx the parse tree
	 */
	void enterReturns_var(LustreParser.Returns_varContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#returns_var}.
	 * @param ctx the parse tree
	 */
	void exitReturns_var(LustreParser.Returns_varContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#state_machine}.
	 * @param ctx the parse tree
	 */
	void enterState_machine(LustreParser.State_machineContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#state_machine}.
	 * @param ctx the parse tree
	 */
	void exitState_machine(LustreParser.State_machineContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#state_decl}.
	 * @param ctx the parse tree
	 */
	void enterState_decl(LustreParser.State_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#state_decl}.
	 * @param ctx the parse tree
	 */
	void exitState_decl(LustreParser.State_declContext ctx);
	/**
	 * Enter a parse tree produced by the {@code state_machine_data_def_equation}
	 * labeled alternative in {@link LustreParser#data_def}.
	 * @param ctx the parse tree
	 */
	void enterState_machine_data_def_equation(LustreParser.State_machine_data_def_equationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code state_machine_data_def_equation}
	 * labeled alternative in {@link LustreParser#data_def}.
	 * @param ctx the parse tree
	 */
	void exitState_machine_data_def_equation(LustreParser.State_machine_data_def_equationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code state_machine_data_def_local_block}
	 * labeled alternative in {@link LustreParser#data_def}.
	 * @param ctx the parse tree
	 */
	void enterState_machine_data_def_local_block(LustreParser.State_machine_data_def_local_blockContext ctx);
	/**
	 * Exit a parse tree produced by the {@code state_machine_data_def_local_block}
	 * labeled alternative in {@link LustreParser#data_def}.
	 * @param ctx the parse tree
	 */
	void exitState_machine_data_def_local_block(LustreParser.State_machine_data_def_local_blockContext ctx);
	/**
	 * Enter a parse tree produced by the {@code state_machine_transition_resume}
	 * labeled alternative in {@link LustreParser#transition}.
	 * @param ctx the parse tree
	 */
	void enterState_machine_transition_resume(LustreParser.State_machine_transition_resumeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code state_machine_transition_resume}
	 * labeled alternative in {@link LustreParser#transition}.
	 * @param ctx the parse tree
	 */
	void exitState_machine_transition_resume(LustreParser.State_machine_transition_resumeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code state_machine_transition_restart}
	 * labeled alternative in {@link LustreParser#transition}.
	 * @param ctx the parse tree
	 */
	void enterState_machine_transition_restart(LustreParser.State_machine_transition_restartContext ctx);
	/**
	 * Exit a parse tree produced by the {@code state_machine_transition_restart}
	 * labeled alternative in {@link LustreParser#transition}.
	 * @param ctx the parse tree
	 */
	void exitState_machine_transition_restart(LustreParser.State_machine_transition_restartContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_simple_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_simple_expr(LustreParser.Expr_simple_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_simple_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_simple_expr(LustreParser.Expr_simple_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_last_decl}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_last_decl(LustreParser.Expr_last_declContext ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_last_decl}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_last_decl(LustreParser.Expr_last_declContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_tempo_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_tempo_expr(LustreParser.Expr_tempo_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_tempo_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_tempo_expr(LustreParser.Expr_tempo_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_bool_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_bool_expr(LustreParser.Expr_bool_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_bool_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_bool_expr(LustreParser.Expr_bool_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_array_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_array_expr(LustreParser.Expr_array_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_array_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_array_expr(LustreParser.Expr_array_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_struct_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_struct_expr(LustreParser.Expr_struct_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_struct_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_struct_expr(LustreParser.Expr_struct_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_mixed_constructor}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_mixed_constructor(LustreParser.Expr_mixed_constructorContext ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_mixed_constructor}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_mixed_constructor(LustreParser.Expr_mixed_constructorContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_switch_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_switch_expr(LustreParser.Expr_switch_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_switch_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_switch_expr(LustreParser.Expr_switch_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_paren}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_paren(LustreParser.Expr_parenContext ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_paren}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_paren(LustreParser.Expr_parenContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_apply_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_apply_expr(LustreParser.Expr_apply_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_apply_expr}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_apply_expr(LustreParser.Expr_apply_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code expr_kind2}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr_kind2(LustreParser.Expr_kind2Context ctx);
	/**
	 * Exit a parse tree produced by the {@code expr_kind2}
	 * labeled alternative in {@link LustreParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr_kind2(LustreParser.Expr_kind2Context ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#list}.
	 * @param ctx the parse tree
	 */
	void enterList(LustreParser.ListContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#list}.
	 * @param ctx the parse tree
	 */
	void exitList(LustreParser.ListContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#kind2_expr}.
	 * @param ctx the parse tree
	 */
	void enterKind2_expr(LustreParser.Kind2_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#kind2_expr}.
	 * @param ctx the parse tree
	 */
	void exitKind2_expr(LustreParser.Kind2_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#activate_expr}.
	 * @param ctx the parse tree
	 */
	void enterActivate_expr(LustreParser.Activate_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#activate_expr}.
	 * @param ctx the parse tree
	 */
	void exitActivate_expr(LustreParser.Activate_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#restart_expr}.
	 * @param ctx the parse tree
	 */
	void enterRestart_expr(LustreParser.Restart_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#restart_expr}.
	 * @param ctx the parse tree
	 */
	void exitRestart_expr(LustreParser.Restart_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code tempo_expr_pre}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void enterTempo_expr_pre(LustreParser.Tempo_expr_preContext ctx);
	/**
	 * Exit a parse tree produced by the {@code tempo_expr_pre}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void exitTempo_expr_pre(LustreParser.Tempo_expr_preContext ctx);
	/**
	 * Enter a parse tree produced by the {@code tempo_expr_arrow_tempo}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void enterTempo_expr_arrow_tempo(LustreParser.Tempo_expr_arrow_tempoContext ctx);
	/**
	 * Exit a parse tree produced by the {@code tempo_expr_arrow_tempo}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void exitTempo_expr_arrow_tempo(LustreParser.Tempo_expr_arrow_tempoContext ctx);
	/**
	 * Enter a parse tree produced by the {@code tempo_expr_arrow}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void enterTempo_expr_arrow(LustreParser.Tempo_expr_arrowContext ctx);
	/**
	 * Exit a parse tree produced by the {@code tempo_expr_arrow}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void exitTempo_expr_arrow(LustreParser.Tempo_expr_arrowContext ctx);
	/**
	 * Enter a parse tree produced by the {@code tempo_expr_fby}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void enterTempo_expr_fby(LustreParser.Tempo_expr_fbyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code tempo_expr_fby}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void exitTempo_expr_fby(LustreParser.Tempo_expr_fbyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code tempo_expr_fby_noconst}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void enterTempo_expr_fby_noconst(LustreParser.Tempo_expr_fby_noconstContext ctx);
	/**
	 * Exit a parse tree produced by the {@code tempo_expr_fby_noconst}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void exitTempo_expr_fby_noconst(LustreParser.Tempo_expr_fby_noconstContext ctx);
	/**
	 * Enter a parse tree produced by the {@code tempo_expr_when}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void enterTempo_expr_when(LustreParser.Tempo_expr_whenContext ctx);
	/**
	 * Exit a parse tree produced by the {@code tempo_expr_when}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void exitTempo_expr_when(LustreParser.Tempo_expr_whenContext ctx);
	/**
	 * Enter a parse tree produced by the {@code tempo_expr_merge}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void enterTempo_expr_merge(LustreParser.Tempo_expr_mergeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code tempo_expr_merge}
	 * labeled alternative in {@link LustreParser#tempo_expr}.
	 * @param ctx the parse tree
	 */
	void exitTempo_expr_merge(LustreParser.Tempo_expr_mergeContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#bool_expr}.
	 * @param ctx the parse tree
	 */
	void enterBool_expr(LustreParser.Bool_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#bool_expr}.
	 * @param ctx the parse tree
	 */
	void exitBool_expr(LustreParser.Bool_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code array_expr_split}
	 * labeled alternative in {@link LustreParser#array_expr}.
	 * @param ctx the parse tree
	 */
	void enterArray_expr_split(LustreParser.Array_expr_splitContext ctx);
	/**
	 * Exit a parse tree produced by the {@code array_expr_split}
	 * labeled alternative in {@link LustreParser#array_expr}.
	 * @param ctx the parse tree
	 */
	void exitArray_expr_split(LustreParser.Array_expr_splitContext ctx);
	/**
	 * Enter a parse tree produced by the {@code array_expr_dynamic}
	 * labeled alternative in {@link LustreParser#array_expr}.
	 * @param ctx the parse tree
	 */
	void enterArray_expr_dynamic(LustreParser.Array_expr_dynamicContext ctx);
	/**
	 * Exit a parse tree produced by the {@code array_expr_dynamic}
	 * labeled alternative in {@link LustreParser#array_expr}.
	 * @param ctx the parse tree
	 */
	void exitArray_expr_dynamic(LustreParser.Array_expr_dynamicContext ctx);
	/**
	 * Enter a parse tree produced by the {@code array_expr_and}
	 * labeled alternative in {@link LustreParser#array_expr}.
	 * @param ctx the parse tree
	 */
	void enterArray_expr_and(LustreParser.Array_expr_andContext ctx);
	/**
	 * Exit a parse tree produced by the {@code array_expr_and}
	 * labeled alternative in {@link LustreParser#array_expr}.
	 * @param ctx the parse tree
	 */
	void exitArray_expr_and(LustreParser.Array_expr_andContext ctx);
	/**
	 * Enter a parse tree produced by the {@code array_expr_list}
	 * labeled alternative in {@link LustreParser#array_expr}.
	 * @param ctx the parse tree
	 */
	void enterArray_expr_list(LustreParser.Array_expr_listContext ctx);
	/**
	 * Exit a parse tree produced by the {@code array_expr_list}
	 * labeled alternative in {@link LustreParser#array_expr}.
	 * @param ctx the parse tree
	 */
	void exitArray_expr_list(LustreParser.Array_expr_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#struct_expr}.
	 * @param ctx the parse tree
	 */
	void enterStruct_expr(LustreParser.Struct_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#struct_expr}.
	 * @param ctx the parse tree
	 */
	void exitStruct_expr(LustreParser.Struct_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#mixed_constructor}.
	 * @param ctx the parse tree
	 */
	void enterMixed_constructor(LustreParser.Mixed_constructorContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#mixed_constructor}.
	 * @param ctx the parse tree
	 */
	void exitMixed_constructor(LustreParser.Mixed_constructorContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#label_expr}.
	 * @param ctx the parse tree
	 */
	void enterLabel_expr(LustreParser.Label_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#label_expr}.
	 * @param ctx the parse tree
	 */
	void exitLabel_expr(LustreParser.Label_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#index}.
	 * @param ctx the parse tree
	 */
	void enterIndex(LustreParser.IndexContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#index}.
	 * @param ctx the parse tree
	 */
	void exitIndex(LustreParser.IndexContext ctx);
	/**
	 * Enter a parse tree produced by the {@code mix_label}
	 * labeled alternative in {@link LustreParser#label_or_index}.
	 * @param ctx the parse tree
	 */
	void enterMix_label(LustreParser.Mix_labelContext ctx);
	/**
	 * Exit a parse tree produced by the {@code mix_label}
	 * labeled alternative in {@link LustreParser#label_or_index}.
	 * @param ctx the parse tree
	 */
	void exitMix_label(LustreParser.Mix_labelContext ctx);
	/**
	 * Enter a parse tree produced by the {@code mix_index}
	 * labeled alternative in {@link LustreParser#label_or_index}.
	 * @param ctx the parse tree
	 */
	void enterMix_index(LustreParser.Mix_indexContext ctx);
	/**
	 * Exit a parse tree produced by the {@code mix_index}
	 * labeled alternative in {@link LustreParser#label_or_index}.
	 * @param ctx the parse tree
	 */
	void exitMix_index(LustreParser.Mix_indexContext ctx);
	/**
	 * Enter a parse tree produced by the {@code switch_expr_ifelse}
	 * labeled alternative in {@link LustreParser#switch_expr}.
	 * @param ctx the parse tree
	 */
	void enterSwitch_expr_ifelse(LustreParser.Switch_expr_ifelseContext ctx);
	/**
	 * Exit a parse tree produced by the {@code switch_expr_ifelse}
	 * labeled alternative in {@link LustreParser#switch_expr}.
	 * @param ctx the parse tree
	 */
	void exitSwitch_expr_ifelse(LustreParser.Switch_expr_ifelseContext ctx);
	/**
	 * Enter a parse tree produced by the {@code switch_expr_case}
	 * labeled alternative in {@link LustreParser#switch_expr}.
	 * @param ctx the parse tree
	 */
	void enterSwitch_expr_case(LustreParser.Switch_expr_caseContext ctx);
	/**
	 * Exit a parse tree produced by the {@code switch_expr_case}
	 * labeled alternative in {@link LustreParser#switch_expr}.
	 * @param ctx the parse tree
	 */
	void exitSwitch_expr_case(LustreParser.Switch_expr_caseContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#case_expr}.
	 * @param ctx the parse tree
	 */
	void enterCase_expr(LustreParser.Case_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#case_expr}.
	 * @param ctx the parse tree
	 */
	void exitCase_expr(LustreParser.Case_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#pattern}.
	 * @param ctx the parse tree
	 */
	void enterPattern(LustreParser.PatternContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#pattern}.
	 * @param ctx the parse tree
	 */
	void exitPattern(LustreParser.PatternContext ctx);
	/**
	 * Enter a parse tree produced by the {@code apply_prefix}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void enterApply_prefix(LustreParser.Apply_prefixContext ctx);
	/**
	 * Exit a parse tree produced by the {@code apply_prefix}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void exitApply_prefix(LustreParser.Apply_prefixContext ctx);
	/**
	 * Enter a parse tree produced by the {@code apply_iterator}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void enterApply_iterator(LustreParser.Apply_iteratorContext ctx);
	/**
	 * Exit a parse tree produced by the {@code apply_iterator}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void exitApply_iterator(LustreParser.Apply_iteratorContext ctx);
	/**
	 * Enter a parse tree produced by the {@code apply_mapw}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void enterApply_mapw(LustreParser.Apply_mapwContext ctx);
	/**
	 * Exit a parse tree produced by the {@code apply_mapw}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void exitApply_mapw(LustreParser.Apply_mapwContext ctx);
	/**
	 * Enter a parse tree produced by the {@code apply_mapwI}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void enterApply_mapwI(LustreParser.Apply_mapwIContext ctx);
	/**
	 * Exit a parse tree produced by the {@code apply_mapwI}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void exitApply_mapwI(LustreParser.Apply_mapwIContext ctx);
	/**
	 * Enter a parse tree produced by the {@code apply_foldw}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void enterApply_foldw(LustreParser.Apply_foldwContext ctx);
	/**
	 * Exit a parse tree produced by the {@code apply_foldw}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void exitApply_foldw(LustreParser.Apply_foldwContext ctx);
	/**
	 * Enter a parse tree produced by the {@code apply_foldwi}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void enterApply_foldwi(LustreParser.Apply_foldwiContext ctx);
	/**
	 * Exit a parse tree produced by the {@code apply_foldwi}
	 * labeled alternative in {@link LustreParser#apply_expr}.
	 * @param ctx the parse tree
	 */
	void exitApply_foldwi(LustreParser.Apply_foldwiContext ctx);
	/**
	 * Enter a parse tree produced by the {@code perfix_ID}
	 * labeled alternative in {@link LustreParser#prefix_operator}.
	 * @param ctx the parse tree
	 */
	void enterPerfix_ID(LustreParser.Perfix_IDContext ctx);
	/**
	 * Exit a parse tree produced by the {@code perfix_ID}
	 * labeled alternative in {@link LustreParser#prefix_operator}.
	 * @param ctx the parse tree
	 */
	void exitPerfix_ID(LustreParser.Perfix_IDContext ctx);
	/**
	 * Enter a parse tree produced by the {@code prefix_unary}
	 * labeled alternative in {@link LustreParser#prefix_operator}.
	 * @param ctx the parse tree
	 */
	void enterPrefix_unary(LustreParser.Prefix_unaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code prefix_unary}
	 * labeled alternative in {@link LustreParser#prefix_operator}.
	 * @param ctx the parse tree
	 */
	void exitPrefix_unary(LustreParser.Prefix_unaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code prefix_binary}
	 * labeled alternative in {@link LustreParser#prefix_operator}.
	 * @param ctx the parse tree
	 */
	void enterPrefix_binary(LustreParser.Prefix_binaryContext ctx);
	/**
	 * Exit a parse tree produced by the {@code prefix_binary}
	 * labeled alternative in {@link LustreParser#prefix_operator}.
	 * @param ctx the parse tree
	 */
	void exitPrefix_binary(LustreParser.Prefix_binaryContext ctx);
	/**
	 * Enter a parse tree produced by the {@code perfix_make}
	 * labeled alternative in {@link LustreParser#prefix_operator}.
	 * @param ctx the parse tree
	 */
	void enterPerfix_make(LustreParser.Perfix_makeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code perfix_make}
	 * labeled alternative in {@link LustreParser#prefix_operator}.
	 * @param ctx the parse tree
	 */
	void exitPerfix_make(LustreParser.Perfix_makeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code perfix_flatten}
	 * labeled alternative in {@link LustreParser#prefix_operator}.
	 * @param ctx the parse tree
	 */
	void enterPerfix_flatten(LustreParser.Perfix_flattenContext ctx);
	/**
	 * Exit a parse tree produced by the {@code perfix_flatten}
	 * labeled alternative in {@link LustreParser#prefix_operator}.
	 * @param ctx the parse tree
	 */
	void exitPerfix_flatten(LustreParser.Perfix_flattenContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#prefix_unary_operator}.
	 * @param ctx the parse tree
	 */
	void enterPrefix_unary_operator(LustreParser.Prefix_unary_operatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#prefix_unary_operator}.
	 * @param ctx the parse tree
	 */
	void exitPrefix_unary_operator(LustreParser.Prefix_unary_operatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#prefix_binary_operator}.
	 * @param ctx the parse tree
	 */
	void enterPrefix_binary_operator(LustreParser.Prefix_binary_operatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#prefix_binary_operator}.
	 * @param ctx the parse tree
	 */
	void exitPrefix_binary_operator(LustreParser.Prefix_binary_operatorContext ctx);
	/**
	 * Enter a parse tree produced by the {@code iterator_map}
	 * labeled alternative in {@link LustreParser#iterator}.
	 * @param ctx the parse tree
	 */
	void enterIterator_map(LustreParser.Iterator_mapContext ctx);
	/**
	 * Exit a parse tree produced by the {@code iterator_map}
	 * labeled alternative in {@link LustreParser#iterator}.
	 * @param ctx the parse tree
	 */
	void exitIterator_map(LustreParser.Iterator_mapContext ctx);
	/**
	 * Enter a parse tree produced by the {@code iterator_fold}
	 * labeled alternative in {@link LustreParser#iterator}.
	 * @param ctx the parse tree
	 */
	void enterIterator_fold(LustreParser.Iterator_foldContext ctx);
	/**
	 * Exit a parse tree produced by the {@code iterator_fold}
	 * labeled alternative in {@link LustreParser#iterator}.
	 * @param ctx the parse tree
	 */
	void exitIterator_fold(LustreParser.Iterator_foldContext ctx);
	/**
	 * Enter a parse tree produced by the {@code iterator_mapi}
	 * labeled alternative in {@link LustreParser#iterator}.
	 * @param ctx the parse tree
	 */
	void enterIterator_mapi(LustreParser.Iterator_mapiContext ctx);
	/**
	 * Exit a parse tree produced by the {@code iterator_mapi}
	 * labeled alternative in {@link LustreParser#iterator}.
	 * @param ctx the parse tree
	 */
	void exitIterator_mapi(LustreParser.Iterator_mapiContext ctx);
	/**
	 * Enter a parse tree produced by the {@code iterator_foldi}
	 * labeled alternative in {@link LustreParser#iterator}.
	 * @param ctx the parse tree
	 */
	void enterIterator_foldi(LustreParser.Iterator_foldiContext ctx);
	/**
	 * Exit a parse tree produced by the {@code iterator_foldi}
	 * labeled alternative in {@link LustreParser#iterator}.
	 * @param ctx the parse tree
	 */
	void exitIterator_foldi(LustreParser.Iterator_foldiContext ctx);
	/**
	 * Enter a parse tree produced by the {@code iterator_mapfold}
	 * labeled alternative in {@link LustreParser#iterator}.
	 * @param ctx the parse tree
	 */
	void enterIterator_mapfold(LustreParser.Iterator_mapfoldContext ctx);
	/**
	 * Exit a parse tree produced by the {@code iterator_mapfold}
	 * labeled alternative in {@link LustreParser#iterator}.
	 * @param ctx the parse tree
	 */
	void exitIterator_mapfold(LustreParser.Iterator_mapfoldContext ctx);
	/**
	 * Enter a parse tree produced by the {@code simple_expr_unary_arith}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expr_unary_arith(LustreParser.Simple_expr_unary_arithContext ctx);
	/**
	 * Exit a parse tree produced by the {@code simple_expr_unary_arith}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expr_unary_arith(LustreParser.Simple_expr_unary_arithContext ctx);
	/**
	 * Enter a parse tree produced by the {@code simple_expr_paren}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expr_paren(LustreParser.Simple_expr_parenContext ctx);
	/**
	 * Exit a parse tree produced by the {@code simple_expr_paren}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expr_paren(LustreParser.Simple_expr_parenContext ctx);
	/**
	 * Enter a parse tree produced by the {@code simple_expr_type}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expr_type(LustreParser.Simple_expr_typeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code simple_expr_type}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expr_type(LustreParser.Simple_expr_typeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code simple_expr_struct}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expr_struct(LustreParser.Simple_expr_structContext ctx);
	/**
	 * Exit a parse tree produced by the {@code simple_expr_struct}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expr_struct(LustreParser.Simple_expr_structContext ctx);
	/**
	 * Enter a parse tree produced by the {@code simple_expr_bin_relation}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expr_bin_relation(LustreParser.Simple_expr_bin_relationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code simple_expr_bin_relation}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expr_bin_relation(LustreParser.Simple_expr_bin_relationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code simple_expr_atom}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expr_atom(LustreParser.Simple_expr_atomContext ctx);
	/**
	 * Exit a parse tree produced by the {@code simple_expr_atom}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expr_atom(LustreParser.Simple_expr_atomContext ctx);
	/**
	 * Enter a parse tree produced by the {@code simple_expr_bin_bool}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expr_bin_bool(LustreParser.Simple_expr_bin_boolContext ctx);
	/**
	 * Exit a parse tree produced by the {@code simple_expr_bin_bool}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expr_bin_bool(LustreParser.Simple_expr_bin_boolContext ctx);
	/**
	 * Enter a parse tree produced by the {@code simple_expr_id}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expr_id(LustreParser.Simple_expr_idContext ctx);
	/**
	 * Exit a parse tree produced by the {@code simple_expr_id}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expr_id(LustreParser.Simple_expr_idContext ctx);
	/**
	 * Enter a parse tree produced by the {@code simple_expr_bin_arith}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expr_bin_arith(LustreParser.Simple_expr_bin_arithContext ctx);
	/**
	 * Exit a parse tree produced by the {@code simple_expr_bin_arith}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expr_bin_arith(LustreParser.Simple_expr_bin_arithContext ctx);
	/**
	 * Enter a parse tree produced by the {@code simple_expr_array}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expr_array(LustreParser.Simple_expr_arrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code simple_expr_array}
	 * labeled alternative in {@link LustreParser#simple_expr}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expr_array(LustreParser.Simple_expr_arrayContext ctx);
	/**
	 * Enter a parse tree produced by the {@code unary_arith_op_sub}
	 * labeled alternative in {@link LustreParser#unary_arith_op}.
	 * @param ctx the parse tree
	 */
	void enterUnary_arith_op_sub(LustreParser.Unary_arith_op_subContext ctx);
	/**
	 * Exit a parse tree produced by the {@code unary_arith_op_sub}
	 * labeled alternative in {@link LustreParser#unary_arith_op}.
	 * @param ctx the parse tree
	 */
	void exitUnary_arith_op_sub(LustreParser.Unary_arith_op_subContext ctx);
	/**
	 * Enter a parse tree produced by the {@code unary_arith_op_add}
	 * labeled alternative in {@link LustreParser#unary_arith_op}.
	 * @param ctx the parse tree
	 */
	void enterUnary_arith_op_add(LustreParser.Unary_arith_op_addContext ctx);
	/**
	 * Exit a parse tree produced by the {@code unary_arith_op_add}
	 * labeled alternative in {@link LustreParser#unary_arith_op}.
	 * @param ctx the parse tree
	 */
	void exitUnary_arith_op_add(LustreParser.Unary_arith_op_addContext ctx);
	/**
	 * Enter a parse tree produced by the {@code unary_arith_op_not}
	 * labeled alternative in {@link LustreParser#unary_arith_op}.
	 * @param ctx the parse tree
	 */
	void enterUnary_arith_op_not(LustreParser.Unary_arith_op_notContext ctx);
	/**
	 * Exit a parse tree produced by the {@code unary_arith_op_not}
	 * labeled alternative in {@link LustreParser#unary_arith_op}.
	 * @param ctx the parse tree
	 */
	void exitUnary_arith_op_not(LustreParser.Unary_arith_op_notContext ctx);
	/**
	 * Enter a parse tree produced by the {@code bin_arith_op_add}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void enterBin_arith_op_add(LustreParser.Bin_arith_op_addContext ctx);
	/**
	 * Exit a parse tree produced by the {@code bin_arith_op_add}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void exitBin_arith_op_add(LustreParser.Bin_arith_op_addContext ctx);
	/**
	 * Enter a parse tree produced by the {@code bin_arith_op_sub}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void enterBin_arith_op_sub(LustreParser.Bin_arith_op_subContext ctx);
	/**
	 * Exit a parse tree produced by the {@code bin_arith_op_sub}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void exitBin_arith_op_sub(LustreParser.Bin_arith_op_subContext ctx);
	/**
	 * Enter a parse tree produced by the {@code bin_arith_op_mul}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void enterBin_arith_op_mul(LustreParser.Bin_arith_op_mulContext ctx);
	/**
	 * Exit a parse tree produced by the {@code bin_arith_op_mul}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void exitBin_arith_op_mul(LustreParser.Bin_arith_op_mulContext ctx);
	/**
	 * Enter a parse tree produced by the {@code bin_arith_op_divided}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void enterBin_arith_op_divided(LustreParser.Bin_arith_op_dividedContext ctx);
	/**
	 * Exit a parse tree produced by the {@code bin_arith_op_divided}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void exitBin_arith_op_divided(LustreParser.Bin_arith_op_dividedContext ctx);
	/**
	 * Enter a parse tree produced by the {@code bin_arith_op_mod}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void enterBin_arith_op_mod(LustreParser.Bin_arith_op_modContext ctx);
	/**
	 * Exit a parse tree produced by the {@code bin_arith_op_mod}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void exitBin_arith_op_mod(LustreParser.Bin_arith_op_modContext ctx);
	/**
	 * Enter a parse tree produced by the {@code bin_arith_op_div}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void enterBin_arith_op_div(LustreParser.Bin_arith_op_divContext ctx);
	/**
	 * Exit a parse tree produced by the {@code bin_arith_op_div}
	 * labeled alternative in {@link LustreParser#bin_arith_op}.
	 * @param ctx the parse tree
	 */
	void exitBin_arith_op_div(LustreParser.Bin_arith_op_divContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#bin_relation_op}.
	 * @param ctx the parse tree
	 */
	void enterBin_relation_op(LustreParser.Bin_relation_opContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#bin_relation_op}.
	 * @param ctx the parse tree
	 */
	void exitBin_relation_op(LustreParser.Bin_relation_opContext ctx);
	/**
	 * Enter a parse tree produced by {@link LustreParser#bin_bool_op}.
	 * @param ctx the parse tree
	 */
	void enterBin_bool_op(LustreParser.Bin_bool_opContext ctx);
	/**
	 * Exit a parse tree produced by {@link LustreParser#bin_bool_op}.
	 * @param ctx the parse tree
	 */
	void exitBin_bool_op(LustreParser.Bin_bool_opContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_BOOL}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void enterAtom_BOOL(LustreParser.Atom_BOOLContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_BOOL}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void exitAtom_BOOL(LustreParser.Atom_BOOLContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_CHAR}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void enterAtom_CHAR(LustreParser.Atom_CHARContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_CHAR}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void exitAtom_CHAR(LustreParser.Atom_CHARContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_INTEGER}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void enterAtom_INTEGER(LustreParser.Atom_INTEGERContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_INTEGER}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void exitAtom_INTEGER(LustreParser.Atom_INTEGERContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_UINT}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void enterAtom_UINT(LustreParser.Atom_UINTContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_UINT}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void exitAtom_UINT(LustreParser.Atom_UINTContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_FLOAT}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void enterAtom_FLOAT(LustreParser.Atom_FLOATContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_FLOAT}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void exitAtom_FLOAT(LustreParser.Atom_FLOATContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_REAL}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void enterAtom_REAL(LustreParser.Atom_REALContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_REAL}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void exitAtom_REAL(LustreParser.Atom_REALContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_USHORT}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void enterAtom_USHORT(LustreParser.Atom_USHORTContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_USHORT}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void exitAtom_USHORT(LustreParser.Atom_USHORTContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_SHORT}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void enterAtom_SHORT(LustreParser.Atom_SHORTContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_SHORT}
	 * labeled alternative in {@link LustreParser#atom}.
	 * @param ctx the parse tree
	 */
	void exitAtom_SHORT(LustreParser.Atom_SHORTContext ctx);
}