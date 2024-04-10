//
// Created by 李奕星 on 2024/4/10.
//

#include "ExtractLustreInfo.h"


std::string ExtractLustreInfo::extractLustreInfo(const std::string &lustreCode) {
    // 定义正则表达式来匹配Lustre节点定义
    //TODO:编写能获取多行函数的正则表达式
    std::regex nodeRegex(R"(\s*node\s+(\w+)\s*\(\s*([^)]*)\s*\)\s*returns\s*\(\s*([^)]*)\s*\);\s*let\s*([^;]+);\s*tel;\s*)");
    // 定义正则表达式来匹配变量定义
    std::regex varsRegex(R"(\s*(\w+)\s*=\s*([^;]+);)");

    std::smatch nodeMatch;
    std::string result;

    // 在Lustre代码中搜索节点定义
    if (std::regex_search(lustreCode, nodeMatch, nodeRegex)) {
        std::string nodeName = nodeMatch[1];
        std::string inputs = nodeMatch[2];
        std::string outputs = nodeMatch[3];
        std::string body = nodeMatch[4];

        /*for(const auto& item:nodeMatch)
            std::cout<<item<<std::endl;*/

        // 分割输入和输出变量列表
        std::vector<std::string> inputVars, outputVars, bodyWords;
        boost::split(inputVars, inputs, boost::is_any_of(","));
        boost::split(outputVars, outputs, boost::is_any_of(","));

        std::smatch varsMatch;
        std::string initialState;
        std::string transitionRelation;
        std::string safetyProperty;

        // 输出测试
        body += ';';
        std::cout<<"body: "<<body<<std::endl;
        CheckTool::print("inputs",inputVars);
        CheckTool::print("outputs",outputVars);
        CheckTool::print("body",body);
        // 遍历变量定义并提取相关信息
        while (std::regex_search(body, varsMatch, varsRegex)) {
            std::string varName = varsMatch[1];
            std::string varExpr = varsMatch[2];

            for(const auto& item:varsMatch)
                std::cout<<"bodyLine: "<<item<<std::endl;

            /*// 构建转移关系
            transitionRelation += varsMatch[0];
            transitionRelation += ";\n";


            // 提取初始状态
            if (varName == "count1") {
                initialState = varExpr + ";\n";
            }

            // 提取安全属性（简单地假设为 "varName <= someValue" 的形式）
            if (varExpr.find("<=") != std::string::npos) {
                safetyProperty = varExpr + ";\n";
            }*/

            body = varsMatch.suffix().str();
        }

        // 格式化K-归纳的输入
        //TODO:输出的格式待定
        result = "system properties\n";
        result += "  I: " + initialState;
        result += "  T: " + transitionRelation;
        result += "  P: " + safetyProperty;
        result += "\nk-induction(I, T, P, 10);";  // 假设K-归纳的深度为10
    }

    return result;
}
