//
// Created by jack on 11/22/23.
//

#include "SymbolVisitor.h"

#include "../tool/LustreVisitorTool.h"
#include "../../SymbolTable/Scope/MethodScope.h"
#include "../../SymbolTable/Scope/LocalScope.h"
#include "../tool/SpdlogTool.h"
#include "../../SymbolTable/Scope/AutomatonScope.h"
#include "../generated/LustreLexer.h"
#include "../../SymbolTable/Scope/StateScope.h"
#include "../src/SymbolTable/Symbol/TransitionSymbol.h"


SymbolVisitor::SymbolVisitor() : scopes(std::make_shared<antlr4::tree::ParseTreeProperty<std::shared_ptr<Scope

>>>()) {

}

//visit方法程序入口
std::any SymbolVisitor::visitProgram(LustreParser::ProgramContext *ctx) {
    globals = std::make_shared<GlobalScope>();
    currentScope = globals;
    LustreBaseVisitor::visitChildren(ctx);
//    std::cout << globals->toString() << std::endl;
    return "";
}

void SymbolVisitor::saveScope(antlr4::ParserRuleContext *ctx, std::shared_ptr<Scope> s) {
    scopes->put(ctx, std::move(s));
}

//在作用域中定义Type类型
void SymbolVisitor::defineType(std::shared_ptr<TypeDefSymbol> typeDefSymbol) {

    typeDefSymbol->setType(Symbol::TYPEDEF);
    currentScope->define(typeDefSymbol);
}

//在作用域中定义Type类型
void SymbolVisitor::defineEnum(std::shared_ptr<EnumSymbol> enumSymbol) {

    enumSymbol->setType(Symbol::ENUM);
    currentScope->define(enumSymbol);
}

void SymbolVisitor::defineParam(const std::shared_ptr<VariableSymbol> &variableSymbol) {

    variableSymbol->setType(Symbol::PARAMETER);
    currentScope->define(variableSymbol);
}

void SymbolVisitor::defineVar(const std::shared_ptr<VariableSymbol> &variableSymbol) {

    variableSymbol->setType(Symbol::VARIABLE);
    currentScope->define(variableSymbol);
}

//在作用域中定义const变量
void SymbolVisitor::defineConst(std::shared_ptr<ConstSymbol> constSymbol) {

    constSymbol->setType(Symbol::CONSTANT);
    currentScope->define(constSymbol);
}

//定义Type_decl中的变量
std::any SymbolVisitor::visitType_decl(LustreParser::Type_declContext *ctx) {
    std::string name = ctx->ID()->getText();
    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());
    if (ctx->type_def()) {

        auto typeDef = visit(ctx->type_def());
        if (typeDef.type() == typeid(std::shared_ptr<TypeDefSymbol>)) {

            auto typeDefSymbol = std::any_cast<std::shared_ptr<TypeDefSymbol>>(typeDef);
            typeDefSymbol->setName(name);
            typeDefSymbol->setToken(nameToken);
            defineType(typeDefSymbol);
        } else if (typeDef.type() == typeid(std::shared_ptr<EnumSymbol>)) {

            auto enumSymbol = std::any_cast<std::shared_ptr<EnumSymbol>>(typeDef);
            enumSymbol->setName(name);
            enumSymbol->setToken(nameToken);
            defineEnum(enumSymbol);
        }
    }
    return std::string("");
}

std::any SymbolVisitor::visitType_def_type(LustreParser::Type_def_typeContext *ctx) {

    return visit(ctx->type());
}

std::any SymbolVisitor::visitType_float(LustreParser::Type_floatContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::FLOAT);
    return varSymbol;
}

std::any SymbolVisitor::visitType_int(LustreParser::Type_intContext *ctx) {

    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::INTEGER);
    return varSymbol;

}

std::any SymbolVisitor::visitType_bool(LustreParser::Type_boolContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::BOOL);
    return varSymbol;


}

std::any SymbolVisitor::visitType_real(LustreParser::Type_realContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::REAL);
    return varSymbol;


}

std::any SymbolVisitor::visitType_char(LustreParser::Type_charContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::CHAR);
    return varSymbol;


}

