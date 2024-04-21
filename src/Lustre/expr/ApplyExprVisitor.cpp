//
// Created by Wang on 2024/3/8.
//

#include "ApplyExprVisitor.h"
#include "../src/SymbolTable/Symbol/VariableSymbol.h"
#include "../src/lustre/tool/LustreVisitorTool.h"
#include "../src/lustre/constBlock/ConstValueVisitor.h"
#include "GetSimpleExprType.h"

#define _tab "    "
#define myvis(x) std::any_cast<std::string>(myLustreVisitor.visit(x))


ApplyExprVisitor::ApplyExprVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope) : myLustreVisitor(myLustreVisitor), currentScope(currentScope){}

std::any ApplyExprVisitor::visitApply_map(LustreParser::Apply_mapContext *ctx) {
    int len = 0;
    auto [func_params, func_returns] = get_params_returns(ctx->prefix_operator(), ctx->list(), ctx->const_expr(), len);

    std::string funcName;
    std::vector<std::pair<std::string, std::string>> params, returns;
    std::vector<std::string> letDecls;
    funcName = func_params.back();
    func_params.pop_back();
    for(int i = 0 ; i < func_params.size() ; i ++) {
        params.emplace_back("x" + std::to_string(i),  func_params[i] + "^" + std::to_string(len));
    }
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        returns.emplace_back("y" + std::to_string(i),  func_returns[i] + "^" + std::to_string(len));
    }
    for(int i = 0 ; i < len ; i ++) {
        char let_buf[1024];
        std::string ylist, xlist;
        for(int j = 0 ; j < func_params.size() ; j ++) {
            if(j != 0) {
                xlist.append(", ");
            }
            xlist.append("x" + std::to_string(j) + "[" + std::to_string(i) + "]");
        }
        for(int j = 0 ; j < func_returns.size() ; j ++) {
            if(j != 0) {
                ylist.append(", ");
            }
            ylist.append("temp_y" + std::to_string(j) + "_" + std::to_string(i));
        }
        sprintf(let_buf, "%s = %s(%s);", ylist.c_str(), funcName.c_str(), xlist.c_str());
        letDecls.emplace_back(let_buf);
    }
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        letDecls.emplace_back("y" + std::to_string(i) + " = [");
        for(int j = 0 ; j < len ; j ++) {
            if(j != 0) {
                letDecls.back().append(", ");
            }
            letDecls.back().append("temp_y" + std::to_string(i) + "_" + std::to_string(j));
        }
        letDecls.back().append("];");
    }
    funcName = "map_" + funcName + "_" + std::to_string(len);
    auto varDecls = buildVarTemps(func_returns, "y", len);
    myLustreVisitor.addFuncToEnd(funcName, LustreVisitorTool::buildLusFunction(funcName, params, returns, varDecls, letDecls));
    std::string res = funcName;
    res.append("(");
    res.append(myvis(ctx->list())).append(")");
    return res;
}


std::any ApplyExprVisitor::visitApply_fold(LustreParser::Apply_foldContext *ctx) {
    int len = 0;
    auto [func_params, func_returns] = get_params_returns(ctx->prefix_operator(), ctx->list(), ctx->const_expr(), len);
    std::string funcName;
    std::vector<std::pair<std::string, std::string>> params, returns;
    std::vector<std::string> letDecls;
    funcName = func_params.back();
    func_params.pop_back();
    for(int i = 0 ; i < func_params.size() ; i ++) {
        if(i == 0) {
            params.emplace_back("x" + std::to_string(i),  func_params[i]);
        } else {
            params.emplace_back("x" + std::to_string(i),  func_params[i] + "^" + std::to_string(len));
        }
    }
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        returns.emplace_back("y" + std::to_string(i),  func_returns[i]);
    }
    for(int i = 0 ; i < len ; i ++) {
        char let_buf[1024];
        std::string xlist;
        if(i == 0) {
            xlist = "x0";
        } else {
            xlist = "temp_y0_" + std::to_string(i-1);
        }
        for(int j = 1 ; j < func_params.size() ; j ++) {
            xlist.append(", x" + std::to_string(j) + "[" + std::to_string(i) + "]");
        }
        sprintf(let_buf, "temp_y0_%d = %s(%s);", i, funcName.c_str(), xlist.c_str());
        letDecls.emplace_back(let_buf);
    }
    letDecls.emplace_back("y0 = temp_y0_" + std::to_string(len-1) + ";");
    funcName = "fold_" + funcName + "_" + std::to_string(len);
    auto varDecls = buildVarTemps(func_returns, "y", len);
    myLustreVisitor.addFuncToEnd(funcName, LustreVisitorTool::buildLusFunction(funcName, params, returns, varDecls, letDecls));
    std::string res = funcName;
    res.append("(");
    res.append(myvis(ctx->list())).append(")");
    return res;
}

