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
#include "../src/Translation/VarStateList.h"
#include "../Tool/StringTool.h"
#include "../Tool/Z3Tool.h"

using namespace z3;

class CreateSolver {
private:
    std::string NodeName;
    z3::context ctx;
public:

    z3::solver add_constraints(VarStateList varStateList);
    z3::expr parse_expression(std::map<std::string, z3::expr>& variables, const std::string& expr_str);
    z3::expr parseExpr(const std::string& exprStr, std::map<std::string, z3::expr>& variables);
    CreateSolver();
    CreateSolver(VarStateList varStateList);

};



#endif //MINIKIND_K_INDUCTION_CREATESOLVER_H
