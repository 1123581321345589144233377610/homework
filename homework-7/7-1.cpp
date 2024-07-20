#include <iostream>
#include <string>

class bad_length {
public:
	void print_error() {
		std::cerr << "You have entered a word of forbidden length! Goodbye";
	}
};

int function(std::string str, int forbidden_length) {
	if (str.size() != forbidden_length) {
		return static_cast<int> (str.size());
	}
	else {
		throw(bad_length());
	}
}

int main() {
	int len; std::string word;
	std::cout << "Enter the forbidden length: ";
	std::cin >> len;
	try {
		while (true) {
			std::cout << "Enter the word: ";
			std::cin >> word;
			int wlen = function(word, len);
			std::cout << "The length of the word " + word + " is equal to " << wlen <<  std::endl;
		}
	}
	catch(bad_length &exception) {
		exception.print_error();
		return 0;
	}
	catch (...) {
		std::cerr << "Unknown error!" << std::endl;
		return 0;
	}
	return 0;
}