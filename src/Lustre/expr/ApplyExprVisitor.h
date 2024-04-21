//
// Created by Wang on 2024/3/8.
//

#ifndef QKIND_APPLYEXPRVISITOR_H
#define QKIND_APPLYEXPRVISITOR_H
#include "../visitor/MyLustreVisitor.h"

class ApplyExprVisitor: public LustreBaseVisitor {

public:
    explicit ApplyExprVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope);

    std::any visitApply_map(LustreParser::Apply_mapContext *ctx) override;

    std::any visitApply_fold(LustreParser::Apply_foldContext *ctx) override;

    std::any visitApply_mapi(LustreParser::Apply_mapiContext *ctx) override;

    std::any visitApply_foldi(LustreParser::Apply_foldiContext *ctx) override;

    std::any visitApply_mapfold(LustreParser::Apply_mapfoldContext *ctx) override;

    std::any visitApply_mapw(LustreParser::Apply_mapwContext *ctx) override;

    std::any visitApply_mapwi(LustreParser::Apply_mapwiContext *ctx) override;

    std::any visitApply_foldw(LustreParser::Apply_foldwContext *ctx) override;

    std::any visitApply_foldwi(LustreParser::Apply_foldwiContext *ctx) override;

    std::pair<std::vector<std::string>, std::vector<std::string>>
    get_params_returns(LustreParser::Prefix_operatorContext* , LustreParser::ListContext*, LustreParser::Const_exprContext*, int& );
    std::shared_ptr<Scope> currentScope;
    MyLustreVisitor &myLustreVisitor;

    static std::vector<std::string> buildVarTemps(const std::vector<std::string> &types, std::string, int num);
};


#endif //QKIND_APPLYEXPRVISITOR_H
