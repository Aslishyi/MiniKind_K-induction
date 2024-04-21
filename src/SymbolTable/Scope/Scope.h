//
// Created by jack on 11/22/23.
//

#ifndef SYMBOL_SCOPE_H
#define SYMBOL_SCOPE_H


#include "../Symbol/Symbol.h"
/*Scope方法使用示例
 * 进入作用域push：currentScope = new LocalScope(CurrentScope);
 * 推出当前作用域返回上一级作用域pop：currentScope = currentScope.getEnclosingScope();
 * 在当前作用域定义符号：Symbol s; currentScope.define(s);
 * 解析当前作用域符号resolve：1) Symbol s = members.get(name);
 *                        2) if(s != null) return s; //在当前作用域找到
 *                        3) if(enclosingScope != null) return enclosingScope.resolve(name); // 前往上一作用域寻找
 *                        4) return null;
 *
 *解析符号：currentScope.resolve(符号);
 * */

/*
 * Scope类即是作用域符号表TypeTable，当前作用域符号通过currentScope.define(s)方法存储在symbols中
 * 插入符号到当前作用域符号表中：define(Symbol s){symbols.put(s.name,type);}
 * 在当前符号表中查找符号：resolve(String name){return symbols.get(name);}
 *
 * MethodScope类同时继承Scope与Symbol
 * GlobalScope与LocalScope仅继承Scope
 *
 * 具体符号解析代码：Symbol s = currentScope.resolve(ID.text);
 * */
class Scope : public std::enable_shared_from_this<Scope> {
public:
    //获取作用域的名称
    virtual const std::string &scopeName() const = 0;

    //获取当前作用域的父作用域
    virtual std::shared_ptr<Scope> getEnclosingScope() const;

    //定义符号
    virtual void define(std::shared_ptr<Symbol> sym) = 0;

    //向外解析符号
    virtual std::shared_ptr<Symbol> resolve(const std::string &name) const = 0;
    //向内解析符号
    virtual std::shared_ptr<Symbol> resolveNested(const std::string &name) const = 0;

    //获取作用域的字符串表示
    virtual const std::string toString() const = 0;

    virtual ~Scope();

    //获取当前作用域的子作用域
    virtual std::vector<std::shared_ptr<Scope>> getNestedScope() const;

    explicit Scope(std::shared_ptr<Scope> enclosingScope);

    virtual std::shared_ptr<Scope> addNestedScopes(std::shared_ptr<Scope> scope);

protected:
    std::shared_ptr<Scope> enclosingScope;
    std::vector<std::shared_ptr<Scope>> nestedScopes;
};


#endif //SYMBOL_SCOPE_H
