#include <iostream>

template <class Type>
class unique_ptr {
private:
	Type* ptr;
public:
	unique_ptr() : ptr{nullptr} {}
	unique_ptr(Type* ptr_) : ptr{ptr_} {}
	unique_ptr(const unique_ptr<Type>& other) = delete;
	Type operator*() {
		return *ptr;
	}
	unique_ptr<Type>& operator=(const unique_ptr<Type>& other) = delete;
	Type* release() {
		Type* new_ptr = ptr;
		ptr = nullptr;
		return new_ptr;
	}
	~unique_ptr() {
		delete ptr;
	}
};

int main(int argc, char* argv[]) {
	unique_ptr<int> ptr(new int(10));
	std::cout << *(ptr) << std::endl;
	int* new_ptr = ptr.release();
	std::cout << *(new_ptr) << std::endl;
	delete new_ptr;
	return EXIT_SUCCESS;
}