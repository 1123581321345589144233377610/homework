#include <iostream>
#include <clocale>

void append_to_dynamic_array(int* &arr, int &logical_size, int &actual_size, int new_element){
	if (logical_size < actual_size) {
		arr[logical_size] = new_element;
		++logical_size;
	}
	else {
		int* new_arr = new int[2 * actual_size] {};
		for (int i{}; i < logical_size; ++i) new_arr[i] = arr[i];
		new_arr[logical_size] = new_element;
		++logical_size;
		actual_size *= 2;
		arr = new_arr;
	}
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	int i{};
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
	setlocale(LC_ALL, "rus");
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
			std::cout << "Введите элемент для добавления: ";
			std::cin >> new_element;
			if (new_element == 0) {
				std::cout << "Спасибо! Ваш массив: ";
				print_dynamic_array(arr, logical_size, actual_size);
				std::cout << std::endl;
				break;
			}
			append_to_dynamic_array(arr, logical_size, actual_size, new_element);
			std::cout << "Динамический массив : ";
			print_dynamic_array(arr, logical_size, actual_size);
		}
		delete[] arr;
	}
	return EXIT_SUCCESS;
}