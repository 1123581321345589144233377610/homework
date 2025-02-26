#include <iostream>
#include <map>
#include <string>
#define ERROR ("error")
#define NUMBER_OF_OUTPUTS (2)

class DataBase{
protected:
    std::map<std::string, std::string> data{};
public:
    DataBase() {}
    DataBase(std::map<std::string, std::string> _data){
        for(auto& element : _data){
            data[element.first] = element.second;
        }
    }
    std::string GetData(const std::string& key){
        return data[key];
    }
};

class ProxyDataBase : public DataBase{
protected:
    DataBase* originDataBase{};
    unsigned int numberOfOutputs{};
public:
    explicit ProxyDataBase(DataBase* _originDataBase, unsigned int _numberOfOutputs) : originDataBase(_originDataBase), numberOfOutputs(_numberOfOutputs) {}
    std::string GetData(const std::string& key){
        if(numberOfOutputs){
            --numberOfOutputs;
            return originDataBase->GetData(key);
        }else{
            return ERROR;
        }
    }
};

int main(int argc, char* argv[]){
    std::map<std::string, std::string> data{{"Jhon", "IP:1923"}, {"Nikita", "IP:1452"}, {"Dima", "IP:4032"}, {"Elon", "IP:0420"}, {"Jeff", "IP:1204"}};
    auto dataBase = new DataBase(data);
    auto proxyDataBase = new ProxyDataBase(dataBase, NUMBER_OF_OUTPUTS);
    std::cout << proxyDataBase->GetData("Elon") << std::endl;
    std::cout << proxyDataBase->GetData("Elon") << std::endl;
    std::cout << proxyDataBase->GetData("Elon") << std::endl;
    return EXIT_SUCCESS;
}