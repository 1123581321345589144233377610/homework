#include <algorithm>
#include <iostream>
#include <string>

class HTMLText{
protected:
    std::string text{};
public:
    virtual void Render(const std::string& text) const{
        std::cout << text;
    }
};

class Decorator : public HTMLText{
protected:
    HTMLText* text{};
public:
    Decorator(HTMLText* _text) : text(_text) {}
};

class Paragraph : public Decorator{
public:
    Paragraph(HTMLText* _text) : Decorator(_text) {}
    void Render(const std::string& data){
        std::cout << "<p>";
        text->Render(data);
        std::cout << "</p>" << std::endl;
    }
};

class Reversed : public Decorator{
public:
    Reversed(HTMLText* _text) : Decorator(_text) {}
    void Render(std::string data){
        std::reverse(data.begin(), data.end());
        text->Render(data);
        std::cout << std::endl;
    }
};

class Link : public Decorator{
public:
    Link(HTMLText* _text) : Decorator(_text) {}
    void Render(const std::string& site, const std::string& data){
        std::cout << "<a href=";
        text->Render(site);
        std::cout << ">";
        text->Render(data);
        std::cout << "</a>" << std::endl;
    }
};

int main(int argc, char* argv[]){  
    auto textBlockParagraph = new Paragraph(new HTMLText());
    textBlockParagraph->Render("Hello world");
    auto textBlockReversed = new Reversed(new HTMLText());
    textBlockReversed->Render("Hello world");
    auto textBlockLink = new Link(new HTMLText());
    textBlockLink->Render("netology.ru", "Hello world");
    return EXIT_SUCCESS;
}