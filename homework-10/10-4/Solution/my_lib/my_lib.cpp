#include "my_lib.h"
my_lib::Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string Type) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	this->Type = Type;
}

void my_lib::Triangle::print_info() {
	std::cout << Type << ":" << std::endl;
	std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
	std::cout << "Corners: " << "A=" << A << " B=" << B << " C=" << C << std::endl << std::endl;
}

my_lib::Triangle::Triangle() : Triangle(10, 20, 30, 50, 60, 70, "Triangle") {}

my_lib::Isosceles_Triangle::Isosceles_Triangle() : Triangle(10, 20, 10, 50, 60, 50, "Isosceles Triangle") {}

my_lib::Tetragon::Tetragon(int a, int b, int c, int d, int A, int B, int C, int D, std::string Type) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
	this->Type = Type;
}

void my_lib::Tetragon::print_info() {
	std::cout << Type << ":" << std::endl;
	std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
	std::cout << "Corners: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl << std::endl;
}

my_lib::Tetragon::Tetragon() : Tetragon(10, 20, 30, 40, 50, 60, 70, 80, "Tetragon") {}

my_lib::Parallelogram::Parallelogram() : Tetragon(20, 30, 20, 30, 30, 40, 30, 40, "Parallelogram") {}

my_lib::Rectangle::Rectangle() : Tetragon(10, 20, 10, 20, 90, 90, 90, 90, "Rectangle") {}

my_lib::Rhomb::Rhomb() : Tetragon(30, 30, 30, 30, 30, 40, 30, 40, "Rhomb") {}

my_lib::Right_Triangle::Right_Triangle() : Triangle(10, 20, 30, 50, 60, 90, "Right Triangle") {}

my_lib::Square::Square() : Tetragon(20, 20, 20, 20, 90, 90, 90, 90, "Square") {}

my_lib::Equilateral_Triangle::Equilateral_Triangle() : Triangle(30, 30, 30, 60, 60, 60, "Equilateral Triangle") {}