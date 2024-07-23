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
	bool operator==(Fraction& f) {
		return (numerator_ * f.denominator_ == denominator_ * f.numerator_);
	}
	bool operator!=(Fraction& f) {
		return !(*this == f);
	}
	bool operator<(Fraction& f) {
		return (numerator_ * f.denominator_ < denominator_ * f.numerator_);
	}
	bool operator>(Fraction& f) {
		return (f < *this);
	}
	bool operator<=(Fraction& f) {
		return !(*this > f);
	}
	bool operator>=(Fraction& f) {
		return !(*this < f);
	}
};

int main(){
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return EXIT_SUCCESS;
}