//
// Created by jack on 1/17/24.
//

#include "SecondSymbolVisitor.h"
#include "../../SymbolTable/Symbol/ConstSymbol.h"
#include "../tool/LustreVisitorTool.h"
#include "../../SymbolTable/Symbol/EnumSymbol.h"
#include "../tool/SpdlogTool.h"
#include "../../SymbolTable/Symbol/VariableSymbol.h"
#include "../src/SymbolTable/Scope/AutomatonScope.h"
#include "../src/SymbolTable/Scope/StateScope.h"
#include "../src/SymbolTable/Symbol/TransitionSymbol.h"

std::vector<std::string> SecondSymbolVisitor::structVector;

SecondSymbolVisitor::SecondSymbolVisitor(
        std::shared_ptr<antlr4::tree::ParseTreeProperty<std::shared_ptr<Scope>>> scopes,
        std::shared_ptr<GlobalScope> globals) : scopes(scopes), globals(globals) {

}

std::any SecondSymbolVisitor::visitProgram(LustreParser::ProgramContext *ctx) {
    currentScope = globals;
    LustreBaseVisitor::visitChildren(ctx);
    SpdlogTool::logErr->info(globals->toString());
    return "";

}

std::any SecondSymbolVisitor::visitUser_op_decl(LustreParser::User_op_declContext *ctx) {
    //符号表进入局部变量
    currentScope = scopes->get(ctx);
    LustreBaseVisitor::visitUser_op_decl(ctx);
    SpdlogTool::logErr->info(currentScope->toString());

    //符号表退出局部变量
    currentScope = currentScope->getEnclosingScope();
    return "";

}

std::any SecondSymbolVisitor::visitLocal_block(LustreParser::Local_blockContext *ctx) {
    //符号表进入局部变量
    currentScope = scopes->get(ctx);
    LustreBaseVisitor::visitLocal_block(ctx);

    SpdlogTool::logErr->info(currentScope->toString());
    //符号表退出局部变量
    currentScope = currentScope->getEnclosingScope();
    return "";
}

std::any SecondSymbolVisitor::visitConst_bin_arith(LustreParser::Const_bin_arithContext *ctx) {
    //获取左侧的Symbol
    auto left = visit(ctx->const_expr(0));
    auto leftConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(left);
    std::any leftValue = leftConstSymbol->getConstValue();
//

    //获取右侧的Symbol
    auto right = visit(ctx->const_expr(1));
    std::string op = ctx->bin_arith_op()->getText();
    auto rightConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(right);
    std::any rightValue = rightConstSymbol->getConstValue();

    auto constExpr = LustreVisitorTool::classifyPropertyType(leftValue, rightValue, op, false);
//    auto constExpr= LustreVisitorTool::classifyPropertyType(leftConstSymbol->constValue, rightConstSymbol->constValue, op, false);
    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(constExpr);
    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::BASETYPE,
                                                     constExprValuePair.first,
                                                     constExprValuePair.second, true, nullptr);
    return constSymbol;

}

