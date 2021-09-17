#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called " << this << std::endl;

	return;
}

Fixed::Fixed(Fixed const & other) {
	std::cout << "Copy constructor called " << this << std::endl;
	*this = other;

	return;
}

Fixed::~Fixed() {
	std::cout << "Destructor called " << this << std::endl;

	return;
}

Fixed &	Fixed::operator=(Fixed const & other) {
	std::cout << "Assignation operator called " << this << std::endl;

	if (this != &other)
		this->_value = other.getRawBits();

	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called " << this << std::endl;

	return _value;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called " << this << std::endl;
	_value = raw;

	return;
}
