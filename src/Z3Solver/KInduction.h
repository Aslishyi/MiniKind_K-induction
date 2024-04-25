//
// Created by 李奕星 on 2024/4/25.
//

#ifndef MINIKIND_K_INDUCTION_KINDUCTION_H
#define MINIKIND_K_INDUCTION_KINDUCTION_H

#include <z3++.h>
#include <iostream>

using namespace z3;


class KInduction {
public:
    static bool split_case_k_induction(context &c, solver &s, expr &lhs_expr, expr &larrow_expr, expr &rarrow_expr);
};

#endif //MINIKIND_K_INDUCTION_KINDUCTION_H
