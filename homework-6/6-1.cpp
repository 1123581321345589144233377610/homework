#include <iostream>
#define MODE 1

int main() {
#ifdef MODE
#if MODE == 0 
	std::cout << "I work in training mode" << std::endl;
#elif MODE == 1 
#define add(a, b) a + b
	int a, b;
	std::cout << "I'm working in combat mode" << std::endl;
	std::cout << "Enter the number 1: ";
	std::cin >> a;
	std::cout << "Enter the number 2: ";
	std::cin >> b;
	std::cout << "The result of addition: " << add(a, b);
	return 0;
#else 
	std::cout << "Unknown mode. Completion of work" << std::endl;
	return 0;
#endif
#else 
	std::cout << "The need to define a MODE" << std::endl;
	return 0;
#endif
	return 0;
}