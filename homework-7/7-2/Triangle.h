#pragma once
#include "Exception.h"

class Triangle {
protected:
	int a, b, c, A, B, C, sides; std::string Type;
	Triangle(int, int, int, int, int, int, std::string, int);
public:
	Triangle();
	void print_info();
};
