#include "SQLSelectQueryBuilder.hpp"

SQLSelectQueryBuilder& SQLSelectQueryBuilder::AddColumn(const std::string& column){
    if(sqlSelectQuery.numberOfLexemsInSelectSection == 0){
        sqlSelectQuery.sectionSelect += column;
        ++sqlSelectQuery.numberOfLexemsInSelectSection;
    }else{
        sqlSelectQuery.sectionSelect += ", " + column;
        ++sqlSelectQuery.numberOfLexemsInSelectSection;
    }
    return *this;
}

SQLSelectQueryBuilder& SQLSelectQueryBuilder::AddFrom(const std::string& from){
    sqlSelectQuery.sectionFrom = from;
    return *this; 
}

SQLSelectQueryBuilder& SQLSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value){
    if(sqlSelectQuery.numberOfLexemsInWhereSection == 0){
        sqlSelectQuery.sectionWhere += column + "=" + value;
        ++sqlSelectQuery.numberOfLexemsInWhereSection;
    }else{
        sqlSelectQuery.sectionWhere += " AND " + column + "=" + value;
        ++sqlSelectQuery.numberOfLexemsInWhereSection;
    }
    return *this;
}

std::string SQLSelectQueryBuilder::BuildQuery(){
    if(sqlSelectQuery.numberOfLexemsInSelectSection == 0){
        return "SELECT * FROM " + sqlSelectQuery.sectionFrom + " WHERE " + sqlSelectQuery.sectionWhere + ";";
    }else{
        return "SELECT " + sqlSelectQuery.sectionSelect + " FROM " + sqlSelectQuery.sectionFrom + " WHERE " + sqlSelectQuery.sectionWhere + ";";
    }
}