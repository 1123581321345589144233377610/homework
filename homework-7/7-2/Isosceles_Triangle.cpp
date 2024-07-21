#include "Isosceles_Triangle.h"

Isosceles_Triangle::Isosceles_Triangle() : Triangle(10, 20, 10, 50, 80, 50, "Isosceles Triangle", 3) {
	if (a != c) throw(Exception("sides a and c are not equal"));
	if (A != C) throw(Exception("the angles A and C are not equal"));
}