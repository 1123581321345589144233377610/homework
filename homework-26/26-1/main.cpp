#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template<class Type>
void move_vectors(std::vector<Type> &first, std::vector<Type> &second) {
	second = std::move(first);
}

int main(int argc, char* argv[]) {
	std::vector<std::string> one = { "test_string1", "test_string2" };
	std::vector<std::string> two;
	move_vectors(one, two);
	std::for_each(two.cbegin(), two.cend(), [](const std::string &str) {std::cout << str << " "; });
	return EXIT_SUCCESS;
}