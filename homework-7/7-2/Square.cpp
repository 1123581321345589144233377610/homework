#include "Square.h"

Square::Square() : Tetragon(20, 20, 20, 20, 90, 90, 90, 90, "Square", 4) {
	if (a != b || a != c || a != d || b != c || b != d || c != d) throw(Exception("some sides are not equal"));
	if (A != 90 || B != 90 || C != 90 || D != 90) throw(Exception("some angle is not equal to 90"));
}