//
// Created by jack on 1/15/24.
//

#ifndef QL2C_MIXEXPRVISITOR_H
#define QL2C_MIXEXPRVISITOR_H

#include <queue>
#include <list>
#include "../visitor/MyLustreVisitor.h"

class MixExprVisitor : public LustreBaseVisitor {
    /**
        * 构建出一个mix相关的函数
        * _L2=mixExpr1(_L1,_L3);
        * 如：../test/origin/srs_l2c_syn_043_003/srs_l2c_syn_043_003.Lustre
        *   生成函数==>
        * function mixExpr1(input1:tempstruct1;input2:int) returns(output1:tempstruct1)
        *   var
        *   tempvar2:tempstruct3^2;
        * let
        *   tempvar2[i]=if i=0 then tempstruct3{label1=input2} else input1.label1.label1[1];
        *   output1=tempstruct1{label1=tempstruct2{label1=tempvar2};label2=1};
        * tel
        */
public:
    std::any visitMixed_constructor(LustreParser::Mixed_constructorContext *ctx) override;

    std::any visitMix_label(LustreParser::Mix_labelContext *ctx) override;

    std::any visitMix_index(LustreParser::Mix_indexContext *ctx) override;

    std::any visitIndex(LustreParser::IndexContext *ctx) override;

    MixExprVisitor(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope,
                   std::vector<std::string> mixNestedPath);


    //
    struct MixFunction {
        std::vector<std::string> varDecl;
        std::vector<std::string> letDecl;
    };
    struct MixTypeNestedPath {
        std::vector<std::string> path;
        int index;
    };
private:
    //获取函数的类型
    std::string getParamTypeString(const std::string &paramString);


    std::shared_ptr<TypeDefSymbol> getParamTypeSymbol(const std::string &paramString);

    std::string getUndefinedName(std::string name, int &index);

    std::vector<std::pair<std::string, std::string>> paramVector;
    int tempMixVarIndex;
    std::shared_ptr<TypeDefSymbol> mixTypeDefSymbol;

    std::queue<LustreParser::Label_or_indexContext *> label_or_indexQueue;
    MyLustreVisitor &myLustreVisitor;
    std::shared_ptr<Scope> currentScope;

};


#endif //QL2C_MIXEXPRVISITOR_H
