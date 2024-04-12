//
// Created by 李奕星 on 2024/4/11.
//

#ifndef MINIKIND_K_INDUCTION_STRINGVECTORTOOL_H
#define MINIKIND_K_INDUCTION_STRINGVECTORTOOL_H

#include <algorithm> // for remove_if
#include <vector>
#include <string>



class StringVectorTool{
public:
    static void removeEmptyStrings(std::vector<std::string>& vec);
    static void removeNewlineChar(std::vector<std::string>& vec);
    static void trimStrings(std::vector<std::string>& vec);
    static std::string mergeStringVector(const std::vector<std::string>& vec);
};



#endif //MINIKIND_K_INDUCTION_STRINGVECTORTOOL_H


