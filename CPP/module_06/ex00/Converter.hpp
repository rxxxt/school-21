#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>


class Converter {

public:
	class Impossible : public std::exception {
	public:
		const char *what() const throw();
	};

private:
	void *value_;

public:
	Converter(char *str);
	Converter(const Converter& other);
	Converter& operator=(const Converter& other);
	~Converter();

//	void convertToOtherTypes(char c);
//	void convertToOtherTypes(double d);
//	void convertToOtherTypes(float f);
//	void convertToOtherTypes(int i);

private:
	Converter();

};


#endif
