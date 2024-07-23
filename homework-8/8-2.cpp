#include <iostream>

class Fraction{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator){
		numerator_ = numerator;
		denominator_ = denominator;
	}
	Fraction operator+(Fraction& f) {
		return Fraction{ numerator_ * f.denominator_ + denominator_ * f.numerator_, denominator_ * f.denominator_ };
	}
	Fraction operator-(Fraction& f) {
		return Fraction{ numerator_ * f.denominator_ - denominator_ * f.numerator_, denominator_ * f.denominator_ };
	}
	Fraction operator*(Fraction& f) {
		return Fraction{ numerator_ * f.numerator_, denominator_ * f.denominator_ };
	}
	Fraction operator/(Fraction& f) {
		return Fraction{ numerator_ * f.denominator_, denominator_ * f.numerator_ };
	}
	Fraction operator-() {
		this->numerator_ = -numerator_;
		return *this;
	}
	Fraction operator++() {
		this->numerator_ = numerator_ + denominator_;
		return *this;
	}
	Fraction operator++(int) {
		Fraction tmp{ *this };
		++(*this);
		return tmp;
	}
	Fraction operator--() {
		this->numerator_ = numerator_ - denominator_;
		return *this;
	}
	Fraction operator--(int) {
		Fraction tmp{ *this };
		--(*this);
		return tmp;
	}
	friend std::ostream& operator<<(std::ostream& ostream, Fraction& f) {
		return (ostream << f.numerator_ << "/" << f.denominator_);
	}
};

int main(){
	int num1{}, num2{}, den1{}, den2{};
	std::cout << "Enter the numerator of the fraction 1: ";
	std::cin >> num1;
	std::cout << "Enter the denominator of the fraction 1: ";
	std::cin >> den1;
	std::cout << "Enter the numerator of the fraction 2: ";
	std::cin >> num2;
	std::cout << "Enter the denominator of the fraction 2: ";
	std::cin >> den2;
	Fraction f1{ num1, den1 }, f2{ num2, den2 }, sum = f1 + f2, sub = f1 - f2, mult = f1 * f2, divi = f1 / f2;
	std::cout << f1 << (" + ") << f2 << (" = ") << sum << std::endl;
	std::cout << f1 << (" - ") << f2 << (" = ") << sub << std::endl;
	std::cout << f1 << (" * ") << f2 << (" = ") << mult << std::endl;
	std::cout << f1 << (" / ") << f2 << (" = ") << divi << std::endl;
	std::cout << ("++") << f1 << (" * ") << f2 << (" = ");
	Fraction princ = (++f1) * f2; 
	std::cout << princ << std::endl;
	std::cout << "The value of the fraction 1 = " << f1 << std::endl;
	std::cout << f1 << ("--") << (" * ") << f2 << (" = ");
	Fraction podec = (f1--) * f2; 
	std::cout << podec << std::endl;
	std::cout << "The value of the fraction 1 = " << f1 << std::endl;
	return EXIT_SUCCESS;
}