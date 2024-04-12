//
// Created by 李奕星 on 2024/4/11.
//

#ifndef MINIKIND_K_INDUCTION_LUSTRENODE_H
#define MINIKIND_K_INDUCTION_LUSTRENODE_H
#include <iostream>
#include <string>
#include <vector>
#include "../Tool/CheckTool.h"
#include "../Tool/StringVectorTool.h"


/*
 * 输入的lustre node代码转化为LustreNode类储存
 *
 * 其中变量包括：输入参数、输出变量、自定义变量、函数语句
 * 函数语句根据“=”分割为左右两部分，左边为变量名，右边为赋值部分
 * */
class LustreNode{
private:
    std::string name;
    std::vector<std::string>inputs;
    std::vector<std::string>outputs;
    std::vector<std::string>vars;
    std::vector<std::string>bodyLines;
    std::vector<std::pair<std::string,std::string>> states;
public:
    LustreNode();
    LustreNode(std::string name, std::vector<std::string>inputs,std::vector<std::string>outputs,
               std::vector<std::string>vars,std::vector<std::string>bodyLines,
               std::vector<std::pair<std::string,std::string>> states);
    std::string getName();
    std::vector<std::string> getInputs();
    std::vector<std::string> getOutputs();
    std::vector<std::string> getVars();
    std::vector<std::string> getBodyLines();
    std::vector<std::pair<std::string,std::string>> getStates();
    void showNodeMessage();
    std::string getNodeMessage();

};
#endif //MINIKIND_K_INDUCTION_LUSTRENODE_H



