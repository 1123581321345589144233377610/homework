#include <iostream>
#include <string>
#include <fstream>

class Address {
private:
	std::string city;
	std::string street;
	int home_number;
	int flat_number;
public:
	Address(std::string city, std::string street, int home_number, int flat_number) : city{ city }, street{ street }, home_number{ home_number }, flat_number{ flat_number } {}
	Address() {}
	std::string get_output_address() {
		return city + ", " + street + ", " + std::to_string(home_number) + ", " + std::to_string(flat_number);
	}
	void set_city(std::string city){
		this->city = city;
	}
	void set_street(std::string street) {
		this->street = street;
	}
	void set_home_number(int home_number) {
		this->home_number = home_number;
	}
	void set_flat_number(int flat_number) {
		this->flat_number = flat_number;
	}
	std::string get_city() {
		return city;
	}
};

int main() {
	std::string city;
	std::string street;
	int home_number;
	int flat_number;
	std::string tmp;
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	size_t size = 0;
	fin >> size;
	fout << size << std::endl;
	Address* arr = new Address [size];
	for (size_t i = 0; i < size; ++i) {
		fin >> city; fin >> street; fin >> home_number; fin >> flat_number;
		arr[i].set_city(city);
		arr[i].set_street(street);
		arr[i].set_home_number(home_number);
		arr[i].set_flat_number(flat_number);
	}
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size - 1; ++j) {
			if (static_cast<int>((arr[j].get_city())[0]) > static_cast<int>((arr[j + 1].get_city())[0])) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}

	for (size_t i = 0; i < size; ++i) {
		tmp = arr[i].get_output_address();
		fout << tmp << std::endl;
	}
	return 0;
}