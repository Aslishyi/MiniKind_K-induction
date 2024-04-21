//
// Created by jack on 12/24/23.
//

#include "ConstArray.h"

#include <utility>
#include "ConstSymbol.h"


std::string ConstArray::toAstString() const {
    std::stringstream  ss;
    auto string=constSymbolVector.size();

    for (int i = 0; i < constSymbolVector.size(); ++i) {

        ss <<  (constSymbolVector[i])->getDefTypeString(constSymbolVector[i]->getDefType()) ;

        if (i < constSymbolVector.size() - 1)
            ss << ",";

    }
    return ss.str();
}


ConstArray::ConstArray(std::vector<std::shared_ptr<ConstSymbol>> constSymbolVector) :constSymbolVector(std::move(constSymbolVector)){

}

std::string ConstArray::toLusString() const {
    std::stringstream  ss;
    for (int i = 0; i < constSymbolVector.size(); ++i) {

        ss <<  (constSymbolVector[i])->getDefTypeLusString(constSymbolVector[i]->getDefType()) ;

        if (i < constSymbolVector.size() - 1)
            ss << " , ";

    }
    return ss.str();
}
