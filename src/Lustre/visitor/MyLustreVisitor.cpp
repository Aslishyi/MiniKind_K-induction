//
// Created by jack on 23-11-16.
//

#include "MyLustreVisitor.h"
#include "../tool/LustreVisitorTool.h"



//MyLustreVisitor::MyLustreVisitor() :scopes(std::make_shared<antlr4::tree::ParseTreeProperty<std::shared_ptr<Scope>>>()) {
//
//}
MyLustreVisitor::MyLustreVisitor(std::shared_ptr<antlr4::tree::ParseTreeProperty<std::shared_ptr<Scope>>> scopes,
                                 std::shared_ptr<GlobalScope> globals) : scopes(std::move(scopes)),
                                                                         globals(std::move(globals)) {}
#define _tab "    "
#define myvis(x) std::any_cast<std::string>(visit(x))

std::any MyLustreVisitor::visitProgram(LustreParser::ProgramContext *ctx) {
    //Program对下面的所有返回值做输出保存工作
    //  设置当前scope为globals
    currentScope = globals;
    //TODO:只进行decls访问
    std::string declsString;
    for (auto decl: ctx->decls()) {
        auto declVisitor = LustreBaseVisitor::visit(decl);

        declsString.append(std::any_cast<std::string>(declVisitor));

    }
    //打印符号表
    std::cout << "globals: " << globals->toString() << std::endl;
    std::cout << declsString << "\n";
    //符号表测试使用：
    //    auto testResole=currentScope->resolve("c1");
    //    std::cout<<"******************************\n";
    //    std::cout<<testResole->getToken()->getLine();
    //    std::cout<<testResole->toAstString();
    //
    //    std::cout<<"\n******************************";

    return std::string("");
}

std::any MyLustreVisitor::visitDecls_type(LustreParser::Decls_typeContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->type_block()));
}

std::any MyLustreVisitor::visitDecls_const(LustreParser::Decls_constContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->const_block()));
}