std::any SymbolVisitor::visitType_short(LustreParser::Type_shortContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::SHORT);
    return varSymbol;

//    return SymbolTable::SHORT;
}

std::any SymbolVisitor::visitType_ushort(LustreParser::Type_ushortContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::USHORT);
    return varSymbol;

}

std::any SymbolVisitor::visitType_uint(LustreParser::Type_uintContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::UINT);
    return varSymbol;
}

std::any SymbolVisitor::visitType_id(LustreParser::Type_idContext *ctx) {
    auto IDString = ctx->ID()->getText();
    auto IDSymbol = currentScope->resolve(IDString);
    auto typeIDSymbol = std::make_shared<TypeId>(IDString, IDSymbol);


    auto constSymbol = std::make_shared<TypeDefSymbol>("", nullptr, currentScope, Symbol::REFERENCE,
                                                       typeIDSymbol);

    return constSymbol;
}

std::any SymbolVisitor::visitType_array(LustreParser::Type_arrayContext *ctx) {
    //获取type
    auto typeDef = visit(ctx->type());
    //转换type为VarSymbol类型
    auto typeDefVar = std::any_cast<std::shared_ptr<TypeDefSymbol >>(typeDef);
    //获取const的值
    std::any constExpr = visit(ctx->const_expr());
    auto constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(constExpr);

    //获取const中值的type和值内容
//    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(constExpr);

    //如果是第一次进入type_array节点，或者array只有一个维度，进行以下处理
//    std::vector<std::pair<Symbol::varType, std::any>> arrayDim;
//    Symbol::varType arrayType{typeDefVar->variableType};

    //TODO:需要更改
//    arrayDim.emplace_back(constExprValuePair);

    auto arraySymbol = std::make_shared<TypeArray>(typeDefVar, constSymbol);
    return std::make_shared<TypeDefSymbol>("", nullptr, currentScope, Symbol::ARRAY, arraySymbol);

}


std::any SymbolVisitor::visitConst_bin_arith(LustreParser::Const_bin_arithContext *ctx) {
    //获取左侧的Symbol
    auto left = visit(ctx->const_expr(0));
    auto leftConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(left);
    std::any leftValue = leftConstSymbol->getConstValue();

    //如果左侧运算数是引用类型，返回引用值
    if (leftConstSymbol->getDefType() == Symbol::REFERENCE) {
        leftValue = getConstRefValue(leftConstSymbol, false);
    }
    //获取右侧的Symbol
    auto right = visit(ctx->const_expr(1));
    std::string op = ctx->bin_arith_op()->getText();
    auto rightConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(right);
    std::any rightValue = rightConstSymbol->getConstValue();

    //如果右侧运算数是引用类型，返回引用值
    if (rightConstSymbol->getDefType() == Symbol::REFERENCE) {
        rightValue = getConstRefValue(rightConstSymbol, false);
    }
    auto constExpr = LustreVisitorTool::classifyPropertyType(leftValue, rightValue, op, false);
//    auto constExpr= LustreVisitorTool::classifyPropertyType(leftConstSymbol->constValue, rightConstSymbol->constValue, op, false);
    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(constExpr);
    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::BASETYPE,
                                                     constExprValuePair.first,
                                                     constExprValuePair.second, false, nullptr);
    return constSymbol;


}


std::any SymbolVisitor::visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) {
    int result = std::stoi(ctx->INTEGER()->getText());
    return std::any(result);
}

std::any SymbolVisitor::visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) {
    float result = std::stof(ctx->FLOAT()->getText());
    return std::any{result};
}


std::any SymbolVisitor::visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) {
    unsigned short result = std::stoul(ctx->USHORT()->getText());
    return std::any{result};
}

std::any SymbolVisitor::visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) {
    short result = static_cast<short>(std::stoi(ctx->SHORT()->getText()));
    return std::any{result};
}

std::any SymbolVisitor::visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) {
    unsigned int result = std::stoul(ctx->UINT()->getText());
    return std::any{result};
}