std::any ApplyExprVisitor::visitApply_mapi(LustreParser::Apply_mapiContext *ctx) {
    int len = 0;
    auto [func_params, func_returns] = get_params_returns(ctx->prefix_operator(), ctx->list(), ctx->const_expr(), len);
    std::string funcName;
    std::vector<std::pair<std::string, std::string>> params, returns;
    std::vector<std::string> letDecls;
    funcName = func_params.back();
    func_params.pop_back();
    func_params.erase(func_params.begin());
    for(int i = 0 ; i < func_params.size() ; i ++) {
        params.emplace_back("x" + std::to_string(i),  func_params[i] + "^" + std::to_string(len));
    }
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        returns.emplace_back("y" + std::to_string(i),  func_returns[i] + "^" + std::to_string(len));
    }
    for(int i = 0 ; i < len ; i ++) {
        char let_buf[1024];
        std::string ylist, xlist;
        for(int j = 0 ; j < func_params.size() ; j ++) {
            if(j != 0) {
                xlist.append(", ");
            }
            xlist.append("x" + std::to_string(j) + "[" + std::to_string(i) + "]");
        }
        for(int j = 0 ; j < func_returns.size() ; j ++) {
            if(j != 0) {
                ylist.append(", ");
            }
            ylist.append("temp_y" + std::to_string(j) + "_" + std::to_string(i));
        }
        sprintf(let_buf, "%s = %s(%d, %s);", ylist.c_str(), funcName.c_str(), i, xlist.c_str());
        letDecls.emplace_back(let_buf);
    }
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        letDecls.emplace_back("y" + std::to_string(i) + " = [");
        for(int j = 0 ; j < len ; j ++) {
            if(j != 0) {
                letDecls.back().append(", ");
            }
            letDecls.back().append("temp_y" + std::to_string(i) + "_" + std::to_string(j));
        }
        letDecls.back().append("];");
    }
    funcName = "mapi_" + funcName + "_" + std::to_string(len);
    auto varDecls = buildVarTemps(func_returns, "y", len);
    myLustreVisitor.addFuncToEnd(funcName, LustreVisitorTool::buildLusFunction(funcName, params, returns, varDecls, letDecls));
    std::string res = funcName;
    res.append("(");
    res.append(myvis(ctx->list())).append(")");
    return res;
}
std::any ApplyExprVisitor::visitApply_foldi(LustreParser::Apply_foldiContext *ctx) {
    int len = 0;
    auto [func_params, func_returns] = get_params_returns(ctx->prefix_operator(), ctx->list(), ctx->const_expr(), len);
    std::string funcName;
    std::vector<std::pair<std::string, std::string>> params, returns;
    std::vector<std::string> letDecls;
    funcName = func_params.back();
    func_params.pop_back();
    func_params.erase(func_params.begin());
    for(int i = 0 ; i < func_params.size() ; i ++) {
        if(i == 0) {
            params.emplace_back("x" + std::to_string(i),  func_params[i]);
        } else {
            params.emplace_back("x" + std::to_string(i),  func_params[i] + "^" + std::to_string(len));
        }
    }
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        returns.emplace_back("y" + std::to_string(i),  func_returns[i]);
    }
    for(int i = 0 ; i < len ; i ++) {
        char let_buf[1024];
        std::string xlist;
        if(i == 0) {
            xlist = "x0";
        } else {
            xlist = "temp_y0_" + std::to_string(i-1);
        }
        for(int j = 1 ; j < func_params.size() ; j ++) {
            xlist.append(", x" + std::to_string(j) + "[" + std::to_string(i) + "]");
        }
        sprintf(let_buf, "temp_y0_%d = %s(%d, %s);", i, funcName.c_str(), i, xlist.c_str());
        letDecls.emplace_back(let_buf);
    }
    letDecls.emplace_back("y0 = temp_y0_" + std::to_string(len-1) + ";");
    funcName = "foldi_" + funcName + "_" + std::to_string(len);
    auto varDecls = buildVarTemps(func_returns, "y", len);
    myLustreVisitor.addFuncToEnd(funcName, LustreVisitorTool::buildLusFunction(funcName, params, returns, varDecls, letDecls));
    std::string res = funcName;
    res.append("(");
    res.append(myvis(ctx->list())).append(")");
    return res;
}

