#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <exception>

class Exception : public std::exception {
private:
	std::string error;
public:
	Exception(std::string_view);
	std::string print_error();
	const char* what() const noexcept override {
		return error.c_str();
	}
};
