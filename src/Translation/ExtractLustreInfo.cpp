//
// Created by 李奕星 on 2024/4/10.
//

#include "ExtractLustreInfo.h"


LustreNode ExtractLustreInfo::extractLustreInfo(const std::string &lustreCode) {
    // 定义正则表达式来匹配Lustre节点定义
    //std::regex nodeRegex(R"(\s*node\s+(\w+)\s*\(\s*([^)]*)\s*\)\s*returns\s*\(\s*([^)]*)\s*\);(?:\s*var\s*([\s\S]*?))?\s*let\s*([\s\S]*?);\s*tel;\s*)");
    std::regex nodeRegex(R"(\s*(?:node|function)\s+(\w+)\s*\(\s*([^)]*)\s*\)\s*returns\s*\(\s*([^)]*)\s*\);(?:\s*var\s*([\s\S]*?))?\s*let\s*([\s\S]*?);\s*tel;\s*)");

    // 定义正则表达式来匹配变量定义
    std::regex varsRegex(R"(\s*(\w+)\s*=\s*([^;]+);)");

    std::smatch nodeMatch;
    LustreNode node;

    // 在Lustre代码中搜索节点定义
    if (std::regex_search(lustreCode, nodeMatch, nodeRegex)) {
        std::string nodeName = nodeMatch[1];
        std::string inputs = nodeMatch[2];
        std::string outputs = nodeMatch[3];
        std::string vars = nodeMatch[4];
        std::string body = nodeMatch[5];

        // 分割输入和输出变量列表
        std::vector<std::string> inputVars, outputVars,varsList , bodyWords;
        std::vector<std::pair<std::string,std::string>> states;
        boost::split(inputVars, inputs, boost::is_any_of(";"));
        boost::split(outputVars, outputs, boost::is_any_of(";"));
        boost::split(varsList, vars, boost::is_any_of(";\n"));
        StringVectorTool::removeEmptyStrings(varsList);
        StringVectorTool::trimStrings(outputVars);
        StringVectorTool::trimStrings(varsList);
        std::smatch varsMatch;
        std::string initialState;
        std::string transitionRelation;
        std::string safetyProperty;

        // 输出测试
        body += ';';
        // 遍历变量定义并提取相关信息
        while (std::regex_search(body, varsMatch, varsRegex)) {
            std::string varName = varsMatch[1];
            std::string varExpr = varsMatch[2];

            bodyWords.emplace_back(varsMatch[0]);
            states.emplace_back(varsMatch[1],varsMatch[2]);

            body = varsMatch.suffix().str();
        }

        // 将lustre node转为node类
        StringVectorTool::removeNewlineChar(bodyWords);
        StringVectorTool::trimStrings(bodyWords);
        node = LustreNode(nodeName,inputVars,outputVars,varsList,bodyWords,states);
    }

    return node;
}
