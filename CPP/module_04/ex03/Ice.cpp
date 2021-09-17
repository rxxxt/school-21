#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other) {}

Ice &Ice::operator=(Ice const &other) {
	if (this != &other) {
		_type = other._type;
		_xp = other._xp;
	}
	return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at "
		<< target.getName()
		<< " *"
		<< std::endl;
}