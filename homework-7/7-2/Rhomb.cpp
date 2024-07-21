#include "Rhomb.h"

Rhomb::Rhomb() : Tetragon(30, 30, 30, 30, 60, 120, 60, 120, "Rhomb", 4) {
	if (a != b || a != c || a != d || b != c || b != d || c != d) throw(Exception("some sides are not equal"));
	if (A != C || B != D) throw(Exception("some opposite angles are not equal"));
}