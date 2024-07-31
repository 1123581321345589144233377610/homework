#include <iostream>
#include <string>
#include <windows.h>

int main() {
	SetConsoleCP(1251);
	std::string name{};
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Здравствуйте, " << name << "!" << std::endl;
	return EXIT_SUCCESS;
}