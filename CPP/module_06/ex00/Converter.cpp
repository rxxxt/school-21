#include "Converter.hpp"

const char * Impossible::what() const throw() {
	return ("impossible");
}

void converter(char* str) {
	char *endPtr;

	if (std::strlen(str) == 1 && !isdigit(*str)) {
		displayConversion((char)*str);
		return;
	}
	long l = std::strtol(str, &endPtr, 10);
	if (!*endPtr && l >= INT32_MIN && l <= INT32_MAX) {
		displayConversion((int)l);
		return;
	}
	float f = std::strtof(str, &endPtr);
	if (std::string(endPtr) == "f") {
		displayConversion(f);
		return;
	}
	double d = std::strtod(str, &endPtr);
	if (!*endPtr) {
		displayConversion(d);
		return;
	}
	throw Impossible();
}
