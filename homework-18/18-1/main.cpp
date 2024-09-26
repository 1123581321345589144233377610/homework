#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>

void print_orgraph(std::vector<std::vector<int>> orgraph, int vertices) {
	std::cout << "Текстовый вид орграфа: " << std::endl;
	for (size_t i{}; i < vertices; ++i) {
		std::cout << i + 1 << ": ";
		int count{};
		for (size_t j{}; j < vertices; ++j) {
			if (orgraph[i][j] == 1) {
				std::cout << j + 1 << " ";
			}
			else ++count;
		}
		if (count == vertices) std::cout << "нет";
		std::cout << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	std::ifstream in("orgraph.txt");
	int vertices{};
	in >> vertices;
	std::vector<std::vector<int>> orgraph(vertices, std::vector<int>(vertices, 0));
	for (size_t i{}; i < vertices; ++i) {
		for (size_t j{}; j < vertices; ++j) {
			in >> orgraph[i][j];
		}
	}
	print_orgraph(orgraph, vertices);
	for (size_t i{}; i < vertices; ++i) {
			orgraph[i].clear();
	}
	orgraph.clear();
	in.close();
	return EXIT_SUCCESS;
}