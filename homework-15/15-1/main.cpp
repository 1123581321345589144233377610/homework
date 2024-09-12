#include <iostream>
#include <cmath>
#include <clocale>

void print_pyramid(const int* arr, const int size){
	std::cout << "Исходный массив: ";
	for (int i{}; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Пирамида: " << std::endl;
	int i{};
	std::cout << "0 root " << arr[0] << std::endl;
	while (true) {
		if (2 * i + 1 < size) {
			std::cout << ceil(std::log2(i + 2)) << " left(" << arr[i] << ") " << arr[2 * i + 1] << std::endl;
			if (2 * i + 2 < size) {
				std::cout << ceil(std::log2(i + 2)) << " right(" << arr[i] << ") " << arr[2 * i + 2] << std::endl;
			}
			++i;
		}
		else break;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int* arr1 = new int[6] {1, 3, 6, 5, 9, 8};
	print_pyramid(arr1, 6);
	arr1 = new int[8] {94, 67, 18, 44, 55, 12, 6, 42};
	print_pyramid(arr1, 8);
	arr1 = new int[10] {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
	print_pyramid(arr1, 10);
	delete[] arr1;
	return EXIT_SUCCESS;
}
