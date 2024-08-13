#include "greet_lib.h"
#include <clocale>
#include <windows.h>

int main() {
	setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	Greeter G;
	G.greet();
	Sleep(1000);
	return EXIT_SUCCESS;
}