std::any ApplyExprVisitor::visitApply_mapfold(LustreParser::Apply_mapfoldContext *ctx) {
    int len = 0;
    auto [func_params, func_returns] = get_params_returns(ctx->prefix_operator(), ctx->list(), ctx->const_expr(), len);
    std::string funcName;
    std::vector<std::pair<std::string, std::string>> params, returns;
    std::vector<std::string> letDecls;
    funcName = func_params.back();
    func_params.pop_back();
    for(int i = 0 ; i < func_params.size() ; i ++) {
        if(i == 0) {
            params.emplace_back("x" + std::to_string(i),  func_params[i]);
        } else {
            params.emplace_back("x" + std::to_string(i),  func_params[i] + "^" + std::to_string(len));
        }
    }
    returns.emplace_back("y0",  func_returns[0]);
    returns.emplace_back("y1",  func_returns[0] + "^" + std::to_string(len));
    for(int i = 0 ; i < len ; i ++) {
        char let_buf[1024];
        std::string xlist;
        if(i == 0) {
            xlist = "x0";
        } else {
            xlist = "temp_y0_" + std::to_string(i-1);
        }
        for(int j = 1 ; j < func_params.size() ; j ++) {
            xlist.append(", x" + std::to_string(j) + "[" + std::to_string(i) + "]");
        }
        sprintf(let_buf, "temp_y0_%d = %s(%s);", i, funcName.c_str(), xlist.c_str());
        letDecls.emplace_back(let_buf);
    }
    letDecls.emplace_back("y0 = temp_y0_" + std::to_string(len-1) + ";");
    letDecls.emplace_back("y1 = [");
    for(int j = 0 ; j < len ; j ++) {
        if(j != 0) {
            letDecls.back().append(", ");
        }
        letDecls.back().append("temp_y0_" + std::to_string(j));
    }
    letDecls.back().append("];");
    funcName = "mapfold_" + funcName + "_" + std::to_string(len);
    auto varDecls = buildVarTemps(func_returns, "y", len);
    myLustreVisitor.addFuncToEnd(funcName, LustreVisitorTool::buildLusFunction(funcName, params, returns, varDecls, letDecls));
    std::string res = funcName;
    res.append("(");
    res.append(myvis(ctx->list())).append(")");
    return res;
}

