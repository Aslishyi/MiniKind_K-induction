//
// Created by jack on 3/5/24.
//

#ifndef QKIND_BOOLEXPRVISITOR_H
#define QKIND_BOOLEXPRVISITOR_H


#include "../generated/LustreBaseVisitor.h"
#include "../visitor/MyLustreVisitor.h"

class BoolExprVisitor : public LustreBaseVisitor {

public:

    explicit BoolExprVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope);

    std::any visitBool_expr(LustreParser::Bool_exprContext *ctx) override;

    std::any visitList(LustreParser::ListContext *ctx) override;

//List返回值:{名称，数组大小}
    struct ListStruct {
        std::string name;
        std::string size;
    };
private:
    std::shared_ptr<Scope> currentScope;

    MyLustreVisitor &myLustreVisitor;
};


#endif //QKIND_BOOLEXPRVISITOR_H
