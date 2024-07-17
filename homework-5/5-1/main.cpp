#include <iostream>
#include "func.h"

int main(){
	int a, b, n;
	std::cout << "Enter the first number: ";
	std::cin >> a;
	std::cout << "Enter the second number: ";
	std::cin >> b;
	std::cout << "Select an operation (1 - addition, 2 - subtraction, 3 - multiplication, 4 - division, 5 - exponentiation): ";
	std::cin >> n;
	switch (n) {
	case 1: std::cout << a << " plus " << b << " = " << add(a, b); break;
	case 2: std::cout << a << " minus " << b << " = " << sub(a, b); break;
	case 3: std::cout << a << " multiplied by " << b << " = " << mult(a, b); break;
	case 4: std::cout << a << " divided by " << b << " = " << division(a, b); break;
	case 5: std::cout << a << " to the extent of " << b << " = " << power(a, b); break;
	}
	return 0;
}