//导入节点无需改动，原样返回
std::any MyLustreVisitor::visitDecls_import_op(LustreParser::Decls_import_opContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitDecls_user_op(LustreParser::Decls_user_opContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->user_op_decl()));
}
std::any MyLustreVisitor::visitDecls_kind2(LustreParser::Decls_kind2Context *ctx){
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitDecls_mode(LustreParser::Decls_modeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitDecls_ghost_var(LustreParser::Decls_ghost_varContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitDecls_assume(LustreParser::Decls_assumeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitDecls_guarantee(LustreParser::Decls_guaranteeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitType_block(LustreParser::Type_blockContext *ctx) {
    std::string declsString;
    for (auto decl: ctx->type_decl()) {
        auto declVisitor = LustreBaseVisitor::visit(decl);
        declsString.append("type ");
        declsString.append(std::any_cast<std::string>(declVisitor));
        declsString.append("\n");
    }
    return declsString;
}

std::any MyLustreVisitor::visitType_decl(LustreParser::Type_declContext *ctx) {
    std::string declString;
    auto idString = ctx->ID()->getText();
    declString.append(idString + " = ");
    if (ctx->type_def()) {
        auto declVisitor = LustreBaseVisitor::visit(ctx->type_def());
        declString.append(std::any_cast<std::string>(declVisitor));

        declString.append(";");

    }
    return declString;
}

std::any MyLustreVisitor::visitType_def_type(LustreParser::Type_def_typeContext *ctx) {
    return myvis(ctx->type());
}

std::any MyLustreVisitor::visitType_def_enum(LustreParser::Type_def_enumContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitType_int(LustreParser::Type_intContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_bool(LustreParser::Type_boolContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_char(LustreParser::Type_charContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_short(LustreParser::Type_shortContext *ctx) {
    return std::string("int16");
}

std::any MyLustreVisitor::visitType_ushort(LustreParser::Type_ushortContext *ctx) {
    return std::string("uint16");
}

std::any MyLustreVisitor::visitType_uint(LustreParser::Type_uintContext *ctx) {
    return std::string("uint32");
}

std::any MyLustreVisitor::visitType_float(LustreParser::Type_floatContext *ctx) {
    //TODO
    return std::string("real");
}

std::any MyLustreVisitor::visitType_real(LustreParser::Type_realContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_id(LustreParser::Type_idContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_struct(LustreParser::Type_structContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitType_array(LustreParser::Type_arrayContext *ctx) {
    std::string res;
    res.append(std::any_cast<std::string>(visit(ctx->type())));
    res.append("^(");
    res.append(std::any_cast<std::string>(visit(ctx->const_expr())));
    res.append(")");
    return res;
}

std::any MyLustreVisitor::visitConst_block(LustreParser::Const_blockContext *ctx) {
    std::string declString("const\n");
    for (auto decl: ctx->const_decl()) {
        auto declVisitor = LustreBaseVisitor::visit(decl);
        declString.append(_tab);
        declString.append(std::any_cast<std::string>(declVisitor));
        declString.append("\n");
    }
    return declString;
}

std::any MyLustreVisitor::visitConst_decl(LustreParser::Const_declContext *ctx) {
    std::string declString;
    auto idString = ctx->ID()->getText();
    declString.append(idString);
    auto constExprVisitor = visit(ctx->const_expr());

    if (ctx->type()) {
        auto typeVisitor = visit(ctx->type());
        declString.append(" : ");
        declString.append(std::any_cast<std::string>(typeVisitor));
    }
    declString.append(" = ");
    declString.append(std::any_cast<std::string>(constExprVisitor));
    declString.append(";");
    return declString;
}

std::any MyLustreVisitor::visitConst_id(LustreParser::Const_idContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitConst_atom(LustreParser::Const_atomContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->atom()));
}

std::any MyLustreVisitor::visitConst_unary_arith(LustreParser::Const_unary_arithContext *ctx) {
    if(ctx->unary_arith_op()->getText()[0] == '+') {        //省略一元运算符的 +
        return std::string(std::any_cast<std::string>(visit(ctx->const_expr())));
    } else {
        return std::string(LustreVisitorTool::getFullText(ctx));
    }
}

std::any MyLustreVisitor::visitConst_paren(LustreParser::Const_parenContext *ctx) {
    return "( " + std::any_cast<std::string>(visit(ctx->const_expr())) + ")";
}

std::any MyLustreVisitor::visitConst_bin_arith(LustreParser::Const_bin_arithContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[0]))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->bin_arith_op()))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[1]))));
    return res;
}

std::any MyLustreVisitor::visitConst_bin_bool(LustreParser::Const_bin_boolContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[0]))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->bin_bool_op()))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[1]))));
    return res;
}

std::any MyLustreVisitor::visitConst_bin_relation(LustreParser::Const_bin_relationContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[0]))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->bin_relation_op()))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()[1]))));
    return res;
}

