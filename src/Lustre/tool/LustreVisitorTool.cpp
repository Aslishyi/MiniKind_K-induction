#include <any>
#include <cassert>
#include <iostream>
#include "LustreVisitorTool.h"


template<class T>
std::any LustreVisitorTool::performArithmeticOperation(T left, T right, const std::string &op) {
    T result;
    switch (op[0]) {
        case '+':
            result = left + right;
            return T(result);
        case '-':
            result = left - right;
            return T(result);
        case '*':
            result = left * right;
            return T(result);
        case '/':
            result = left / right;
            return T(result);
        case 'm':
            // TODO:处理 mod 运算符
            return T(0);
        case 'd':
            // 处理 div 运算符
            result = left / right;
            return T(result);
        default:
            // 处理无效的运算符
            return T(0);
    }
}


template<class T>
bool LustreVisitorTool::performRelationOperation(T left, T right, const std::string &op) {
    T result;
    if (op == "=") {
        return left == right;
    } else if (op == "<>") {
        return left != right;
    } else if (op == "<") {
        return left < right;
    } else if (op == ">") {
        return left > right;
    } else if (op == "<=") {
        return left <= right;
    } else if (op == ">=") {
        return left >= right;
    }

    return false;
}

bool LustreVisitorTool::performBoolOperation(bool left, bool right, const std::string &op) {
    switch (op[0]) {
        case 'a'://and
            return left && right;
        case 'o'://or
            return left || right;
        case 'x'://xor
            return left ^ right;
        case 'n'://not是一元运算符
            return !right;
    }
    return false;
}

std::any
LustreVisitorTool::classifyPropertyType(std::any left, std::any right, const std::string &op, bool isRelation) {
    if (right.type() == typeid(int)) {
        int leftInt = std::any_cast<int>(left);
        int rightInt = std::any_cast<int>(right);

        auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftInt, rightInt, op)
                                 : LustreVisitorTool::performArithmeticOperation(leftInt, rightInt, op);
        return result;

    } else if (right.type() == typeid(double)) {
        auto leftDouble = std::any_cast<double>(left);
        auto rightDouble = std::any_cast<double>(right);

        auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                 : LustreVisitorTool::performArithmeticOperation(rightDouble, rightDouble, op);

        return result;

    } else if (right.type() == typeid(short)) {
        auto leftShort = std::any_cast<short>(left);
        auto rightShort = std::any_cast<short>(right);

        auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftShort, rightShort, op)
                                 : LustreVisitorTool::performArithmeticOperation(leftShort, rightShort, op);

        return result;

    } else if (right.type() == typeid(unsigned short)) {
        auto leftUShort = std::any_cast<unsigned short>(left);
        auto rightUShort = std::any_cast<unsigned short>(right);

        auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftUShort, rightUShort, op)
                                 : LustreVisitorTool::performArithmeticOperation(rightUShort, rightUShort, op);

        return result;

    } else if (right.type() == typeid(float)) {
        auto leftFloat = std::any_cast<float>(left);
        auto rightFloat = std::any_cast<float>(right);

        auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftFloat, rightFloat, op)
                                 : LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);


        return result;

    } else if (right.type() == typeid(unsigned int)) {
        auto leftUInt = std::any_cast<unsigned int>(left);
        auto rightUInt = std::any_cast<unsigned int>(right);

        auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftUInt, rightUInt, op)
                                 : LustreVisitorTool::performArithmeticOperation(leftUInt, rightUInt, op);

        return result;

    } else if (right.type() == typeid(bool)) {
        auto leftBool = std::any_cast<bool>(left);
        auto rightBool = std::any_cast<bool>(right);

        auto result = LustreVisitorTool::performBoolOperation(leftBool, rightBool, op);
        return result;

    }
// 处理无效的类型或其他情况
    return std::int32_t(0);

}

std::any LustreVisitorTool::classifyPropertyType(std::any right, const std::string &op) {
    if (right.type() == typeid(int)) {
        int leftInt = 0;
        int rightInt = std::any_cast<int>(right);

        auto result = LustreVisitorTool::performArithmeticOperation(leftInt, rightInt, op);
        return result;

    } else if (right.type() == typeid(double)) {
        double leftDouble = 0.0;
        auto rightDouble = std::any_cast<double>(right);

        auto result = LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);

        return result;

    } else if (right.type() == typeid(short)) {
        short leftShort = 0;
        auto rightShort = std::any_cast<short>(right);

        auto result = LustreVisitorTool::performArithmeticOperation(leftShort, rightShort, op);

        return result;

    } else if (right.type() == typeid(unsigned short)) {
        unsigned short leftUShort = 0;
        auto rightUShort = std::any_cast<unsigned short>(right);

        auto result = LustreVisitorTool::performArithmeticOperation(leftUShort, rightUShort, op);

        return result;

    } else if (right.type() == typeid(float)) {
        float leftFloat = 0.0;
        auto rightFloat = std::any_cast<float>(right);

        auto result = LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);

        return result;

    } else if (right.type() == typeid(unsigned int)) {
        unsigned int leftUInt = 0;
        auto rightUInt = std::any_cast<unsigned int>(right);

        auto result = LustreVisitorTool::performArithmeticOperation(leftUInt, rightUInt, op);
        return result;

    } else if (right.type() == typeid(bool)) {
        auto leftBool = true;
        auto rightBool = std::any_cast<bool>(right);

        auto result = LustreVisitorTool::performBoolOperation(leftBool, rightBool, op);
        return result;

    }