std::any ApplyExprVisitor::visitApply_mapw(LustreParser::Apply_mapwContext *ctx) {
    int len = 0;
    auto [func_params, func_returns] = get_params_returns(ctx->prefix_operator(), ctx->list()[1], ctx->const_expr(), len);
    std::string funcName;
    std::vector<std::pair<std::string, std::string>> params, returns;
    params.emplace_back("flag", "bool");
    returns.emplace_back("idx", "int");
    funcName = func_params.back();
    func_params.pop_back();
    func_returns.erase(func_returns.begin());
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        params.emplace_back("d" + std::to_string(i),  func_returns[i]);
        returns.emplace_back("y" + std::to_string(i),  func_returns[i] + "^" + std::to_string(len));
    }
    for(int i = 0 ; i < func_params.size() ; i ++) {
        params.emplace_back("x" + std::to_string(i),  func_params[i] + "^" + std::to_string(len));
    }
    std::vector<std::string> letDecls;
    for(int i = 0 ; i < len ; i ++) {
        char let_buf[1024];
        std::string ylist, xlist;
        for(int j = 0 ; j < func_params.size() ; j ++) {
            if(j != 0) {
                xlist.append(", ");
            }
            xlist.append("x" + std::to_string(j) + "[" + std::to_string(i) + "]");
        }
        ylist = "temp_flag0_" + std::to_string(i);
        for(int j = 0 ; j < func_returns.size() ; j ++) {
            ylist.append(", ");
            ylist.append("temp_y" + std::to_string(j) + "_" + std::to_string(i));
        }
        sprintf(let_buf, "%s = %s(%s);", ylist.c_str(), funcName.c_str(), xlist.c_str());
        letDecls.emplace_back(let_buf);
    }
    letDecls.push_back("idx = 0;");
    for(int i = 0 ; i < len ; i ++) {
        if(i == 0) {
            letDecls.push_back("if flag then");
        } else {
            letDecls.push_back("if temp_flag0_" + std::to_string(i-1) + " then");
        }
        letDecls.push_back("    idx = " + std::to_string(i) + ";");
        letDecls.push_back("else");
        letDecls.push_back("    temp_flag0_" + std::to_string(i) + " = false;");
        for(int j = 0 ; j < func_returns.size() ; j ++) {
            letDecls.push_back("    temp_y" + std::to_string(j) + "_" + std::to_string(i) + " = d" + std::to_string(j) +";");
        }
        letDecls.push_back("fi");
    }
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        letDecls.emplace_back("y" + std::to_string(i) + " = [");
        for(int j = 0 ; j < len ; j ++) {
            if(j != 0) {
                letDecls.back().append(", ");
            }
            letDecls.back().append("temp_y" + std::to_string(i) + "_" + std::to_string(j));
        }
        letDecls.back().append("];");
    }
    funcName = "mapw_" + funcName + "_" + std::to_string(len);
    auto tmpy = buildVarTemps(func_returns, "y", len);
    auto tmpf = buildVarTemps({"bool"}, "flag", len);
    tmpy.insert(tmpy.end(), tmpf.begin(), tmpf.end());
    myLustreVisitor.addFuncToEnd(funcName, LustreVisitorTool::buildLusFunction(funcName, params, returns, tmpy, letDecls));
    std::string res = funcName;
    res.append("(");
    res.append(myvis(ctx->simple_expr())).append(", ");
    res.append(myvis(ctx->list()[0])).append(", ");
    res.append(myvis(ctx->list()[1])).append(")");
    return res;
}

