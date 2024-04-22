//
// Created by 李奕星 on 2024/4/12.
//

#include "VarState.h"

#include <utility>
#include "../Tool/StringTool.h"

VarState::VarState(std::string name) {
    this->varName = std::move(name);
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


std::vector<std::string> VarState::getStatement() const {
    return this -> statement;
}

void VarState::statement_pushback(const std::string &str) {
    this -> statement.emplace_back(str);
}

VarState::VarState() = default;
