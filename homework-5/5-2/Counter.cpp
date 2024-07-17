#include "Counter.h"

void Counter::setter_add() {
	this->count += 1;
}

void Counter::setter_sub(){
	this->count -= 1;
}

void Counter::getter() {
	std::cout << count << std::endl;
}

void Counter::setter(int count) {
	this->count = count;
}