std::any ApplyExprVisitor::visitApply_mapwi(LustreParser::Apply_mapwiContext *ctx) {
    int len = 0;
    auto [func_params, func_returns] = get_params_returns(ctx->prefix_operator(), ctx->list()[1], ctx->const_expr(), len);
    std::string funcName;
    std::vector<std::pair<std::string, std::string>> params, returns;
    params.emplace_back("flag", "bool");
    returns.emplace_back("idx", "int");
    funcName = func_params.back();
    func_params.pop_back();
    func_params.erase(func_params.begin());
    func_returns.erase(func_returns.begin());
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        params.emplace_back("d" + std::to_string(i),  func_returns[i]);
        returns.emplace_back("y" + std::to_string(i),  func_returns[i] + "^" + std::to_string(len));
    }
    for(int i = 0 ; i < func_params.size() ; i ++) {
        params.emplace_back("x" + std::to_string(i),  func_params[i] + "^" + std::to_string(len));
    }
    std::vector<std::string> letDecls;
    for(int i = 0 ; i < len ; i ++) {
        char let_buf[1024];
        std::string ylist, xlist;
        for(int j = 0 ; j < func_params.size() ; j ++) {
            if(j != 0) {
                xlist.append(", ");
            }
            xlist.append("x" + std::to_string(j) + "[" + std::to_string(i) + "]");
        }
        ylist = "temp_flag0_" + std::to_string(i);
        for(int j = 0 ; j < func_returns.size() ; j ++) {
            ylist.append(", ");
            ylist.append("temp_y" + std::to_string(j) + "_" + std::to_string(i));
        }
        sprintf(let_buf, "%s = %s(%d, %s);", ylist.c_str(), funcName.c_str(), i, xlist.c_str());
        letDecls.emplace_back(let_buf);
    }
    letDecls.push_back("idx = 0;");
    for(int i = 0 ; i < len ; i ++) {
        if(i == 0) {
            letDecls.push_back("if flag then");
        } else {
            letDecls.push_back("if temp_flag0_" + std::to_string(i-1) + " then");
        }
        letDecls.push_back("    idx = " + std::to_string(i) + ";");
        letDecls.push_back("else");
        letDecls.push_back("    temp_flag0_" + std::to_string(i) + " = false;");
        for(int j = 0 ; j < func_returns.size() ; j ++) {
            letDecls.push_back("    temp_y" + std::to_string(j) + "_" + std::to_string(i) + " = d" + std::to_string(j) +";");
        }
        letDecls.push_back("fi");
    }
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        letDecls.emplace_back("y" + std::to_string(i) + " = [");
        for(int j = 0 ; j < len ; j ++) {
            if(j != 0) {
                letDecls.back().append(", ");
            }
            letDecls.back().append("temp_y" + std::to_string(i) + "_" + std::to_string(j));
        }
        letDecls.back().append("];");
    }
    funcName = "mapwi_" + funcName + "_" + std::to_string(len);
    auto tmpy = buildVarTemps(func_returns, "y", len);
    auto tmpf = buildVarTemps({"bool"}, "flag", len);
    tmpy.insert(tmpy.end(), tmpf.begin(), tmpf.end());
    myLustreVisitor.addFuncToEnd(funcName, LustreVisitorTool::buildLusFunction(funcName, params, returns, tmpy, letDecls));
    std::string res = funcName;
    res.append("(");
    res.append(myvis(ctx->simple_expr())).append(", ");
    res.append(myvis(ctx->list()[0])).append(", ");
    res.append(myvis(ctx->list()[1])).append(")");
    return res;
}

std::any ApplyExprVisitor::visitApply_foldw(LustreParser::Apply_foldwContext *ctx) {
    int len = 0;
    auto [func_params, func_returns] = get_params_returns(ctx->prefix_operator(), ctx->list(), ctx->const_expr(), len);
    std::string funcName;
    std::vector<std::pair<std::string, std::string>> params, returns;
    params.emplace_back("flag", "bool");
    returns.emplace_back("idx", "int");
    funcName = func_params.back();
    func_params.pop_back();
    func_returns.erase(func_returns.begin());
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        returns.emplace_back("y" + std::to_string(i),  func_returns[i]);
    }
    for(int i = 0 ; i < func_params.size() ; i ++) {
        if(i == 0) {
            params.emplace_back("x" + std::to_string(i),  func_params[i]);
        } else {
            params.emplace_back("x" + std::to_string(i),  func_params[i] + "^" + std::to_string(len));
        }
    }
    std::vector<std::string> letDecls;
    for(int i = 0 ; i < len ; i ++) {
        char let_buf[1024];
        std::string xlist;
        if(i == 0) {
            xlist.append("x0");
        } else {
            xlist.append("temp_y0_" + std::to_string(i-1));
        }
        for(int j = 1 ; j < func_params.size() ; j ++) {
            xlist.append(", ");
            xlist.append("x" + std::to_string(j) + "[" + std::to_string(i) + "]");
        }
        sprintf(let_buf, "temp_flag0_%d, temp_y0_%d = %s(%s);", i, i, funcName.c_str(), xlist.c_str());
        letDecls.emplace_back(let_buf);
    }
    letDecls.push_back("idx = 0;");
    for(int i = 0 ; i < len ; i ++) {
        if(i == 0) {
            letDecls.push_back("if flag then");
        } else {
            letDecls.push_back("if temp_flag0_" + std::to_string(i-1) + " then");
        }
        letDecls.push_back("    idx = " + std::to_string(i) + ";");
        letDecls.push_back("else");
        letDecls.push_back("    temp_flag0_" + std::to_string(i) + " = false;");
        if(i == 0) {
            letDecls.push_back("    temp_y0_"+ std::to_string(i) + " = x0;");
        } else {
            letDecls.push_back("    temp_y0_"+ std::to_string(i) + " = temp_y0_" + std::to_string(i-1) +";");
        }
        letDecls.push_back("fi");
    }
    letDecls.push_back("y0 = temp_y0_" + std::to_string(len-1) + ";");
    funcName = "foldw_" + funcName + "_" + std::to_string(len);
    auto tmpy = buildVarTemps(func_returns, "y", len);
    auto tmpf = buildVarTemps({"bool"}, "flag", len);
    tmpy.insert(tmpy.end(), tmpf.begin(), tmpf.end());
    myLustreVisitor.addFuncToEnd(funcName, LustreVisitorTool::buildLusFunction(funcName, params, returns, tmpy, letDecls));
    std::string res = funcName;
    res.append("(");
    res.append(myvis(ctx->simple_expr())).append(", ");
    res.append(myvis(ctx->list())).append(")");
    return res;
}

