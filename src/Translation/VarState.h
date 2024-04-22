//
// Created by 李奕星 on 2024/4/12.
//

#ifndef MINIKIND_K_INDUCTION_VARSTATE_H
#define MINIKIND_K_INDUCTION_VARSTATE_H

#include <string>
#include <iostream>
#include <vector>

class VarState {
private:
    std::string varName;
    std::string type;
    std::vector<std::string> statement;

public:
    explicit VarState(std::string name);
    void setName(const std::string& name);
    void setType(const std::string& vartype);
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getType() const;
    void setNameAndTypeByVarStr(const std::string& varStr);
    [[nodiscard]] std::vector<std::string> getStatement() const;
    void statement_pushback(const std::string& str);

    VarState();
};




#endif //MINIKIND_K_INDUCTION_VARSTATE_H