std::any SymbolVisitor::visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) {
    char result = ctx->CHAR()->getText()[0];
    return std::any{result};
}

std::any SymbolVisitor::visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) {

    bool result = ctx->BOOL()->getText() == "true";
    return std::any{result};
}

std::any SymbolVisitor::visitAtom_REAL(LustreParser::Atom_REALContext *ctx) {
    double result = std::stod(ctx->REAL()->getText());
    return std::any{result};

}

std::any SymbolVisitor::visitConst_decl(LustreParser::Const_declContext *ctx) {
    std::string name = ctx->ID()->getText();
    std::shared_ptr<ConstSymbol> constSymbol = std::make_shared<ConstSymbol>();
    //获取const的值
    if (ctx->const_expr()) {
        std::any constExpr = visit(ctx->const_expr());
        constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(constExpr);
    }
    auto typeDefSymbol = std::shared_ptr<TypeDefSymbol>();
    if (ctx->type()) {
        //获取type
        auto typeDef = visit(ctx->type());
        //转换type为枚举类型
        typeDefSymbol = std::any_cast<std::shared_ptr<TypeDefSymbol >>(typeDef);

    }

//    std::pair<Symbol::varType, std::string> constExprValuePair = LustreVisitorTool::properTypeToEnum(constExpr);
    //此处建立一个Token类型的智能指针会出现段错误，得创建一个CommonToken类型的智能指针
    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());
    constSymbol->setName(name).setToken(nameToken);
    constSymbol->setConstType(typeDefSymbol).setIsValueVerify(false).setConstCtx(ctx);

    //在当前作用域下定义一个const
    defineConst(constSymbol);
    return std::string("");

}

std::any SymbolVisitor::visitConst_unary_arith(LustreParser::Const_unary_arithContext *ctx) {

    std::any constExpr = visit(ctx->const_expr());
    auto constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(constExpr);
    auto constValue = constSymbol->getConstValue();

    std::string op = ctx->unary_arith_op()->getText();
    //如果右侧运算数是引用类型，返回引用值
    if (constSymbol->getDefType() == Symbol::REFERENCE) {
        constValue = getConstRefValue(constSymbol, false);

        //当没找到引用，并且是bool运算时返回false
        if (op == "not" && !constSymbol->getConstID()->getConstIDSymbol()) {
            constValue = false;
        }
    }
    auto constExprValue = LustreVisitorTool::classifyPropertyType(constValue, op);
    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(constExprValue);
    return std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr, Symbol::BASETYPE,
                                         constExprValuePair.first,
                                         constExprValuePair.second, false, nullptr);
}

std::any SymbolVisitor::visitConst_paren(LustreParser::Const_parenContext *ctx) {
    return LustreBaseVisitor::visit(ctx->const_expr());
}

std::any SymbolVisitor::visitUser_op_decl(LustreParser::User_op_declContext *ctx) {
    std::string name = ctx->ID()->getText();


    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());
    std::shared_ptr<MethodScope> function = std::make_shared<MethodScope>(currentScope,name, Symbol::FUNCTION, nameToken,
                                                                          currentScope);
    //在全局scope中添加function的符号
    currentScope->define(function);
    currentScope->addNestedScopes(function);
    saveScope(ctx, function);
    currentScope = function;

    //只需要访问形参，return中的params不用构造符号表
    LustreBaseVisitor::visit(ctx->params()[0]);

    LustreBaseVisitor::visit(ctx->op_body());

    //访问return中的params,构造符号表
//    LustreBaseVisitor::visit(ctx->params()[1]);
    auto return_params = dynamic_cast<LustreParser::ParamsContext *>(ctx->params()[1]);
    if (return_params) {
        for (auto var_decl: return_params->var_decls()) {
            auto varSymbolVisitor = visit(var_decl);
            auto varSymbolVector = std::any_cast<std::vector<std::shared_ptr<VariableSymbol>>>(varSymbolVisitor);
            for (const auto &varSymbol: varSymbolVector) {
                varSymbol->setType(Symbol::PARAMETER);
                function->defineReturns(varSymbol);
            }
        }
    }

