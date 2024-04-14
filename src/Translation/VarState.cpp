//
// Created by 李奕星 on 2024/4/12.
//

#include "VarState.h"

#include <utility>
#include "../Tool/StringTool.h"

VarState::VarState(std::string name) {
    this->varName = std::move(name);
}

void VarState::pre_pushback(const std::string& str) {
    this->pre.emplace_back(str);
}

void VarState::guard_pushback(const std::string& str) {
    this->guard.emplace_back(str);
}

void VarState::translate_pushback(const std::string& str) {
    this->translate.emplace_back(str);
}

void VarState::post_pushback(const std::string& str) {
    this->post.emplace_back(str);
}

void VarState::setName(const std::string& name) {
    this->varName = name;
}

void VarState::setType(const std::string& varType) {
    this->type = varType;
}

void VarState::setNameAndTypeByVarStr(const std::string& varStr) {
    std::vector<std::string> res;
    res = StringTool::StrSplitting(varStr, ":");
    this->setName(res[0]);
    this->setType(res[1]);
}

std::string VarState::getName() const {
    return this->varName;
}

std::string VarState::getType() const {
    return this->type;
}

std::vector<std::string> VarState::getPre() const {
    return this->pre;
}

std::vector<std::string> VarState::getGuard()  const{
    return this->guard;
}

std::vector<std::string> VarState::getTranslate() const {
    return this->translate;
}

std::vector<std::string> VarState::getPost() const {
    return this->post;
}

VarState::VarState() = default;
