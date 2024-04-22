//
// Created by 李奕星 on 2024/4/22.
//

#include "Z3Tool.h"

solver Z3Tool::create_solver() {
    context ctx;
    solver s(ctx);
    return s;
}

bool Z3Tool::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int Z3Tool::getPriority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

std::string Z3Tool::infixToPostfix(const string &infix) {
    string postfix;
    stack<char> opStack;

    istringstream iss(infix);
    string token;
    while (iss >> token) {
        char ch = token[0];
        if (isalnum(ch)) {
            postfix += token + " ";  // 如果是数字或字母，直接输出到后缀表达式
        } else if (ch == '(') {
            opStack.push(ch);  // 如果是左括号，直接入栈
        } else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            opStack.pop();  // 弹出左括号
        } else {
            while (!opStack.empty() && getPriority(opStack.top()) >= getPriority(ch)) {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            opStack.push(ch);  // 将当前操作符入栈
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        postfix += " ";
        opStack.pop();
    }

    return postfix;
}
