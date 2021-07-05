#include "Converter.hpp"

const char* Converter::Impossible::what() const throw() {
	return ("impossible");
}

Converter::Converter() {}

Converter::Converter(char *str) {
	char *endPtr;

	if (std::strlen(str) == 1 && !isdigit(*str)) {
		value_ = static_cast<double>(*str);
		return;
	}
	value_ = std::strtod(str, &endPtr);
	if (!*endPtr || std::string(endPtr) == "f")
		return;
	throw Impossible();
}

Converter::Converter(const Converter &other) : value_(other.value_) {}

Converter &Converter::operator=(const Converter &other) {
	if (this != &other)
		value_ = other.value_;
	return *this;
}

Converter::~Converter() {}

void Converter::printChar() {
	std::cout << "char: ";
	if ((value_ >= CHAR_MIN && value_ < ' ') || value_ == CHAR_MAX)
		std::cout << "Non displayable" << std::endl;
	else if (value_ >= ' ' && value_ < CHAR_MAX)
		std::cout << "'" << static_cast<char>(value_) << "'" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void Converter::printInt() {
	std::cout << "int: ";
	if (value_ >= INT32_MIN && value_ <= INT32_MAX)
		std::cout << static_cast<int>(value_) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void Converter::printFloat() {
	std::cout << "float: ";
	if (value_ == floor(value_))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << static_cast<float>(value_);
	std::cout << "f" << std::endl;
}

void Converter::printDouble() {
	std::cout << "double: ";
	if (value_ == floor(value_))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << value_;
	std::cout << std::endl;
}
