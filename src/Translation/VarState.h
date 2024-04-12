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
    std::vector<std::string> pre;
    std::vector<std::string> guard;
    std::vector<std::string> translate;
    std::vector<std::string> post;

public:
    explicit VarState(std::string name);

    void setName(const std::string& name);
    void setType(const std::string& vartype);

    std::string getName() const;
    std::string getType() const;
    void getVarStr(const std::string& varStr);
    std::vector<std::string> getPre() const;
    std::vector<std::string> getGuard() const;
    std::vector<std::string> getTranslate() const;
    std::vector<std::string> getPost() const;


    void pre_pushback(const std::string& str);
    void guard_pushback(const std::string& str);
    void translate_pushback(const std::string& str);
    void post_pushback(const std::string& str);

    VarState();
};




#endif //MINIKIND_K_INDUCTION_VARSTATE_H
