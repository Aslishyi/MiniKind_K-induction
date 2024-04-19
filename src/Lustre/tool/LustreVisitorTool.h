//
// Created by jack on 23-11-16.
//

#ifndef LUSTRETOL2C_LUSTREVISITORTOOL_H
#define LUSTRETOL2C_LUSTREVISITORTOOL_H


#include <string>
#include "../../SymbolTable/Symbol/Symbol.h"

//工具类
class LustreVisitorTool {

public:

    //二元算术运算
    template<class T>
    static std::any performArithmeticOperation(T left, T right, const std::string &op);

    //二元比较运算
    template<class T>
    static bool performRelationOperation(T left, T right, const std::string &op);

    //二元布尔运算:如果是not运算的话，是对right进行运算，left随意赋值
    static bool performBoolOperation(bool left, bool right, const std::string &op);


    //对不同类型的数分门别类送入performArithmeticOperation和performBoolOperation进行运算,通过isRelation判断送入哪个函数
    static std::any classifyPropertyType(std::any left, std::any right, const std::string &op, bool isRelation);



    static std::any classifyPropertyType(std::any right, const std::string &op);

    //根据类型把数据和Symbol的varType对应起来
    static std::pair<Symbol::varType, std::any> properTypeToEnum(std::any typeValue);

    //根据类型把值返回string类型
    static std::string properTypeToString(const std::any & typeValue);

    //获取tree节点以及子节点的原始文本
    static std::string getFullText(antlr4::tree::ParseTree *tree);

};


#endif //LUSTRETOL2C_LUSTREVISITORTOOL_H
