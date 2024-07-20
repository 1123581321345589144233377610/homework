#include <iostream>
#include <string>
#include <string_view>
#include <exception>


class Exception : public std::exception{
private:
	std::string error;
public:
	Exception(std::string_view setError) : error{setError} {}
	void print_error() {
		std::cerr << "Error creating the shape. Reason: ";
	}
	const char* what() const noexcept override {
		return error.c_str();
	}
};

class Triangle {
protected:
	int a, b, c, A, B, C; std::string Type;
	Triangle(int a, int b, int c, int A, int B, int C, std::string Type) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->Type = Type;
	}
public:
	Triangle() : Triangle(10, 20, 30, 50, 60, 70, "Triangle") {}
	void print_info() {
		std::cout << Type << " (sides: " << a << ", " << b << ", " << c << "; corners: " << A << ", " << B << ", " << C << " generated" << std::endl;
	}
};

class Right_Triangle : public Triangle {
public:
	Right_Triangle() : Triangle(10, 20, 30, 50, 60, 90, "Right Triangle") {}
};

class Isosceles_Triangle : public Triangle {
public:
	Isosceles_Triangle() : Triangle(10, 20, 10, 50, 60, 50, "Isosceles Triangle") {}
};

class Equilateral_Triangle : public Triangle {
public:
	Equilateral_Triangle() : Triangle(30, 30, 30, 60, 60, 60, "Equilateral Triangle") {}
};

class Tetragon {
protected:
	int a, b, c, d, A, B, C, D; std::string Type;
	Tetragon(int a, int b, int c, int d, int A, int B, int C, int D, std::string Type) {
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
public:
	Tetragon() : Tetragon(10, 20, 30, 40, 50, 60, 70, 80, "Tetragon") {}
	void print_info() {
		std::cout << Type << " (sides: " << a << ", " << b << ", " << c << ", " << d << "; corners: " << A << ", " << B << ", " << C << ", " << D << " generated" << std::endl;
	}
};

class Rectangle : public Tetragon {
public:
	Rectangle() : Tetragon(10, 20, 10, 20, 90, 90, 90, 90, "Rectangle") {}
};

class Square : public Tetragon {
public:
	Square() : Tetragon(20, 20, 20, 20, 90, 90, 90, 90, "Square") {}
};

class Parallelogram : public Tetragon {
public:
	Parallelogram() : Tetragon(20, 30, 20, 30, 30, 40, 30, 40, "Parallelogram") {}
};

class Rhomb : public Tetragon {
public:
	Rhomb() : Tetragon(30, 30, 30, 30, 30, 40, 30, 40, "Rhomb") {}
};

int main() {
	Triangle t;
	Right_Triangle r;
	Isosceles_Triangle i;
	Equilateral_Triangle e;
	Tetragon te;
	Rectangle re;
	Square s;
	Parallelogram p;
	Rhomb rh;
	t.print_info();
	r.print_info();
	i.print_info();
	e.print_info();
	te.print_info();
	re.print_info();
	s.print_info();
	p.print_info();
	rh.print_info();
	return 0;
}