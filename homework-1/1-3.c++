#include <iostream>
#include <string>
struct address {
	std::string town;
	std::string street;
	unsigned int number_of_house;
	unsigned int number_of_flat;
	unsigned int index;
};

void print_struct(address &your_address) {
	std::cout << "Town: ";
	std::cin >> your_address.town;
	std::cout << "Street: ";
	std::cin >> your_address.street;
	std::cout << "House number: ";
	std::cin >> your_address.number_of_house;
	std::cout << "Apartment number: ";
	std::cin >> your_address.number_of_flat;
	std::cout << "Index: ";
	std::cin >> your_address.index;
}

int main() {
	address my_address;
	address friend_address;
	print_struct(my_address);
	std::cout << "\n";
	print_struct(friend_address);
	return 0;
}