//    std::cout << "Func: " << currentScope->toString() << std::endl;
    currentScope = currentScope->getEnclosingScope();
    return std::string{""};
}

std::any SymbolVisitor::visitParams(LustreParser::ParamsContext *ctx) {
    for (auto var_decl: ctx->var_decls()) {
        auto varSymbolVisitor = visit(var_decl);
        auto varSymbolVector = std::any_cast<std::vector<std::shared_ptr<VariableSymbol>>>(varSymbolVisitor);
        for (const auto &varSymbol: varSymbolVector) {
            defineParam(varSymbol);
        }
    }
    return std::string{""};
}

std::any SymbolVisitor::visitVar_decls(LustreParser::Var_declsContext *ctx) {
//    std::cout << ctx->getText() << std::endl;
    std::any typeVisitor = visit(ctx->type());
    std::vector<std::shared_ptr<VariableSymbol>> varSymbolVector;
    auto typeSymbol = std::any_cast<std::shared_ptr<TypeDefSymbol >>(typeVisitor);
    auto clockID = std::make_pair(false, std::string(""));
    std::shared_ptr<ConstSymbol> lastSymbol = nullptr;
    //当有when字段时
    if (ctx->when_decl()) {
        auto clockVisitor = visit(ctx->when_decl());
        clockID = std::any_cast<std::pair<bool, std::string>>(clockVisitor);
    }
    //当有last字段时
    if (ctx->last_decl()) {
        auto lastVisitor = visit(ctx->last_decl());
        lastSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(lastVisitor);

    }

    //把ID存储进variableSymbol中
    for (size_t i = 0; i < ctx->ID().size(); i++) {
        auto varIDContext = ctx->ID()[i];

        std::any varID = visit(varIDContext);
        auto varIDString = varIDContext->getText();

        auto nameToken = std::make_shared<antlr4::CommonToken>(varIDContext->getSymbol());

//        defineParam(*typeSymbol, clockID);
        std::shared_ptr<VariableSymbol> varSymbol = std::make_shared<VariableSymbol>(varIDString,
                                                                                     nameToken, currentScope,
                                                                                     typeSymbol, clockID, lastSymbol);
        varSymbolVector.push_back(varSymbol);

    }
    return varSymbolVector;
}

std::any SymbolVisitor::visitLocal_block(LustreParser::Local_blockContext *ctx) {


    std::shared_ptr<LocalScope> localScope = std::make_shared<LocalScope>(currentScope);
    currentScope->addNestedScopes(localScope);
    saveScope(ctx, localScope);
    currentScope = localScope;
    //设置节点中的形参
//    std::any inputParameters = visit(ctx->params()[0]);
//    std::string inputParametersString = std::any_cast<std::string>(inputParameters);

    for (auto var_decl: ctx->var_decls()) {
        auto varSymbolVisitor = visit(var_decl);
        auto varSymbolVector = std::any_cast<std::vector<std::shared_ptr<VariableSymbol>>>(varSymbolVisitor);
        for (const auto &varSymbol: varSymbolVector) {
            defineVar(varSymbol);
        }
    }
    LustreBaseVisitor::visitChildren(ctx);

//    std::cout << currentScope->toString() << std::endl;
    currentScope = currentScope->getEnclosingScope();

    return std::string{""};
}

std::any SymbolVisitor::visitType_struct(LustreParser::Type_structContext *ctx) {

    std::vector<std::shared_ptr<TypeDefSymbol>> structSet;

    for (auto field_decl: ctx->field_decl()) {
        auto fieldVisitor = visit(field_decl);
        auto fieldSymbol = std::any_cast<std::shared_ptr<TypeDefSymbol>>(fieldVisitor);
        structSet.push_back(fieldSymbol);
    }
//    auto structSymbol = std::make_shared<TypeStruct>(structVector);

    return std::make_shared<TypeDefSymbol>("", nullptr, currentScope, Symbol::STRUCT,
                                           std::make_shared<TypeStruct>(structSet));
}

std::any SymbolVisitor::visitWhen_decl(LustreParser::When_declContext *ctx) {
    return LustreBaseVisitor::visit(ctx->clock_expr());
}

