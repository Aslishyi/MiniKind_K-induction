#include <any>
#include <cassert>
#include <iostream>
#include <cmath>
#include "LustreVisitorTool.h"
#include "../../SymbolTable/Scope/Scope.h"
#include "../../SymbolTable/Symbol/TypeDefSymbol.h"
#include "../../SymbolTable/Symbol/VariableSymbol.h"
#include "../../SymbolTable/Symbol/EnumSymbol.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"
#include "SpdlogTool.h"

#define _tab "    "

template<class T>
std::any LustreVisitorTool::performArithmeticOperation(T left, T right, const std::string &op) {
    T result;
    switch (op[0]) {
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            result = left / right;
            break;
        case 'm':
            result = left - floor(left / right) * right;
            break;
        case 'd':
            // 处理 div 运算符
            result = left / right;
            break;
        default:
            // 处理无效的运算符
            result = 0;
    }
    return T(result);
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
    if (left.type() == typeid(int)) {
        if (right.type() == typeid(int)) {
            int leftInt = std::any_cast<int>(left);
            int rightInt = std::any_cast<int>(right);

            // 进行 int 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftInt, rightInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftInt, rightInt, op);
            return result;

        } else if (right.type() == typeid(double)) {
            int leftInt = std::any_cast<int>(left);
            double rightDouble = std::any_cast<double>(right);

            // 将 leftInt 转换为 double 类型
            double leftDouble = static_cast<double>(leftInt);

            // 进行 int 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;

        } else if (right.type() == typeid(short)) {
            int leftInt = std::any_cast<int>(left);
            short rightShort = std::any_cast<short>(right);


            int rightInt = static_cast<int>(rightShort);
            // 进行 int 和 short 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftInt, rightInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftInt, rightInt, op);
            return result;

        } else if (right.type() == typeid(unsigned short)) {
            int leftInt = std::any_cast<int>(left);
            unsigned short rightUShort = std::any_cast<unsigned short>(right);

            // 进行 int 和 unsigned short 类型的运算
            int rightInt = static_cast<int>(rightUShort);
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftInt, rightInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftInt, rightInt, op);
            return result;

        } else if (right.type() == typeid(unsigned int)) {
            int leftInt = std::any_cast<int>(left);
            unsigned int rightUInt = std::any_cast<unsigned int>(right);

            // 根据值的范围和符号选择转换方式
            // 进行 int 和 unsigned int 类型的运算
            int rightInt = static_cast<int>(rightUInt);
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftInt, rightInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftInt, rightInt, op);
            return result;

        } else if (right.type() == typeid(float)) {
            int leftInt = std::any_cast<int>(left);
            float rightFloat = std::any_cast<float>(right);

            // 将 leftInt 转换为 float 类型
            float leftFloat = static_cast<float>(leftInt);

            // 进行 int 和 float 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftFloat, rightFloat, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);
            return result;
        }

    } else if (left.type() == typeid(double)) {
        if (right.type() == typeid(int)) {
            double leftDouble = std::any_cast<double>(left);
            int rightInt = std::any_cast<int>(right);

            // 将 rightInt 转换为 double 类型
            double rightDouble = static_cast<double>(rightInt);

            // 进行 double 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;

        } else if (right.type() == typeid(short)) {
            double leftDouble = std::any_cast<double>(left);
            short rightShort = std::any_cast<short>(right);

            // 将 rightShort 转换为 double 类型
            double rightDouble = static_cast<double>(rightShort);

            // 进行 double 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;

        } else if (right.type() == typeid(unsigned short)) {
            double leftDouble = std::any_cast<double>(left);
            unsigned short rightUShort = std::any_cast<unsigned short>(right);

            // 将 rightUShort 转换为 double 类型
            double rightDouble = static_cast<double>(rightUShort);

            // 进行 double 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;

        } else if (right.type() == typeid(unsigned int)) {
            double leftDouble = std::any_cast<double>(left);
            unsigned int rightUInt = std::any_cast<unsigned int>(right);

            // 将 rightUInt 转换为 double 类型
            double rightDouble = static_cast<double>(rightUInt);

            // 进行 double 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;

        } else if (right.type() == typeid(float)) {
            double leftDouble = std::any_cast<double>(left);
            float rightFloat = std::any_cast<float>(right);

            // 将 rightFloat 转换为 double 类型
            double rightDouble = static_cast<double>(rightFloat);

            // 进行 double 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;
        } else if (right.type() == typeid(double)) {
            double leftDouble = std::any_cast<double>(left);
            double rightDouble = std::any_cast<double>(right);

            // 进行 double 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;
        }
    } else if (left.type() == typeid(short)) {
        if (right.type() == typeid(int)) {
            short leftShort = std::any_cast<short>(left);
            int rightInt = std::any_cast<int>(right);

            // 将 leftShort 转换为 int 类型
            int leftInt = static_cast<int>(leftShort);

            // 进行 short 和 int 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftInt, rightInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftInt, rightInt, op);
            return result;

        } else if (right.type() == typeid(double)) {
            short leftShort = std::any_cast<short>(left);
            double rightDouble = std::any_cast<double>(right);

            // 将 leftShort 转换为 double 类型
            double leftDouble = static_cast<double>(leftShort);

            // 进行 short 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;

        } else if (right.type() == typeid(short)) {
            short leftShort = std::any_cast<short>(left);
            short rightShort = std::any_cast<short>(right);

            // 进行两个 short 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftShort, rightShort, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftShort, rightShort, op);
            return result;

        } else if (right.type() == typeid(unsigned short)) {
            short leftShort = std::any_cast<short>(left);
            unsigned short rightUShort = std::any_cast<unsigned short>(right);


            short rightShort = static_cast<short>(rightUShort);
            // 进行 short 和 unsigned short 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftShort, rightShort, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftShort, rightShort, op);
            return result;

        } else if (right.type() == typeid(unsigned int)) {
            short leftShort = std::any_cast<short>(left);
            unsigned int rightUInt = std::any_cast<unsigned int>(right);

            // 进行 short 和 unsigned int 类型的运算
            unsigned int leftUInt = static_cast<unsigned int>(leftShort);
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftUInt, rightUInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftUInt, rightUInt, op);
            return result;

        } else if (right.type() == typeid(float)) {
            short leftShort = std::any_cast<short>(left);
            float rightFloat = std::any_cast<float>(right);

            // 将 leftShort 转换为 float 类型
            float leftFloat = static_cast<float>(leftShort);

            // 进行 short 和 float 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftFloat, rightFloat, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);
            return result;
        }

    } else if (left.type() == typeid(unsigned short)) {
        if (right.type() == typeid(int)) {
            unsigned short leftUShort = std::any_cast<unsigned short>(left);
            int rightInt = std::any_cast<int>(right);

            // 将 leftUShort 转换为 int 类型
            int leftInt = static_cast<int>(leftUShort);

            // 进行 unsigned short 和 int 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftInt, rightInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftInt, rightInt, op);
            return result;

        } else if (right.type() == typeid(double)) {
            unsigned short leftUShort = std::any_cast<unsigned short>(left);
            double rightDouble = std::any_cast<double>(right);

            // 将 leftUShort 转换为 double 类型
            double leftDouble = static_cast<double>(leftUShort);

            // 进行 unsigned short 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;

        } else if (right.type() == typeid(short)) {
            unsigned short leftUShort = std::any_cast<unsigned short>(left);
            short rightShort = std::any_cast<short>(right);

            // 将 leftUShort 和 rightShort 转换为相同类型
            unsigned short rightUShort = static_cast<unsigned short>(rightShort);

            // 进行 unsigned short 和 unsigned short 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftUShort, rightUShort, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftUShort, rightUShort, op);
            return result;

        } else if (right.type() == typeid(unsigned short)) {
            unsigned short leftUShort = std::any_cast<unsigned short>(left);
            unsigned short rightUShort = std::any_cast<unsigned short>(right);

            // 进行两个 unsigned short 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftUShort, rightUShort, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftUShort, rightUShort, op);
            return result;

        } else if (right.type() == typeid(unsigned int)) {
            unsigned short leftUShort = std::any_cast<unsigned short>(left);
            unsigned int rightUInt = std::any_cast<unsigned int>(right);

            // 将 leftUShort 和 rightUInt 转换为相同类型
            unsigned int leftUInt = static_cast<unsigned int>(leftUShort);

            // 进行 unsigned short 和 unsigned int 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftUInt, rightUInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftUInt, rightUInt, op);
            return result;

        } else if (right.type() == typeid(float)) {
            unsigned short leftUShort = std::any_cast<unsigned short>(left);
            float rightFloat = std::any_cast<float>(right);

            // 将 leftUShort 转换为 float 类型
            float leftFloat = static_cast<float>(leftUShort);

            // 进行 unsigned short 和 float 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftFloat, rightFloat, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);
            return result;
        }
    } else if (left.type() == typeid(float)) {
        if (right.type() == typeid(int)) {
            float leftFloat = std::any_cast<float>(left);
            int rightInt = std::any_cast<int>(right);

            // 将 rightInt 转换为 float 类型
            float rightFloat = static_cast<float>(rightInt);

            // 进行 float 和 float 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftFloat, rightFloat, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);
            return result;

        } else if (right.type() == typeid(double)) {
            float leftFloat = std::any_cast<float>(left);
            double rightDouble = std::any_cast<double>(right);

            // 将 leftFloat 转换为 double 类型
            double leftDouble = static_cast<double>(leftFloat);

            // 进行 float 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;

        } else if (right.type() == typeid(short)) {
            float leftFloat = std::any_cast<float>(left);
            short rightShort = std::any_cast<short>(right);

            // 将 rightShort 转换为 float 类型
            float rightFloat = static_cast<float>(rightShort);

            // 进行 float 和 float 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftFloat, rightFloat, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);
            return result;

        } else if (right.type() == typeid(unsigned short)) {
            float leftFloat = std::any_cast<float>(left);
            unsigned short rightUShort = std::any_cast<unsigned short>(right);

            // 将 rightUShort 转换为 float 类型
            float rightFloat = static_cast<float>(rightUShort);

            // 进行 float 和 float 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftFloat, rightFloat, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);
            return result;

        } else if (right.type() == typeid(unsigned int)) {
            float leftFloat = std::any_cast<float>(left);
            unsigned int rightUInt = std::any_cast<unsigned int>(right);

            // 将 rightUInt 转换为 float 类型
            auto rightFloat = static_cast<float>(rightUInt);

            // 进行 float 和 float 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftFloat, rightFloat, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);
            return result;

        } else if (right.type() == typeid(float)) {
            auto leftFloat = std::any_cast<float>(left);
            auto rightFloat = std::any_cast<float>(right);

            // 进行两个 float 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftFloat, rightFloat, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);
            return result;
        }
    } else if (left.type() == typeid(unsigned int)) {
        if (right.type() == typeid(int)) {
            auto leftUInt = std::any_cast<unsigned int>(left);
            int rightInt = std::any_cast<int>(right);
            int leftInt = static_cast<int>(leftUInt);

            // 进行 unsigned int 和 int 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftInt, rightInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftInt, rightInt, op);
            return result;

        } else if (right.type() == typeid(double)) {
            auto leftUInt = std::any_cast<unsigned int>(left);
            auto rightDouble = std::any_cast<double>(right);

            // 将 leftUInt 转换为 double 类型
            auto leftDouble = static_cast<double>(leftUInt);

            // 进行 unsigned int 和 double 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftDouble, rightDouble, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftDouble, rightDouble, op);
            return result;

        } else if (right.type() == typeid(short)) {
            auto leftUInt = std::any_cast<unsigned int>(left);
            auto rightShort = std::any_cast<short>(right);

            // 将 leftUInt 和 rightShort 转换为相同类型
            auto rightUInt = static_cast<unsigned int>(rightShort);

            // 进行 unsigned int 和 unsigned int 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftUInt, rightUInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftUInt, rightUInt, op);
            return result;

        } else if (right.type() == typeid(unsigned short)) {
            auto leftUInt = std::any_cast<unsigned int>(left);
            auto rightUShort = std::any_cast<unsigned short>(right);


            auto rightUInt = static_cast<unsigned int>(rightUShort);
            // 进行 unsigned int 和 unsigned short 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftUInt, rightUInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftUInt, rightUInt, op);
            return result;

        } else if (right.type() == typeid(unsigned int)) {
            auto leftUInt = std::any_cast<unsigned int>(left);
            auto rightUInt = std::any_cast<unsigned int>(right);

            // 进行两个 unsigned int 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftUInt, rightUInt, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftUInt, rightUInt, op);
            return result;

        } else if (right.type() == typeid(float)) {
            auto leftUInt = std::any_cast<unsigned int>(left);
            auto rightFloat = std::any_cast<float>(right);

            // 将 leftUInt 转换为 float 类型
            auto leftFloat = static_cast<float>(leftUInt);

            // 进行 unsigned int 和 float 类型的运算
            auto result = isRelation ? LustreVisitorTool::performRelationOperation(leftFloat, rightFloat, op)
                                     : LustreVisitorTool::performArithmeticOperation(leftFloat, rightFloat, op);
            return result;
        }
    } else if (left.type() == typeid(bool) && right.type() == typeid(bool)) {
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
        auto typeBool = std::any_cast<bool>(typeValue);
        return typeBool ? "true" : "false";
//        return std::to_string(std::any_cast<bool>(typeValue));

    } else if (typeValue.type() == typeid(char)) {
        return std::to_string(std::any_cast<char>(typeValue));

    }
