//
// Created by 李奕星 on 2024/4/22.
//


#include "CreateSolver.h"

#include <utility>


z3::expr CreateSolver::parse_expression(std::map<std::string, z3::expr> &variables, const std::string &expr_str) {
    std::string::size_type arrow_pos = expr_str.find("->");
    if (arrow_pos == std::string::npos) {
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
            std::cerr << "Invalid expression: " << expr_str << std::endl;
            exit(1);
        }
    } else {
        std::string init_str = expr_str.substr(0, arrow_pos);
        std::string pre_str = expr_str.substr(arrow_pos + 2);

        z3::expr init_expr = parse_expression(variables, init_str);
        z3::expr pre_expr = parse_expression(variables, pre_str);

        return ite(init_expr, pre_expr, variables.find(init_str)->second);
    }
}

z3::expr CreateSolver::parseExpr(const std::string &exprStr, std::map<std::string, z3::expr> &variables) {
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

    return exprStack.top();
}



z3::solver CreateSolver::add_constraints(VarStateList varStateList) {
    solver s(ctx);
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

        /*if (var_type == "int") {
            //variables[var_name] = ctx.int_const(var_name.c_str());
            variables.insert({var_name,ctx.int_const(var_name.c_str())});
        } else if (var_type == "bool") {
            //variables[var_name] = ctx.bool_const(var_name.c_str());
            variables.insert({var_name, ctx.bool_const(var_name.c_str())});
        } else {
            std::cout << "Unsupported variable type: " << var_type << std::endl;
            exit(1);
        }*/

        for(const auto& assignment: var_statement){
            std::string lhs = var_name;
            std::string rhs = assignment;
            z3::expr lhs_expr = variables.find(lhs)->second;
            if(StringTool::StrCheck(rhs,"->") || StringTool::StrCheck(rhs, "true")
            || StringTool::StrCheck(rhs, "false") || isdigit(rhs[0])){
                z3::expr rhs_expr = parse_expression(variables, rhs);
                s.add(lhs_expr == rhs_expr);
            }
            else {
                //std::string constraint_str = lhs + " = " + rhs;
                z3::expr expr1 = parseExpr(lhs,variables);
                rhs = Z3Tool::infixToPostfix(rhs);
                z3::expr expr2 = parseExpr(rhs,variables);
                //z3::expr constraint = (expr1 == expr2);
                //add报错
                s.add(expr1 == expr2);
            }

        }
    }

    return s;
}

CreateSolver::CreateSolver( VarStateList varStateList) {
    add_constraints(std::move(varStateList));
}

CreateSolver::CreateSolver() = default;








