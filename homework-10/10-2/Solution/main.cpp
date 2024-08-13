#include "leave_lib.h"
#include <cstdio>
#include <Windows.h>
#pragma execution_character_set( "utf-8" )

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Leaver L;
    L.leave();
    Sleep(1000);
    return EXIT_SUCCESS;
}