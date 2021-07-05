#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cmath>


class Converter {

public:
	class Impossible : public std::exception {
	public:
		const char *what() const throw();
	};

private:
	double value_;

public:
	explicit Converter(char *str);
	Converter(const Converter &other);
	Converter &operator=(const Converter &other);
	~Converter();

	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

private:
	Converter();

};


#endif
