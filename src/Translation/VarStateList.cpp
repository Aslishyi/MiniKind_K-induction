//
// Created by 李奕星 on 2024/4/12.
//

#include "VarStateList.h"



void VarStateList::BuildVarStateList(LustreNode lustreNode) {

    this->name = lustreNode.getName();
    // 获取变量名和类型
    for(const auto& item: lustreNode.getInputs()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].setNameAndTypeByVarStr(item);
    }
    for(const auto& item: lustreNode.getOutputs()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].setNameAndTypeByVarStr(item);
    }
    for(const auto& item: lustreNode.getVars()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].setNameAndTypeByVarStr(item);
    }


    // 根据函数语句分类

    for(const auto& item: lustreNode.getStates()) {
        std::string var = item.first;
        std::string trans = item.second;

        this->varStateList[var].statement_pushback(trans);

    }

}

VarStateList::VarStateList() = default;

VarStateList::VarStateList(const LustreNode& lustreNode) {
    this->BuildVarStateList(lustreNode);
}

void VarStateList::ShowMessage() {
    for(const auto& [name, state]: this->varStateList){
        CheckTool::print("");
        CheckTool::print("[" + name + "]'s state:");
        CheckTool::print("1.VarName is: [" + state.getName() +"], VarType is: ["+ state.getType() + "]");
        CheckTool::print("2.[" + name + "]'s Statements:");
        for(const auto& item: state.getStatement()){
            CheckTool::print("{" + item + "}");
        }
    }

}

std::string VarStateList::getNodeName() {
    return this->name;
}

std::map<std::string, VarState> VarStateList::getVarStateList() {
    return this->varStateList;
}