std::any SecondSymbolVisitor::visitConst_decl(LustreParser::Const_declContext *ctx) {
    /**
     * 此处是Const递归起点
     * 测试文件：./srs_l2c_syn_010_003/srs_l2c_syn_010_003.Lustre
     * 如：   myConst1 : int = myConst2 * 123 - (  8 + 23);
     *       myConst2 : int = 23;
     * 当值为后定义时的解决方案，在myConst1访问到他的子节点myConst2时，
     * 会通过myConst2的ctx访问到本方法从而先算出myConst2的值，再得出myConst1的值
     *
     *
     */

    std::string name = ctx->ID()->getText();
    auto it = std::find(constPointVector.begin(), constPointVector.end(), name);
    auto constSymbol = std::dynamic_pointer_cast<ConstSymbol>(currentScope->resolve(name));
    //递归退出条件1:有循环依赖
    if (it != constPointVector.end()) {
        std::string errorString("在确认常量值的时候发现循环回路:");
        for (const auto &element: constPointVector) {
            errorString += element + "->";

        }
        errorString = errorString + name + "\n";
        SpdlogTool::logErr->error(errorString);

        return constSymbol;
    }

    //循环退出条件2:自己的Symbol已经被检查过了
    if (constSymbol->getIsValueVerify()) {
        return constSymbol;
    }

    auto currentConstSymbol = std::make_shared<ConstSymbol>();
    constPointVector.push_back(name);

    //重新设置type
    std::any type = visit(ctx->type());
    auto currentTypeSymbol = std::any_cast<std::shared_ptr<TypeDefSymbol>>(type);

    constSymbol->setConstType(currentTypeSymbol);
    /**
     * 这里判断是否返回的是struct类型
     * 如果是，说明这个const指向一个匿名的结构体，我们需要对他重新定义，方便语法转换
     */
    if (currentTypeSymbol->getDefType() == Symbol::STRUCT) {
        constSymbol->setConstType(setNewStructType(globals, currentScope, currentTypeSymbol));
    }


    //重新设置初始值
    if (ctx->const_expr()) {
        //检查自己的Symbol值
        std::any constExpr = visit(ctx->const_expr());
        currentConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(constExpr);
        //如果有引用类型，就重新定义引用类型
        //重新设置自己的Symbol值,包括type和value
        constSymbol->setIsValueVerify(true).setConstValueType(currentConstSymbol->getConstValueType())
                .setConstValue(currentConstSymbol->getConstValue());
    }
    if (constPointVector[0] == name) {
        constPointVector.clear();

    }
    //因为在const_id时会重新调用本方法来递归，所以要返回自己的Symbol给const_id;
    return constSymbol;
}

std::any SecondSymbolVisitor::visitConst_id(LustreParser::Const_idContext *ctx) {

    auto IDString = ctx->ID()->getText();
    auto IDSymbol = currentScope->resolve(IDString);
    std::shared_ptr<ConstSymbol> refConstSymbol = std::dynamic_pointer_cast<ConstSymbol>(IDSymbol);

    std::shared_ptr<EnumSymbol> refEnumSymbol = std::dynamic_pointer_cast<EnumSymbol>(IDSymbol);
    //如果是const类型
    //如果在const中没有找到，那么就是值，而不是引用，它会把枚举和结构体的值都放在其中
    if (refConstSymbol) {
        auto constSymbol = visitConst_decl(refConstSymbol->getConstCtx());
        return constSymbol;
    } else {
        auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                         Symbol::BASETYPE,
                                                         Symbol::CHAR,
                                                         std::string(IDString), true, nullptr);
        return constSymbol;
    }

    return std::string("");
}

std::any SecondSymbolVisitor::visitConst_atom(LustreParser::Const_atomContext *ctx) {
    auto atom = visit(ctx->atom());

    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(atom);
    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::BASETYPE,
                                                     constExprValuePair.first,
                                                     constExprValuePair.second, true, nullptr);
    return constSymbol;
}

std::any SecondSymbolVisitor::visitAtom_INTEGER(LustreParser::Atom_INTEGERContext *ctx) {
    int result = std::stoi(ctx->INTEGER()->getText());
    return std::any(result);
}

std::any SecondSymbolVisitor::visitAtom_FLOAT(LustreParser::Atom_FLOATContext *ctx) {
    float result = std::stof(ctx->FLOAT()->getText());
    return std::any{result};
}


std::any SecondSymbolVisitor::visitAtom_USHORT(LustreParser::Atom_USHORTContext *ctx) {
    unsigned short result = std::stoul(ctx->USHORT()->getText());
    return std::any{result};
}

std::any SecondSymbolVisitor::visitAtom_SHORT(LustreParser::Atom_SHORTContext *ctx) {
    short result = static_cast<short>(std::stoi(ctx->SHORT()->getText()));
    return std::any{result};
}

std::any SecondSymbolVisitor::visitAtom_UINT(LustreParser::Atom_UINTContext *ctx) {
    unsigned int result = std::stoul(ctx->UINT()->getText());
    return std::any{result};
}


std::any SecondSymbolVisitor::visitAtom_CHAR(LustreParser::Atom_CHARContext *ctx) {
    char result = ctx->CHAR()->getText()[0];
    return std::any{result};
}

std::any SecondSymbolVisitor::visitAtom_BOOL(LustreParser::Atom_BOOLContext *ctx) {

    bool result = ctx->BOOL()->getText() == "true";
    return std::any{result};
}

