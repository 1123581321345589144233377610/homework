#include "Tetragon.h"

Tetragon::Tetragon(int a, int b, int c, int d, int A, int B, int C, int D, std::string Type) {
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

void Tetragon::print_info() {
	std::cout << Type << ":" << std::endl;
	std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
	std::cout << "Corners: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl << std::endl;
}

Tetragon::Tetragon() : Tetragon(10, 20, 30, 40, 50, 60, 70, 80, "Tetragon") {}