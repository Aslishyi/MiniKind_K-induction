//
// Created by 李奕星 on 2024/4/11.
//

#ifndef MINIKIND_K_INDUCTION_LUSTRENODE_H
#define MINIKIND_K_INDUCTION_LUSTRENODE_H

#endif //MINIKIND_K_INDUCTION_LUSTRENODE_H

#include <iostream>
#include <string>
#include <vector>
#include "../Tool/CheckTool.h"
#include "../Tool/StringVectorTool.h"

#ifndef LUSTRENODE_H
#define LUSTRENODE_H

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

#endif // LUSTRENODE_H