std::any SecondSymbolVisitor::visitAtom_REAL(LustreParser::Atom_REALContext *ctx) {
    double result = std::stod(ctx->REAL()->getText());
    return std::any{result};

}

std::any SecondSymbolVisitor::visitConst_paren(LustreParser::Const_parenContext *ctx) {
    return LustreBaseVisitor::visit(ctx->const_expr());
}

std::any SecondSymbolVisitor::visitConst_bin_bool(LustreParser::Const_bin_boolContext *ctx) {
    auto left = visit(ctx->const_expr(0));
    auto leftConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(left);

    std::any leftValue = leftConstSymbol->getConstValue();


    auto right = visit(ctx->const_expr(1));
    std::string op = ctx->bin_bool_op()->getText();
    auto rightConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(right);
    std::any rightValue = rightConstSymbol->getConstValue();


    auto constExpr = LustreVisitorTool::classifyPropertyType(leftValue, rightValue,
                                                             op, false);

    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(constExpr);
    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::BASETYPE,
                                                     constExprValuePair.first,
                                                     constExprValuePair.second, true, nullptr);
    return constSymbol;


}

std::any SecondSymbolVisitor::visitConst_unary_arith(LustreParser::Const_unary_arithContext *ctx) {

    std::any constExpr = visit(ctx->const_expr());
    auto constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(constExpr);
    auto constValue = constSymbol->getConstValue();

    std::string op = ctx->unary_arith_op()->getText();

    auto constExprValue = LustreVisitorTool::classifyPropertyType(constValue, op);
    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(constExprValue);
    return std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr, Symbol::BASETYPE,
                                         constExprValuePair.first,
                                         constExprValuePair.second, true, nullptr);
}

std::any SecondSymbolVisitor::visitConst_bin_relation(LustreParser::Const_bin_relationContext *ctx) {
    auto left = visit(ctx->const_expr(0));
    auto leftConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(left);
    std::any leftValue = leftConstSymbol->getConstValue();

    auto right = visit(ctx->const_expr(1));
    std::string op = ctx->bin_relation_op()->getText();
    auto rightConstSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(right);
    std::any rightValue = leftConstSymbol->getConstValue();

    auto constExpr = LustreVisitorTool::classifyPropertyType(leftValue, rightValue,
                                                             op, true);
    std::pair<Symbol::varType, std::any> constExprValuePair = LustreVisitorTool::properTypeToEnum(constExpr);
    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::BASETYPE,
                                                     constExprValuePair.first,
                                                     constExprValuePair.second, true, nullptr);
    return constSymbol;
}

std::any SecondSymbolVisitor::visitConst_array(LustreParser::Const_arrayContext *ctx) {
    auto constList = visit(ctx->const_list());
    auto constSymbolVector = std::any_cast<std::vector<std::shared_ptr<ConstSymbol>>>(constList);
    auto constArray = std::make_shared<ConstArray>(constSymbolVector);

    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::ARRAY, constArray, true, nullptr);
    return constSymbol;
}

std::any SecondSymbolVisitor::visitConst_struct(LustreParser::Const_structContext *ctx) {

    std::unordered_set<std::shared_ptr<ConstSymbol>> structSet;
    for (auto labelExpr: ctx->const_label_expr()) {
        auto labelExprVisitor = visit(labelExpr);
        auto constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(labelExprVisitor);
        structSet.insert(constSymbol);

    }
    auto constStruct = std::make_shared<ConstStruct>(structSet);

    auto constSymbol = std::make_shared<ConstSymbol>("", Symbol::CONSTANT, nullptr, currentScope, nullptr,
                                                     Symbol::STRUCT,
                                                     constStruct, true, nullptr);
    return constSymbol;
}

std::any SecondSymbolVisitor::visitConst_list(LustreParser::Const_listContext *ctx) {
    std::vector<std::shared_ptr<ConstSymbol>> constSymbolVector;
    for (auto constExpr: ctx->const_expr()) {
        auto constExprVisitor = visit(constExpr);
        auto constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(constExprVisitor);
        constSymbolVector.emplace_back(constSymbol);

    }

    return constSymbolVector;
}