std::any ApplyExprVisitor::visitApply_foldwi(LustreParser::Apply_foldwiContext *ctx) {
    int len = 0;
    auto [func_params, func_returns] = get_params_returns(ctx->prefix_operator(), ctx->list(), ctx->const_expr(), len);
    std::string funcName;
    std::vector<std::pair<std::string, std::string>> params, returns;
    params.emplace_back("flag", "bool");
    returns.emplace_back("idx", "int");
    funcName = func_params.back();
    func_params.pop_back();
    func_params.erase(func_params.begin());
    func_returns.erase(func_returns.begin());
    for(int i = 0 ; i < func_returns.size() ; i ++) {
        returns.emplace_back("y" + std::to_string(i),  func_returns[i]);
    }
    for(int i = 0 ; i < func_params.size() ; i ++) {
        if(i == 0) {
            params.emplace_back("x" + std::to_string(i),  func_params[i]);
        } else {
            params.emplace_back("x" + std::to_string(i),  func_params[i] + "^" + std::to_string(len));
        }
    }
    std::vector<std::string> letDecls;
    for(int i = 0 ; i < len ; i ++) {
        char let_buf[1024];
        std::string xlist;
        if(i == 0) {
            xlist.append("x0");
        } else {
            xlist.append("temp_y0_" + std::to_string(i-1));
        }
        for(int j = 1 ; j < func_params.size() ; j ++) {
            xlist.append(", ");
            xlist.append("x" + std::to_string(j) + "[" + std::to_string(i) + "]");
        }
        sprintf(let_buf, "temp_flag0_%d, temp_y0_%d = %s(%d, %s);", i, i, funcName.c_str(), i, xlist.c_str());
        letDecls.emplace_back(let_buf);
    }
    letDecls.push_back("idx = 0;");
    for(int i = 0 ; i < len ; i ++) {
        if(i == 0) {
            letDecls.push_back("if flag then");
        } else {
            letDecls.push_back("if temp_flag0_" + std::to_string(i-1) + " then");
        }
        letDecls.push_back("    idx = " + std::to_string(i) + ";");
        letDecls.push_back("else");
        letDecls.push_back("    temp_flag0_" + std::to_string(i) + " = false;");
        if(i == 0) {
            letDecls.push_back("    temp_y0_"+ std::to_string(i) + " = x0;");
        } else {
            letDecls.push_back("    temp_y0_"+ std::to_string(i) + " = temp_y0_" + std::to_string(i-1) +";");
        }
        letDecls.push_back("fi");
    }
    letDecls.push_back("y0 = temp_y0_" + std::to_string(len-1) + ";");
    funcName = "foldwi_" + funcName + "_" + std::to_string(len);
    auto tmpy = buildVarTemps(func_returns, "y", len);
    auto tmpf = buildVarTemps({"bool"}, "flag", len);
    tmpy.insert(tmpy.end(), tmpf.begin(), tmpf.end());
    myLustreVisitor.addFuncToEnd(funcName, LustreVisitorTool::buildLusFunction(funcName, params, returns, tmpy, letDecls));
    std::string res = funcName;
    res.append("(");
    res.append(myvis(ctx->simple_expr())).append(", ");
    res.append(myvis(ctx->list())).append(")");
    return res;
}

