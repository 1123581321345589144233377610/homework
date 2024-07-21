#include "Equilateral_Triangle.h"

Equilateral_Triangle::Equilateral_Triangle() : Triangle(30, 30, 30, 60, 60, 60, "Equilateral Triangle", 3) {
	if (a != b || b != c || a != c) throw(Exception("not all sides are equal"));
	if (A != 60 || B != 60 || C != 60) throw(Exception("some angle is not equal to 60"));
}