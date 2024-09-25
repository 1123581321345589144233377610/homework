#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <clocale>

void bfs(std::vector<std::vector<int>> graph, int vertices, size_t start) {
	std::vector<int> visited(vertices, 0);
	std::queue<int> Q{};
	visited[start - 1] = 1;
	for (size_t i{ start - 1 }; i <= start - 1; ++i) {
		for (size_t j{}; j < vertices; ++j) {
			if (graph[i][j] == 1 && visited[j] == 0) {
				Q.push(j);
				visited[j] = 1;
				std::cout << j + 1 << " ";
			}
		}
	}
	while (!(Q.empty())) {
		int i{ Q.front() };
		Q.pop();
		for (int k{ i }; k <= i; ++k) {
			for (int j{}; j < vertices; ++j) {
				if (graph[k][j] == 1 && visited[j] == 0) {
					Q.push(j);
					visited[j] = 1;
					std::cout << j + 1 << " ";
				}
			}
		}
	}
	visited.clear();
}

int main() {
	setlocale(LC_ALL, "rus");
	std::ifstream in("graph.txt");
	int vertices{};
	size_t start{};
	in >> vertices;
	std::vector<std::vector<int>> graph(vertices, std::vector<int>(vertices, 0));
	for (size_t i{}; i < vertices; ++i) {
		for (size_t j{}; j < vertices; ++j) {
			in >> graph[i][j];
		}
	}
	std::cout << "В графе " << vertices << " вершин. Введите номер вершины, с которой начнётся обход : ";
	std::cin >> start;
	std::cout << "Порядок обхода вершин: " << start << " ";
	bfs(graph, vertices, start);
	for (size_t i{}; i < graph.size(); ++i) {
		graph[i].clear();
	}
	graph.clear();
	return EXIT_SUCCESS;
}