std::any SecondSymbolVisitor::visitConst_label_expr(LustreParser::Const_label_exprContext *ctx) {
    auto IDString = ctx->ID()->getText();
    auto constExpr = visit(ctx->const_expr());
    auto constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(constExpr);
    constSymbol->setName(IDString);
    return constSymbol;
}

std::any SecondSymbolVisitor::visitType_id(LustreParser::Type_idContext *ctx) {
    auto IDString = ctx->ID()->getText();
    auto IDSymbol = currentScope->resolve(IDString);
    auto typeIDSymbol = std::make_shared<TypeId>(IDString, IDSymbol);


    auto constSymbol = std::make_shared<TypeDefSymbol>("", nullptr, currentScope, Symbol::REFERENCE,
                                                       typeIDSymbol);

    return constSymbol;
}

std::any SecondSymbolVisitor::visitType_def_type(LustreParser::Type_def_typeContext *ctx) {

    return visit(ctx->type());
}

std::any SecondSymbolVisitor::visitType_float(LustreParser::Type_floatContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::FLOAT);
    return varSymbol;
}

std::any SecondSymbolVisitor::visitType_int(LustreParser::Type_intContext *ctx) {

    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::INTEGER);
    return varSymbol;

}

std::any SecondSymbolVisitor::visitType_bool(LustreParser::Type_boolContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::BOOL);
    return varSymbol;


}

std::any SecondSymbolVisitor::visitType_real(LustreParser::Type_realContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::REAL);
    return varSymbol;


}

std::any SecondSymbolVisitor::visitType_char(LustreParser::Type_charContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::CHAR);
    return varSymbol;


}

std::any SecondSymbolVisitor::visitType_short(LustreParser::Type_shortContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::SHORT);
    return varSymbol;

//    return SymbolTable::SHORT;
}

std::any SecondSymbolVisitor::visitType_ushort(LustreParser::Type_ushortContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::USHORT);
    return varSymbol;

}

std::any SecondSymbolVisitor::visitType_uint(LustreParser::Type_uintContext *ctx) {
    auto varSymbol = std::make_shared<TypeDefSymbol>();
    varSymbol->setDefType(Symbol::BASETYPE);
    varSymbol->setVariableType(Symbol::UINT);
    return varSymbol;
}

std::any SecondSymbolVisitor::visitType_array(LustreParser::Type_arrayContext *ctx) {
    //获取type
    auto typeDef = visit(ctx->type());
    //转换type为VarSymbol类型
    auto typeDefVar = std::any_cast<std::shared_ptr<TypeDefSymbol >>(typeDef);
    //获取const的值
    std::any constExpr = visit(ctx->const_expr());
    auto constSymbol = std::any_cast<std::shared_ptr<ConstSymbol>>(constExpr);

    /**
     * 这里判断是否返回的是struct类型
     * 如果是，说明这个const指向一个匿名的结构体，我们需要对他重新定义，方便语法转换
     */
    if (typeDefVar->getDefType() == Symbol::STRUCT) {
        typeDefVar = setNewStructType(globals, currentScope, typeDefVar);
    }
    auto arraySymbol = std::make_shared<TypeArray>(typeDefVar, constSymbol);
    return std::make_shared<TypeDefSymbol>("", nullptr, currentScope, Symbol::ARRAY, arraySymbol);

}

