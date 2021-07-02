#include "Converter.hpp"

const char *Converter::Impossible::what( ) const throw() {
	return ("impossible");
}

Converter::Converter() {}

Converter::Converter(char* str) {
	char* endPtr;

	if (std::strlen(str) == 1) {
		value_ = (void *)&*str;
		return;
	}
	long l = std::strtol(str, &endPtr, 10);
	if (!*endPtr) {

	}
	else {
		double d = std::strtod(argv[1], &endPtr);
		std::cout << endPtr
				  << std::endl;
	}
}

Converter::Converter(const Converter &other) {}

Converter& Converter::operator=(const Converter& other) {
	if (this != &other)
	return *this;
}

Converter::~Converter() {}

//void Converter::convertToOtherTypes(char c) {
//	std::cout << "char: ";
//	if (c < ' ' || c > '~')
//		std::cout << "Non displayable"
//			<< std::endl;
//	else
//		std::cout << c
//			<< std::endl;
//	std::cout << "int: "
//		<< std::endl;
//}
