//
// Created by 李奕星 on 2024/4/25.
//

#include "KInduction.h"

bool KInduction::split_case_k_induction(context &c, solver &s, expr &lhs_expr, expr &larrow_expr, expr &rarrow_expr) {

    expr k = c.int_const("k");
    s.add(k >= 0);
    s.push();
    // Base Case: k == 1, assert lhs_expr == larrow_expr
    s.add(k == 1);
    s.add(lhs_expr == larrow_expr);
    check_result base_result = s.check();
    if (base_result == unsat) {
        std::cout << "Base case failed to hold." << std::endl;
        model m = s.get_model();
        std::cout << m << std::endl;
        /*std::cout << "Base case counterexample found:\n k = " << m.eval(k)
                  << "\nlhs_expr = " << m.eval(lhs_expr) << "\nlarrow_expr = " << m.eval(larrow_expr)
                  << "\nrarrow_expr = " << m.eval(rarrow_expr) << std::endl;*/
        s.pop();
        return false;
    } else if (base_result == sat) {
        model m = s.get_model();
        std::cout << "Base case holds!" << std::endl;
        //std::cout << m << std::endl;
        /*std::cout << "Base case counterexample found:\n k = " << m.eval(k)
                  << "\nlhs_expr = " << m.eval(lhs_expr) << "\nlarrow_expr = " << m.eval(larrow_expr)
                  << "\nrarrow_expr = " << m.eval(rarrow_expr) << std::endl;*/
        //return false;
        s.pop();
    }

    // Clear solver for inductive step
    //s.reset();

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
        model m = s.get_model();
        //std::cout << m << std::endl;
        /*std::cout << "Step case counterexample found:\n k = " << m.eval(k) << "\nk_prime = " << m.eval(k_prime)
                  << "\nlhs_expr = " << m.eval(lhs_expr) << "\nlarrow_expr = " << m.eval(larrow_expr)
                  << "\nrarrow_expr = " << m.eval(rarrow_expr) << std::endl;*/

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

bool KInduction::combined_case_k_induction(context &c, solver &s, expr &lhs_expr, expr &larrow_expr, expr &rarrow_expr) {
    // Variables used in the loop
    z3::expr k = c.int_const("k");


    // Initial state where k = 1
    z3::expr base_case = (k == 1 && lhs_expr == larrow_expr);

    // Step case - assume property holds for k, prove for k+1
    // Assumption: lhs_expr == (k == 1 ? larrow_expr : rarrow_expr)
    z3::expr inductive_assumption = implies(k == 1, lhs_expr == larrow_expr) && implies(k != 1, lhs_expr == rarrow_expr);
    z3::expr inductive_step = implies(inductive_assumption && k >= 1,
                                      (k + 1 == 1 ? lhs_expr == larrow_expr : lhs_expr == rarrow_expr));

    // Adding both cases to the solver
    s.add(base_case);
    s.add(inductive_step);

    // Check the solver for possible solutions
    switch (s.check()) {
        case z3::sat:
            std::cout << "Loop is correct under given assumptions." << std::endl;
            // std::cout << s.get_model() << std::endl;
            return true;
            break;
        case z3::unsat:
            std::cout << "Found a counterexample, loop might be incorrect:" << std::endl;
            std::cout << s.get_model() << std::endl;
            return false;
            break;
        case z3::unknown:
            std::cout << "Unable to determine correctness." << std::endl;
            return false;
            break;
    }
    return false;

}
