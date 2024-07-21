#include "Parallelogram.h"

Parallelogram::Parallelogram() : Tetragon(20, 30, 20, 30, 90, 90, 90, 90, "Parallelogram", 4) {
	if (a != c || b != d) throw(Exception("some opposite sides are not equal"));
	if (A != C || B != D) throw(Exception("some opposite angles are not equal"));
}