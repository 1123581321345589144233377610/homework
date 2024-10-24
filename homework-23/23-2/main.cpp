#include <iostream>
#include <set>

void print_unique(unsigned int &amount) {
	std::set<int> set{};
	while (amount) {
		int tmp{};
		std::cin >> tmp;
		set.insert(tmp);
		--amount;
	}
	std::set<int>::reverse_iterator rit{};
	std::cout << std::endl;
	for (rit = set.rbegin(); rit != set.rend(); ++rit) {
		std::cout << *rit << std::endl;
	}
}

int main(int argc, char* argv[]) {
	unsigned int amount{};
	std::cout << "Enter amount of numbers: ";
	std::cin >> amount;
	print_unique(amount);
	return EXIT_SUCCESS;
}