std::any SymbolVisitor::visitClock_id(LustreParser::Clock_idContext *ctx) {
    auto IDString = ctx->getText();
    return std::make_pair(true, IDString);
}

std::any SymbolVisitor::visitClock_not(LustreParser::Clock_notContext *ctx) {
    auto IDString = ctx->getText();
    return std::make_pair(false, IDString);
}

std::any SymbolVisitor::visitField_decl(LustreParser::Field_declContext *ctx) {
    auto name = ctx->ID()->getText();

    auto typeDef = visit(ctx->type());

    auto varSymbol = std::any_cast<std::shared_ptr<TypeDefSymbol>>(typeDef);
    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());
    varSymbol->setName(name);
    varSymbol->setToken(nameToken);
    return varSymbol;
}

std::any SymbolVisitor::visitConst_bin_bool(LustreParser::Const_bin_boolContext *ctx) {
    auto left = visit(ctx->const_expr(0));
    auto leftConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(left);

    std::any leftValue = leftConstSymbol->getConstValue();

    //如果右侧运算数是引用类型，返回引用值
    if (leftConstSymbol->getDefType() == Symbol::REFERENCE) {
        leftValue = getConstRefValue(leftConstSymbol, true);
    }
    auto right = visit(ctx->const_expr(1));
    std::string op = ctx->bin_bool_op()->getText();
    auto rightConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(right);
    std::any rightValue = rightConstSymbol->getConstValue();

    //如果右侧运算数是引用类型，返回引用值
    if (rightConstSymbol->getDefType() == Symbol::REFERENCE) {
        rightValue = getConstRefValue(rightConstSymbol, true);
    }

    auto constExpr = LustreVisitorTool::classifyPropertyType(leftValue, rightValue,
                                                             op, false);

    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(constExpr);
    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::BASETYPE,
                                                     constExprValuePair.first,
                                                     constExprValuePair.second, false, nullptr);
    return constSymbol;
}

std::any SymbolVisitor::visitConst_bin_relation(LustreParser::Const_bin_relationContext *ctx) {
    auto left = visit(ctx->const_expr(0));
    auto leftConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(left);
    std::any leftValue = leftConstSymbol->getConstValue();

    //如果右侧运算数是引用类型，返回引用值
    if (leftConstSymbol->getDefType() == Symbol::REFERENCE) {
        leftValue = getConstRefValue(leftConstSymbol, false);
    }

    auto right = visit(ctx->const_expr(1));
    std::string op = ctx->bin_relation_op()->getText();
    auto rightConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(right);
    std::any rightValue = leftConstSymbol->getConstValue();

    //如果右侧运算数是引用类型，返回引用值
    if (rightConstSymbol->getDefType() == Symbol::REFERENCE) {
        rightValue = getConstRefValue(rightConstSymbol, false);
    }


    auto constExpr = LustreVisitorTool::classifyPropertyType(leftValue, rightValue,
                                                             op, true);
    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(constExpr);
    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::BASETYPE,
                                                     constExprValuePair.first,
                                                     constExprValuePair.second, false, nullptr);
    return constSymbol;
}

std::any SymbolVisitor::visitConst_atom(LustreParser::Const_atomContext *ctx) {
    auto atom = visit(ctx->atom());

    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(atom);
    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::BASETYPE,
                                                     constExprValuePair.first,
                                                     constExprValuePair.second, false, nullptr);
    return constSymbol;
//    return LustreBaseVisitor::visitChildren(ctx);

}

std::any SymbolVisitor::visitConst_array(LustreParser::Const_arrayContext *ctx) {

    auto constList = visit(ctx->const_list());
    auto constSymbolVector = std::any_cast<std::vector<std::shared_ptr<ConstSymbol>>>(constList);
    auto constArray = std::make_shared<ConstArray>(constSymbolVector);

    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::ARRAY, constArray, false, nullptr);
    return constSymbol;
}

