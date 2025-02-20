#include "SQLSelectQueryBuilder.hpp"

void Test(){
    SQLSelectQueryBuilder queryBuilder;
    queryBuilder.AddColumns({{"name"}, {"surname"}, {"phone"}, {"sex"}});
    queryBuilder.AddFrom("students");
    queryBuilder.AddWhere({{"id", "42"}, {"name", "John"}, {"sex", "male"}});
    assert(queryBuilder.BuildQuery() == "SELECT name, surname, phone, sex FROM students WHERE id=42 AND name=John AND sex=male;");
}

int main(int argc, char* argv[]){
    Test();
    return EXIT_SUCCESS;
}