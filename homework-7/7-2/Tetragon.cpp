#include "Tetragon.h"

Tetragon::Tetragon(int a, int b, int c, int d, int A, int B, int C, int D, std::string Type, int sides) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
	this->Type = Type;
	this->sides = sides;
	if (sides != 4) throw(Exception("the number of sides is not equal to 4"));
	if (A + B + C + D != 360) throw(Exception("the sum of the angles is not equal to 360"));
}

Tetragon::Tetragon() : Tetragon(10, 20, 30, 40, 50, 60, 70, 180, "Tetragon", 4) {}

void Tetragon::print_info() {
	std::cout << Type << " (sides: " << a << ", " << b << ", " << c << ", " << d << "; corners: " << A << ", " << B << ", " << C << ", " << D << ")" << " generated" << std::endl;
}