std::any SecondSymbolVisitor::visitType_decl(LustreParser::Type_declContext *ctx) {
    /**
     * typeDecl只需要关注引用类型的更改就行了
     */
    std::string name = ctx->ID()->getText();
    if (ctx->type_def()) {

        auto typeDef = visit(ctx->type_def());
        auto IDSymbol = currentScope->resolve(name);
        /**
         * 此处只对type定义做重新定义，未对枚举做任何操作,因为枚举不会调用其他定义
         */
        if (typeDef.type() == typeid(std::shared_ptr<TypeDefSymbol>)) {
            std::shared_ptr<TypeDefSymbol> typeDefSymbol = std::dynamic_pointer_cast<TypeDefSymbol>(IDSymbol);

            auto currentTypeDefSymbol = std::any_cast<std::shared_ptr<TypeDefSymbol>>(typeDef);
            //如果有引用，数组，结构体类型，就重新定义类型，因为这些字段能引用下文字段
            if (currentTypeDefSymbol->getTypeID()) {
                typeDefSymbol->setTypeID(currentTypeDefSymbol->getTypeID());
            }
            if (currentTypeDefSymbol->getStructSymbol()) {
                typeDefSymbol->setStructSymbol(currentTypeDefSymbol->getStructSymbol());
            }
            if (currentTypeDefSymbol->getArraySymbol()) {
                typeDefSymbol->setArraySymbol(currentTypeDefSymbol->getArraySymbol());
            }
            /**
             * 这里判断是否返回的是struct类型
             * 如果是，说明这个const指向一个匿名的结构体，我们需要对他重新定义，方便语法转换
             */
            if (currentTypeDefSymbol->getDefType() == Symbol::STRUCT) {
                globals->setSymbolBySymbolName(setNewStructType(globals, currentScope, currentTypeDefSymbol));
            }
        }
    }
    return std::string("");
}

std::any SecondSymbolVisitor::visitType_struct(LustreParser::Type_structContext *ctx) {

    std::vector<std::shared_ptr<TypeDefSymbol>> structSet;

    for (auto field_decl: ctx->field_decl()) {
        auto fieldVisitor = visit(field_decl);
        auto fieldSymbol = std::any_cast<std::shared_ptr<TypeDefSymbol>>(fieldVisitor);
        structSet.push_back(fieldSymbol);
    }

    return std::make_shared<TypeDefSymbol>("", nullptr, currentScope, Symbol::STRUCT,
                                           std::make_shared<TypeStruct>(structSet));
}

std::any SecondSymbolVisitor::visitField_decl(LustreParser::Field_declContext *ctx) {
    auto name = ctx->ID()->getText();

    auto typeDef = visit(ctx->type());

    auto currentTypeSymbol = std::any_cast<std::shared_ptr<TypeDefSymbol>>(typeDef);

    if (currentTypeSymbol->getDefType() == Symbol::STRUCT) {
        currentTypeSymbol = setNewStructType(globals, currentScope, currentTypeSymbol);
    }
    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());
    currentTypeSymbol->setName(name);
    currentTypeSymbol->setToken(nameToken);
    return currentTypeSymbol;
}

std::shared_ptr<TypeDefSymbol>
SecondSymbolVisitor::setTypeToRefGlobalType(std::shared_ptr<GlobalScope> globals1, std::shared_ptr<Scope> currentScope1,
                                            std::shared_ptr<TypeDefSymbol> currentTypeSymbol) {

    //1.设置引用类型的名字,TODO:最好采用全局
    std::string refName;
    for (int i = 0; i < 1000; i++) {
        std::string tempRefName("tempStructType" + std::to_string(i));
        if (!currentScope1->resolve(tempRefName)) {
            refName = tempRefName;
            break;
        }
    }
    //2.设置引用类型的类
    auto typeIDSymbol = std::make_shared<TypeId>(refName, currentTypeSymbol);
    auto typeRefSymbol = std::make_shared<TypeDefSymbol>("", nullptr, currentScope, Symbol::REFERENCE,
                                                         typeIDSymbol);
    //3.用vector保存新增的类型
    structVector.push_back(refName);
    //4.在符号表的全局范围中，增加新增的type类型
    currentTypeSymbol->setName(refName);
    globals1->define(currentTypeSymbol);
    return typeRefSymbol;
}

std::any SecondSymbolVisitor::visitVar_decls(LustreParser::Var_declsContext *ctx) {
    for (int i = 0; i < ctx->ID().size(); ++i) {
        std::string test = ctx->ID()[i]->getText();

        auto tempSymbol = currentScope->resolve(ctx->ID()[i]->getText());
        auto varSymbol = std::dynamic_pointer_cast<VariableSymbol>(tempSymbol);
        if (!varSymbol) {
            return "";
        }
        /**
        * 这里判断是否返回的是struct类型
        * 如果是，说明这个const指向一个匿名的结构体，我们需要对他重新定义，方便语法转换
        */
//        auto currentTypeSymbol = varSymbol->getTypeDefSymbol();
        auto currentTypeSymbol = std::any_cast<std::shared_ptr<TypeDefSymbol>>(visit(ctx->type()));
        varSymbol->setTypeDefSymbol(currentTypeSymbol);

        if (currentTypeSymbol->getDefType() == Symbol::STRUCT) {
            varSymbol->setTypeDefSymbol(setNewStructType(globals, currentScope, currentTypeSymbol));
        }

    }
    return "";
}

