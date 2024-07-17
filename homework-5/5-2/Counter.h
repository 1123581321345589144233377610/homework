#pragma once
#include <iostream>
class Counter {
private:
	int count = 1;
public:
	int n;
	void setter_add();
	void setter_sub();
	void getter();
	void setter(int);
};