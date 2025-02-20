#pragma once
#include <cassert>
#include <iostream>
#include <map>
#include <string>

class SQLSelectQuery{
public:
    std::string sectionSelect;
    std::string sectionFrom;
    std::string sectionWhere;
    unsigned int numberOfLexemsInSelectSection = 0;
    unsigned int numberOfLexemsInWhereSection = 0;
};