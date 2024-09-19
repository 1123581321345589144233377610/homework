#include <iostream>
#include <numeric>
#include <clocale>

unsigned int simple_string_hash(const std::string &str) {
	return std::accumulate(str.begin(), str.end(), 0);
}

int main() {
	setlocale(LC_ALL, "rus");
	std::string str{};
	while (true) {
		std::cout << "Введите строку: ";
		std::cin >> str;
		std::cout << "Наивный хэш строки " << str << " = " << simple_string_hash(str) << std::endl;
		if (str == "exit") break;
	}
	return EXIT_SUCCESS;
}