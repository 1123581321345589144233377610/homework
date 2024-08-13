#pragma once
#include <string>
#include <iostream>

#ifndef MY_LIBRARY
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

class my_lib{
public:
    class Triangle {
    protected:
	int a, b, c, A, B, C; std::string Type;
	MY_LIB_API Triangle(int, int, int, int, int, int, std::string);
    public:
	MY_LIB_API Triangle();
	MY_LIB_API void print_info();
    };
    
    class Isosceles_Triangle : public Triangle {
    public:
	    MY_LIB_API Isosceles_Triangle();
    };

    class Tetragon {
    protected:
	    int a, b, c, d, A, B, C, D; std::string Type;
	    MY_LIB_API Tetragon(int, int, int, int, int, int, int, int, std::string);
    public:
	    MY_LIB_API Tetragon();
	    MY_LIB_API void print_info();
    };

    class Parallelogram : public Tetragon {
    public:
	    MY_LIB_API Parallelogram();
    };

    class Rectangle : public Tetragon {
    public:
	    MY_LIB_API Rectangle();
    };

    class Rhomb : public Tetragon {
    public:
	    MY_LIB_API Rhomb();
    };

    class Right_Triangle : public Triangle {
    public:
	    MY_LIB_API Right_Triangle();
    };

    class Square : public Tetragon {
    public:
	    MY_LIB_API Square();
    };

    class Equilateral_Triangle : public Triangle {
    public:
	    MY_LIB_API Equilateral_Triangle();
    };
};