std::any SymbolVisitor::visitConst_list(LustreParser::Const_listContext *ctx) {
    std::vector<std::shared_ptr<ConstSymbol>> constSymbolVector;
    for (auto constExpr: ctx->const_expr()) {
        auto constExprVisitor = visit(constExpr);
        auto constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(constExprVisitor);
        constSymbolVector.emplace_back(constSymbol);

    }

    return constSymbolVector;
}

std::any SymbolVisitor::visitConst_struct(LustreParser::Const_structContext *ctx) {

    std::unordered_set<std::shared_ptr<ConstSymbol>> structSet;
    for (auto labelExpr: ctx->const_label_expr()) {
        auto labelExprVisitor = visit(labelExpr);
        auto constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(labelExprVisitor);
        structSet.insert(constSymbol);

    }
    auto constStruct = std::make_shared<ConstStruct>(structSet);

    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::STRUCT, constStruct, false, nullptr);
    return constSymbol;
}

std::any SymbolVisitor::visitConst_label_expr(LustreParser::Const_label_exprContext *ctx) {
    auto IDString = ctx->ID()->getText();
    auto constExpr = visit(ctx->const_expr());
    auto constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(constExpr);
    constSymbol->setName(IDString);
    return constSymbol;
}

std::any SymbolVisitor::visitConst_id(LustreParser::Const_idContext *ctx) {
    auto IDString = ctx->ID()->getText();
    auto IDSymbol = currentScope->resolve(IDString);
    auto constIDSymbol = std::make_shared<ConstID>(IDString, IDSymbol);


    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::REFERENCE,
                                                     constIDSymbol, false, nullptr);

    return constSymbol;
}

std::any SymbolVisitor::visitType_def_enum(LustreParser::Type_def_enumContext *ctx) {
    std::unordered_map<std::string, std::shared_ptr<antlr4::Token>> enumMap;
    for (auto ID: ctx->ID()) {
        enumMap.insert(std::make_pair(ID->getText(), std::make_shared<antlr4::CommonToken>(ID->getSymbol())));
    }
    auto enumSymbol = std::make_shared<EnumSymbol>("", Symbol::ENUM, nullptr, currentScope, enumMap);
    return enumSymbol;
}

std::any SymbolVisitor::getConstRefValue(std::shared_ptr<ConstSymbol> constSymbol, bool isBool) const {

    std::shared_ptr<Symbol> refSymbol = constSymbol->getConstID()->getConstIDSymbol();
    if (!refSymbol) {
        SpdlogTool::logErr->error("在常量运算时未找到Const:" + constSymbol->getConstID()->getConstID() + "的引用\n");

        return isBool ? false : std::int32_t(0);
    }
    std::shared_ptr<ConstSymbol> refConstSymbol = std::dynamic_pointer_cast<ConstSymbol>(refSymbol);
    return refConstSymbol->getConstValue();

}

/**
 * 定义状态机的作用域
 * @param ctx
 * @return
 */
std::any SymbolVisitor::visitState_machine(LustreParser::State_machineContext *ctx) {
    std::string name = ctx->ID()->getText();

    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());
    std::shared_ptr<AutomatonScope> automatonScope = std::make_shared<AutomatonScope>(currentScope,name, Symbol::AUTOMATON,
                                                                                      nameToken,
                                                                                      currentScope);

    //在局部scope中添加状态机的符号
    currentScope->define(automatonScope);
    currentScope->addNestedScopes(automatonScope);
    saveScope(ctx, automatonScope);
    currentScope = automatonScope;

    //访问每个状态
    for (int i = 0; i < ctx->state_decl().size(); ++i) {
        visit(ctx->state_decl()[i]);
    }

    currentScope = currentScope->getEnclosingScope();
    return std::string{""};
}

/**
 * 定义state的作用域
 * @param ctx
 * @return
 */
