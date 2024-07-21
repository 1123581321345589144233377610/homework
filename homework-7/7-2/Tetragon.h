#pragma once
#include "Exception.h"

class Tetragon {
protected:
	int a, b, c, d, A, B, C, D, sides; std::string Type;
	Tetragon(int, int, int, int, int, int, int, int, std::string, int);
public:
	Tetragon();
	void print_info();
};

