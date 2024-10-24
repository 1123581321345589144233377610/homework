#include <iostream>
#include <exception>

template <class Type>
class vector {
private:
	Type* vec;
	size_t vsize;
	size_t vcapacity;
public:
	vector() : vsize{}, vcapacity{} {}
	vector(const Type &value) {
		for (size_t i{}; i < vsize; ++i) {
			vec[i] = value;
		}
	}
	Type operator[](const int &index) {
		return vec[index];
	}
	Type at(const int &index) {
		if (index >= 0 && index < vsize) {
			return vec[index];
		}
		else {
			throw std::exception("Exception: Out of range!");
		}
	}
	void push_back(const Type &value) {
		if (vsize == 0 && vcapacity == 0) {
			++vcapacity;
			Type* tmp = new Type[vcapacity];
			tmp[0] = value;
			delete[] vec;
			++vsize;
			vec = tmp;
		}
		else if(vsize < vcapacity){
			vec[vsize] = value;
			++vsize;
		}
		else if (vsize == vcapacity) {
			vcapacity *= 2;
			Type* tmp = new Type[vcapacity];
			for (size_t i{}; i < vsize; ++i) {
				tmp[i] = vec[i];
			}
			delete[] vec;
			tmp[vsize] = value;
			++vsize;
			vec = tmp;
		}
	}
	size_t size() {
		return vsize;
	}
	size_t capacity() {
		return vcapacity;
	}
};

int main() {
	try {
		vector<int> vec{};
		vec.push_back(1);
		vec.push_back(3);
		vec.push_back(4);
		std::cout << "Size: " << vec.size() << " Capacity: " << vec.capacity() << std::endl;
		std::cout << vec.at(4);
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
	catch (...) {
		std::cout << "Exception: Unknown exception!";
	}
	return EXIT_SUCCESS;
}