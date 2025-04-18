#include <string>
#include "Counter.h"

int main() {
	std::string answer;
	Counter my_counter;
	std::cout << "Do you want to specify the initial value of the counter? Enter yes or no: ";
	std::cin >> answer;
	if (answer == "yes") {
		std::cout << "Enter the initial value of the counter: ";
		std::cin >> my_counter.n;
		my_counter.setter(my_counter.n);
	}
	while (true) {
		std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
		std::cin >> answer;
		if (answer == "+") {
			my_counter.setter_add();
			continue;
		}
		else if (answer == "-") {
			my_counter.setter_sub();
			continue;
		}
		else if (answer == "=") {
			my_counter.getter();
			continue;
		}
		else if (answer == "x") {
			std::cout << "Goodbye!";
			break;
		}
	}
	return 0;
}