#include <fstream>
#include <iostream>
#include <string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void Print(const std::string& message) = 0;
};

class PrintMessageInConsole : public LogCommand{
public:
    void Print(const std::string& message) override{
        std::cout << message << std::endl;
    }
};

class PrintMessageInFile : public LogCommand{
private:
    std::ofstream output;
public:
    PrintMessageInFile(const std::string& fileName){
        output = std::ofstream(fileName);
    }
    void Print(const std::string& message) override{
        output << message << std::endl;
    }
};

void Print(LogCommand* command, const std::string& message){
    command->Print(message);
}

int main(int argc, char* argv[]){
    LogCommand* first = new PrintMessageInConsole();
    LogCommand* second = new PrintMessageInFile("output.txt");
    Print(first, "Hello world!");
    Print(second, "Hello world!");
    delete first;
    delete second;
    return EXIT_SUCCESS;
}