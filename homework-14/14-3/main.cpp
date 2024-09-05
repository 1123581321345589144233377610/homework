#include <iostream>
#include <clocale>
#include <string>
#include <Windows.h>

void remove_dynamic_array_head(int* &arr, int &logical_size, int &actual_size) {
	if (logical_size - 1 > (actual_size) / 3) {
		for (int i{}; i < logical_size - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		--logical_size;
	}
	else {
		int* new_arr = new int[actual_size / 3] {};
		for (int i{}; i < logical_size - 1; ++i) {
			new_arr[i] = arr[i + 1];
		}
		--logical_size;
		actual_size = actual_size / 3;
		delete[] arr;
		arr = new_arr;
	}
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	int i{};
	if (logical_size <= 0) std::cout << "_ ";
	while (i < logical_size) {
		std::cout << arr[i] << " ";
		++i;
	}
	while (i < actual_size) {
		std::cout << "_ ";
		++i;
	}
	std::cout << std::endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	std::string answer{};
	int actual_size{}, logical_size{}, new_element{};
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
		std::cout << "Динамический массив : ";
		print_dynamic_array(arr, logical_size, actual_size);
		while (true) {
			std::cout << "Удалить первый элемент? ";
			std::cin >> answer;
			if (logical_size <= 0) {
				std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
				std::cout << std::endl;
				std::cout << std::endl;
				break;
			}
			if (answer == "да") {
				remove_dynamic_array_head(arr, logical_size, actual_size);
				std::cout << "Динамический массив: ";
				print_dynamic_array(arr, logical_size, actual_size);
			}
			else if (answer == "нет") {
				std::cout << "Спасибо! Ваш динамический массив: ";
				print_dynamic_array(arr, logical_size, actual_size);
				std::cout << std::endl;
				break;
			}
		}
		delete[] arr;
	}
	return EXIT_SUCCESS;
}