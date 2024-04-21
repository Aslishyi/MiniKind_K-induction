//
// Created by jack on 12/24/23.
//

#ifndef QL2C_CONSTSTRUCT_H
#define QL2C_CONSTSTRUCT_H


#include <unordered_set>
#include <string>
#include <memory>

class ConstSymbol;
class ConstStruct {


public:
    ConstStruct()=delete;

    //array类型的构造函数
    explicit ConstStruct(std::unordered_set<std::shared_ptr<ConstSymbol>> structVector);

    //打印具体的symbol类型：包括array，基础类型打印
    std::string toAstString() const;

    std::string toLusString() const;

    std::unordered_set<std::shared_ptr<ConstSymbol>> structSet;

};


#endif //QL2C_CONSTSTRUCT_H
