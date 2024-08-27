#include <iostream>
#include <clocale>
#define K (25)

void count_sort(int* &arr, int size) {
	int* counts = new int[K]{};
	for (int i{}; i < size; ++i) {
		counts[arr[i]] += 1;
	}
	int c{10};
	for (int i{}; i < size; ++i) {
		while (counts[c] == 0) c += 1;
		arr[i] = c;
		counts[c] -= 1;
	}
}

void print(int* arr, int size) {
	std::cout << "Исходный массив: ";
	for (int i{}; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Отсортированный массив: ";
	count_sort(arr, size);
	for (int i{}; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int* arr1 = new int[30]{ 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
	print(arr1, 30);
	int* arr2 = new int[40] {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16};
	print(arr2, 40);
	int* arr3 = new int[45] {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10};
	print(arr3, 45);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	return EXIT_SUCCESS;
}