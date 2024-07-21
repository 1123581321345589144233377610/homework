#include "Rectangle.h"

Rectangle::Rectangle() : Tetragon(11, 20, 10, 20, 90, 90, 90, 90, "Rectangle", 4) {
	if (a != c || b != d) throw(Exception("some opposite sides are not equal"));
	if (A != 90 || B != 90 || C != 90 || D != 90) throw(Exception("some angle is not equal to 90"));
}