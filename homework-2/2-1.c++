#include <iostream>

class Calculator {
public:
	double num1, num2;
	double add() {
		return num1 + num2;
	}
	double multiply() {
		return num1 * num2;
	}
	double subtract_1_2() {
		return num1 - num2;
	}
	double subtract_2_1() {
		return num2 - num1;
	}
	double divide_1_2() {
		return num1 / num2;
	}
	double divide_2_1() {
		return num2 / num1;
	}
	bool set_num1(double num1) {
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}
		return false;
	}
	bool set_num2(double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}
		return false;
	}
};

int main() {
	Calculator my_operations;
	while (true) {
		std::cout << "Enter num1: ";
		std::cin >> my_operations.num1;
		std::cout << "Enter num2: ";
		std::cin >> my_operations.num2;
		if (my_operations.set_num1(my_operations.num1) == true && my_operations.set_num2(my_operations.num2) == true) {
			std::cout << "num1 + num2 = " << my_operations.add() << std::endl;
			std::cout << "num1 * num2 = " << my_operations.multiply() << std::endl;
			std::cout << "num1 - num2 = " << my_operations.subtract_1_2() << std::endl;
			std::cout << "num2 - num1 = " << my_operations.subtract_2_1() << std::endl;
			std::cout << "num1 / num2 = " << my_operations.divide_1_2() << std::endl;
			std::cout << "num2 / num1 = " << my_operations.divide_2_1() << std::endl;
		}
		else {
			std::cout << "Incorrect input!" << std::endl;
			if (my_operations.set_num1(my_operations.num1) == false && my_operations.set_num2(my_operations.num2) == false) {
				continue;
			}
			while (!my_operations.set_num1(my_operations.num1)) {				
				std::cout << "Enter num1: ";
				std::cin >> my_operations.num1;
				if (my_operations.set_num1(my_operations.num1) == false) {
					std::cout << "Incorrect input!" << std::endl;
					continue;
				}
				std::cout << "num1 + num2 = " << my_operations.add() << std::endl;
				std::cout << "num1 * num2 = " << my_operations.multiply() << std::endl;
				std::cout << "num1 - num2 = " << my_operations.subtract_1_2() << std::endl;
				std::cout << "num2 - num1 = " << my_operations.subtract_2_1() << std::endl;
				std::cout << "num1 / num2 = " << my_operations.divide_1_2() << std::endl;
				std::cout << "num2 / num1 = " << my_operations.divide_2_1() << std::endl;
			}
			while (!my_operations.set_num2(my_operations.num2)) {
				std::cout << "Enter num2: ";
				std::cin >> my_operations.num2;
				if (my_operations.set_num2(my_operations.num2) == false) {
					std::cout << "Incorrect input!" << std::endl;
					continue;
				}
				std::cout << "num1 + num2 = " << my_operations.add() << std::endl;
				std::cout << "num1 * num2 = " << my_operations.multiply() << std::endl;
				std::cout << "num1 - num2 = " << my_operations.subtract_1_2() << std::endl;
				std::cout << "num2 - num1 = " << my_operations.subtract_2_1() << std::endl;
				std::cout << "num1 / num2 = " << my_operations.divide_1_2() << std::endl;
				std::cout << "num2 / num1 = " << my_operations.divide_2_1() << std::endl;
			}
		}
	}
	return 0;
}
