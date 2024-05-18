//
// Created by 李奕星 on 2024/4/25.
//

#include "KInduction.h"

bool KInduction::split_case_k_induction(context &c, solver &s, expr &lhs_expr, expr &larrow_expr, expr &rarrow_expr) {

    expr k = c.int_const("k");
    s.add(k >= 0);

    std::cout << "Base case verified start: " << std::endl;
    for(int i = 1; i <= 5; i ++){
        s.push();
        s.add(k == i);
        s.add(lhs_expr == (ite(k == 1, larrow_expr, rarrow_expr)));
        if (s.check() == sat) std::cout << "Base case verified for k = " << i << std::endl;
        else {
            std::cout << "Base case failed for k = " << i << std::endl;
            model m = s.get_model();
            std::cout << m << std::endl;
            s.pop();
            return false;
        }
        s.pop();
    }

    std::cout << "Step case verified start: " << std::endl;
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

    expr k = c.int_const("k");
    s.add(k >= 0);

    std::cout << "Combined case verification start: " << std::endl;

    // Base case verification and k-unwinding in one go
    for(int i = 1; i <= 5; i++) {
        s.push(); // Start a new scope for the solver

        // Set k to the unwound iteration
        s.add(k == i);

        // Check the expressions up to k times, and assume valid on k+1
        s.add(lhs_expr == (ite(k == 1, larrow_expr, rarrow_expr)));

        // Assume the condition holds for k iterations
        expr assume_k = (lhs_expr == (ite(k == 1, larrow_expr, rarrow_expr)));
        // Assert the same condition for k+1, representing combined base and step case
        expr assert_k_plus_1 = (lhs_expr == (ite(k+1 == 1, larrow_expr, rarrow_expr)));
        s.add(implies(assume_k, assert_k_plus_1));

        check_result result = s.check();
        if (result == sat) {
            std::cout << "Combined case holds for k = " << i << std::endl;
        } else if (result == unsat) {
            std::cout << "Combined case fails for k = " << i << std::endl;
            model m = s.get_model();
            std::cout << m << std::endl;
            s.pop();
            return false;
        }
        s.pop(); // Restore the solver state
    }

    std::cout << "Combined case verification completed." << std::endl;
    return true; // If all iterations are successful
}

