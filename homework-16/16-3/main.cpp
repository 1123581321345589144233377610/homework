#include <iostream>
#include <numeric>
#include <clocale>

unsigned int simple_string_hash(const std::string& str) {
	return std::accumulate(str.begin(), str.end(), 0);
}

int find_substring_light_rabin_karp(const std::string& p, const std::string& str) {
	unsigned int p_hash = simple_string_hash(p), h{};
	for (size_t i{}; i <= str.size() - p.size() ; ++i) {
		if (i == 0) h = simple_string_hash(str.substr(0, p.size()));
		else {
			h -= str[i - 1];
			h += str[i + p.size() - 1];
		}
		if (h != p_hash) {
			continue;
		}
		else {
			for (size_t j{}; j < p.size(); ++j) {
				if (str[i + j] != p[j]) break;
			}
			return i;
		}
	}
	return -1;
}

int main() {
	setlocale(LC_ALL, "rus");
	std::string str{}, find{};
	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> str;
	while (true){
		std::cout << "Введите подстроку, которую нужно найти: ";
		std::cin >> find;
		int index{ find_substring_light_rabin_karp(find, str) };
		if (index != -1) {
			std::cout << "Подстрока " << find << " найдена по индексу " << index << std::endl;
		}
		else {
			std::cout << "Подстрока " << find << " не найдена" << std::endl;
		}
		if (find == "exit") break;
	}
	return EXIT_SUCCESS;
}