std::any SymbolVisitor::visitState_decl(LustreParser::State_declContext *ctx) {
    // 检查State_declContext中的token，判断是否存在initial或final关键字
    bool hasInitial = ctx->INITIAL();
    bool hasFinal = ctx->FINAL();


    std::string name = ctx->ID()->getText();

    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());
    std::shared_ptr<StateScope> automatonScope = std::make_shared<StateScope>(currentScope,name, Symbol::AUTOMATON,
                                                                              nameToken,
                                                                              currentScope, hasInitial, hasFinal);

    //在局部scope中添加状态机的符号
    currentScope->define(automatonScope);
    currentScope->addNestedScopes(automatonScope);
    saveScope(ctx, automatonScope);
    currentScope = automatonScope;


    /**
     * 定义转换语句Symbol
     */
//    if (ctx->unless_tran()) {
//        auto tranSymbolVector = std::any_cast<std::vector<std::shared_ptr<TransitionSymbol>>>(
//                visit(ctx->unless_tran()));
//        for (auto &tranSymbol: tranSymbolVector) {
//            //TODO:名字可能重名
//            tranSymbol->setName(name + "_" + (tranSymbol->strongTran ? "strong" : "weak") + "_" +
//                                (tranSymbol->resume ? "resume" : "restart") + "_" + tranSymbol->stateSymbol.first);
//            currentScope->define(tranSymbol);
//        }
//    }
    /**
     * 访问节点内部
     */
    visit(ctx->data_def());
    /**
     * 定义转换语句Symbol
     */
//    if (ctx->until_tran()) {
//        auto tranSymbolVector = std::any_cast<std::vector<std::shared_ptr<TransitionSymbol>>>(
//                visit(ctx->until_tran()));
//        for (auto &tranSymbol: tranSymbolVector) {
//            //TODO:名字可能重名
//            tranSymbol->setName(name + "_" + (tranSymbol->strongTran ? "strong" : "weak") + "_" +
//                                (tranSymbol->resume ? "resume" : "restart") + "_" + tranSymbol->stateSymbol.first);
//            currentScope->define(tranSymbol);
//        }
//
//    }

    currentScope = currentScope->getEnclosingScope();
    return std::string{""};
}

std::any
SymbolVisitor::visitState_machine_transition_restart(LustreParser::State_machine_transition_restartContext *ctx) {

    std::string name = ctx->ID()->getText();

    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());

    auto transitionSymbol = std::make_shared<TransitionSymbol>("", nameToken, currentScope, false, false, ctx->expr(),
                                                               std::make_pair(name,
                                                                              nullptr));
    return transitionSymbol;
}

std::any
SymbolVisitor::visitState_machine_transition_resume(LustreParser::State_machine_transition_resumeContext *ctx) {


    std::string name = ctx->ID()->getText();

    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());

    auto transitionSymbol = std::make_shared<TransitionSymbol>("", nameToken, currentScope, false, true, ctx->expr(),
                                                               std::make_pair(name,
                                                                              nullptr));
    return transitionSymbol;
}

std::any SymbolVisitor::visitUntil_tran(LustreParser::Until_tranContext *ctx) {
    std::vector<std::shared_ptr<TransitionSymbol>> tranSymbolVector;
    for (int i = 0; i < ctx->transition().size(); ++i) {
        auto tranSymbol = std::any_cast<std::shared_ptr<TransitionSymbol>>(visit(ctx->transition()[i]));
        tranSymbol->strongTran = false;
        tranSymbolVector.emplace_back(tranSymbol);
    }
    return tranSymbolVector;
}

std::any SymbolVisitor::visitUnless_tran(LustreParser::Unless_tranContext *ctx) {
    std::vector<std::shared_ptr<TransitionSymbol>> tranSymbolVector;
    for (int i = 0; i < ctx->transition().size(); ++i) {
        auto tranSymbol = std::any_cast<std::shared_ptr<TransitionSymbol>>(visit(ctx->transition()[i]));
        tranSymbol->strongTran = true;
        tranSymbolVector.emplace_back(tranSymbol);
    }
    return tranSymbolVector;
}

std::any
SymbolVisitor::visitState_machine_data_def_equation(LustreParser::State_machine_data_def_equationContext *ctx) {

    return {};
}

std::any
SymbolVisitor::visitState_machine_data_def_local_block(LustreParser::State_machine_data_def_local_blockContext *ctx) {
    if (ctx->local_block()) {
        visit(ctx->local_block());
    }
    return {};
}