// 返回值为函数的参数列表以及返回值列表的变量类型, 在参数列表最后再额外存储函数名
// 传参的len用引用形式，用于得到数组长度
std::pair<std::vector<std::string>, std::vector<std::string>>
ApplyExprVisitor::get_params_returns(LustreParser::Prefix_operatorContext *op_ctx, LustreParser::ListContext *list_ctx, LustreParser::Const_exprContext* const_ctx, int& len) {

    auto constValueVisitor = std::make_shared<ConstValueVisitor>(myLustreVisitor, myLustreVisitor.currentScope);
    auto constValue=constValueVisitor->visit(const_ctx);
    len=LustreVisitorTool::anyConverter<int>(constValue);
    if(dynamic_cast<LustreParser::Prefix_unaryContext *>(op_ctx) || dynamic_cast<LustreParser::Prefix_binaryContext *>(op_ctx)) {
//        auto ss = currentScope->resolve(list_ctx->simple_expr()[0]->getText());
//        auto typeDefSymbol=std::dynamic_pointer_cast<VariableSymbol>(ss)->getTypeDefSymbol();
//        std::string type = typeDefSymbol->getDefTypeLusString(typeDefSymbol->getDefType());   //获取list中的第一个值的类型 "int" 或 int^5
        auto getSimpleExprType = std::make_shared<GetSimpleExprType>(myLustreVisitor, currentScope);
        auto type = std::any_cast<std::string>(getSimpleExprType->visit(list_ctx->simple_expr()[0]));
        auto idx = type.find('^');
        if(idx != std::string::npos) {
            type = type.substr(0, idx);
        }
        auto [funcName, op] = std::any_cast<std::pair<std::string, std::string>>(myLustreVisitor.visit(op_ctx));
        std::vector<std::pair<std::string, std::string>> params, returns;
        std::vector<std::string> varDecls, letDecls;
        params.emplace_back("x0", type);
        char let_buf[1024];
        if(dynamic_cast<LustreParser::Prefix_binaryContext *>(op_ctx)) {        //二元运算符
            params.emplace_back("x1", type);
            sprintf(let_buf, "y0 = x0 %s x1;", op.c_str());
        } else {
            sprintf(let_buf, "y0 = %s x0;", op.c_str());
        }
        letDecls.emplace_back(let_buf);
        returns.emplace_back("y0", type);
        funcName.append("_").append(type);
        myLustreVisitor.addFuncToEnd(funcName, LustreVisitorTool::buildLusFunction(funcName, params, returns, varDecls, letDecls));
        if(dynamic_cast<LustreParser::Prefix_binaryContext *>(op_ctx)) {        //二元运算符
            return std::make_pair(std::vector{type, type, funcName}, std::vector{type});
        } else {
            return std::make_pair(std::vector{type, funcName}, std::vector{type});
        }
    } else {
        return std::any_cast<std::pair<std::vector<std::string>, std::vector<std::string>>>(myLustreVisitor.visit(op_ctx));
    }
}

std::vector<std::string> ApplyExprVisitor::buildVarTemps(const std::vector<std::string> &types, std::string tname,int num) {
    std::vector<std::string> varDecls;
    for (int i = 0; i < types.size(); i++) {
        std::string var_buf;
        for (int j = 0; j < num; j++) {
            if (j != 0) {
                var_buf.append(", ");
            }
            var_buf.append("temp_" + tname + std::to_string(i) + "_" + std::to_string(j));     //temp_yi_j
        }
        var_buf.append(" : " + types[i] + ";");
        varDecls.push_back(var_buf);
    }
    return varDecls;
}