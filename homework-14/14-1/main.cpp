#include <iostream>
#include <clocale>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	int i{};
	std::cout << "Динамический массив : ";
	while (i < logical_size) {
		std::cout << arr[i] << " ";
		++i;
	}
	while (i < actual_size) {
		std::cout << "_ ";
		++i;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int actual_size{}, logical_size{};
	while (true) {
		std::cout << "Введите фактичеcкий размер массива: ";
		std::cin >> actual_size;
		std::cout << "Введите логический размер массива: ";
		std::cin >> logical_size;
		if (logical_size > actual_size) {
			std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
			std::cout << std::endl;
			continue;
		}
		int* arr = new int[actual_size] {};
		for (int i{}; i < logical_size; ++i) {
			std::cout << "Введите arr[" << i << "]: ";
			std::cin >> arr[i];
		}
		print_dynamic_array(arr, logical_size, actual_size);
		delete[] arr;
	}
	return EXIT_SUCCESS;
}