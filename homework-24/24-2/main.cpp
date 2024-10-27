#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>

template <class Type>
void print_container(const Type& container) {
	typedef decltype(*(container.begin())) value_type;
	std::for_each(container.cbegin(), container.cend(), [](const  value_type &value) { std::cout << value << " "; });
	std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set);
	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list);
	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector);
	return EXIT_SUCCESS;
}