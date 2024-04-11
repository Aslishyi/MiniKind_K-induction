//
// Created by 李奕星 on 2024/4/11.
//

#include "StringVectorTool.h"
#include <algorithm> // for remove_if
#include <vector>
#include <string>
#include <boost/algorithm/string/trim.hpp>

bool isEmpty(const std::string& str) {
    return str.empty();
}


void StringVectorTool::removeEmptyStrings(std::vector<std::string> &vec) {
    vec.erase(std::remove_if(vec.begin(), vec.end(), isEmpty), vec.end());
}

//去除首尾空格
void StringVectorTool::trimStrings(std::vector<std::string> &vec) {
    for(auto& str : vec) {
        boost::trim(str);
    }
}

std::string StringVectorTool::mergeStringVector(std::vector<std::string> vec) {
    std::string str;
    for(const auto& item:vec){
        str += ("[" + item + "]\n");
    }
    return str;
}

void StringVectorTool::removeNewlineChar(std::vector<std::string> &vec) {
    for (auto& str : vec) {
        if (!str.empty() && str[0] == '\n') {
            str.erase(str.begin());
        }
    }
}


