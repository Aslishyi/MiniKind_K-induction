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

    /*for(const auto& item: lustreNode.getInputs()){
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
    }*/
    /*for(const auto& item: lustreNode.getInputs()){
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
    }*/

    // 根据函数语句分类
    // 通过语句获取Guard信息
    // 通过语句获取Post信息
    for(const auto& item: lustreNode.getStates()) {
        std::string var = item.first;
        std::string trans = item.second;

        /* 存在由 "->" 与 "if" 构成的循环
         * 目前只能处理由"->"与"if"构成的循环
         * 如果日后需要匹配更多种类的循环
         * 可以将语句中的循环处理独立为一个新类
         * */
        if (StringTool::StrCheck(trans, "->") && StringTool::StrCheck(trans, "if")){
            std::string preMessage = StringTool::get_substring_to(trans, "->");
            this->varStateList[var].pre_pushback(preMessage);

            std::string guardMessage = StringTool::get_substring_between(trans, "if","then");
            this->varStateList[var].guard_pushback(guardMessage);

            std::string translateMessage = StringTool::get_substring_from(trans, "else");
            this->varStateList[var].translate_pushback(translateMessage);

            std::string postMessage = StringTool::get_substring_between(trans, "then", "else");
            this->varStateList[var].post_pushback(postMessage);
        }
        else if(StringTool::StrCheck(trans, "->"))
            this->varStateList[var].translate_pushback(trans);

        else
            this->varStateList[var].pre_pushback(trans);
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


