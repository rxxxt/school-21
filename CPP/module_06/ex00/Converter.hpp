#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cmath>


class Impossible : public std::exception {

public:
	const char *what() const throw();

};


template <typename T>
void printType()
{
	if (typeid(T) == typeid(char))
		std::cout << "char" << std::endl;
	else if (typeid(T) == typeid(int))
		std::cout << "int" << std::endl;
	else if (typeid(T) == typeid(float))
		std::cout << "float" << std::endl;
	else if (typeid(T) == typeid(double))
		std::cout << "double" << std::endl;
}

template<typename T>
void displayConversion(T number) {
	//determining the type of a literal
	std::cout << "type of literal: ";
	printType<T>();

	//cast to char
	std::cout << "char: ";
	if ((number >= CHAR_MIN && number < ' ') || number == CHAR_MAX)
		std::cout << "Non displayable" << std::endl;
	else if (number >= ' ' && number < CHAR_MAX)
		std::cout << "'" << static_cast<char>(number) << "'" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	//cast to int
	std::cout << "int: ";
	if (number >= INT32_MIN && number <= INT32_MAX)
		std::cout << static_cast<int>(number) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	//precision addition condition
	T roundedNumber = floor(number);
	if (abs(number) - abs(roundedNumber) < 0.1)
		std::cout << std::fixed << std::setprecision(1);

	//cast to float
	std::cout << "float: ";
	std::cout << static_cast<float>(number);
	std::cout << "f" << std::endl;

	//cast to double
	std::cout << "double: ";
	std::cout << static_cast<double>(number);
	std::cout << std::endl;
}



void converter(char* str);

#endif
