//
// Created by 李奕星 on 2024/4/22.
//

#ifndef MINIKIND_K_INDUCTION_Z3TOOL_H
#define MINIKIND_K_INDUCTION_Z3TOOL_H

#include <iostream>
#include <z3++.h>
#include <string>
#include <stack>
#include <sstream>
using namespace z3;
using namespace std;

class Z3Tool {
public:
    static solver create_solver();
    // 判断字符是否为运算符
    static bool isOperator(char c);
    // 获取运算符优先级
    static int getPriority(char op);
    // 中缀表达式转换为后缀表达式
    static std::string infixToPostfix(const std::string& infix);
};

#endif //MINIKIND_K_INDUCTION_Z3TOOL_H
