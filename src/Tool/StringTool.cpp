//
// Created by 李奕星 on 2024/4/12.
//

#include "StringTool.h"

std::vector<std::string> StringTool::StrSplitting(std::string str, const std::string& dstr) {
    std::vector<std::string> res;
    boost::split(res, str, boost::is_any_of(dstr));
    StringVectorTool::trimStrings(res);
    return res;
}

bool StringTool::StrCheck(const std::string& str, const std::string& substr) {
    if(str.find(substr) == std::string::npos)
        return false;
    else
        return true;
}
