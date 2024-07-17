#include "Triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string Type) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	this->Type = Type;
}

void Triangle::print_info() {
	std::cout << Type << ":" << std::endl;
	std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
	std::cout << "Corners: " << "A=" << A << " B=" << B << " C=" << C << std::endl << std::endl;
}

Triangle::Triangle() : Triangle(10, 20, 30, 50, 60, 70, "Triangle") {}