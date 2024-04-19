//
// Created by 李奕星 on 2024/4/10.
//
#include <fstream>
#include "GetInput.h"


std::string GetInput::getInputByFilename(const std::string& filename) {
    std::ifstream inputFile("../src/" + filename);
    // 读取 input.Lustre 文件内容
    std::string content((std::istreambuf_iterator<char>(inputFile)),
                        std::istreambuf_iterator<char>());
    // 关闭 input.Lustre 文件
    inputFile.close();
    return content;
}
