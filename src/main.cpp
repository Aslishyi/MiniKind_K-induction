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
#include <iostream>
#include <memory>
#include "lustre/generated/LustreLexer.h"
#include "lustre/generated/LustreParser.h"
#include "CommonToken.h"
#include "tree/ParseTree.h"
#include "lustre/visitor/MyLustreVisitor.h"
#include "lustre/visitor/SymbolVisitor.h"
#include <z3++.h>
using namespace std;

int main(int argc, char **argv) {
#ifdef __WIN32
    system("chcp 65001");         //解决windows下中文编码问题
#endif
    /*============================== 项目模块一: L2C解析模块 ======================================*/
//    cout << "==============================================";
//    std::cout << "输入:";
//    cout << "==============================================" << endl;
    string inputFile;
    if (argc >= 2) {
        inputFile = argv[1];
        cout << "inputFile : " << inputFile << endl;
    } else {        //在build目录下新建test.Lustre，可以将测试数据复制进去使用
        cout << "使用默认路径 : " << "./test.Lustre" << endl;
        inputFile = "./test.Lustre";
    }

    auto inputStream = make_unique<ifstream>(inputFile);
    if (inputStream->is_open()) {

        auto input = make_unique<antlr4::ANTLRInputStream>(*inputStream);
        auto lexer = make_unique<LustreLexer>(input.get());
        auto tokens = make_unique<antlr4::CommonTokenStream>(lexer.get());
//            tokens->fill();
//    for (auto token: tokens->getTokens()) {
//        std::cout << token->toString() << std::endl;
//    }

        auto parser = make_unique<LustreParser>(tokens.get());
        antlr4::tree::ParseTree *tree = parser->program();
//        cout << "==============================================";
//        std::cout << "语法树";
//        cout << "==============================================" << endl;
//        cout << tree->toStringTree(parser.get()) << endl;
        tree->toStringTree(parser.get());
//        cout << "==============================================";
//        std::cout << "符号表";
//        cout << "==============================================" << endl;
        //预先构建符号表
        auto symbolVisitor = make_unique<SymbolVisitor>();
        symbolVisitor->visit(tree);

//        cout << "==============================================";
//        std::cout << "转换后";
//        cout << "==============================================" << endl;
        //转换语法
        auto myLustreVisitor = make_unique<MyLustreVisitor>(symbolVisitor->scopes, symbolVisitor->globals);
        myLustreVisitor->visit(tree);
//        antlr4::tree::ParseTree *processedTree = myLustreVisitor->getProcessedTree();

        inputStream->close();
    } else {
        cout << "文件无法打开" << endl;
        //return 1;
    }


    /*============================== 项目模块二:  模型验证模块 ======================================*/
    //将控制台输出信息转移到cmdMessage.txt
    std::ostringstream oss;
    std::streambuf* pCoutBuf = std::cout.rdbuf();  // 保存旧的 cout buffer
    std::cout.rdbuf(oss.rdbuf());


    // 从Lustre文件中读取lustre代码;
    string inFilename = "input.Lustre";
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

    /*========= z3 test ==========*/
    std::cout << "de-Morgan example\n";

    z3::context c;

    z3::expr x = c.bool_const("x");
    z3::expr y = c.bool_const("y");
    z3::expr conjecture = (!(x && y)) == (!x || !y);

    z3::solver s(c);
    // adding the negation of the conjecture as a constraint.
    s.add(!conjecture);
    std::cout << s << "\n";
    std::cout << s.to_smt2() << "\n";
    switch (s.check()) {
        case z3::unsat:   std::cout << "de-Morgan is valid\n"; break;
        case z3::sat:     std::cout << "de-Morgan is not valid\n"; break;
        case z3::unknown: std::cout << "unknown\n"; break;
    }

    return 0;
}