std::shared_ptr<TypeDefSymbol>
SecondSymbolVisitor::setNewStructType(std::shared_ptr<GlobalScope> globals1, std::shared_ptr<Scope> currentScope1,
                                      std::shared_ptr<TypeDefSymbol> currentTypeSymbol) {
    std::shared_ptr<TypeDefSymbol> equalType;
    //如果返回的是struct类型
    for (const auto &symbol: globals1->getAllSymbols()) {
        if (auto typeSymbol = std::dynamic_pointer_cast<TypeDefSymbol>(symbol.second)) {
            if (currentTypeSymbol->isEqual(typeSymbol)) {
                equalType = typeSymbol;
                break;
            }
        }
    }
    if (equalType) {
        //当匿名的结构体和已经存在的结构体一致，就把它的类型设置为已有的类型
//                    std::cout<<name<<std::endl;
        // 把当前const的type设置成引用类型，引用已经存在的结构体
        auto typeIDSymbol = std::make_shared<TypeId>(equalType->getName(), equalType);
        auto typeRefSymbol = std::make_shared<TypeDefSymbol>("", nullptr, currentScope1, Symbol::REFERENCE,
                                                             typeIDSymbol);
        return typeRefSymbol;

    } else {
        //当匿名的结构体类型和已经存在的不一致,就新建一个引用类型，让他引用这个新建的类型
        //更改引用类型
        return setTypeToRefGlobalType(globals1, currentScope1, currentTypeSymbol);
    }
}


/**
 * 定义状态机的作用域
 * @param ctx
 * @return
 */
std::any SecondSymbolVisitor::visitState_machine(LustreParser::State_machineContext *ctx) {

    auto name = ctx->ID()->getText();

    //访问每个状态
    for (int i = 0; i < ctx->state_decl().size(); ++i) {
        visit(ctx->state_decl()[i]);
    }

    return currentScope->resolve(name);
}

/**
 * 定义state的作用域
 * @param ctx
 * @return
 */
std::any SecondSymbolVisitor::visitState_decl(LustreParser::State_declContext *ctx) {
    //符号表进入局部变量
    currentScope = scopes->get(ctx);


    std::string name = ctx->ID()->getText();


    /**
     * 定义转换语句Symbol
     */
    if (ctx->unless_tran()) {
        auto tranSymbolVector = std::any_cast<std::vector<std::shared_ptr<TransitionSymbol>>>(
                visit(ctx->unless_tran()));
        for (auto &tranSymbol: tranSymbolVector) {
            //TODO:名字可能重名
            tranSymbol->setName(name + "_" + (tranSymbol->strongTran ? "strong" : "weak") + "_" +
                                (tranSymbol->resume ? "resume" : "restart") + "_" + tranSymbol->stateSymbol.first);
            currentScope->define(tranSymbol);
        }
    }
    /**
     * 访问节点内部
     */
    visit(ctx->data_def());
    /**
     * 定义转换语句Symbol
     */
    if (ctx->until_tran()) {
        auto tranSymbolVector = std::any_cast<std::vector<std::shared_ptr<TransitionSymbol>>>(
                visit(ctx->until_tran()));
        for (auto &tranSymbol: tranSymbolVector) {
            //TODO:名字可能重名
            tranSymbol->setName(name + "_" + (tranSymbol->strongTran ? "strong" : "weak") + "_" +
                                (tranSymbol->resume ? "resume" : "restart") + "_" + tranSymbol->stateSymbol.first);
            currentScope->define(tranSymbol);
        }

    }

    SpdlogTool::logErr->info(currentScope->toString());
    currentScope = currentScope->getEnclosingScope();
    return std::string{""};
}

