#include <iostream>
#include <clocale>

int* merge(int* arr1, int size1, int* arr2, int size2) {
	int* arr3 = new int[size1 + size2] {};
	int i1{}, i2{}, i3{};
	while (i1 < size1 || i2 < size2) {
		if (i1 == size1) {
			arr3[i3] = arr2[i2];
			++i2;
		}
		else if (i2 == size2) {
			arr3[i3] = arr1[i1];
			++i1;
		}
		else {
			if (arr1[i1] >= arr2[i2]) {
				arr3[i3] = arr2[i2];
				++i2;
			}
			else {
				arr3[i3] = arr1[i1];
				++i1;
			}
		}
		++i3;
	}
	return arr3;
}

int* merge_sort(int* arr, int size) {
	if (size == 1) return arr;
	int left{}, right{ size - 1 }, middle{ (left + right) / 2 };
	int* left_arr = new int[middle + 1] {};
	int* right_arr = new int[size - 1 - middle] {};
	for (int i{}; i <= middle; ++i) {
		left_arr[i] = arr[i];
	}
	for (int j{}; j <= size - 2 - middle; ++j) {
		right_arr[j] = arr[j + middle + 1];
	}
	int* left_sorted = merge_sort(left_arr, middle + 1);
	int* right_sorted = merge_sort(right_arr, size - 1 - middle);
	return merge(left_sorted, middle + 1, right_sorted, size - 1 - middle);
}

void print(int* arr, int size) {
	std::cout << "Исходный массив: ";
	for (int i{}; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	int* arr_sorted = merge_sort(arr, size);
	std::cout << "Отсортированный массив: ";
	for (int i{}; i < size; ++i) {
		std::cout << arr_sorted[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	delete[] arr_sorted;
}

int main() {
	setlocale(LC_ALL, "rus");
	int* arr1 = new int[10] {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
	print(arr1, 10);
	int* arr2 = new int[15] {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
	print(arr2, 15);
	int* arr3 = new int[18] {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
	print(arr3, 18);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	return EXIT_SUCCESS;//O(nlogn) and O(n)
}