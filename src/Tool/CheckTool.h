//
// Created by 李奕星 on 2024/4/10.
//

#ifndef MINIKIND_K_INDUCTION_CHECKTOOL_H
#define MINIKIND_K_INDUCTION_CHECKTOOL_H

#endif //MINIKIND_K_INDUCTION_CHECKTOOL_H


#include <iostream>
#include <string>
#include <vector>

class CheckTool{
public:
    static void print(const std::string& name, const std::string& str);
    static void print(const std::string& name, const std::vector<std::string>& vstr);
    static void print(const std::string& name, const std::string vstr[],int lengh);
};