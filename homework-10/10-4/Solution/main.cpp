#include <cstdio>
#include <Windows.h>
#include "my_lib/my_lib.h"
#pragma execution_character_set( "utf-8" )

int main() {
    SetConsoleOutputCP(65001);
	my_lib::Triangle t;
	my_lib::Right_Triangle r;
	my_lib::Isosceles_Triangle i;
	my_lib::Equilateral_Triangle e;
	my_lib::Tetragon te;
	my_lib::Rectangle re;
	my_lib::Square s;
	my_lib::Parallelogram p;
	my_lib::Rhomb rh;
	t.print_info();
	r.print_info();
	i.print_info();
	e.print_info();
	te.print_info();
	re.print_info();
	s.print_info();
	p.print_info();
	rh.print_info();
	Sleep(5000);
	return 0;
}