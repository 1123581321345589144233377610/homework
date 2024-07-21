#include "Exception.h"

Exception::Exception(std::string_view setError) : error{ setError } {}

std::string Exception::print_error() {
	return "Error creating the shape. Reason: ";
}