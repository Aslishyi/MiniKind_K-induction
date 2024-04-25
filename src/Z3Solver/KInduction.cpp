//
// Created by 李奕星 on 2024/4/25.
//

#include "KInduction.h"

bool KInduction::split_case_k_induction(context &c, solver &s, expr &lhs_expr, expr &larrow_expr, expr &rarrow_expr) {
    expr k = c.int_const("k");

    // Base Case: k == 1, assert lhs_expr == larrow_expr
    s.add(k == 1);
    s.add(lhs_expr == larrow_expr);
    check_result base_result = s.check();
    if (base_result == unsat) {
        std::cout << "Base case failed to hold." << std::endl;
        model m = s.get_model();
        std::cout << "Base case counterexample found:\n k = " << m.eval(k)
                  << "\nlhs_expr = " << m.eval(lhs_expr) << "\nlarrow_expr = " << m.eval(larrow_expr)
                  << "\nrarrow_expr = " << m.eval(rarrow_expr) << std::endl;
        return false;
    } else if (base_result == sat) {
        model m = s.get_model();
        std::cout << "Base case holds!" << std::endl;
        //std::cout << "Base case counterexample found: k = " << m.eval(k) << ", lhs_expr = " << m.eval(lhs_expr) << ", larrow_expr = " << m.eval(larrow_expr) << std::endl;
        //return false;
    }

    // Clear solver for inductive step
    s.reset();

    // Inductive Step: Assume valid for k, prove for k + 1
    expr k_prime = c.int_const("k_prime");
    s.add(k_prime == k + 1);
    s.add(implies(k == 1, lhs_expr == larrow_expr));
    s.add(implies(k > 1, lhs_expr == rarrow_expr));

    // Prove for k + 1
    s.add(implies(k_prime == 1, lhs_expr == larrow_expr));
    s.add(implies(k_prime > 1, lhs_expr == rarrow_expr));

    check_result step_result = s.check();
    if (step_result == sat) {
        std::cout << "Step case holds!" << std::endl;
        return true;
    } else if (step_result == unsat) {
        std::cout << "Step case failed to hold." << std::endl;
        model m = s.get_model();
        std::cout << "Step case counterexample found:\n k = " << m.eval(k) << "\nk_prime = " << m.eval(k_prime)
                  << "\nlhs_expr = " << m.eval(lhs_expr) << "\nlarrow_expr = " << m.eval(larrow_expr)
                  << "\nrarrow_expr = " << m.eval(rarrow_expr) << std::endl;
        return false;
    }
    return false; // Default return for unexpected cases
}