// 处理无效的类型或其他情况

    return std::string{""};

}

std::string
LustreVisitorTool::buildLusFunction(const std::string &funName,
                                    const std::vector<std::pair<std::string, std::string>> &paramVector,
                                    const std::vector<std::pair<std::string, std::string>> &returnVector,
                                    const std::vector<std::string> &varDecl,
                                    const std::vector<std::string> &letDecl) {
    std::stringstream functionString;
    functionString << "function " << funName << " ( ";
    for (int i = 0; i < paramVector.size(); ++i) {
        functionString << paramVector[i].first << " : " << paramVector[i].second;

        if (i < paramVector.size() - 1) {
            functionString << " ; ";
        }
    }


    functionString << " ) returns" << " ( ";

    for (int i = 0; i < returnVector.size(); ++i) {
        functionString << returnVector[i].first << " : " << returnVector[i].second;

        if (i < returnVector.size() - 1) {
            functionString << " ; ";
        }
    }
    functionString << " );\n";
    if (!varDecl.empty()) {
        functionString << "var\n";
        for (const auto &line: varDecl) {
            functionString << "    " << line << "\n";
        }
    }

    functionString << "let\n";
    for (const auto &line: letDecl) {
        functionString << "    " << line << "\n";
    }
    functionString << "tel\n";
    return functionString.str();
}

