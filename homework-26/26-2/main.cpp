#include <sstream>
#include <iostream>
#include <string>

class big_integer {
private:
	std::string number{};
public:
	big_integer() : number{"0"} {}
	big_integer(const std::string &number_) {
		number = number_;
	}
	big_integer(const big_integer& other) {
		number = other.number;
	}
	big_integer(big_integer&& other) noexcept{
		number = other.number;
	}
	big_integer& operator=(big_integer&& other) noexcept{
		number = std::move(other.number);
		return *this;
	}
	big_integer& operator=(big_integer& other) {
		number = other.number;
		return *this;
	}
	void appendZeros(std::string& number, int n) {
		while (n) {
			number = "0" + number;
			--n;
		}
	}
	big_integer& operator+(const big_integer& other) {
		std::string x{ number }, y{ other.number }, result{};
		if (x.length() > y.length()) {
			appendZeros(y, x.length() - y.length());
		}
		else if (x.length() < y.length()) {
			appendZeros(x, y.length() - x.length());
		}
		int sum{}, carry{};
		for (int i{ static_cast<int>(x.length() - 1)}; i >= 0; --i) {
			sum = x[i] - '0' + y[i] - '0' + carry;
			if (sum > 9) {
				result = std::to_string(sum % 10) + result;
				carry =  sum / 10;
			}else {
				result = std::to_string(sum) + result;
				carry = 0;
			}
		}
		if (carry != 0) {
			result = std::to_string(carry) + result;
		}
		number = result;
		return *this;
	}
	big_integer& operator*(int number){
		big_integer multiplication{ *this }, sum;
		int tmp{ std::abs(number) };
		while (tmp) {
			sum = sum + multiplication;
			--tmp;
		}
		if (number < 0) {
			sum.number = "-" + sum.number;
		}
		this->number = sum.number;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& stream, const big_integer &number) {
		for (size_t i{}; i < number.number.length(); ++i) {
			stream << number.number[i];
		}
		return stream;
	}
};

int main(int argc, char* argv[]) {
	std::cout << big_integer("114575") + big_integer("78524") << std::endl;
	std::cout << (big_integer("21")) * (4) << std::endl;
	std::cout << (big_integer("199")) * (-7) << std::endl;
	return EXIT_SUCCESS;
}