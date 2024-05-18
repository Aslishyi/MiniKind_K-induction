//
// Created by 李奕星 on 2024/4/22.
//

#include "CreateSolver.h"

#include <utility>


z3::expr CreateSolver::parse_bool_digit_expr(std::map<std::string, z3::expr> &variables, std::string &expr_str) {

    if (isdigit(expr_str[0])) {
        return ctx.int_val(stoi(expr_str));
    } else if (expr_str == "true") {
        return ctx.bool_val(true);
    } else if (expr_str == "false") {
        return ctx.bool_val(false);
    } else if (variables.find(expr_str) != variables.end()) {
        //return variables[expr_str];
        return variables.find(expr_str)->second;
    } else {
        expr_str = Z3Tool::infixToPostfix(expr_str);
        return parse_expr(expr_str, variables);
    }
}

z3::expr CreateSolver::parse_expr(const std::string &exprStr, std::map<std::string, z3::expr> &variables) {
    size_t pos = 0;
    std::string token;
    std::stack<z3::expr>exprStack;

    while (pos < exprStr.size()) {
        char ch = exprStr[pos];
        if (std::isalnum(ch)) {
            token.clear();
            while (pos < exprStr.size() && (std::isalnum(exprStr[pos]) || exprStr[pos] == '_')) {
                token += exprStr[pos++];
            }

            if (variables.find(token) != variables.end()) {
                exprStack.push(variables.find(token)->second);
            } else {
                // Create a new variable if it doesn't exist
                z3::expr newVar = ctx.int_const(token.c_str());
                //variables.find(token)->second = newVar;
                variables.insert({token,newVar});
                exprStack.push(newVar);
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (exprStack.size() < 2) {
                throw std::invalid_argument("exprStack.size() < 2");
            }
            z3::expr right = exprStack.top();
            exprStack.pop();
            z3::expr left = exprStack.top();
            exprStack.pop();

            switch (ch) {
                case '+':
                    exprStack.push(left + right);
                    break;
                case '-':
                    exprStack.push(left - right);
                    break;
                case '*':
                    exprStack.push(left * right);
                    break;
                case '/':
                    exprStack.push(left / right);
                    break;
            }
            pos++;
        } else if (std::isspace(ch)) {
            pos++;
        } else {
            throw std::invalid_argument("Invalid character in expression");
        }
    }

    if (exprStack.size() != 1) {
        throw std::invalid_argument("exprStack.size() != 1");
    }
    myvariables = variables;
    return exprStack.top();
}



z3::solver CreateSolver::build_z3solver(VarStateList varStateList) {
    z3::solver s(ctx);
    //z3::context c = ctx;
    this->NodeName = varStateList.getNodeName();
    std::map<std::string,VarState>stateList = varStateList.getVarStateList();

    std::map<std::string, z3::expr> variables;

    for(auto [name, state]:stateList) {
        std::string var_name = state.getName();
        std::string var_type  = state.getType();
        std::vector<std::string> var_statement = state.getStatement();

        if (var_type == "int") {
            //variables[var_name] = ctx.int_const(var_name.c_str());
            variables.insert({var_name,ctx.int_const(var_name.c_str())});
        } else if (var_type == "bool") {
            //variables[var_name] = ctx.bool_const(var_name.c_str());
            variables.insert({var_name, ctx.bool_const(var_name.c_str())});
        } else {
            std::cout << "Unsupported variable type: " << var_type << std::endl;
            exit(1);
        }
    }
    for(auto [name, state]:stateList){
        std::string var_name = state.getName();
        std::string var_type  = state.getType();
        std::vector<std::string> var_statement = state.getStatement();


        for(const auto& assignment: var_statement){
            std::string lhs = var_name;
            std::string rhs = assignment;
            z3::expr lhs_expr = variables.find(lhs)->second;

            if(StringTool::StrCheck(rhs, "true")
            || StringTool::StrCheck(rhs, "false") || isdigit(rhs[0])){
                z3::expr rhs_expr = parse_bool_digit_expr(variables, rhs);
                s.add(lhs_expr == rhs_expr);

            }
            else if(StringTool::StrCheck(rhs,"->")){
                // 处理 "->"
                std::vector<std::string> vstr = StringTool::StrSplitting(rhs,"->");
                std::string larrow = vstr[0];
                std::string rarrow = vstr[1];
                //std::cout << "Model before k induction:\n" << s.get_model() << "\n";
                // K-induction部分


                string tlarrow = larrow, trarrow = rarrow;

                larrow = Z3Tool::infixToPostfix(larrow);
                rarrow = Z3Tool::infixToPostfix(rarrow);
                z3::expr larrow_expr = parse_expr(larrow, variables);
                z3::expr rarrow_expr = parse_expr(rarrow, variables);

                CheckTool::print("Split case K-induction : [" + lhs + " = " + tlarrow + " -> " + trarrow + "]");
                s.push();
                if (KInduction::split_case_k_induction(ctx, s, lhs_expr, larrow_expr, rarrow_expr)) {
                    std::cout << "Split case K-induction verified successfully." << std::endl;
                } else {
                    std::cout << "Split case K-induction could not be verified." << std::endl;
                }
                s.pop();

                CheckTool::print("Combined case K-induction : [" + lhs + " = " + tlarrow + " -> " + trarrow + "]");
                if (KInduction::combined_case_k_induction(ctx, s, lhs_expr, larrow_expr, rarrow_expr)) {
                    std::cout << "Combined case K-induction verified successfully." << std::endl;
                } else {
                    std::cout << "Combined case K-induction could not be verified." << std::endl;
                }

            }
            else {
                //std::string constraint_str = lhs + " = " + rhs;
                z3::expr expr1 = parse_expr(lhs, variables);
                rhs = Z3Tool::infixToPostfix(rhs);
                z3::expr expr2 = parse_expr(rhs, variables);
                s.add(expr1 == expr2);
            }

        }
    }
    mysolver = s;
    myvariables = variables;
    return s;
}

z3::solver CreateSolver::add_expr_to_solver(solver &solver, expr &expr) {
    solver.add(expr);
    mysolver = solver;
    return solver;
}

CreateSolver::CreateSolver() = default;










