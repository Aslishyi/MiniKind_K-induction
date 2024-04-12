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
    explicit VarStateList(const LustreNode& lustreNode);
    void PushPreByName (const std::string& name, const std::string& words);
    void PushGuardByName (const std::string& name, const std::string& words);
    void PushTranslateByName (const std::string& name, const std::string& words);
    void PushPostByName (const std::string& name, const std::string& words);
    void BuildVarStateList(LustreNode lustreNode);
    void ShowMessage();
};




#endif //MINIKIND_K_INDUCTION_VARSTATELIST_H
