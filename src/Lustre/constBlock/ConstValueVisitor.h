//
// Created by jack on 2/28/24.
//

#ifndef QKIND_CONSTVALUEVISITOR_H
#define QKIND_CONSTVALUEVISITOR_H

#include <string>
#include <vector>

#include "../generated/LustreBaseVisitor.h"
#include "../visitor/MyLustreVisitor.h"

/**
 * 通过遍历整个const_expr来确定const的真正值
 */
class ConstValueVisitor : public LustreBaseVisitor {

public:

    explicit ConstValueVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope);

    std::any visitConst_id(LustreParser::Const_idContext *ctx) override;

    std::any visitConst_atom(LustreParser::Const_atomContext *ctx) override;

    std::any visitConst_unary_arith(LustreParser::Const_unary_arithContext *ctx) override;

    std::any visitConst_paren(LustreParser::Const_parenContext *ctx) override;

    std::any visitConst_bin_arith(LustreParser::Const_bin_arithContext *ctx) override;

    //下面的运算并没有实现，因为暂时没有用到
//    std::any visitConst_bin_bool(LustreParser::Const_bin_boolContext *ctx) override;
//    std::any visitConst_bin_relation(LustreParser::Const_bin_relationContext *ctx) override;
//    std::any visitConst_list(LustreParser::Const_listContext *ctx) override;
//    std::any visitConst_struct(LustreParser::Const_structContext *ctx) override;


private:
    std::shared_ptr<Scope> currentScope;

    MyLustreVisitor &myLustreVisitor;

    std::any visitAtom_REAL(LustreParser::Atom_REALContext *ctx) override;

    std::any visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) override;

    std::any visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) override;

    std::any visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) override;

    std::any visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) override;

    std::any visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) override;

    std::any visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) override;

    std::any visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) override;
};


#endif //QKIND_CONSTVALUEVISITOR_H
