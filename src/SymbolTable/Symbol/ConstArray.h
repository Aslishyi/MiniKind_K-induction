//
// Created by jack on 12/24/23.
//

#ifndef QL2C_CONSTARRAY_H
#define QL2C_CONSTARRAY_H


#include <vector>
#include <string>
#include <memory>
#include "Symbol.h"

class ConstSymbol;

class ConstArray {

public:
    ConstArray()=delete;

    //array类型的构造函数
    explicit ConstArray( std::vector<std::shared_ptr<ConstSymbol>> constSymbolVector);

    //打印具体的symbol类型：包括array，基础类型打印
    std::string toAstString() const;

    //array的维度值：可能是多维，所以用数组存储
    std::vector<std::shared_ptr<ConstSymbol>> constSymbolVector;

};


#endif //QL2C_CONSTARRAY_H
