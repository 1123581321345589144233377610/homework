#include "greet_lib.h"

void Greeter::greet() {
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Здравствуйте, " << name << "!" << std::endl;
}