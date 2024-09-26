#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>

void dfs(const std::vector<std::vector<int>> orgraph, int vertex, std::vector<int> &visited, std::vector<int> &order,const int vertices) {
	visited[vertex] = 1;
	size_t i{ static_cast<size_t>(vertex) };
	for (size_t j{}; j < vertices; ++j) {
		if (i == j) continue;
		if (orgraph[i][j] == 1 && visited[j] == 0) {
			dfs(orgraph, j, visited, order, vertices);
		}
	}
	std::vector<int> tmp(order.size() + 1, 0);
	tmp[0] = i + 1;
	for (size_t k{ 1 }; k < tmp.size(); ++k) {
		tmp[k] = order[k - 1];
	}
	order = tmp;
	tmp.clear();
}

std::vector<int> top_sort(const std::vector<std::vector<int>> orgraph,const int vertices) {
	std::vector<int> order{};
	std::vector<int> visited(vertices, 0);
	for (size_t i{}; i < vertices; ++i){
		for (size_t j{}; j < vertices; ++j) {
			if (visited[j] == 0 && orgraph[i][j] == 1) {
				dfs(orgraph, j, visited, order, vertices);
			}
		}
	}
	visited.clear();
	return order;
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
	std::vector<int> order{ top_sort(orgraph, vertices) };
	std::cout << "Топологический порядок вершин: ";
	for (size_t j{static_cast<size_t>(vertices - 1)}; j > 0; --j) {
		int count{};
		for (size_t i{}; i < vertices; ++i) {
			++count;
			if (orgraph[i][j] == 1) {
				count = 0;
				break;
			}
		}
		if (count == vertices) std::cout << j + 1 << " ";
	}
	for (size_t i{}; i < order.size(); ++i) {
		std::cout << order[i] << " ";
	}
	for (size_t i{}; i < vertices; ++i) {
			orgraph[i].clear();
	}
	orgraph.clear();
	order.clear();
	in.close();
	return EXIT_SUCCESS;
}