#include "Exception.h"
#include "Triangle.h"
#include "Right_Triangle.h"
#include "Isosceles_Triangle.h"
#include "Equilateral_Triangle.h"
#include "Tetragon.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"

int main() {
	try {
		Triangle t;
		t.print_info();
		Right_Triangle r;
		r.print_info();
		Isosceles_Triangle i;
		i.print_info();
		Equilateral_Triangle e;
		e.print_info();
		Tetragon te;
		te.print_info();
		Rectangle re;
		re.print_info();
		Square s;
		s.print_info();
		Parallelogram p;
		p.print_info();
		Rhomb rh;
		rh.print_info();
	}
	catch (Exception& exception) {
		std::cerr << exception.print_error() << exception.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown exception" << std::endl;
	}
	return 0;
}