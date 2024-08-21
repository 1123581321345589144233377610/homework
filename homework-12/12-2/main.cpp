#include <iostream>
#include <clocale>

int fib(int n, int* memory) {
	if (memory[n - 1] != 0) {
		return memory[n - 1];
	}
	if (n == 1) return 0;
	if (n == 2) return 1;
	memory[n - 1] = fib(n - 1, memory) + fib(n - 2, memory);
}

int main() {
	int n;
	setlocale(LC_ALL, "rus");
	std::cout << "Введите номер чила Фибоначчи, которое хотите узнать: ";
	std::cin >> n;
	static int* memory = new int[n] {};
	std::cout << n << "-ое число Фибоначчи: " << fib(n, memory);
	delete[] memory;
	return EXIT_SUCCESS;//Асимптотика по времени: O(n) и по памяти O(n)
}