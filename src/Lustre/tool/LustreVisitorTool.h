//
// Created by jack on 23-11-16.
//

#ifndef LUSTRETOL2C_LUSTREVISITORTOOL_H
#define LUSTRETOL2C_LUSTREVISITORTOOL_H


#include <string>
#include "../../SymbolTable/Symbol/Symbol.h"
#include "../../SymbolTable/Symbol/TypeDefSymbol.h"

//工具类
class LustreVisitorTool {

public:

    /**
     * 添加标记，表示注解原来所在的行。用于kind2结果解析，使kind2的结果和原始行相匹配；
     * 注意：1.要使能被解析，要放在需解析行的上一行
     * 如：--Line=行号
     * @param tree ctx上下文对象
     * @return  新的行(--%Line=行号\n)，
     */
    static std::string getLineAnnotation(antlr4::tree::ParseTree *tree);

    //二元算术运算
    template<class T>
    static std::any performArithmeticOperation(T left, T right, const std::string &op);

    //二元比较运算
    template<class T>
    static bool performRelationOperation(T left, T right, const std::string &op);

    //二元布尔运算:如果是not运算的话，是对right进行运算，left随意赋值
    static bool performBoolOperation(bool left, bool right, const std::string &op);


    //对不同类型的数分门别类送入performArithmeticOperation和performBoolOperation进行运算,通过isRelation判断送入哪个函数(是否是比较运算)
    static std::any classifyPropertyType(std::any left, std::any right, const std::string &op, bool isRelation);



    static std::any classifyPropertyType(std::any right, const std::string &op);

    //根据类型把数据和Symbol的varType对应起来
    static std::pair<Symbol::varType, std::any> properTypeToEnum(std::any typeValue);

    //根据类型把值返回string类型
    static std::string properTypeToString(const std::any & typeValue);

    //获取tree节点以及子节点的原始文本
    static std::string getFullText(antlr4::tree::ParseTree *tree);

    /*
     * 类型转换，把any的类型统一转换T
     */
    template<class T>
    static T anyConverter(std::any value) {
        if (value.type() == typeid(int)) {
            return static_cast<T>(std::any_cast<int>(value));
        } else if (value.type() == typeid(unsigned int)) {
            return static_cast<T>(std::any_cast<unsigned int>(value));
        } else if (value.type() == typeid(unsigned short)) {
            return static_cast<T>(std::any_cast<unsigned short>(value));
        } else if (value.type() == typeid(short)) {
            return static_cast<T>(std::any_cast<short>(value));
        } else if (value.type() == typeid(float)) {
            return static_cast<T>(std::any_cast<float>(value));
        } else if (value.type() == typeid(double)) {
            return static_cast<T>(std::any_cast<double>(value));
        } else {
            throw std::runtime_error("Invalid value type for conversion");
        }
    }

    /**
     * 把any的值转换为字符串
     * @param value
     * @return 对应的字符串
     */
    static std::string anyToString(std::any value);

    /**
     * 构建一个kind2能用的lustre方法节点
     * @param funName 节点名字:string
     * @param paramVector 形参:vector<pair<变量名,变量类型>>
     * @param returnVector 返回参数:vector<pair<变量名,变量类型>>
     * @param varDecl 常量定义:vector<string>
     * @param letDecl 运算表达式:vector<string>
     * @return 节点的文本:string
     */
    static std::string buildLusFunction(const std::string& funName, const std::vector<std::pair<std::string, std::string>>& paramVector,
                                  const std::vector<std::pair<std::string, std::string>>& returnVector,
                                  const std::vector<std::string> &varDecl, const std::vector<std::string> &letDecl);

    /**
     * 生成一个没有被使用过的名字
     * @param currentScope 当前所使用的定义域
     * @param name 要生成的名字的前缀
     * @return 新的名字
     */
     static std::string getNeverUsedName(std::shared_ptr<Scope> currentScope,std::string name);


     /**
      * 根据ID获取id的类型，返回string的类型字符串
      * @param currentScope
      * @param IDName
      * @return 类型字符串
      */
     static std::string getIDType(std::shared_ptr<Scope>currentScope,std::string IDName);
     /**
      * 根据ID获得id的类型符号（Symbol）
      * @param currentScope
      * @param IDName
      * @return 类型的符号
      */
     static std::shared_ptr<TypeDefSymbol> getIDTypeSymbol(std::shared_ptr<Scope>currentScope,std::string IDName);



};


#endif //LUSTRETOL2C_LUSTREVISITORTOOL_H
