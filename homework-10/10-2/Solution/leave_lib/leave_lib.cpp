#include "leave_lib.h"
#include <Windows.h>

void Leaver::leave(){
        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cout << "Good bye, " << name << "!";
    }