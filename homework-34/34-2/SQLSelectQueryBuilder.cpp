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

SQLSelectQueryBuilder& SQLSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& keyValue) noexcept{
    if(sqlSelectQuery.numberOfLexemsInWhereSection == 0){
        if(keyValue.size() == 1){
            for(auto& element : keyValue){
                sqlSelectQuery.sectionWhere += element.first + "=" + element.second;
                ++sqlSelectQuery.numberOfLexemsInWhereSection;
            }
        }else{
            auto iterator = keyValue.begin();
            for(iterator; iterator != std::prev(keyValue.end(), 1); ++iterator){
                sqlSelectQuery.sectionWhere += iterator->first + "=" + iterator->second + " AND ";
                ++sqlSelectQuery.numberOfLexemsInWhereSection;
            }
            sqlSelectQuery.sectionWhere += iterator->first + "=" + iterator->second;
            ++sqlSelectQuery.numberOfLexemsInWhereSection;
        }
    }else{
        for(auto& element : keyValue){
            sqlSelectQuery.sectionWhere += " AND" + element.first + "=" + element.second;
            ++sqlSelectQuery.numberOfLexemsInWhereSection;
        }
    }
    return *this;
}

SQLSelectQueryBuilder& SQLSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept{
    if(sqlSelectQuery.numberOfLexemsInSelectSection == 0){
        if(columns.size() == 1){
            sqlSelectQuery.sectionSelect += columns[0];
            ++sqlSelectQuery.numberOfLexemsInSelectSection;
        }else{
            for(size_t index = 0; index < columns.size() - 1; ++index){
                sqlSelectQuery.sectionSelect += columns[index] + ", ";
                ++sqlSelectQuery.numberOfLexemsInSelectSection;
            }
            sqlSelectQuery.sectionSelect += columns[columns.size() - 1];
            ++sqlSelectQuery.numberOfLexemsInSelectSection;
        }
    }else{
        for(size_t index = 0; index < columns.size(); ++index){
            sqlSelectQuery.sectionSelect += ", " + columns[index];
            ++sqlSelectQuery.numberOfLexemsInSelectSection;
        }
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