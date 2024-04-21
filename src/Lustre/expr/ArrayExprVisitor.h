//
// Created by jack on 1/14/24.
//

#ifndef QL2C_ARRAYEXPRVISITOR_H
#define QL2C_ARRAYEXPRVISITOR_H


#include "../visitor/MyLustreVisitor.h"

class ArrayExprVisitor : public LustreBaseVisitor {

public:
    std::any visitArray_expr_dynamic(LustreParser::Array_expr_dynamicContext *ctx) override;

    explicit ArrayExprVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope);

    static std::string
    generateArrayProjection(const std::vector<std::string> &indexVector, const std::vector<std::string> &dimVector,
                            const std::string &leftExpr);

private:
    std::shared_ptr<Scope> currentScope;

    MyLustreVisitor &myLustreVisitor;
};


#endif //QL2C_ARRAYEXPRVISITOR_H
