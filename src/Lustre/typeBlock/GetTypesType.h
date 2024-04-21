//
// Created by jack on 3/22/24.
//

#ifndef QKIND_GETTYPESTYPE_H
#define QKIND_GETTYPESTYPE_H


#include "../generated/LustreBaseVisitor.h"
#include "../visitor/MyLustreVisitor.h"

/**
 * 用来获取simple_expr的类型
 * 返回值：int，int16，uint16，bool ……
 */
class GetTypesType  : public LustreBaseVisitor{
public:
    explicit GetTypesType(MyLustreVisitor &myLustreVisitor, std::shared_ptr<Scope> currentScope);
    std::any visitType_int(LustreParser::Type_intContext *ctx) override;
    std::any visitType_bool(LustreParser::Type_boolContext *ctx) override;
    std::any visitType_char(LustreParser::Type_charContext *ctx) override;
    std::any visitType_short(LustreParser::Type_shortContext *ctx) override;
    std::any visitType_ushort(LustreParser::Type_ushortContext *ctx) override;
    std::any visitType_uint(LustreParser::Type_uintContext *ctx) override;
    std::any visitType_float(LustreParser::Type_floatContext *ctx) override;
    std::any visitType_real(LustreParser::Type_realContext *ctx) override;
    std::any visitType_id(LustreParser::Type_idContext *ctx) override;
    std::any visitType_struct(LustreParser::Type_structContext *ctx) override;
    std::any visitType_array(LustreParser::Type_arrayContext *ctx) override;

private:
    std::shared_ptr<Scope> currentScope;
    MyLustreVisitor &myLustreVisitor;
};


#endif //QKIND_GETTYPESTYPE_H
