#include "SQLSelectQueryBuilder.hpp"

void Test(){
    SQLSelectQueryBuilder queryBuilder;
    queryBuilder.AddColumn("name").AddColumn("phone");
    queryBuilder.AddFrom("students");
    queryBuilder.AddWhere("id", "42").AddWhere("name", "John");
    assert(queryBuilder.BuildQuery() == "SELECT name, phone FROM students WHERE id=42 AND name=John;");
}

int main(int argc, char* argv[]){
    Test();
    return EXIT_SUCCESS;
}