//
// Created by 李奕星 on 2024/4/12.
//

#include "VarStateList.h"

void VarStateList::PushPreByName(const std::string& name, const std::string& words) {
    this->varStateList[name].pre_pushback(words);
}

void VarStateList::PushGuardByName(const std::string& name, const std::string& words) {
    this->varStateList[name].guard_pushback(words);
}

void VarStateList::PushTranslateByName(const std::string& name, const std::string& words) {
    this->varStateList[name].translate_pushback(words);
}

void VarStateList::PushPostByName(const std::string& name, const std::string& words) {
    this->varStateList[name].post_pushback(words);
}

void VarStateList::BuildVarStateList(LustreNode lustreNode) {

    this->name = lustreNode.getName();
    // 获取变量名和类型
    for(const auto& item: lustreNode.getInputs()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].getVarStr(item);
    }
    for(const auto& item: lustreNode.getOutputs()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].getVarStr(item);
    }
    for(const auto& item: lustreNode.getVars()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].getVarStr(item);
    }

    // TODO:通过语句获取Guard信息
    for(const auto& item: lustreNode.getInputs()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].guard_pushback("GrandMessage");
    }
    for(const auto& item: lustreNode.getOutputs()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].guard_pushback("GrandMessage");
    }
    for(const auto& item: lustreNode.getVars()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].guard_pushback("GrandMessage");
    }

    // TODO:根据函数语句分类
    for(const auto& item: lustreNode.getStates()) {
        std::string var = item.first;
        std::string trans = item.second;
        if (StringTool::StrCheck(trans, "pre"))
            this->varStateList[var].translate_pushback(trans);
        else
            this->varStateList[var].pre_pushback(trans);
    }

    // TODO:通过语句获取Post信息
    for(const auto& item: lustreNode.getInputs()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].post_pushback("PostMessage");
    }
    for(const auto& item: lustreNode.getOutputs()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].post_pushback("PostMessage");
    }
    for(const auto& item: lustreNode.getVars()){
        std::vector<std::string> vec;
        vec = StringTool::StrSplitting(item,":");
        this->varStateList[vec[0]].post_pushback("PostMessage");
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
        CheckTool::print("2.[" + name + "]'s Pre:");
        for(const auto& item: state.getPre()){
            CheckTool::print("{" + item + "}");
        }
        CheckTool::print("3.[" + name + "]'s Guard:");
        for(const auto& item: state.getGuard()){
            CheckTool::print("{" + item + "}");
        }
        CheckTool::print("4.[" + name + "]'s Translate:");
        for(const auto& item: state.getTranslate()){
            CheckTool::print("{" + item + "}");
        }
        CheckTool::print("5.[" + name + "]'s Post:");
        for(const auto& item: state.getPost()){
            CheckTool::print("{" + item + "}");
        }
    }

}


