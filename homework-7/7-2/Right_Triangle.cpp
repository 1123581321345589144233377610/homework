#include "Right_Triangle.h"

Right_Triangle::Right_Triangle() : Triangle(10, 20, 30, 50, 40, 90, "Right Triangle", 3) {
	if (C != 90) throw(Exception("the angle C is not equal to 90"));
}