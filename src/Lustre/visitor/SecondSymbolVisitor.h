

#ifndef QL2C_SECONDSYMBOLVISITOR_H
#define QL2C_SECONDSYMBOLVISITOR_H


#include "../generated/LustreBaseVisitor.h"
#include "../../SymbolTable/Scope/GlobalScope.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"

class SecondSymbolVisitor : public LustreBaseVisitor {
    /**
     * 此Visit是在SymbolVisitor的基础上进行二次遍历
     * 解决：一次遍历解决不了的先计算后定义的问题:
     */
public:
    std::shared_ptr<antlr4::tree::ParseTreeProperty<std::shared_ptr<Scope>>> scopes;
    std::shared_ptr<GlobalScope> globals;
    std::shared_ptr<Scope> currentScope;

    //存入匿名结构体的名字,以便语法转换时定义type使用
    static std::vector<std::string> structVector;
    //用于验证const指向时是否存在循环回路
    std::vector<std::string> constPointVector;

//    std::shared_ptr<ConstSymbol> currentConstSymbol;
    SecondSymbolVisitor(std::shared_ptr<antlr4::tree::ParseTreeProperty<std::shared_ptr<Scope>>> scopes,
                        std::shared_ptr<GlobalScope> globals);

    std::any visitProgram(LustreParser::ProgramContext *ctx) override;

    std::any visitUser_op_decl(LustreParser::User_op_declContext *ctx) override;

    std::any visitLocal_block(LustreParser::Local_blockContext *ctx) override;

    std::any visitConst_bin_arith(LustreParser::Const_bin_arithContext *ctx) override;

    /**
     * Const_decl:此处是Const递归起点
     * 测试文件：./srs_l2c_syn_010_003/srs_l2c_syn_010_003.Lustre
     * 如：   myConst1 : int = myConst2 * 123 - (  8 + 23);
     *       myConst2 : int = 23;
     * 当值为后定义时的解决方案，在myConst1访问到他的子节点myConst2时，
     * 会通过myConst2的ctx访问到本方法从而先算出myConst2的值，再得出myConst1的值
     *
     *
     */
    std::any visitConst_decl(LustreParser::Const_declContext *ctx) override;

    std::any visitConst_id(LustreParser::Const_idContext *ctx) override;

    std::any visitAtom_REAL(LustreParser::Atom_REALContext *ctx) override;

    std::any visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) override;

    std::any visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) override;

    std::any visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) override;

    std::any visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) override;

    std::any visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) override;

    std::any visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) override;

    std::any visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) override;

    std::any visitConst_atom(LustreParser::Const_atomContext *ctx) override;

    std::any visitConst_paren(LustreParser::Const_parenContext *ctx) override;

    std::any visitConst_bin_bool(LustreParser::Const_bin_boolContext *ctx) override;

    std::any visitConst_unary_arith(LustreParser::Const_unary_arithContext *ctx) override;

    std::any visitConst_bin_relation(LustreParser::Const_bin_relationContext *ctx) override;

    std::any visitConst_array(LustreParser::Const_arrayContext *ctx) override;

    std::any visitConst_struct(LustreParser::Const_structContext *ctx) override;

    std::any visitConst_list(LustreParser::Const_listContext *ctx) override;

    std::any visitConst_label_expr(LustreParser::Const_label_exprContext *ctx) override;

    std::any visitType_id(LustreParser::Type_idContext *ctx) override;

    std::any visitType_array(LustreParser::Type_arrayContext *ctx) override;

    std::any visitType_uint(LustreParser::Type_uintContext *ctx) override;

    std::any visitType_ushort(LustreParser::Type_ushortContext *ctx) override;

    std::any visitType_short(LustreParser::Type_shortContext *ctx) override;

    std::any visitType_char(LustreParser::Type_charContext *ctx) override;

    std::any visitType_real(LustreParser::Type_realContext *ctx) override;

    std::any visitType_bool(LustreParser::Type_boolContext *ctx) override;

    std::any visitType_int(LustreParser::Type_intContext *ctx) override;

    std::any visitType_float(LustreParser::Type_floatContext *ctx) override;

    std::any visitType_def_type(LustreParser::Type_def_typeContext *ctx) override;

    std::any visitType_decl(LustreParser::Type_declContext *ctx) override;

    std::any visitType_struct(LustreParser::Type_structContext *ctx) override;

    std::any visitField_decl(LustreParser::Field_declContext *ctx) override;

    std::any visitVar_decls(LustreParser::Var_declsContext *ctx) override;

    std::any visitEquation_state_machine(LustreParser::Equation_state_machineContext *ctx) override;
    std::any visitState_machine(LustreParser::State_machineContext *ctx) override;
    std::any visitState_decl(LustreParser::State_declContext *ctx) override;
    std::any visitUnless_tran(LustreParser::Unless_tranContext *ctx) override;
    std::any visitUntil_tran(LustreParser::Until_tranContext *ctx) override;
    std::any visitState_machine_data_def_equation(LustreParser::State_machine_data_def_equationContext *ctx) override;
    std::any visitState_machine_data_def_local_block(LustreParser::State_machine_data_def_local_blockContext *ctx) override;
    std::any visitState_machine_transition_restart(LustreParser::State_machine_transition_restartContext *ctx) override;
    std::any visitState_machine_transition_resume(LustreParser::State_machine_transition_resumeContext *ctx) override;

    std::any visitReturn(LustreParser::ReturnContext *ctx) override;
    std::any visitReturns_var(LustreParser::Returns_varContext *ctx) override;

    std::shared_ptr<TypeDefSymbol>
    setTypeToRefGlobalType(std::shared_ptr<GlobalScope> globals, std::shared_ptr<Scope> currentScope,
                           std::shared_ptr<TypeDefSymbol> currentTypeSymbol);

    std::shared_ptr<TypeDefSymbol>
    setNewStructType(std::shared_ptr<GlobalScope> globals1, std::shared_ptr<Scope> currentScope1,
                     std::shared_ptr<TypeDefSymbol> currentTypeSymbol);


};

#endif //QL2C_SECONDSYMBOLVISITOR_H
