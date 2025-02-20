#pragma once
#include <cassert>
#include <iostream>
#include <string>

class SQLSelectQuery{
public:
    std::string sectionSelect;
    std::string sectionFrom;
    std::string sectionWhere;
    unsigned int numberOfLexemsInSelectSection;
    unsigned int numberOfLexemsInWhereSection;
};