std::any MyLustreVisitor::visitConst_array(LustreParser::Const_arrayContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitConst_struct(LustreParser::Const_structContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitVar_decls(LustreParser::Var_declsContext *ctx) {
    std::string res;
    for(auto id: ctx->ID()) {
        res.append(id->getText()).append(",");
    }
    res.pop_back();
    res.append(" : ");
    res.append(std::any_cast<std::string>(visit(ctx->type())));
    if(ctx->when_decl()) {
        res.append(" ").append(std::any_cast<std::string>(visit(ctx->when_decl())));
    }
    if(ctx->last_decl()) {
        res.append(" ").append(std::any_cast<std::string>(visit(ctx->last_decl())));
    }
    return res;
}
std::any MyLustreVisitor::visitClock_id(LustreParser::Clock_idContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitClock_not(LustreParser::Clock_notContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitUser_op_decl(LustreParser::User_op_declContext *ctx) {
    std::string res = ctx->op_kind()->getText();
    res.append(" ");
    res.append(ctx->ID()->getText());
    //    if(ctx->static_parameters()) {
    //        res.append(" ");
    //        res.append(std::any_cast<std::string>(ctx->static_parameters()));
    //        res.append(" ");
    //    }
    auto in_params = LustreBaseVisitor::visit(ctx->params()[0]);
    res.append(std::any_cast<std::string>(in_params));
    res.append(" returns ");
    auto out_params = LustreBaseVisitor::visit(ctx->params()[1]);
    res.append(std::any_cast<std::string>(out_params));
    res.append(";\n");
    res.append(std::any_cast<std::string>(visit(ctx->op_body())));
    //std::cout <<"? : "<< res << std::endl;

    return res;
}

std::any MyLustreVisitor::visitOp_kind_funtion(LustreParser::Op_kind_funtionContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitOp_kind_node(LustreParser::Op_kind_nodeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitParams(LustreParser::ParamsContext *ctx) {
    std::string res = "(";
    for(auto var_decls : ctx->var_decls()) {
        res.append(std::any_cast<std::string>(visit(var_decls))).append("; ");
    }
    res.pop_back();
    res.back() = ')';
    return res;
}

std::any MyLustreVisitor::visitOp_body_null(LustreParser::Op_body_nullContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitOp_body_ctx(LustreParser::Op_body_ctxContext *ctx) {
    std::string res;
    if(ctx->local_block()) {
        res.append(std::any_cast<std::string>(visit(ctx->local_block())));
        res.append(" ");
    }
    res.append("let\n");
    for(auto let_block: ctx->let_block()) {
        res.append(_tab);
        auto t = visit(let_block);
        try {
            res.append(std::any_cast<std::string>(t));
        } catch (const std::bad_any_cast&) {

        }
        res.append(";\n");
    }
    res.append("tel\n");

    return res;
}

std::any MyLustreVisitor::visitLet_block_equation(LustreParser::Let_block_equationContext *ctx) {
    return visit(ctx->equation());
}
std::any MyLustreVisitor::visitLet_block_kind2_frame_block(LustreParser::Let_block_kind2_frame_blockContext *ctx){
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitLet_block_kind2_kind2_Statement(LustreParser::Let_block_kind2_kind2_StatementContext *ctx){
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitEquation_expr(LustreParser::Equation_exprContext *ctx) {
    auto lhs = std::any_cast<std::string>(visit(ctx->lhs()));
    auto expr = std::any_cast<std::string>(visit(ctx->expr()));
    return std::make_pair(lhs, expr);
    //    std::string res;
//    res.append(std::any_cast<std::string>(visit(ctx->lhs())));
//    res.append(" = ");
//    res.append(std::any_cast<std::string>(visit(ctx->expr())));
//    return res;
}

std::any MyLustreVisitor::visitEquation_state_machine(LustreParser::Equation_state_machineContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitLhs_pair(LustreParser::Lhs_pairContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitLhs_id_list(LustreParser::Lhs_id_listContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitState_machine_data_def_equation(LustreParser::State_machine_data_def_equationContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitState_machine_data_def_local_block(LustreParser::State_machine_data_def_local_blockContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitState_machine_transition_resume(LustreParser::State_machine_transition_resumeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitState_machine_transition_restart(LustreParser::State_machine_transition_restartContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitExpr_simple_expr(LustreParser::Expr_simple_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->simple_expr()));
}

std::any MyLustreVisitor::visitExpr_last_decl(LustreParser::Expr_last_declContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitExpr_tempo_expr(LustreParser::Expr_tempo_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->tempo_expr()));
}

std::any MyLustreVisitor::visitExpr_bool_expr(LustreParser::Expr_bool_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->bool_expr()));
}

std::any MyLustreVisitor::visitExpr_array_expr(LustreParser::Expr_array_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->array_expr()));
}

std::any MyLustreVisitor::visitExpr_struct_expr(LustreParser::Expr_struct_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->struct_expr()));
}

std::any MyLustreVisitor::visitExpr_mixed_constructor(LustreParser::Expr_mixed_constructorContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->mixed_constructor()));
}

std::any MyLustreVisitor::visitExpr_switch_expr(LustreParser::Expr_switch_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->switch_expr()));
}

std::any MyLustreVisitor::visitExpr_paren(LustreParser::Expr_parenContext *ctx) {
    return "(" + myvis(ctx->expr()) + ")";
}

std::any MyLustreVisitor::visitExpr_apply_expr(LustreParser::Expr_apply_exprContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->apply_expr()));
}

std::any MyLustreVisitor::visitExpr_kind2(LustreParser::Expr_kind2Context *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitTempo_expr_pre(LustreParser::Tempo_expr_preContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitTempo_expr_arrow(LustreParser::Tempo_expr_arrowContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitTempo_expr_fby(LustreParser::Tempo_expr_fbyContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitTempo_expr_fby_noconst(LustreParser::Tempo_expr_fby_noconstContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitTempo_expr_when(LustreParser::Tempo_expr_whenContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitTempo_expr_merge(LustreParser::Tempo_expr_mergeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitArray_expr_split(LustreParser::Array_expr_splitContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitArray_expr_dynamic(LustreParser::Array_expr_dynamicContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitArray_expr_and(LustreParser::Array_expr_andContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitArray_expr_list(LustreParser::Array_expr_listContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitMix_label(LustreParser::Mix_labelContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitMix_index(LustreParser::Mix_indexContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitSwitch_expr_ifelse(LustreParser::Switch_expr_ifelseContext *ctx) {
    std::string res;
    res.append("if ").append(myvis(ctx->simple_expr()[0]));
    res.append(" then ").append(myvis(ctx->simple_expr()[1]));
    res.append(" else ").append(myvis(ctx->simple_expr()[2]));
    return res;
}
std::any MyLustreVisitor::visitSwitch_expr_case(LustreParser::Switch_expr_caseContext *ctx) {
    std::string res;
    res.append("(case ").append(myvis(ctx->simple_expr())).append(" of\n");
    for(auto case_expr : ctx->case_expr()) {
        res.append(_tab).append(myvis(case_expr)).append("\n");
    }
    res.pop_back(); //去除最后一个表达式的换行
    res.append(")");
    return res;
}
std::any MyLustreVisitor::visitCase_expr(LustreParser::Case_exprContext *ctx) {
    return "| " + ctx->pattern()->getText() + " : " + myvis(ctx->simple_expr());
}
std::any MyLustreVisitor::visitApply_prefix(LustreParser::Apply_prefixContext *ctx) {
    return myvis(ctx->prefix_operator()) + "(" + myvis(ctx->list()) + ")";
}
std::any MyLustreVisitor::visitApply_iterator(LustreParser::Apply_iteratorContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitApply_mapw(LustreParser::Apply_mapwContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitApply_mapwI(LustreParser::Apply_mapwIContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitApply_foldw(LustreParser::Apply_foldwContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitApply_foldwi(LustreParser::Apply_foldwiContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitPerfix_ID(LustreParser::Perfix_IDContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitPrefix_unary(LustreParser::Prefix_unaryContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitPrefix_binary(LustreParser::Prefix_binaryContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitPerfix_make(LustreParser::Perfix_makeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitPerfix_flatten(LustreParser::Perfix_flattenContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitIterator_map(LustreParser::Iterator_mapContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitIterator_fold(LustreParser::Iterator_foldContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitIterator_mapi(LustreParser::Iterator_mapiContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitIterator_foldi(LustreParser::Iterator_foldiContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitIterator_mapfold(LustreParser::Iterator_mapfoldContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitIterator_red(LustreParser::Iterator_redContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitIterator_fill(LustreParser::Iterator_fillContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitIterator_fillred(LustreParser::Iterator_fillredContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitIterator_boolred(LustreParser::Iterator_boolredContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitSimple_expr_id(LustreParser::Simple_expr_idContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitSimple_expr_atom(LustreParser::Simple_expr_atomContext *ctx) {
    return std::any_cast<std::string>(visit(ctx->atom()));
}
std::any MyLustreVisitor::visitSimple_expr_paren(LustreParser::Simple_expr_parenContext *ctx) {
    std::string res("(");
    for(auto sim_expr : ctx->simple_expr()) {
        res.append(myvis(sim_expr)).append(", ");
    }
    res.pop_back();res.pop_back();  //去除最后多余的 ", "
    res.append(")");
    return res;
}
std::any MyLustreVisitor::visitSimple_expr_array(LustreParser::Simple_expr_arrayContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->simple_expr()))));
    res.append("[");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->const_expr()))));
    res.append("]");
    return res;
}

std::any MyLustreVisitor::visitSimple_expr_struct(LustreParser::Simple_expr_structContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitSimple_expr_unary_arith(LustreParser::Simple_expr_unary_arithContext *ctx) {
    if(ctx->unary_arith_op()->getText()[0] == '+') {        //省略一元运算符的 +
        return std::string(std::any_cast<std::string>(visit(ctx->simple_expr())));
    } else {
        return std::string(LustreVisitorTool::getFullText(ctx));
    }
}

std::any MyLustreVisitor::visitSimple_expr_bin_arith(LustreParser::Simple_expr_bin_arithContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->simple_expr()[0]))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->bin_arith_op()))));
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->simple_expr()[1]))));
    return res;
}

std::any MyLustreVisitor::visitSimple_expr_bin_bool(LustreParser::Simple_expr_bin_boolContext *ctx) {
    std::string res;
    res.append(std::string(std::any_cast<std::string>(visit(ctx->simple_expr()[0]))));
    res.append(" ");
    res.append(ctx->bin_bool_op()->getText());      //and、or、xor
    res.append(" ");
    res.append(std::string(std::any_cast<std::string>(visit(ctx->simple_expr()[1]))));
    return res;
}

std::any MyLustreVisitor::visitSimple_expr_bin_relation(LustreParser::Simple_expr_bin_relationContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitSimple_expr_type(LustreParser::Simple_expr_typeContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitUnary_arith_op_sub(LustreParser::Unary_arith_op_subContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitUnary_arith_op_add(LustreParser::Unary_arith_op_addContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitUnary_arith_op_not(LustreParser::Unary_arith_op_notContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}
std::any MyLustreVisitor::visitBin_arith_op_add(LustreParser::Bin_arith_op_addContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_sub(LustreParser::Bin_arith_op_subContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_mul(LustreParser::Bin_arith_op_mulContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_divided(LustreParser::Bin_arith_op_dividedContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_mod(LustreParser::Bin_arith_op_modContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitBin_arith_op_div(LustreParser::Bin_arith_op_divContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) {
    std::string res = LustreVisitorTool::getFullText(ctx);
    res.pop_back();     //删除结尾的u
    return "(uint32 " + res + ")";
}

std::any MyLustreVisitor::visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) {
    //TODO 目前实现为转换成real
    std::string res = LustreVisitorTool::getFullText(ctx);
    res.pop_back();     //删除结尾的f
    return res;
}

std::any MyLustreVisitor::visitAtom_REAL(LustreParser::Atom_REALContext *ctx) {
    return std::string(LustreVisitorTool::getFullText(ctx));
}

std::any MyLustreVisitor::visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) {
    std::string res = LustreVisitorTool::getFullText(ctx);
    res.pop_back(); res.pop_back();    //删除结尾的us
    return "(uint16 " + res + ")";
}

std::any MyLustreVisitor::visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) {
    std::string res = LustreVisitorTool::getFullText(ctx);
    res.pop_back();      //删除结尾的s
    return "(int16 " + res + ")";
}