//
// Created by 李奕星 on 2024/4/10.
//
#include <iostream>
#include "Tool/GetInput.h"
#include "Tool/ExportOutput.h"
#include "Translation/ExtractLustreInfo.h"
#include "Translation/LustreNode.h"
#include "Tool/CheckTool.h"
#include "Translation/VarStateList.h"

using namespace std;

int main(){
#ifdef __WIN32
    system("chcp 65001");         //解决windows下中文编码问题
#endif
    //将控制台输出信息转移到cmdMessage.txt
    std::ostringstream oss;
    std::streambuf* pCoutBuf = std::cout.rdbuf();  // 保存旧的 cout buffer
    std::cout.rdbuf(oss.rdbuf());


    // 从Lustre文件中读取lustre代码;
    string inFilename = "input.lustre";
    string outFilename = "output.txt";
    string lustreContent = GetInput::getInputByFilename(inFilename);

    // 利用lustre代码生成LustreNode类
    CheckTool::print("====================LustreNode类信息==========================");
    LustreNode lustreNode = ExtractLustreInfo::extractLustreInfo(lustreContent);
    lustreNode.showNodeMessage();

    // 利用LustreNode类生成VarStateList类
    CheckTool::print("====================VarStateList类信息==========================");
    VarStateList varStateList = *new VarStateList(lustreNode);
    varStateList.ShowMessage();


    // 导出结果信息到output.txt
    string result = lustreNode.getNodeMessage();
    ExportOutput::exportOutputToFile(outFilename, result);


    //将控制台输出信息转移到cmdMessage.txt
    std::cout.rdbuf(pCoutBuf);
    std::string cmdMessage = oss.str();  // 获取输出的字符串
    ExportOutput::exportOutputToFile("cmdMessage.txt", cmdMessage);
}