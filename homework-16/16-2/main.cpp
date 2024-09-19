#include <iostream>
#include <numeric>
#include <clocale>
#include <algorithm>

unsigned long long real_string_hash(const std::string& str, const unsigned long long &p, const unsigned long long &n) {
	unsigned long long mult{ 1 }, ans{};
	std::for_each(str.begin(), str.end(), [&mult, &ans, p, n](unsigned long long a) {
			ans += ((mult % n) * (a % n)) % n;
			mult = ((mult % n) * (p % n)) % n;
		});
	return ans % n;
}

int main() {
	setlocale(LC_ALL, "rus");
	std::string str{}; 
	unsigned long long p{}, n{};
	std::cout << "Введите p: ";
	std::cin >> p;
	std::cout << "Введите n: ";
	std::cin >> n;
	while (true) {
		std::cout << "Введите строку: ";
		std::cin >> str;
		std::cout << "Хэш строки " << str << " = " << real_string_hash(str, p, n) << std::endl;
		if (str == "exit") break;
	}
	return EXIT_SUCCESS;
}