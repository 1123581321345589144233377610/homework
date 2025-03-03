#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Observer{
public:
    virtual void OnWarning(const std::string& message) {}
    virtual void OnError(const std::string& message) {}
    virtual void OnFatalError(const std::string& message) {}
};

class Notification{
private:
    std::vector<Observer*> followers;
public:
    void AddObserver(Observer* follower){
        followers.push_back(follower);
    }
    void RemoveObserver(Observer* follower){
        auto iterator{std::remove(followers.begin(), followers.end(), follower)};
        followers.erase(iterator, followers.end());
    }
    void Warning(const std::string& message) const{
        for(Observer* follower : followers){
            follower->OnWarning(message);
        }
    }
    void Error(const std::string& message) const{
        for(Observer* follower : followers){
            follower->OnError(message);
        }
    }
    void FatalError(const std::string& message) const{
        for(Observer* follower : followers){
            follower->OnFatalError(message);
        }
    }
};

class WarningObserver : public Observer{
public:
    void OnWarning(const std::string& message) override{
        std::cout << message << std::endl;
    }
};

class ErrorObserver : public Observer{
private:
    std::ofstream output{};
public:
    ErrorObserver(const std::string& fileName){
        output = std::ofstream(fileName);
    }
    void OnError(const std::string& message) override{
        if(output.is_open()){
            output << message << std::endl;
        }else{
            throw "Error: File not found!";
        }
    }
};

class FatalErrorObserver : public Observer{
private:
    std::ofstream output{};
public:
    FatalErrorObserver(const std::string& fileName){
        output = std::ofstream(fileName);
    }
    void OnFatalError(const std::string& message) override{
        std::cout << message << std::endl;
        if(output.is_open()){
            output << message << std::endl;
        }else{
            throw "Error: File not found!";
        }
    }
};

int main(int argc, char* argv[]){
    Notification notification;
    Observer* warningObserver{new WarningObserver()};
    Observer* errorObserver{new ErrorObserver("output.txt")};
    Observer* fatalErrorObserver{new FatalErrorObserver("output.txt")};
    notification.AddObserver(warningObserver);
    notification.AddObserver(errorObserver);
    notification.AddObserver(fatalErrorObserver);
    try{
        notification.Warning("Warning!");
        notification.Error("Error!");
        notification.FatalError("Fatal Error!");
        notification.RemoveObserver(fatalErrorObserver);
        notification.RemoveObserver(errorObserver);
        notification.Warning("Warning!");
        notification.Error("Error!");
        notification.FatalError("Fatal Error!");
    }catch(const std::exception& exception){
        std::cerr << exception.what() << std::endl;
    }catch(...){
        std::cerr << "Unknown Error!" << std::endl;
    }
    delete warningObserver;
    delete errorObserver;
    delete fatalErrorObserver;
    return EXIT_SUCCESS;
}