std::any
SecondSymbolVisitor::visitState_machine_transition_restart(LustreParser::State_machine_transition_restartContext *ctx) {

    std::string name = ctx->ID()->getText();

    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());
    //TODO:不能跨状态机找state节点
    auto symbol = currentScope->resolve(name);
    auto transitionSymbol = std::make_shared<TransitionSymbol>("", nameToken, currentScope, false, false, ctx->expr(),
                                                               std::make_pair(name, symbol));
    return transitionSymbol;
}

std::any
SecondSymbolVisitor::visitState_machine_transition_resume(LustreParser::State_machine_transition_resumeContext *ctx) {


    std::string name = ctx->ID()->getText();

    auto nameToken = std::make_shared<antlr4::CommonToken>(ctx->ID()->getSymbol());
    //TODO:不能跨状态机找state节点
    auto symbol = currentScope->resolve(name);
    auto transitionSymbol = std::make_shared<TransitionSymbol>("", nameToken, currentScope, false, true, ctx->expr(),
                                                               std::make_pair(name, symbol));
    return transitionSymbol;
}

std::any SecondSymbolVisitor::visitUntil_tran(LustreParser::Until_tranContext *ctx) {
    std::vector<std::shared_ptr<TransitionSymbol>> tranSymbolVector;
    for (int i = 0; i < ctx->transition().size(); ++i) {
        auto tranSymbol = std::any_cast<std::shared_ptr<TransitionSymbol>>(visit(ctx->transition()[i]));
        tranSymbol->strongTran = false;
        tranSymbolVector.emplace_back(tranSymbol);
    }
    return tranSymbolVector;
}

std::any SecondSymbolVisitor::visitUnless_tran(LustreParser::Unless_tranContext *ctx) {
    std::vector<std::shared_ptr<TransitionSymbol>> tranSymbolVector;
    for (int i = 0; i < ctx->transition().size(); ++i) {
        auto tranSymbol = std::any_cast<std::shared_ptr<TransitionSymbol>>(visit(ctx->transition()[i]));
        tranSymbol->strongTran = true;
        tranSymbolVector.emplace_back(tranSymbol);
    }
    return tranSymbolVector;
}

std::any
SecondSymbolVisitor::visitState_machine_data_def_equation(LustreParser::State_machine_data_def_equationContext *ctx) {

    return {};
}

std::any
SecondSymbolVisitor::visitState_machine_data_def_local_block(
        LustreParser::State_machine_data_def_local_blockContext *ctx) {
    if (ctx->local_block()) {
        visit(ctx->local_block());
    }
    return {};
}

std::any SecondSymbolVisitor::visitEquation_state_machine(LustreParser::Equation_state_machineContext *ctx) {
    //符号表进入局部变量
    currentScope = scopes->get(ctx);
    auto stateMachine = visit(ctx->state_machine());
    auto returnIDVector =std::any_cast<std::vector<std::string>>(visit(ctx->return_()));

    /**
     * 定义状态机的返回值
     */
    if (auto symbol=std::any_cast<std::shared_ptr<Symbol>>(stateMachine)){
        auto automatonScope=std::dynamic_pointer_cast<AutomatonScope>(symbol);
        if (!automatonScope){
            SpdlogTool::logErr->info(currentScope->toString());
            currentScope = currentScope->getEnclosingScope();
            SpdlogTool::logErr->error("符号表中找不到状态机");
            return std::string{};
        }
        for (const auto & i : returnIDVector) {
            if (i==".."){
                //TODO:对全部的返回值进行定义
            }
            currentScope->define(currentScope->resolveNested(i)?currentScope->resolveNested(i):currentScope->resolve(i));
        }
    }

    SpdlogTool::logErr->info(currentScope->toString());
    currentScope = currentScope->getEnclosingScope();
    return std::string{};
}

std::any SecondSymbolVisitor::visitReturns_var(LustreParser::Returns_varContext *ctx) {
    std::vector<std::string> IDVector;
    if (ctx->getText()==".."){
        IDVector.emplace_back("..");
    }
    for (int i = 0; i < ctx->ID().size(); ++i) {
       IDVector.emplace_back(ctx->ID()[i]->getText());
    }
    return IDVector;
}

std::any SecondSymbolVisitor::visitReturn(LustreParser::ReturnContext *ctx) {
    return visit(ctx->returns_var());
}

