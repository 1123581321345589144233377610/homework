#pragma once
#include <cmath>
#include <vector>
#define M_PI (3.1415926535)

enum Shapes : short {
	line,
	square,
	cube,
	circle,
	cylinder
};

struct Point{
	int x{};
	int y{};
	int z{};
};

class Shape{
public:
	Shape() = default;
	Shape(int type, std::vector<Point> points);
	Shape(int type, Point point, double R, double H);
	std::vector<Point> points;
	double volume;
	double square;
	double height;
	double radius;
	virtual void shift(int m, int n, int k);
	virtual void scaleX(int a);
	virtual void scaleY(int d);
	virtual void scaleZ(int e);
	virtual void scale(int s);
	Shape* shape;
};

class Line : public Shape {
public:
	Line() = default;
	Line(std::vector<Point> _points) {
		for (int index{}; index < 2; ++index) {
			points[index].x = _points[index].x;
			points[index].y = _points[index].y;
		}
		square = 0;
		volume = 0;
	}
	void shift(int m, int n, int k) override {
		for (int index{}; index < 2; ++index) {
			points[index].x += m;
			points[index].y += n;
		}
	}
	void scaleX(int a) override {
		for (int index{}; index < 2; ++index) {
			points[index].x *= a;
		}
	}
	void scaleY(int d) override {
		for (int index{}; index < 2; ++index) {
			points[index].y *= d;
		}
	}
	void scaleZ(int e) override {
		for (int index{}; index < 2; ++index) {
			points[index].z *= e;
		}
	}
	void scale(int s) override {
		for (int index{}; index < 2; ++index) {
			points[index].x /= s;
			points[index].y /= s;
		}
	}
};

class Square : public Shape {
public:
	Square() = default;
	Square(std::vector<Point> _points) {
		for (int index{}; index < 4; ++index) {
			points[index].x = _points[index].x;
			points[index].y = _points[index].y;
		}
		int a = abs(points[0].x - points[1].x);
		int b = abs(points[0].y - points[1].y);
		square = a * b;
		volume = 0;
	}
	void shift(int m, int n, int k) override {
		for (int index{}; index < 4; ++index) {
			points[index].x += m;
			points[index].y += n;
		}
	}
	void scaleX(int a) override{
		for (int index{}; index < 4; ++index) {
			points[index].x *= a;
		}
	}
	void scaleY(int d) override {
		for (int index{}; index < 4; ++index) {
			points[index].y *= d;
		}
	}
	void scaleZ(int e) override {
		for (int index{}; index < 4; ++index) {
			points[index].z *= e;
		}
	}
	void scale(int s) override {
		for (int index{}; index < 4; ++index) {
			points[index].x /= s;
			points[index].y /= s;
		}
	}
};

class Cube : public Shape {
public:
	Cube() = default;
	Cube(std::vector<Point> _points) {
		for (int index{}; index < 8; ++index) {
			points[index].x = _points[index].x;
			points[index].y = _points[index].y;
			points[index].z = _points[index].z;
		}
		int a = abs(points[0].x - points[1].x);
		int b = abs(points[0].y - points[1].y);
		int c = abs(points[0].z - points[1].z);
		square = 2 * a * b + 2 * a * c + 2 * b * c;
		volume = a * b * c;
	}
	void shift(int m, int n, int k) override {
		for (int index{}; index < 8; ++index) {
			points[index].x += m;
			points[index].y += n;
			points[index].z += k;
		}
	}
	void scaleX(int a) override {
		for (int index{}; index < 8; ++index) {
			points[index].x *= a;
		}
	}
	void scaleY(int d) override {
		for (int index{}; index < 8; ++index) {
			points[index].y *= d;
		}
	}
	void scaleZ(int e) override {
		for (int index{}; index < 8; ++index) {
			points[index].z *= e;
		}
	}
	void scale(int s) override {
		for (int index{}; index < 8; ++index) {
			points[index].x /= s;
			points[index].y /= s;
			points[index].z /= s;
		}
	}
};  

class Circle : public Shape{
public:
	Circle() = default;
	Circle(Point _point, double R, double H) {
		points[0].x = _point.x;
		points[0].y = _point.y;
		radius = R;
		square = M_PI * R * R;
		volume = 0;
	}
};

class Cylinder : public Shape {
public:
	Cylinder() = default;
	Cylinder(Point _point, double R, double H) {
		points[0].x = _point.x;
		points[0].y = _point.y;
		radius = R;
		height = H;
		square = M_PI * R * R + 2 * R * height;
		volume = M_PI * R * R * height;
	}
};
