#pragma once
#include <iostream>
#include <string>

class Triangle {
protected:
	int a, b, c, A, B, C; std::string Type;
	Triangle(int, int, int, int, int, int, std::string);
public:
	Triangle();
	void print_info();
};