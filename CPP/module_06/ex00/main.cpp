#include "Converter.hpp"

int main(int argc, char *argv[]) {
	if (argc == 2 && *argv[1]) {
		try {
			converter(argv[1]);
		}
		catch (std::exception &ex) {
			std::cout << "type of literal: not detected" << std::endl;
			std::cout << "char: " << ex.what() << std::endl;
			std::cout << "int: " << ex.what() << std::endl;
			std::cout << "float: " << ex.what() << std::endl;
			std::cout << "double: " << ex.what() << std::endl;
		}
	}
	return 0;
}
