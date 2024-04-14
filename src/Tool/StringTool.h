//
// Created by 李奕星 on 2024/4/12.
//

#ifndef MINIKIND_K_INDUCTION_STRINGTOOL_H
#define MINIKIND_K_INDUCTION_STRINGTOOL_H

#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "StringVectorTool.h"

class StringTool {
public:
    static std::vector<std::string> StrSplitting(std::string str, const std::string& dstr);
    static bool StrCheck(const std::string& str, const std::string& substr);
    static std::string get_substring_between(const std::string& str, const std::string& x, const std::string& y);
    static std::string get_substring_to(const std::string& x, const std::string& y);
    static std::string get_substring_from(const std::string& x, const std::string& y);
};

#endif //MINIKIND_K_INDUCTION_STRINGTOOL_H
