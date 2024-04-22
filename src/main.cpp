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
#include <memory>
#include "lustre/generated/LustreLexer.h"
#include "lustre/generated/LustreParser.h"
#include "tree/ParseTree.h"
#include "lustre/visitor/MyLustreVisitor.h"
#include "lustre/visitor/SymbolVisitor.h"
#include "lustre/visitor/SecondSymbolVisitor.h"
#include "lustre/tool/SpdlogTool.h"
#include "Z3Solver/CreateSolver.h"
#include "Tool/Z3Tool.h"
#include <z3++.h>
using namespace std;
using namespace z3;

int main(int argc, char **argv) {
#ifdef __WIN32
    system("chcp 65001");         //解决windows下中文编码问题
#endif

    /*============================== 项目模块一:  L2C解析模块 ======================================*/
    string inputFile = "G:\\Github\\MiniKind_k-induction\\src\\input.Lustre";
    //设置日志输出级别
    spdlog::set_level(spdlog::level::info);
    string inputString;

    auto inputStream = make_unique<ifstream>();
    std::unique_ptr<antlr4::ANTLRInputStream> input;
    if (!inputFile.empty()) {
        // 读入数据流
        inputStream->open(inputFile);
        //文件无法打开
        if (!inputStream->is_open()) {
            SpdlogTool::logErr->error("文件无法打开:" + inputFile);
            return -1;
        }
        input = make_unique<antlr4::ANTLRInputStream>(*inputStream);
    } else {
        // 从字符串中创建输入流
        input = make_unique<antlr4::ANTLRInputStream>(inputString);
    }
    //新建词法分析器处理数据流
    auto lexer = make_unique<LustreLexer>(input.get());
    //新建词法符号缓冲区 存储词法分析器将生成的词法符号
    auto tokens = make_unique<antlr4::CommonTokenStream>(lexer.get());
    //新建语法分析器处理词法符号缓冲区内容
    auto parser = make_unique<LustreParser>(tokens.get());
    //新建一个通用的、能触发回调函数的语法分析树遍历器
    antlr4::tree::ParseTree *tree = parser->program();

    //预先构建符号表
    auto symbolVisitor = make_unique<SymbolVisitor>();
    symbolVisitor->visit(tree);
    //二次遍历，解决符号表先调用后定义问题
    auto secondSymbolVisitor = make_unique<SecondSymbolVisitor>(symbolVisitor->scopes, symbolVisitor->globals);
    secondSymbolVisitor->visit(tree);
    //转换语法
    auto myLustreVisitor = make_unique<MyLustreVisitor>(secondSymbolVisitor->scopes, secondSymbolVisitor->globals);
    //输出转换后的语法
    auto SSA = std::any_cast<std::string>(myLustreVisitor->visit(tree));

    inputStream->close();

    std::cout<<SSA<<std::endl;
    ExportOutput::exportOutputToFile("SSA.lustre", SSA);

    /*============================== 项目模块二:  模型验证模块 ======================================*/
    /*//将控制台输出信息转移到cmdMessage.txt
    std::ostringstream oss;
    std::streambuf* pCoutBuf = std::cout.rdbuf();  // 保存旧的 cout buffer
    std::cout.rdbuf(oss.rdbuf());*/


    // 从Lustre文件中读取lustre代码;
    string inFilename = "SSA.lustre";
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

    // 利用VarStateList类生成CreateSolver类
    CheckTool::print("====================CreateSolver类信息==========================");

    CreateSolver createSolver = CreateSolver();
    z3::solver solver  = createSolver.add_constraints(varStateList);
    //z3::solver solver = Z3Tool::create_solver();
    cout << "Solver:\n" << solver << endl;

    // 导出结果信息到output.txt
    string result = lustreNode.getNodeMessage();
    ExportOutput::exportOutputToFile(outFilename, result);

/*
    //将控制台输出信息转移到cmdMessage.txt
    std::cout.rdbuf(pCoutBuf);
    std::string cmdMessage = oss.str();  // 获取输出的字符串
    ExportOutput::exportOutputToFile("cmdMessage.txt", cmdMessage);*/

    /*========= z3 test ==========*/


    return 0;
}

