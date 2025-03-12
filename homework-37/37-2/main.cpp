#include <fstream>

class Printable{
public:
    virtual ~Printable() = default;
    virtual std::string Print(const std::string& data) = 0;
};

class PrintAsHTML : public Printable{
public:
    std::string Print(const std::string& data) override{
        return "<html>" + data + "<html/>";
    }
};

class PrintAsText : public Printable{
public:
    std::string Print(const std::string& data) override{
        return data;
    }
};

class PrintAsJSON : public Printable{
public:
    std::string Print(const std::string& data) override{
        return "{ \"data\": \"" + data + "\"}";
    }
};

void Save(std::ofstream& file, Printable* format, const std::string& data){
    file << format->Print(data);
}

int main(int argc, char* argv[]){
    std::ofstream output("output.txt");
    Printable* printAsHTML = new PrintAsHTML();
    Printable* printAsText = new PrintAsText();
    Printable* printAsJSON = new PrintAsJSON();
    Save(output, printAsHTML, "first");
    Save(output, printAsText, "second");
    Save(output, printAsJSON, "third");
    delete printAsHTML;
    delete printAsText;
    delete printAsJSON;
    return EXIT_SUCCESS;
}