// 处理无效的类型或其他情况
    return std::int32_t(0);

}


std::pair<Symbol::varType, std::any> LustreVisitorTool::properTypeToEnum(std::any typeValue) {
    if (typeValue.type() == typeid(int)) {

//        std::string value = std::to_string(std::any_cast<int>(typeValue));

        return std::make_pair(Symbol::INTEGER, typeValue);

    } else if (typeValue.type() == typeid(unsigned int)) {
//        std::string value = std::to_string(std::any_cast<unsigned int>(typeValue));

        return std::make_pair(Symbol::UINT, typeValue);

    } else if (typeValue.type() == typeid(double)) {
//        std::string value = std::to_string(std::any_cast<double>(typeValue));

        return std::make_pair(Symbol::REAL, typeValue);

    } else if (typeValue.type() == typeid(short)) {
//        std::string value = std::to_string(std::any_cast<short>(typeValue));

        return std::make_pair(Symbol::SHORT, typeValue);

    } else if (typeValue.type() == typeid(unsigned short)) {
//        std::string value = std::to_string(std::any_cast<unsigned short>(typeValue));

        return std::make_pair(Symbol::USHORT, typeValue);

    } else if (typeValue.type() == typeid(float)) {
//        std::string value = std::to_string(std::any_cast<float>(typeValue));

        return std::make_pair(Symbol::FLOAT, typeValue);

    } else if (typeValue.type() == typeid(std::string)) {
//        auto value = std::any_cast<std::string>(typeValue);

        return std::make_pair(Symbol::CHAR, typeValue);

    } else if (typeValue.type() == typeid(bool)) {
//        std::string value = std::to_string(std::any_cast<bool>(typeValue));

        return std::make_pair(Symbol::BOOL, typeValue);

    } else if (typeValue.type() == typeid(char)) {
//        std::string value = std::to_string(std::any_cast<char>(typeValue));
        return std::make_pair(Symbol::CHAR, typeValue);
    }
// 处理无效的类型或其他情况
    return std::make_pair(Symbol::UNKNOWNVAR, "");

}

//获取当前节点包括子节点的原始文本内容(不省略空格和换行)
std::string LustreVisitorTool::getFullText(antlr4::tree::ParseTree *tree) {
    auto *context = dynamic_cast<antlr4::ParserRuleContext *>(tree);
    if (context->children.empty()) {
        return "";
    }
    antlr4::Token *startToken = context->start;
    antlr4::Token *stopToken = context->stop;
    antlr4::misc::Interval interval(startToken->getStartIndex(), stopToken->getStopIndex());
    std::string result = context->start->getInputStream()->getText(interval);
    return result;
}

std::string LustreVisitorTool::properTypeToString(const std::any &typeValue) {
    if (typeValue.type() == typeid(int)) {
        return std::to_string(std::any_cast<int>(typeValue));
    } else if (typeValue.type() == typeid(unsigned int)) {
        return std::to_string(std::any_cast<unsigned int>(typeValue));
    } else if (typeValue.type() == typeid(double)) {
        return std::to_string(std::any_cast<double>(typeValue));
    } else if (typeValue.type() == typeid(short)) {
        return std::to_string(std::any_cast<short>(typeValue));
    } else if (typeValue.type() == typeid(unsigned short)) {
        return std::to_string(std::any_cast<unsigned short>(typeValue));
    } else if (typeValue.type() == typeid(float)) {
        return std::to_string(std::any_cast<float>(typeValue));
    } else if (typeValue.type() == typeid(std::string)) {
        return std::any_cast<std::string>(typeValue);

    } else if (typeValue.type() == typeid(bool)) {
        auto typeBool=std::any_cast<bool>(typeValue);
        return typeBool?"true":"false";
//        return std::to_string(std::any_cast<bool>(typeValue));

    } else if (typeValue.type() == typeid(char)) {
        return std::to_string(std::any_cast<char>(typeValue));

    }
// 处理无效的类型或其他情况

    return std::string{""};

}

