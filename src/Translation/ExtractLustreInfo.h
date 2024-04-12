//
// Created by 李奕星 on 2024/4/10.
//

#ifndef MINIKIND_K_INDUCTION_EXTRACTLUSTREINFO_H
#define MINIKIND_K_INDUCTION_EXTRACTLUSTREINFO_H


#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <boost/algorithm/string.hpp>
#include "../Tool/StringVectorTool.h"
#include "LustreNode.h"

class ExtractLustreInfo{
public:
    static LustreNode extractLustreInfo(const std::string& lustreCode);
};


#endif //MINIKIND_K_INDUCTION_EXTRACTLUSTREINFO_H
