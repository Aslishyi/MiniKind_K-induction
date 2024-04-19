//
// Created by jack on 11/22/23.
//

#include <iostream>
#include <sstream>
#include "GlobalScope.h"

GlobalScope::GlobalScope()
        : symbols(std::make_shared<std::unordered_map<std::string, std::shared_ptr<Symbol>>>())
{ }

GlobalScope::~GlobalScope()
{ }

const std::string &GlobalScope::scopeName() const
{
    return name;
}

std::shared_ptr<Scope> GlobalScope::getEnclosingScope() const
{
    return nullptr;
}

void GlobalScope::define(std::shared_ptr<Symbol> symbol)
{
    symbols->insert(std::make_pair(symbol->getName(), symbol));
}

std::shared_ptr<Symbol> GlobalScope::resolve(const std::string &name) const
{
    auto iter = symbols->find(name);
    if (iter != symbols->end())
        return iter->second;
    else
        return nullptr;
}

const std::string GlobalScope::toString() const
{
	std::stringstream ss;
	ss << scopeName() << ": ";
	for (auto &ele : *symbols)
		ss << ele.second->toAstString() << ",";
	ss << std::endl;
	return ss.str();
//    std::cout<<"GlobalScope.toString"<<std::endl;
//    return "GlobalScope.toString";
}
