#include <iostream>
#include <clocale>
int fib(int n) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	return fib(n - 1) + fib(n - 2);
}

int main() {
	int n;
	setlocale(LC_ALL, "rus");
	std::cout << "Введите номер чила Фибоначчи, которое хотите узнать: ";
	std::cin >> n;
	std::cout << n << "-ое число Фибоначчи: " << fib(n);
	return EXIT_SUCCESS;//Асимптотика по времени: O(2^n), а по памяти O(1)
}