//
// Created by 李奕星 on 2024/4/10.
//
#include <iostream>
#include <fstream>

#include "Tool/GetInput.h"
#include "Tool/ExportOutput.h"
#include "Translation/ExtractLustreInfo.h"

using namespace std;

int main(){
#ifdef __WIN32
    system("chcp 65001");         //解决windows下中文编码问题
#endif
    // get the lustreContent in lustre file;
    string inFilename = "input.lustre";
    string outFilename = "output.txt";
    string lustreContent = GetInput::getInputByFilename(inFilename);



    // export the result to the output file
    string result = ExtractLustreInfo::extractLustreInfo(lustreContent);
    ExportOutput::exportOutputToFile(outFilename, result);
}