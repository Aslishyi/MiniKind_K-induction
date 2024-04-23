//
// Created by 李奕星 on 2024/4/22.
//

#ifndef MINIKIND_K_INDUCTION_CREATESOLVER_H
#define MINIKIND_K_INDUCTION_CREATESOLVER_H

#include <iostream>
#include <z3++.h>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <boost/algorithm/string/trim.hpp>
#include "../src/Translation/VarStateList.h"
#include "../Tool/StringTool.h"
#include "../Tool/Z3Tool.h"

using namespace z3;

class CreateSolver {
private:
    std::string NodeName;
    z3::context ctx;
    z3::solver mysolver = z3::solver(ctx);
    std::map<std::string, z3::expr> myvariables;
public:

    z3::solver build_z3solver(VarStateList varStateList);
    z3::expr parse_bool_digit_expr(std::map<std::string, z3::expr>& variables, std::string& expr_str);
    z3::expr parse_expr(const std::string& exprStr, std::map<std::string, z3::expr>& variables);

    z3::solver add_expr_to_solver(z3::solver &solver, z3::expr &expr);
    CreateSolver();
};



#endif //MINIKIND_K_INDUCTION_CREATESOLVER_H
