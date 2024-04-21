//
// Created by jack on 3/23/24.
//

#include "TransitionSymbol.h"
#include "../../lustre/tool/LustreVisitorTool.h"

std::string TransitionSymbol::toAstString() const {
    std::string res("tran(");
    if (strongTran){
        res.append("strong");
    } else{
        res.append("weak");
    }
    res.append(",");
    if (resume){
        res.append("resume");
    } else{
        res.append("restart");
    }
    res.append(",");
    res.append(LustreVisitorTool::getFullText(exprCtx));
    res.append(",");
    res.append(stateSymbol.second->toAstString());
    res.append(")");
    return res;
}

TransitionSymbol::TransitionSymbol(const std::string &name, std::shared_ptr<antlr4::Token> token,
                                   std::shared_ptr<Scope> scope)
        : Symbol(name, Symbol::VARIABLE, token, scope) {}

TransitionSymbol::TransitionSymbol(const std::string &name, std::shared_ptr<antlr4::Token> token,
                                   std::shared_ptr<Scope> scope, bool strongTran, bool resume,
                                   LustreParser::ExprContext *exprCtx, std::pair<std::string ,std::shared_ptr<Symbol>> stateSymbol)
        : Symbol(name, Symbol::VARIABLE, token, scope), strongTran(strongTran), resume(resume), exprCtx(exprCtx),
          stateSymbol(stateSymbol) {

}
