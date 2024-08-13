#pragma once

#ifndef LEAVE_LIBRARY
#define LEAVE_LIB_API __declspec(dllexport)
#else
#define LEAVE_LIB_API __declspec(dllimport)
#endif

#include <string>
#include <iostream>

class Leaver{
private:
    std::string name;
public:
    LEAVE_LIB_API void leave();
};