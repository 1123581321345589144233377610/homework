#include <iostream>
#include <clocale>

int pivoting(int* arr, int size) {
	int left{}, right{ size - 1 }, pivot{ arr[right] };
	while (true) {
		while (arr[left] < pivot) {
			++left;
		}
		while (arr[right] > pivot) {
			--right;
		}
		if (left >= right) return left;
		std::swap(arr[left], arr[right]);
		++left;
		--right;
	}
}

int* quick_sort(int* arr, const int size) {
	if (size == 1) return arr;
    int border{ pivoting(arr, size) };
    int* left = new int[border] {};
    int* right = new int[size - border] {};
    for (int i{}; i < border; ++i) {
    	left[i] = arr[i];
    }
    for (int j{}; j < size - border; ++j) {
    	right[j] = arr[j + border];
    }
    quick_sort(left, border);
    quick_sort(right, size - border);
    for (int i{}; i < size; ++i) {
    	if (i < border) arr[i] = left[i];
    	else arr[i] = right[i - border];
    }
	delete[] left;
	delete[] right;
    return arr;
}

void print(int* arr, int size) {
	std::cout << "Исходный массив: ";
	for (int i{}; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	int* arr_sorted = quick_sort(arr, size);
	std::cout << "Отсортированный массив: ";
	for (int i{}; i < size; ++i) {
		std::cout << arr_sorted[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
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
	return EXIT_SUCCESS;//O(nlogn) and O(1)
}