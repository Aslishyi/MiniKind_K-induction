//
// Created by 李奕星 on 2024/4/10.
//

#include "ExtractLustreInfo.h"

std::string ExtractLustreInfo::extractLustreInfo(const std::string &lustreCode) {
    std::regex nodeRegex(R"(\s*node\s+(\w+)\s*\(([^)]+)\)\s*returns\s*\(([^)]+)\);\s*let\s*([^;]+);\s*tel;\s*)");
    std::regex varsRegex(R"(\s*(\w+)\s*=\s*([^;]+);)");

    std::smatch nodeMatch;
    std::string result;

    if (std::regex_search(lustreCode, nodeMatch, nodeRegex)) {
        std::string nodeName = nodeMatch[1];
        std::string inputs = nodeMatch[2];
        std::string outputs = nodeMatch[3];
        std::string body = nodeMatch[4];

        std::vector<std::string> inputVars, outputVars;
        boost::split(inputVars, inputs, boost::is_any_of(","));
        boost::split(outputVars, outputs, boost::is_any_of(","));

        std::smatch varsMatch;
        std::string initialState;
        std::string transitionRelation;
        std::string safetyProperty;

        while (std::regex_search(body, varsMatch, varsRegex)) {
            std::string varName = varsMatch[1];
            std::string varExpr = varsMatch[2];

            if (std::find(outputVars.begin(), outputVars.end(), varName) != outputVars.end()) {
                transitionRelation += varExpr + " -> pre " + varName + ";\n";
            }

            if (varName == "init") {
                initialState = varExpr + ";\n";
            }

            // For demonstration, assuming safety property is "varName <= someValue"
            if (varExpr.find("<=") != std::string::npos) {
                safetyProperty = varExpr + ";\n";
            }

            body = varsMatch.suffix().str();
        }

        result = "system properties\n";
        result += "  I: " + initialState;
        result += "  T: " + transitionRelation;
        result += "  P: " + safetyProperty;
        result += "\nk-induction(I, T, P, 10);";  // Assuming a depth of 10 for k-induction
    }

    return result;
}
