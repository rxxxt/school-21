#include "Converter.hpp"

int main(int argc, char *argv[]) {
	if (argc == 2 && *argv[1]) {
		try {
			Converter converter(argv[1]);
			converter.printChar();
			converter.printInt();
			converter.printFloat();
			converter.printDouble();
		}
		catch (std::exception &ex) {
			std::cout << "char: " << ex.what() << std::endl;
			std::cout << "int: " << ex.what() << std::endl;
			std::cout << "float: " << ex.what() << std::endl;
			std::cout << "double: " << ex.what() << std::endl;
		}
	}
	return 0;
}
