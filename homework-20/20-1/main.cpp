#include <iostream>
#include <exception>

class smart_array {
private:
	int* arr{};
	int last_index{};
	size_t size{};
public:
	smart_array(size_t size_) : size{size_} {
		arr = new int[size] {};
	}
	void add_element(int a) {
		if (last_index + 1 < size) {
			arr[last_index] = a;
			++last_index;
		}else {
			int* copy{ arr };
			arr = new int[2 * size] {};
			for (size_t i{}; i < size; ++i) {
				arr[i] = copy[i];
			}
			size *= 2;
			arr[last_index] = a;
			++last_index;
			delete[] copy;
		}
	}
	int operator[](int index) {
		if (index >= last_index){
			throw(std::exception("Out of range!"));
		}else{
			return arr[index];
		}
	}
	~smart_array() {
		delete[] arr;
	}
};

int main() {
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr[2] << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return EXIT_SUCCESS;
}