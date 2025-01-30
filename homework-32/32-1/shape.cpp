#include "shape.hpp"

Shape::Shape(int type, std::vector<Point> _points){
	switch (type){
	case Shapes::line:
		shape = new Line();
		break;
	case Shapes::square:
		shape = new Square();
		break;
	case Shapes::cube:
		shape = new Cube();
		break;
	default:
		break;
	}
}

Shape::Shape(int type, Point _point, double R, double H){
	switch (type){
	case Shapes::circle:
		shape = new Circle();
		break;
	case Shapes::cylinder:
		shape = new Cylinder();
		break;
	default:
		break;
	}
}


void Shape::shift(int m, int n, int k) {
	shape->shift(m, n, k);
}

void Shape::scaleX(int a) {
	shape->scaleX(a);
}

void Shape::scaleY(int d) {
	shape->scaleY(d);
}

void Shape::scaleZ(int e) {
	shape->scaleZ(e);
}

void Shape::scale(int s) {
	shape->scale(s);
}