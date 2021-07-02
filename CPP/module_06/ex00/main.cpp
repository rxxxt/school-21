#include <iostream>
//#include "Converter.hpp"

int main(int argc, char *argv[]) {
	if (argc == 2 && *argv[1]) {
		if (std::strlen(argv[1]) == 1) {
			char c = *argv[1];

		}
		char* endPtr;
		long int i = std::strtol(argv[1], &endPtr, 10);
		if (!*endPtr) {

		}
		else {
			double d = std::strtod(argv[1], &endPtr);
			std::cout << endPtr
				<< std::endl;
		}


//		Converter literal(argv[1]);
//		char c = literal;
//		std::cout << "char: " << c << std::endl;
//
//		int i = literal;
//		std::cout << "int: " << i << std::endl;
//
//		float f = literal;
//		std::cout << "float: " << f << std::endl;

//		double d = literal;
//		std::cout << "double: " << d << std::endl;
	}
	return 0;
}
