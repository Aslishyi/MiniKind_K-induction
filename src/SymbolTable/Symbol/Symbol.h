#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include "antlr4-runtime.h"

class Scope;

/*
 * Symbol用于收集实体信息：变量名、类型、作用域
 * 每个类别用单独的类定义
 * 名称、类型为类中的属性
 *
 * 继承Symbol类可以派生出各种类：如该项目中的VariableSymbol代表变量
 * */
class Symbol {
public:

    //定义Symbol的类型
    enum Type {
        //basetype:基础类型：int，bool……
        BASETYPE,
        ARRAY,
        STRUCT,
        FUNCTION,
        PARAMETER,
        VARIABLE,
        CONSTANT,
        REFERENCE,
        TYPEDEF,
        ENUM,
        FILE,
        AUTOMATON,
        STATE,
        UNKNOWN
    };
    //变量的类型
    enum varType {
        BOOL, INTEGER, UINT, REAL, CHAR, FLOAT, USHORT, SHORT, UNKNOWNVAR
    };


    Symbol(std::string name, Type type, std::shared_ptr<antlr4::Token> token, const std::shared_ptr<Scope>& scope);

    Symbol();

//	SymbolTable(string &&name, Type token);
    virtual ~Symbol();

    //用Ast格式打印：如：c1 : int = 2+3;打印为const(c1,int,INT(5))
    virtual std::string toAstString() const;

    //输出较短格式的String，方便和其他类组合输出
    virtual std::string toShortAstString() const;

    //用Lustre V6格式打印
    virtual std::string toLusString() const;

    //判断两个Symbol的内容是否相同
    virtual bool isEqual(std::shared_ptr<Symbol>symbol);


    //对VarType类型进行打印
    static std::string getVarTypeString(varType valType);

    Symbol &setName(const std::string &name);

    const std::string &getName() const;

    Symbol &setType(const Type &type);

    const Type &getType() const;

    Symbol &setToken(std::shared_ptr<antlr4::Token> token);

    // 获取符号的 antlr4::Token 共享指针
    std::shared_ptr<antlr4::Token> getToken() const;

    Symbol &setScope(std::shared_ptr<Scope> scope);

    std::weak_ptr<Scope> getScope() const;

protected:
    //符号的类型
    Type type;
    //符号的名称
    std::string name;
    std::shared_ptr<antlr4::Token> token; // 添加成员变量保存 antlr4::Token 引用
    //符号的作用域
    std::weak_ptr<Scope> scope;

    //获取基础的符号类型
    virtual std::string getTypeString() const;
    //对传入的Type枚举类型进行打印
    virtual std::string getTypeString(Type type1) const;

    //对传入的Type枚举类型进行大写打印,用于const类型
    static std::string getTypeStringInCaps(varType valType);
};


