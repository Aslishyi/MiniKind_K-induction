
// Generated from Lustre.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  LustreParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, T__51 = 52, T__52 = 53, T__53 = 54, T__54 = 55, T__55 = 56, 
    T__56 = 57, T__57 = 58, T__58 = 59, T__59 = 60, T__60 = 61, T__61 = 62, 
    T__62 = 63, T__63 = 64, T__64 = 65, T__65 = 66, T__66 = 67, T__67 = 68, 
    T__68 = 69, T__69 = 70, T__70 = 71, T__71 = 72, T__72 = 73, T__73 = 74, 
    T__74 = 75, T__75 = 76, T__76 = 77, T__77 = 78, T__78 = 79, T__79 = 80, 
    T__80 = 81, T__81 = 82, T__82 = 83, T__83 = 84, T__84 = 85, T__85 = 86, 
    T__86 = 87, T__87 = 88, T__88 = 89, T__89 = 90, T__90 = 91, T__91 = 92, 
    T__92 = 93, T__93 = 94, T__94 = 95, T__95 = 96, T__96 = 97, T__97 = 98, 
    T__98 = 99, T__99 = 100, T__100 = 101, T__101 = 102, T__102 = 103, T__103 = 104, 
    T__104 = 105, T__105 = 106, T__106 = 107, T__107 = 108, T__108 = 109, 
    T__109 = 110, T__110 = 111, T__111 = 112, T__112 = 113, T__113 = 114, 
    T__114 = 115, T__115 = 116, T__116 = 117, T__117 = 118, T__118 = 119, 
    T__119 = 120, T__120 = 121, T__121 = 122, T__122 = 123, T__123 = 124, 
    T__124 = 125, T__125 = 126, T__126 = 127, T__127 = 128, T__128 = 129, 
    T__129 = 130, T__130 = 131, T__131 = 132, T__132 = 133, T__133 = 134, 
    T__134 = 135, T__135 = 136, T__136 = 137, T__137 = 138, BOOL = 139, 
    INTEGER = 140, UINT = 141, REAL = 142, CHAR = 143, FLOAT = 144, USHORT = 145, 
    SHORT = 146, ID = 147, SL_COMMENT = 148, ML_COMMENT = 149, MLX_COMMENT = 150, 
    PRAGMA = 151, STRING = 152, WS = 153, ERROR = 154
  };

  enum {
    RuleProgram = 0, RuleInclude = 1, RulePack_list = 2, RuleOne_park = 3, 
    RulePack_decl = 4, RuleUses = 5, RulePack_eq = 6, RuleProvides = 7, 
    RuleProvide = 8, RuleModel_decl = 9, RuleUser_op_provide = 10, RuleDecls = 11, 
    RuleKind2_decl = 12, RuleMode_decl = 13, RuleRequirement = 14, RuleAssurance = 15, 
    RuleVar_decl = 16, RuleAssume_decl = 17, RuleGuarantee_decl = 18, RuleType_block = 19, 
    RuleType_decl = 20, RuleType_def = 21, RuleType = 22, RuleField_decl = 23, 
    RuleConst_block = 24, RuleConst_decl = 25, RuleConst_expr = 26, RuleConst_list = 27, 
    RuleConst_label_expr = 28, RuleVar_decls = 29, RuleWhen_decl = 30, RuleClock_expr = 31, 
    RuleLast_decl = 32, RuleUser_op_decl = 33, RuleOp_kind = 34, RuleParams = 35, 
    RuleOp_body = 36, RuleContract_statement = 37, RuleMerge_decl = 38, 
    RuleLet_block = 39, RuleLocal_block = 40, RuleKind2_Statement = 41, 
    RuleMainStatement = 42, RulePropertyStatement = 43, RuleCheckStatement = 44, 
    RuleFrame_block = 45, RuleFrame_init = 46, RuleFrame_body = 47, RuleImport_op_decl = 48, 
    RuleEquation = 49, RuleLhs = 50, RuleReturn = 51, RuleReturns_var = 52, 
    RuleState_machine = 53, RuleState_decl = 54, RuleData_def = 55, RuleTransition = 56, 
    RuleExpr = 57, RuleList = 58, RuleKind2_expr = 59, RuleActivate_expr = 60, 
    RuleRestart_expr = 61, RuleTempo_expr = 62, RuleBool_expr = 63, RuleArray_expr = 64, 
    RuleStruct_expr = 65, RuleMixed_constructor = 66, RuleLabel_expr = 67, 
    RuleIndex = 68, RuleLabel_or_index = 69, RuleSwitch_expr = 70, RuleCase_expr = 71, 
    RulePattern = 72, RuleApply_expr = 73, RulePrefix_operator = 74, RulePrefix_unary_operator = 75, 
    RulePrefix_binary_operator = 76, RuleIterator = 77, RuleIterator_lv6 = 78, 
    RuleSimple_expr = 79, RuleUnary_arith_op = 80, RuleBin_arith_op = 81, 
    RuleBin_relation_op = 82, RuleBin_bool_op = 83, RuleAtom = 84
  };

  explicit LustreParser(antlr4::TokenStream *input);

  LustreParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~LustreParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class IncludeContext;
  class Pack_listContext;
  class One_parkContext;
  class Pack_declContext;
  class UsesContext;
  class Pack_eqContext;
  class ProvidesContext;
  class ProvideContext;
  class Model_declContext;
  class User_op_provideContext;
  class DeclsContext;
  class Kind2_declContext;
  class Mode_declContext;
  class RequirementContext;
  class AssuranceContext;
  class Var_declContext;
  class Assume_declContext;
  class Guarantee_declContext;
  class Type_blockContext;
  class Type_declContext;
  class Type_defContext;
  class TypeContext;
  class Field_declContext;
  class Const_blockContext;
  class Const_declContext;
  class Const_exprContext;
  class Const_listContext;
  class Const_label_exprContext;
  class Var_declsContext;
  class When_declContext;
  class Clock_exprContext;
  class Last_declContext;
  class User_op_declContext;
  class Op_kindContext;
  class ParamsContext;
  class Op_bodyContext;
  class Contract_statementContext;
  class Merge_declContext;
  class Let_blockContext;
  class Local_blockContext;
  class Kind2_StatementContext;
  class MainStatementContext;
  class PropertyStatementContext;
  class CheckStatementContext;
  class Frame_blockContext;
  class Frame_initContext;
  class Frame_bodyContext;
  class Import_op_declContext;
  class EquationContext;
  class LhsContext;
  class ReturnContext;
  class Returns_varContext;
  class State_machineContext;
  class State_declContext;
  class Data_defContext;
  class TransitionContext;
  class ExprContext;
  class ListContext;
  class Kind2_exprContext;
  class Activate_exprContext;
  class Restart_exprContext;
  class Tempo_exprContext;
  class Bool_exprContext;
  class Array_exprContext;
  class Struct_exprContext;
  class Mixed_constructorContext;
  class Label_exprContext;
  class IndexContext;
  class Label_or_indexContext;
  class Switch_exprContext;
  class Case_exprContext;
  class PatternContext;
  class Apply_exprContext;
  class Prefix_operatorContext;
  class Prefix_unary_operatorContext;
  class Prefix_binary_operatorContext;
  class IteratorContext;
  class Iterator_lv6Context;
  class Simple_exprContext;
  class Unary_arith_opContext;
  class Bin_arith_opContext;
  class Bin_relation_opContext;
  class Bin_bool_opContext;
  class AtomContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IncludeContext *include();
    std::vector<DeclsContext *> decls();
    DeclsContext* decls(size_t i);
    std::vector<Pack_listContext *> pack_list();
    Pack_listContext* pack_list(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  IncludeContext : public antlr4::ParserRuleContext {
  public:
    IncludeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludeContext* include();

  class  Pack_listContext : public antlr4::ParserRuleContext {
  public:
    Pack_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<One_parkContext *> one_park();
    One_parkContext* one_park(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pack_listContext* pack_list();

  class  One_parkContext : public antlr4::ParserRuleContext {
  public:
    One_parkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Model_declContext *model_decl();
    Pack_declContext *pack_decl();
    Pack_eqContext *pack_eq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  One_parkContext* one_park();

  class  Pack_declContext : public antlr4::ParserRuleContext {
  public:
    Pack_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    UsesContext *uses();
    ProvidesContext *provides();
    DeclsContext *decls();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pack_declContext* pack_decl();

  class  UsesContext : public antlr4::ParserRuleContext {
  public:
    UsesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UsesContext* uses();

  class  Pack_eqContext : public antlr4::ParserRuleContext {
  public:
    Pack_eqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pack_eqContext* pack_eq();

  class  ProvidesContext : public antlr4::ParserRuleContext {
  public:
    ProvidesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ProvideContext *> provide();
    ProvideContext* provide(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProvidesContext* provides();

  class  ProvideContext : public antlr4::ParserRuleContext {
  public:
    ProvideContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Const_blockContext *const_block();
    Type_blockContext *type_block();
    User_op_provideContext *user_op_provide();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProvideContext* provide();

  class  Model_declContext : public antlr4::ParserRuleContext {
  public:
    Model_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    UsesContext *uses();
    User_op_provideContext *user_op_provide();
    DeclsContext *decls();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Model_declContext* model_decl();

  class  User_op_provideContext : public antlr4::ParserRuleContext {
  public:
    User_op_provideContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Op_kindContext *op_kind();
    antlr4::tree::TerminalNode *ID();
    std::vector<ParamsContext *> params();
    ParamsContext* params(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  User_op_provideContext* user_op_provide();

  class  DeclsContext : public antlr4::ParserRuleContext {
  public:
    DeclsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DeclsContext() = default;
    void copyFrom(DeclsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Decls_typeContext : public DeclsContext {
  public:
    Decls_typeContext(DeclsContext *ctx);

    Type_blockContext *type_block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Decls_user_opContext : public DeclsContext {
  public:
    Decls_user_opContext(DeclsContext *ctx);

    User_op_declContext *user_op_decl();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Decls_import_opContext : public DeclsContext {
  public:
    Decls_import_opContext(DeclsContext *ctx);

    Import_op_declContext *import_op_decl();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Decls_constContext : public DeclsContext {
  public:
    Decls_constContext(DeclsContext *ctx);

    Const_blockContext *const_block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Decls_kind2Context : public DeclsContext {
  public:
    Decls_kind2Context(DeclsContext *ctx);

    Kind2_declContext *kind2_decl();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DeclsContext* decls();

  class  Kind2_declContext : public antlr4::ParserRuleContext {
  public:
    Kind2_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Kind2_declContext() = default;
    void copyFrom(Kind2_declContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Decls_guaranteeContext : public Kind2_declContext {
  public:
    Decls_guaranteeContext(Kind2_declContext *ctx);

    Guarantee_declContext *guarantee_decl();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Decls_ghost_varContext : public Kind2_declContext {
  public:
    Decls_ghost_varContext(Kind2_declContext *ctx);

    Var_declContext *var_decl();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Decls_modeContext : public Kind2_declContext {
  public:
    Decls_modeContext(Kind2_declContext *ctx);

    Mode_declContext *mode_decl();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Decls_assumeContext : public Kind2_declContext {
  public:
    Decls_assumeContext(Kind2_declContext *ctx);

    Assume_declContext *assume_decl();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Kind2_declContext* kind2_decl();

  class  Mode_declContext : public antlr4::ParserRuleContext {
  public:
    Mode_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    std::vector<RequirementContext *> requirement();
    RequirementContext* requirement(size_t i);
    std::vector<AssuranceContext *> assurance();
    AssuranceContext* assurance(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mode_declContext* mode_decl();

  class  RequirementContext : public antlr4::ParserRuleContext {
  public:
    RequirementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RequirementContext* requirement();

  class  AssuranceContext : public antlr4::ParserRuleContext {
  public:
    AssuranceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssuranceContext* assurance();

  class  Var_declContext : public antlr4::ParserRuleContext {
  public:
    Var_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    TypeContext *type();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declContext* var_decl();

  class  Assume_declContext : public antlr4::ParserRuleContext {
  public:
    Assume_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assume_declContext* assume_decl();

  class  Guarantee_declContext : public antlr4::ParserRuleContext {
  public:
    Guarantee_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Guarantee_declContext* guarantee_decl();

  class  Type_blockContext : public antlr4::ParserRuleContext {
  public:
    Type_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_declContext *> type_decl();
    Type_declContext* type_decl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_blockContext* type_block();

  class  Type_declContext : public antlr4::ParserRuleContext {
  public:
    Type_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Type_defContext *type_def();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_declContext* type_decl();

  class  Type_defContext : public antlr4::ParserRuleContext {
  public:
    Type_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Type_defContext() = default;
    void copyFrom(Type_defContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Type_def_typeContext : public Type_defContext {
  public:
    Type_def_typeContext(Type_defContext *ctx);

    TypeContext *type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_def_enumContext : public Type_defContext {
  public:
    Type_def_enumContext(Type_defContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Type_defContext* type_def();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() = default;
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Type_realContext : public TypeContext {
  public:
    Type_realContext(TypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_floatContext : public TypeContext {
  public:
    Type_floatContext(TypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_boolContext : public TypeContext {
  public:
    Type_boolContext(TypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_arrayContext : public TypeContext {
  public:
    Type_arrayContext(TypeContext *ctx);

    TypeContext *type();
    Const_exprContext *const_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_charContext : public TypeContext {
  public:
    Type_charContext(TypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_idContext : public TypeContext {
  public:
    Type_idContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_ushortContext : public TypeContext {
  public:
    Type_ushortContext(TypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_uintContext : public TypeContext {
  public:
    Type_uintContext(TypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_shortContext : public TypeContext {
  public:
    Type_shortContext(TypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_structContext : public TypeContext {
  public:
    Type_structContext(TypeContext *ctx);

    std::vector<Field_declContext *> field_decl();
    Field_declContext* field_decl(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_intContext : public TypeContext {
  public:
    Type_intContext(TypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();
  TypeContext* type(int precedence);
  class  Field_declContext : public antlr4::ParserRuleContext {
  public:
    Field_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Field_declContext* field_decl();

  class  Const_blockContext : public antlr4::ParserRuleContext {
  public:
    Const_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Const_declContext *> const_decl();
    Const_declContext* const_decl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_blockContext* const_block();

  class  Const_declContext : public antlr4::ParserRuleContext {
  public:
    Const_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    TypeContext *type();
    Const_exprContext *const_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_declContext* const_decl();

  class  Const_exprContext : public antlr4::ParserRuleContext {
  public:
    Const_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Const_exprContext() = default;
    void copyFrom(Const_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Const_idContext : public Const_exprContext {
  public:
    Const_idContext(Const_exprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Const_parenContext : public Const_exprContext {
  public:
    Const_parenContext(Const_exprContext *ctx);

    Const_exprContext *const_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Const_bin_relationContext : public Const_exprContext {
  public:
    Const_bin_relationContext(Const_exprContext *ctx);

    std::vector<Const_exprContext *> const_expr();
    Const_exprContext* const_expr(size_t i);
    Bin_relation_opContext *bin_relation_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Const_atomContext : public Const_exprContext {
  public:
    Const_atomContext(Const_exprContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Const_unary_arithContext : public Const_exprContext {
  public:
    Const_unary_arithContext(Const_exprContext *ctx);

    Unary_arith_opContext *unary_arith_op();
    Const_exprContext *const_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Const_structContext : public Const_exprContext {
  public:
    Const_structContext(Const_exprContext *ctx);

    std::vector<Const_label_exprContext *> const_label_expr();
    Const_label_exprContext* const_label_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Const_bin_arithContext : public Const_exprContext {
  public:
    Const_bin_arithContext(Const_exprContext *ctx);

    std::vector<Const_exprContext *> const_expr();
    Const_exprContext* const_expr(size_t i);
    Bin_arith_opContext *bin_arith_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Const_bin_boolContext : public Const_exprContext {
  public:
    Const_bin_boolContext(Const_exprContext *ctx);

    std::vector<Const_exprContext *> const_expr();
    Const_exprContext* const_expr(size_t i);
    Bin_bool_opContext *bin_bool_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Const_arrayContext : public Const_exprContext {
  public:
    Const_arrayContext(Const_exprContext *ctx);

    Const_listContext *const_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Const_exprContext* const_expr();
  Const_exprContext* const_expr(int precedence);
  class  Const_listContext : public antlr4::ParserRuleContext {
  public:
    Const_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Const_exprContext *> const_expr();
    Const_exprContext* const_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_listContext* const_list();

  class  Const_label_exprContext : public antlr4::ParserRuleContext {
  public:
    Const_label_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Const_exprContext *const_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_label_exprContext* const_label_expr();

  class  Var_declsContext : public antlr4::ParserRuleContext {
  public:
    Var_declsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    TypeContext *type();
    When_declContext *when_decl();
    Last_declContext *last_decl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declsContext* var_decls();

  class  When_declContext : public antlr4::ParserRuleContext {
  public:
    When_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Clock_exprContext *clock_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  When_declContext* when_decl();

  class  Clock_exprContext : public antlr4::ParserRuleContext {
  public:
    Clock_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Clock_exprContext() = default;
    void copyFrom(Clock_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Clock_idContext : public Clock_exprContext {
  public:
    Clock_idContext(Clock_exprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Clock_notContext : public Clock_exprContext {
  public:
    Clock_notContext(Clock_exprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Clock_exprContext* clock_expr();

  class  Last_declContext : public antlr4::ParserRuleContext {
  public:
    Last_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Const_exprContext *const_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Last_declContext* last_decl();

  class  User_op_declContext : public antlr4::ParserRuleContext {
  public:
    User_op_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Op_kindContext *op_kind();
    antlr4::tree::TerminalNode *ID();
    std::vector<ParamsContext *> params();
    ParamsContext* params(size_t i);
    Op_bodyContext *op_body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  User_op_declContext* user_op_decl();

  class  Op_kindContext : public antlr4::ParserRuleContext {
  public:
    Op_kindContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Op_kindContext() = default;
    void copyFrom(Op_kindContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Op_kind_nodeContext : public Op_kindContext {
  public:
    Op_kind_nodeContext(Op_kindContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Op_kind_funtionContext : public Op_kindContext {
  public:
    Op_kind_funtionContext(Op_kindContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Op_kindContext* op_kind();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Var_declsContext *> var_decls();
    Var_declsContext* var_decls(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  Op_bodyContext : public antlr4::ParserRuleContext {
  public:
    Op_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Op_bodyContext() = default;
    void copyFrom(Op_bodyContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Op_body_nullContext : public Op_bodyContext {
  public:
    Op_body_nullContext(Op_bodyContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Op_body_ctxContext : public Op_bodyContext {
  public:
    Op_body_ctxContext(Op_bodyContext *ctx);

    Contract_statementContext *contract_statement();
    Merge_declContext *merge_decl();
    Local_blockContext *local_block();
    std::vector<Let_blockContext *> let_block();
    Let_blockContext* let_block(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Op_bodyContext* op_body();

  class  Contract_statementContext : public antlr4::ParserRuleContext {
  public:
    Contract_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Contract_statementContext* contract_statement();

  class  Merge_declContext : public antlr4::ParserRuleContext {
  public:
    Merge_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Merge_declContext* merge_decl();

  class  Let_blockContext : public antlr4::ParserRuleContext {
  public:
    Let_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Let_blockContext() = default;
    void copyFrom(Let_blockContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Let_block_kind2_frame_blockContext : public Let_blockContext {
  public:
    Let_block_kind2_frame_blockContext(Let_blockContext *ctx);

    Frame_blockContext *frame_block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Let_block_kind2_kind2_StatementContext : public Let_blockContext {
  public:
    Let_block_kind2_kind2_StatementContext(Let_blockContext *ctx);

    Kind2_StatementContext *kind2_Statement();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Let_block_equationContext : public Let_blockContext {
  public:
    Let_block_equationContext(Let_blockContext *ctx);

    EquationContext *equation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Let_blockContext* let_block();

  class  Local_blockContext : public antlr4::ParserRuleContext {
  public:
    Local_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Var_declsContext *> var_decls();
    Var_declsContext* var_decls(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Local_blockContext* local_block();

  class  Kind2_StatementContext : public antlr4::ParserRuleContext {
  public:
    Kind2_StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MainStatementContext *mainStatement();
    PropertyStatementContext *propertyStatement();
    CheckStatementContext *checkStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Kind2_StatementContext* kind2_Statement();

  class  MainStatementContext : public antlr4::ParserRuleContext {
  public:
    MainStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainStatementContext* mainStatement();

  class  PropertyStatementContext : public antlr4::ParserRuleContext {
  public:
    PropertyStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyStatementContext* propertyStatement();

  class  CheckStatementContext : public antlr4::ParserRuleContext {
  public:
    CheckStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CheckStatementContext* checkStatement();

  class  Frame_blockContext : public antlr4::ParserRuleContext {
  public:
    Frame_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Frame_initContext *frame_init();
    Frame_bodyContext *frame_body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Frame_blockContext* frame_block();

  class  Frame_initContext : public antlr4::ParserRuleContext {
  public:
    Frame_initContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Frame_initContext* frame_init();

  class  Frame_bodyContext : public antlr4::ParserRuleContext {
  public:
    Frame_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Frame_bodyContext* frame_body();

  class  Import_op_declContext : public antlr4::ParserRuleContext {
  public:
    Import_op_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    std::vector<ParamsContext *> params();
    ParamsContext* params(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_op_declContext* import_op_decl();

  class  EquationContext : public antlr4::ParserRuleContext {
  public:
    EquationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    EquationContext() = default;
    void copyFrom(EquationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Equation_state_machineContext : public EquationContext {
  public:
    Equation_state_machineContext(EquationContext *ctx);

    State_machineContext *state_machine();
    ReturnContext *return_();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Equation_exprContext : public EquationContext {
  public:
    Equation_exprContext(EquationContext *ctx);

    LhsContext *lhs();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  EquationContext* equation();

  class  LhsContext : public antlr4::ParserRuleContext {
  public:
    LhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LhsContext() = default;
    void copyFrom(LhsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Lhs_pairContext : public LhsContext {
  public:
    Lhs_pairContext(LhsContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lhs_id_listContext : public LhsContext {
  public:
    Lhs_id_listContext(LhsContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LhsContext* lhs();

  class  ReturnContext : public antlr4::ParserRuleContext {
  public:
    ReturnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Returns_varContext *returns_var();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnContext* return_();

  class  Returns_varContext : public antlr4::ParserRuleContext {
  public:
    Returns_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Returns_varContext* returns_var();

  class  State_machineContext : public antlr4::ParserRuleContext {
  public:
    State_machineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    std::vector<State_declContext *> state_decl();
    State_declContext* state_decl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  State_machineContext* state_machine();

  class  State_declContext : public antlr4::ParserRuleContext {
  public:
    State_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Data_defContext *data_def();
    std::vector<TransitionContext *> transition();
    TransitionContext* transition(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  State_declContext* state_decl();

  class  Data_defContext : public antlr4::ParserRuleContext {
  public:
    Data_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Data_defContext() = default;
    void copyFrom(Data_defContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  State_machine_data_def_local_blockContext : public Data_defContext {
  public:
    State_machine_data_def_local_blockContext(Data_defContext *ctx);

    Local_blockContext *local_block();
    std::vector<EquationContext *> equation();
    EquationContext* equation(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  State_machine_data_def_equationContext : public Data_defContext {
  public:
    State_machine_data_def_equationContext(Data_defContext *ctx);

    EquationContext *equation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Data_defContext* data_def();

  class  TransitionContext : public antlr4::ParserRuleContext {
  public:
    TransitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TransitionContext() = default;
    void copyFrom(TransitionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  State_machine_transition_restartContext : public TransitionContext {
  public:
    State_machine_transition_restartContext(TransitionContext *ctx);

    ExprContext *expr();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  State_machine_transition_resumeContext : public TransitionContext {
  public:
    State_machine_transition_resumeContext(TransitionContext *ctx);

    ExprContext *expr();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TransitionContext* transition();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Expr_apply_exprContext : public ExprContext {
  public:
    Expr_apply_exprContext(ExprContext *ctx);

    Apply_exprContext *apply_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_simple_exprContext : public ExprContext {
  public:
    Expr_simple_exprContext(ExprContext *ctx);

    Simple_exprContext *simple_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_mixed_constructorContext : public ExprContext {
  public:
    Expr_mixed_constructorContext(ExprContext *ctx);

    Mixed_constructorContext *mixed_constructor();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_tempo_exprContext : public ExprContext {
  public:
    Expr_tempo_exprContext(ExprContext *ctx);

    Tempo_exprContext *tempo_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_struct_exprContext : public ExprContext {
  public:
    Expr_struct_exprContext(ExprContext *ctx);

    Struct_exprContext *struct_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_bool_exprContext : public ExprContext {
  public:
    Expr_bool_exprContext(ExprContext *ctx);

    Bool_exprContext *bool_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_last_declContext : public ExprContext {
  public:
    Expr_last_declContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_parenContext : public ExprContext {
  public:
    Expr_parenContext(ExprContext *ctx);

    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_array_exprContext : public ExprContext {
  public:
    Expr_array_exprContext(ExprContext *ctx);

    Array_exprContext *array_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_kind2Context : public ExprContext {
  public:
    Expr_kind2Context(ExprContext *ctx);

    Kind2_exprContext *kind2_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_switch_exprContext : public ExprContext {
  public:
    Expr_switch_exprContext(ExprContext *ctx);

    Switch_exprContext *switch_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListContext* list();

  class  Kind2_exprContext : public antlr4::ParserRuleContext {
  public:
    Kind2_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Activate_exprContext *activate_expr();
    Restart_exprContext *restart_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Kind2_exprContext* kind2_expr();

  class  Activate_exprContext : public antlr4::ParserRuleContext {
  public:
    Activate_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    ParamsContext *params();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Activate_exprContext* activate_expr();

  class  Restart_exprContext : public antlr4::ParserRuleContext {
  public:
    Restart_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    ParamsContext *params();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Restart_exprContext* restart_expr();

  class  Tempo_exprContext : public antlr4::ParserRuleContext {
  public:
    Tempo_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Tempo_exprContext() = default;
    void copyFrom(Tempo_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Tempo_expr_arrow_tempoContext : public Tempo_exprContext {
  public:
    Tempo_expr_arrow_tempoContext(Tempo_exprContext *ctx);

    Simple_exprContext *simple_expr();
    Tempo_exprContext *tempo_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Tempo_expr_mergeContext : public Tempo_exprContext {
  public:
    Tempo_expr_mergeContext(Tempo_exprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Tempo_expr_arrowContext : public Tempo_exprContext {
  public:
    Tempo_expr_arrowContext(Tempo_exprContext *ctx);

    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Tempo_expr_fbyContext : public Tempo_exprContext {
  public:
    Tempo_expr_fbyContext(Tempo_exprContext *ctx);

    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);
    Const_exprContext *const_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Tempo_expr_preContext : public Tempo_exprContext {
  public:
    Tempo_expr_preContext(Tempo_exprContext *ctx);

    Simple_exprContext *simple_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Tempo_expr_whenContext : public Tempo_exprContext {
  public:
    Tempo_expr_whenContext(Tempo_exprContext *ctx);

    Simple_exprContext *simple_expr();
    Clock_exprContext *clock_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Tempo_expr_fby_noconstContext : public Tempo_exprContext {
  public:
    Tempo_expr_fby_noconstContext(Tempo_exprContext *ctx);

    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Tempo_exprContext* tempo_expr();

  class  Bool_exprContext : public antlr4::ParserRuleContext {
  public:
    Bool_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ListContext *list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bool_exprContext* bool_expr();

  class  Array_exprContext : public antlr4::ParserRuleContext {
  public:
    Array_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Array_exprContext() = default;
    void copyFrom(Array_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Array_expr_splitContext : public Array_exprContext {
  public:
    Array_expr_splitContext(Array_exprContext *ctx);

    Simple_exprContext *simple_expr();
    std::vector<antlr4::tree::TerminalNode *> INTEGER();
    antlr4::tree::TerminalNode* INTEGER(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Array_expr_andContext : public Array_exprContext {
  public:
    Array_expr_andContext(Array_exprContext *ctx);

    Simple_exprContext *simple_expr();
    Const_exprContext *const_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Array_expr_listContext : public Array_exprContext {
  public:
    Array_expr_listContext(Array_exprContext *ctx);

    std::vector<ListContext *> list();
    ListContext* list(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Array_expr_dynamicContext : public Array_exprContext {
  public:
    Array_expr_dynamicContext(Array_exprContext *ctx);

    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);
    std::vector<IndexContext *> index();
    IndexContext* index(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Array_exprContext* array_expr();

  class  Struct_exprContext : public antlr4::ParserRuleContext {
  public:
    Struct_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Label_exprContext *> label_expr();
    Label_exprContext* label_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Struct_exprContext* struct_expr();

  class  Mixed_constructorContext : public antlr4::ParserRuleContext {
  public:
    Mixed_constructorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Simple_exprContext *simple_expr();
    std::vector<Label_or_indexContext *> label_or_index();
    Label_or_indexContext* label_or_index(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mixed_constructorContext* mixed_constructor();

  class  Label_exprContext : public antlr4::ParserRuleContext {
  public:
    Label_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Simple_exprContext *simple_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Label_exprContext* label_expr();

  class  IndexContext : public antlr4::ParserRuleContext {
  public:
    IndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_exprContext *simple_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexContext* index();

  class  Label_or_indexContext : public antlr4::ParserRuleContext {
  public:
    Label_or_indexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Label_or_indexContext() = default;
    void copyFrom(Label_or_indexContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Mix_labelContext : public Label_or_indexContext {
  public:
    Mix_labelContext(Label_or_indexContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Mix_indexContext : public Label_or_indexContext {
  public:
    Mix_indexContext(Label_or_indexContext *ctx);

    IndexContext *index();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Label_or_indexContext* label_or_index();

  class  Switch_exprContext : public antlr4::ParserRuleContext {
  public:
    Switch_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Switch_exprContext() = default;
    void copyFrom(Switch_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Switch_expr_ifelseContext : public Switch_exprContext {
  public:
    Switch_expr_ifelseContext(Switch_exprContext *ctx);

    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Switch_expr_caseContext : public Switch_exprContext {
  public:
    Switch_expr_caseContext(Switch_exprContext *ctx);

    Simple_exprContext *simple_expr();
    std::vector<Case_exprContext *> case_expr();
    Case_exprContext* case_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Switch_exprContext* switch_expr();

  class  Case_exprContext : public antlr4::ParserRuleContext {
  public:
    Case_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PatternContext *pattern();
    Simple_exprContext *simple_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_exprContext* case_expr();

  class  PatternContext : public antlr4::ParserRuleContext {
  public:
    PatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *BOOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PatternContext* pattern();

  class  Apply_exprContext : public antlr4::ParserRuleContext {
  public:
    Apply_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Apply_exprContext() = default;
    void copyFrom(Apply_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Apply_prefixContext : public Apply_exprContext {
  public:
    Apply_prefixContext(Apply_exprContext *ctx);

    Prefix_operatorContext *prefix_operator();
    ListContext *list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Apply_iteratorContext : public Apply_exprContext {
  public:
    Apply_iteratorContext(Apply_exprContext *ctx);

    IteratorContext *iterator();
    Prefix_operatorContext *prefix_operator();
    Const_exprContext *const_expr();
    ListContext *list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Apply_mapwIContext : public Apply_exprContext {
  public:
    Apply_mapwIContext(Apply_exprContext *ctx);

    Prefix_operatorContext *prefix_operator();
    Const_exprContext *const_expr();
    Simple_exprContext *simple_expr();
    std::vector<ListContext *> list();
    ListContext* list(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Apply_iterator_lv6Context : public Apply_exprContext {
  public:
    Apply_iterator_lv6Context(Apply_exprContext *ctx);

    Iterator_lv6Context *iterator_lv6();
    std::vector<ListContext *> list();
    ListContext* list(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Apply_mapwContext : public Apply_exprContext {
  public:
    Apply_mapwContext(Apply_exprContext *ctx);

    Prefix_operatorContext *prefix_operator();
    Const_exprContext *const_expr();
    Simple_exprContext *simple_expr();
    std::vector<ListContext *> list();
    ListContext* list(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Apply_foldwContext : public Apply_exprContext {
  public:
    Apply_foldwContext(Apply_exprContext *ctx);

    Prefix_operatorContext *prefix_operator();
    Const_exprContext *const_expr();
    Simple_exprContext *simple_expr();
    ListContext *list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Apply_foldwiContext : public Apply_exprContext {
  public:
    Apply_foldwiContext(Apply_exprContext *ctx);

    Prefix_operatorContext *prefix_operator();
    Const_exprContext *const_expr();
    Simple_exprContext *simple_expr();
    ListContext *list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Apply_exprContext* apply_expr();

  class  Prefix_operatorContext : public antlr4::ParserRuleContext {
  public:
    Prefix_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Prefix_operatorContext() = default;
    void copyFrom(Prefix_operatorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Perfix_flattenContext : public Prefix_operatorContext {
  public:
    Perfix_flattenContext(Prefix_operatorContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Prefix_unaryContext : public Prefix_operatorContext {
  public:
    Prefix_unaryContext(Prefix_operatorContext *ctx);

    Prefix_unary_operatorContext *prefix_unary_operator();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Perfix_IDContext : public Prefix_operatorContext {
  public:
    Perfix_IDContext(Prefix_operatorContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Prefix_binaryContext : public Prefix_operatorContext {
  public:
    Prefix_binaryContext(Prefix_operatorContext *ctx);

    Prefix_binary_operatorContext *prefix_binary_operator();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Perfix_makeContext : public Prefix_operatorContext {
  public:
    Perfix_makeContext(Prefix_operatorContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Prefix_operatorContext* prefix_operator();

  class  Prefix_unary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Prefix_unary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Prefix_unary_operatorContext* prefix_unary_operator();

  class  Prefix_binary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Prefix_binary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Prefix_binary_operatorContext* prefix_binary_operator();

  class  IteratorContext : public antlr4::ParserRuleContext {
  public:
    IteratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IteratorContext() = default;
    void copyFrom(IteratorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Iterator_boolredContext : public IteratorContext {
  public:
    Iterator_boolredContext(IteratorContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_redContext : public IteratorContext {
  public:
    Iterator_redContext(IteratorContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_mapiContext : public IteratorContext {
  public:
    Iterator_mapiContext(IteratorContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_fillredContext : public IteratorContext {
  public:
    Iterator_fillredContext(IteratorContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_foldiContext : public IteratorContext {
  public:
    Iterator_foldiContext(IteratorContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_mapContext : public IteratorContext {
  public:
    Iterator_mapContext(IteratorContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_foldContext : public IteratorContext {
  public:
    Iterator_foldContext(IteratorContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_fillContext : public IteratorContext {
  public:
    Iterator_fillContext(IteratorContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_mapfoldContext : public IteratorContext {
  public:
    Iterator_mapfoldContext(IteratorContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IteratorContext* iterator();

  class  Iterator_lv6Context : public antlr4::ParserRuleContext {
  public:
    Iterator_lv6Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Iterator_lv6Context() = default;
    void copyFrom(Iterator_lv6Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Iterator_lv6_fillredContext : public Iterator_lv6Context {
  public:
    Iterator_lv6_fillredContext(Iterator_lv6Context *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_lv6_redContext : public Iterator_lv6Context {
  public:
    Iterator_lv6_redContext(Iterator_lv6Context *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_lv6_fillContext : public Iterator_lv6Context {
  public:
    Iterator_lv6_fillContext(Iterator_lv6Context *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Iterator_lv6_boolredContext : public Iterator_lv6Context {
  public:
    Iterator_lv6_boolredContext(Iterator_lv6Context *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Iterator_lv6Context* iterator_lv6();

  class  Simple_exprContext : public antlr4::ParserRuleContext {
  public:
    Simple_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Simple_exprContext() = default;
    void copyFrom(Simple_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Simple_expr_unary_arithContext : public Simple_exprContext {
  public:
    Simple_expr_unary_arithContext(Simple_exprContext *ctx);

    Unary_arith_opContext *unary_arith_op();
    Simple_exprContext *simple_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_expr_parenContext : public Simple_exprContext {
  public:
    Simple_expr_parenContext(Simple_exprContext *ctx);

    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_expr_typeContext : public Simple_exprContext {
  public:
    Simple_expr_typeContext(Simple_exprContext *ctx);

    TypeContext *type();
    Simple_exprContext *simple_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_expr_structContext : public Simple_exprContext {
  public:
    Simple_expr_structContext(Simple_exprContext *ctx);

    Simple_exprContext *simple_expr();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_expr_bin_relationContext : public Simple_exprContext {
  public:
    Simple_expr_bin_relationContext(Simple_exprContext *ctx);

    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);
    Bin_relation_opContext *bin_relation_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_expr_atomContext : public Simple_exprContext {
  public:
    Simple_expr_atomContext(Simple_exprContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_expr_bin_boolContext : public Simple_exprContext {
  public:
    Simple_expr_bin_boolContext(Simple_exprContext *ctx);

    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);
    Bin_bool_opContext *bin_bool_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_expr_idContext : public Simple_exprContext {
  public:
    Simple_expr_idContext(Simple_exprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_expr_bin_arithContext : public Simple_exprContext {
  public:
    Simple_expr_bin_arithContext(Simple_exprContext *ctx);

    std::vector<Simple_exprContext *> simple_expr();
    Simple_exprContext* simple_expr(size_t i);
    Bin_arith_opContext *bin_arith_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_expr_arrayContext : public Simple_exprContext {
  public:
    Simple_expr_arrayContext(Simple_exprContext *ctx);

    Simple_exprContext *simple_expr();
    Const_exprContext *const_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Simple_exprContext* simple_expr();
  Simple_exprContext* simple_expr(int precedence);
  class  Unary_arith_opContext : public antlr4::ParserRuleContext {
  public:
    Unary_arith_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Unary_arith_opContext() = default;
    void copyFrom(Unary_arith_opContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Unary_arith_op_notContext : public Unary_arith_opContext {
  public:
    Unary_arith_op_notContext(Unary_arith_opContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Unary_arith_op_subContext : public Unary_arith_opContext {
  public:
    Unary_arith_op_subContext(Unary_arith_opContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Unary_arith_op_addContext : public Unary_arith_opContext {
  public:
    Unary_arith_op_addContext(Unary_arith_opContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Unary_arith_opContext* unary_arith_op();

  class  Bin_arith_opContext : public antlr4::ParserRuleContext {
  public:
    Bin_arith_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Bin_arith_opContext() = default;
    void copyFrom(Bin_arith_opContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Bin_arith_op_mulContext : public Bin_arith_opContext {
  public:
    Bin_arith_op_mulContext(Bin_arith_opContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bin_arith_op_dividedContext : public Bin_arith_opContext {
  public:
    Bin_arith_op_dividedContext(Bin_arith_opContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bin_arith_op_subContext : public Bin_arith_opContext {
  public:
    Bin_arith_op_subContext(Bin_arith_opContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bin_arith_op_modContext : public Bin_arith_opContext {
  public:
    Bin_arith_op_modContext(Bin_arith_opContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bin_arith_op_addContext : public Bin_arith_opContext {
  public:
    Bin_arith_op_addContext(Bin_arith_opContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bin_arith_op_divContext : public Bin_arith_opContext {
  public:
    Bin_arith_op_divContext(Bin_arith_opContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Bin_arith_opContext* bin_arith_op();

  class  Bin_relation_opContext : public antlr4::ParserRuleContext {
  public:
    Bin_relation_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bin_relation_opContext* bin_relation_op();

  class  Bin_bool_opContext : public antlr4::ParserRuleContext {
  public:
    Bin_bool_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bin_bool_opContext* bin_bool_op();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() = default;
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Atom_CHARContext : public AtomContext {
  public:
    Atom_CHARContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *CHAR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_SHORTContext : public AtomContext {
  public:
    Atom_SHORTContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *SHORT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_UINTContext : public AtomContext {
  public:
    Atom_UINTContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *UINT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_FLOATContext : public AtomContext {
  public:
    Atom_FLOATContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_REALContext : public AtomContext {
  public:
    Atom_REALContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *REAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_BOOLContext : public AtomContext {
  public:
    Atom_BOOLContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *BOOL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_INTEGERContext : public AtomContext {
  public:
    Atom_INTEGERContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *INTEGER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_USHORTContext : public AtomContext {
  public:
    Atom_USHORTContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *USHORT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool typeSempred(TypeContext *_localctx, size_t predicateIndex);
  bool const_exprSempred(Const_exprContext *_localctx, size_t predicateIndex);
  bool simple_exprSempred(Simple_exprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

