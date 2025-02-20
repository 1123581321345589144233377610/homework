#pragma once
#include "SQLSelectQuery.hpp"

class SQLSelectQueryBuilder{
private:
    SQLSelectQuery sqlSelectQuery;
public:
    SQLSelectQueryBuilder& AddColumn(const std::string&);
    SQLSelectQueryBuilder& AddFrom(const std::string&);
    SQLSelectQueryBuilder& AddWhere(const std::string&, const std::string&);
    std::string BuildQuery();
};