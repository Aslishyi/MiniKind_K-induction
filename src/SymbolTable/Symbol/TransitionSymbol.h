//
// Created by jack on 3/23/24.
//

#ifndef QKIND_TRANSITIONSYMBOL_H
#define QKIND_TRANSITIONSYMBOL_H


#include "Symbol.h"
#include "../../lustre/generated/LustreParser.h"

class TransitionSymbol : public Symbol {


public:
    TransitionSymbol() = delete;


    //普通Symbol类型的构造函数
    TransitionSymbol(const std::string &name, std::shared_ptr<antlr4::Token> token,
                     std::shared_ptr<Scope> scope);

    TransitionSymbol(const std::string &name, std::shared_ptr<antlr4::Token> token,
                     std::shared_ptr<Scope> scope, bool strongTran, bool resume, LustreParser::ExprContext *exprCtx,
                     std::pair<std::string ,std::shared_ptr<Symbol>> stateSymbol
    );

    //打印具体的symbol类型
    std::string toAstString() const override;


    //强迁移
    bool strongTran;
    //resume切换
    bool resume;
    //转移条件ctx
    LustreParser::ExprContext *exprCtx;
    //转移目标
    std::pair<std::string ,std::shared_ptr<Symbol>> stateSymbol;

private:


};


#endif //QKIND_TRANSITIONSYMBOL_H
