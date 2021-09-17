#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) :
		_type(type),
		_xp(0) {}

AMateria::AMateria(AMateria const &other) :
		_type(other._type),
		_xp(other._xp) {}

AMateria &AMateria::operator=(AMateria const &other) {
	if (this != &other) {
		_type = other._type;
		_xp = other._xp;
	}
	return *this;
}

AMateria::~AMateria() {}

unsigned int AMateria::getXP() const {
	return _xp;
}

const std::string &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	(void) target;
	_xp += 10;
}