std::string LustreVisitorTool::getLineAnnotation(antlr4::tree::ParseTree *tree) {
    // 用来获得行号
    std::string annotation("--Line=");
    auto *ctx = dynamic_cast<antlr4::ParserRuleContext *>(tree);
    auto *terminalNode = dynamic_cast<antlr4::tree::TerminalNode *>(tree);
    if (terminalNode) {
        annotation.append(std::to_string(terminalNode->getSymbol()->getLine()));
    } else if (ctx) {
        annotation.append(std::to_string(ctx->getStart()->getLine()));
    } else {
        return "";
    }
    annotation.append("\n");
    return annotation;
}

std::string LustreVisitorTool::getNeverUsedName(std::shared_ptr<Scope> currentScope, std::string name) {
    static int index = 0;
    while (currentScope->resolve(name + std::to_string(index))) {
        index++;
    }
    index++;
    return name + std::to_string(index);
}

std::string LustreVisitorTool::getIDType(std::shared_ptr<Scope> currentScope, std::string IDName) {
    return getIDTypeSymbol(currentScope, IDName)->getDefTypeLusString(
            getIDTypeSymbol(currentScope, IDName)->getDefType());
}

std::shared_ptr<TypeDefSymbol>
LustreVisitorTool::getIDTypeSymbol(std::shared_ptr<Scope> currentScope, std::string IDName) {
    auto symbol = currentScope->resolve(IDName);
    std::shared_ptr<TypeDefSymbol> typeDefSymbol;
    if (auto varSymbol = std::dynamic_pointer_cast<VariableSymbol>(symbol)) {
        typeDefSymbol = varSymbol->getTypeDefSymbol();
    } else if (auto constSymbol = std::dynamic_pointer_cast<ConstSymbol>(symbol)) {
        typeDefSymbol = constSymbol->getDefTypeSymbol();
    } else if (auto typeSymbol = std::dynamic_pointer_cast<TypeDefSymbol>(symbol)) {
        typeDefSymbol = typeSymbol;
    } else if (auto enumSymbol = std::dynamic_pointer_cast<EnumSymbol>(symbol)) {
        //TODO:枚举类型该返回什么类型
        return nullptr;
    }
    return typeDefSymbol;
}

std::string LustreVisitorTool::anyToString(std::any value) {
    /*
     * 类型转换，把any的类型统一转换string
     */
    if (value.type() == typeid(int)) {
        return std::to_string(std::any_cast<int>(value));
    } else if (value.type() == typeid(unsigned int)) {
        return std::to_string(std::any_cast<unsigned int>(value));
    } else if (value.type() == typeid(unsigned short)) {
        return std::to_string(std::any_cast<unsigned short>(value));
    } else if (value.type() == typeid(short)) {
        return std::to_string(std::any_cast<short>(value));
    } else if (value.type() == typeid(float)) {
        return std::to_string(std::any_cast<float>(value));
    } else if (value.type() == typeid(double)) {
        return std::to_string(std::any_cast<double>(value));
    } else if (value.type() == typeid(std::string)) {
        return std::any_cast<std::string>(value);
    } else {
        SpdlogTool::logErr->error("anyToString转换失败！");
    }
    return std::string("");
}



