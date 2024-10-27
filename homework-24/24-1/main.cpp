#include <algorithm>
#include <iostream>
#include <vector>

template <class Type>
Type delete_duplicates(Type &container) {
	std::sort(container.begin(), container.end());
	auto it = std::unique(container.begin(), container.end());
	container.erase(it, container.end());
	return container;
}

int main(int argc, char* argv[]) {
	std::vector<int> vec{1, 1, 2, 5, 6, 1, 2, 4};
	auto unique_vec{ delete_duplicates(vec) };
	std::for_each(unique_vec.cbegin(), unique_vec.cend(), [](const int& value) { std::cout << value << " "; });
	return EXIT_SUCCESS;
}