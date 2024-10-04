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
		if (index >= last_index) {
			throw(std::exception("Out of range!"));
		}
		else {
			return arr[index];
		}
	}
	~smart_array() {
		delete[] arr;
	}
	void operator=(smart_array &other) {
		int* copy = new int[other.size] {};
		delete[] arr;
		for (size_t i{}; i < other.size; ++i) {
			copy[i] = other.arr[i];
		}
		this->arr = copy;
		this->last_index = other.last_index;
		this->size = other.size;
	}
};

int main() {
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	arr = new_array;
	return EXIT_SUCCESS;
}