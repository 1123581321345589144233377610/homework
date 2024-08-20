#include <iostream>
#include <clocale>

int main(){
	setlocale(LC_ALL, "rus");
	int arr[9] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int num{}, size{ 9 }, left{}, right{ size - 1 }, count{};
	std::cout << "Введите точку отсчёта: ";
	std::cin >> num;
	while (left < right) {
		int middle = (left + right) / 2;
		if (num < arr[middle]) {
			count += right - middle + 1;
			right = middle - 1;
		}
		else if (num >= arr[middle]) {
			left = middle + 1;
		}
	}
	if (arr[left] > num) count += 1;
	std::cout << "Количество элементов в массиве больших, чем " << num << ": " << count << std::endl;
	return EXIT_SUCCESS;//O(log(n)) and memory O(1)
}