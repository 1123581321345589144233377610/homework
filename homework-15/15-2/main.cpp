#include <iostream>
#include <cmath>
#include <clocale>
#include <string>

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

void moving(int& index, const std::string direction, const int* arr, const int size) {
	if (direction == "up") {
		if ((double)(index - 1) / (double)2 >= 0) {
			std::cout << "Ок " << std::endl;
			index = (index - 1) / 2;
			std::cout << "Вы находитесь здесь: " << floor(std::log2(index + 1)) << ((index % 2 == 0) ? " right(" : " left(") << arr[(index - 1) / 2] << ") " << arr[index] << std::endl;
		}
		else {
			std::cout << "Ошибка! Отсутствует родитель " << std::endl;
			std::cout << "Вы находитесь здесь: " << "0 root " << arr[0] << std::endl;
		}
	}
	else if (direction == "right") {
		if (2 * index + 2 < size) {
			std::cout << "Ок " << std::endl;
			index = 2 * index + 2;
			std::cout << "Вы находитесь здесь: " << floor(std::log2(index)) << " right(" << arr[(index - 1) / 2] << ") " << arr[index] << std::endl;
		}
		else {
			std::cout << "Ошибка! Отсутствует правый потомок " << std::endl;
			std::cout << "Вы находитесь здесь: " << floor(std::log2(index)) << ((index % 2 == 0) ? " right(" : " left(") << arr[(index - 1) / 2] << ") " << arr[index] << std::endl;
		}
	}
	else if (direction == "left") {
		if (2 * index + 1 < size) {
			std::cout << "Ок " << std::endl;
			index = 2 * index + 1;
			std::cout << "Вы находитесь здесь: " << floor(std::log2(index)) << " left(" << arr[(index - 1) / 2] << ") " << arr[index] << std::endl;
		}
		else {
			std::cout << "Ошибка! Отсутствует левый потомок " << std::endl;
			std::cout << "Вы находитесь здесь: " << floor(std::log2(index)) << ((index % 2 == 0) ? " right(" : " left(") << arr[(index - 1) / 2] << ") " << arr[index] << std::endl;
		}
	}
	else if (direction == "") {}
	else {
		std::cout << "Ошибка! Отсутсвует такая команда " << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	std::string command{};
	int index{};
	int* arr = new int[6] {1, 3, 6, 5, 9, 8};
	print_pyramid(arr, 6);
	std::cout << "Вы находитесь здесь: 0 root " << arr[0] << std::endl;
	while (true) {
		moving(index, command, arr, 6);
		std::cout << "Введите команду: ";
		std::cin >> command;
		if (command == "exit") break;
	}
	delete[] arr;
	return EXIT_SUCCESS;
}
