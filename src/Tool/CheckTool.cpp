//
// Created by 李奕星 on 2024/4/10.
//

#include "CheckTool.h"

void CheckTool::print(const std::string& name, const std::string& str) {
    std::cout<<name+": ["+str+"]"<<std::endl;
}

void CheckTool::print(const std::string& name, const std::vector<std::string>& vstr) {
    std::cout<<name+": [";
    for(const auto &item:vstr)
        std::cout<< item + "; ";
    std::cout<<"]"<<std::endl;

}

void CheckTool::print(const std::string &name, const std::string *vstr, int lengh) {
    std::cout<<name+": [";
    for(int i = 0; i < lengh; i++)
        std::cout<< vstr[i] + "; ";
    std::cout<<"]"<<std::endl;
}

void CheckTool::print(const std::string& str) {
    std::cout<<str<<std::endl;
}
