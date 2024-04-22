//
// Created by 李奕星 on 2024/4/12.
//

#ifndef MINIKIND_K_INDUCTION_VARSTATELIST_H
#define MINIKIND_K_INDUCTION_VARSTATELIST_H

#include <iostream>
#include <map>
#include <string>
#include "VarState.h"
#include "LustreNode.h"
#include "../Tool/StringTool.h"

class VarStateList {
private:
    std::string name; // node的名字
    std::map<std::string,VarState> varStateList;
public:
    VarStateList();
    std::string getNodeName();
    std::map<std::string,VarState> getVarStateList();
    explicit VarStateList(const LustreNode& lustreNode);
    void BuildVarStateList(LustreNode lustreNode);
    void ShowMessage();
};




#endif //MINIKIND_K_INDUCTION_VARSTATELIST_H
