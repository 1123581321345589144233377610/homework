#include "Triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string Type, int sides) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	this->Type = Type;
	this->sides = sides;
	if (sides != 3) throw(Exception("the number of sides is not equal to 3"));
	if (A + B + C != 180) throw(Exception("the sum of the angles is not equal to 180"));
}

Triangle::Triangle() : Triangle(10, 20, 30, 50, 60, 70, "Triangle", 3) {}

void Triangle::print_info() {
	std::cout << Type << " (sides: " << a << ", " << b << ", " << c << "; corners: " << A << ", " << B << ", " << C << ")" << " generated" << std::endl;
}