#include <exception>
#include <fstream>
#include <iostream>
#include <string>

class LogMessage {
public:
    virtual std::string Type() = 0;
    std::string message;
    virtual void GetMessage() = 0;
};

class Warning : public LogMessage{
public:
    Warning(const std::string& _message){
        message = _message;
    }
    std::string Type() override{
        return "Warning";
    }
    void GetMessage() override{
        std::cout << message << std::endl;
    }
};

class Error : public LogMessage{
private:
    std::ofstream output{};
public:
    Error(const std::string& _message, const std::string& fileName){
        message = _message;
        output = std::ofstream(fileName);
    }
    std::string Type() override{
        return "Error";
    }
    void GetMessage() override{
        if(output.is_open()){
            output << message << std::endl;
        }else{
            throw "File not found!";
        }
    }
};

class FatalError : public LogMessage{
public:
    FatalError(const std::string& _message){
        message = _message;
    }
    std::string Type() override{
        return "FatalError";
    }
    void GetMessage() override{
        throw std::runtime_error("Fatal Error: " + message + "!");
    }
};

class UnknownMessage : public LogMessage{
public:
    UnknownMessage(const std::string& _message){
        message = _message;
    }
    std::string Type() override{
        return "UnknownMessage";
    }
    void GetMessage() override{
        throw std::runtime_error("Unknown message: " + message + "!");
    }
};

class Handler{
public:
    virtual void ProcessMessage(LogMessage* logMessage) = 0;
    virtual void SetNextHandler(Handler* nextHandler) = 0;
};

class FatalErrorHandler : public Handler{
private:
    Handler* nextHandler{nullptr};
public:
    void ProcessMessage(LogMessage* logMessage) override{
        if(logMessage->Type() == "FatalError"){
            logMessage->GetMessage();
        }else if(nextHandler){
            nextHandler->ProcessMessage(logMessage);
        }else{
            throw "This message is unvalide!";
        }
    }
    void SetNextHandler(Handler* _nextHandler) override{
        nextHandler = _nextHandler;
    }
};

class ErrorHandler : public Handler{
private:
    Handler* nextHandler{nullptr};
public:
    void ProcessMessage(LogMessage* logMessage) override{
        if (logMessage->Type() == "Error"){
            logMessage->GetMessage();
        }else if(nextHandler){
            nextHandler->ProcessMessage(logMessage);
        }else{
            throw "This message is unvalide!";
        }
    }
    void SetNextHandler(Handler* _nextHandler) override{
        nextHandler = _nextHandler;
    }
};

class WarningHandler : public Handler{
private:
    Handler* nextHandler{nullptr};
public:
    void ProcessMessage(LogMessage* logMessage) override{
        if (logMessage->Type() == "Warning"){
            logMessage->GetMessage();
        }else if(nextHandler){
            nextHandler->ProcessMessage(logMessage);
        }else{
            throw "This message is unvalide!";
        }
    }
    void SetNextHandler(Handler* _nextHandler) override{
        nextHandler = _nextHandler;
    }
};

class UnknownMessageHandler : public Handler{
private:
    Handler* nextHandler{nullptr};
public:
    void ProcessMessage(LogMessage* logMessage) override{
        if (logMessage->Type() == "UnknownMessage"){
            logMessage->GetMessage();
        }else if(nextHandler){
            nextHandler->ProcessMessage(logMessage);
        }else{
            throw "This message is unvalide!";
        }
    }
    void SetNextHandler(Handler* _nextHandler) override{
        nextHandler = _nextHandler;
    }
};

int main(int argc, char* argv[]){
    LogMessage* warning{new Warning("Dont free data!")};
    LogMessage* error{new Error("You need to use ; ", "output.txt")};
    LogMessage* fatalError{new FatalError("Cant create object file")};
    LogMessage* unknownMessage{new UnknownMessage("C4129")};
    Handler* firstHandler{new FatalErrorHandler()};
    Handler* secondHandler{new ErrorHandler()};
    Handler* thirdHandler{new WarningHandler()};
    Handler* fourthHandler{new UnknownMessageHandler()};
    try{
        firstHandler->SetNextHandler(secondHandler);
        secondHandler->SetNextHandler(thirdHandler);
        thirdHandler->SetNextHandler(fourthHandler);
        firstHandler->ProcessMessage(warning);
        firstHandler->ProcessMessage(error);
        firstHandler->ProcessMessage(fatalError);
        firstHandler->ProcessMessage(unknownMessage);
        fourthHandler->ProcessMessage(warning);
    }catch(const std::exception& exception){
        std::cerr << exception.what() << std::endl;
    }catch(...){
        std::cerr << "Unknown problem!" << std::endl;
    }
    return EXIT_SUCCESS;
}