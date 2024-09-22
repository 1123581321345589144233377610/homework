#include <iostream>
#include <fstream>
#include <vector>

int main() {
	std::ifstream in("graph.txt");
	int vertices{};
	in >> vertices;
	std::vector<std::vector<int>> graph(vertices, std::vector<int>(vertices, 0));
	for (size_t i{}; i < vertices; ++i) {
		for (size_t j{}; j < vertices; ++j) {
			in >> graph[i][j];
		}
	}
	std::vector<int> visited(vertices, 0);
	std::cout << "Порядок обхода вершин: " << 1 << " ";
	visited[0] = 1;
	for (size_t i{}; i < vertices; ++i) {
		for (size_t j{1}; j < vertices; ++j) {
			if (graph[i][j] == 1 && visited[j] == 0) {
				visited[j] = 1;
				std::cout << j + 1 << " ";
				i = j - 1;
			    break;
			}
		}
	}
	for (size_t i{}; i < graph.size(); ++i) {
		graph[i].clear();
	}
	graph.clear();
	visited.clear();
	return EXIT_SUCCESS;
}