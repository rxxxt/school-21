#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called " << this << std::endl;

	return;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called " << this << std::endl;

	_value = value << _fractionalBits;
	return;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called " << this << std::endl;

	_value = round(value * ( 1 << _fractionalBits));
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

float Fixed::toFloat() const {
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
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

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed) {
	o << fixed.toFloat();

	return o;
}
