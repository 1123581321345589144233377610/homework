#pragma once
#include <iostream>
#include <string>

class Tetragon {
protected:
	int a, b, c, d, A, B, C, D; std::string Type;
	Tetragon(int, int, int, int, int, int, int, int, std::string);
public:
	Tetragon();
	void print_info();
};