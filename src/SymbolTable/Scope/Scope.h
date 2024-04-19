//
// Created by jack on 11/22/23.
//

#ifndef SYMBOL_SCOPE_H
#define SYMBOL_SCOPE_H


#include "../Symbol/Symbol.h"

class Scope {
    public:
        //获取作用域的名称
        virtual const std::string &scopeName() const = 0;
        //获取当前作用域的父作用域
        virtual std::shared_ptr<Scope> getEnclosingScope() const = 0;
        //定义符号
        virtual void define(std::shared_ptr<Symbol> sym) = 0;
        //解析符号
        virtual std::shared_ptr<Symbol> resolve(const std::string &name) const = 0;
        //获取作用域的字符串表示
        virtual const std::string toString() const = 0;
        virtual ~Scope();
};


#endif //SYMBOL_SCOPE_H
