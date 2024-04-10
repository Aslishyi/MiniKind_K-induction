//
// Created by 李奕星 on 2024/4/10.
//
#include <fstream>
#include "ExportOutput.h"


void ExportOutput::exportOutputToFile(const std::string &filename, const std::string &content) {
    // 打开 output.txt 文件以写入内容
    std::ofstream outputFile("../src/" + filename);

    // 写入 input.lustre 文件内容到 output.txt 文件
    outputFile << content;
    // 关闭 output.txt 文件
    outputFile.close();
}
