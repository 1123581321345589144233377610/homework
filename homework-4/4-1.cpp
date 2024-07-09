#include <iostream>

class Figure {
protected:
	unsigned int number_of_sides = 0;
	Figure(unsigned int number_of_sides) {
		this->number_of_sides = number_of_sides;
	}	
public:
	Figure() : Figure(0) {}
	unsigned int get_sides() {
		return number_of_sides;
	}	
};

class Triangle : public Figure {
private:
	unsigned int number_of_sides = 3;
public:
	Triangle() : Figure(3) {}
};

class Tetragon : public Figure {
private:
	unsigned int number_of_sides = 4;
public:
	Tetragon() : Figure(4) {}
};

int main() {
	Figure f;
	Triangle t;
	Tetragon te;
	std::cout << "Number of sides: " << std::endl;
	std::cout << "Figure: " << f.get_sides() << std::endl;
	std::cout << "Triangle: " << t.get_sides() << std::endl;
	std::cout << "Tetragon: " << te.get_sides() << std::endl;
    return 0;
}