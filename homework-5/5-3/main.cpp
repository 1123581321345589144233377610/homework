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