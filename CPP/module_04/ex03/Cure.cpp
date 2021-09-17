#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &other) : AMateria(other) {}

Cure &Cure::operator=(Cure const &other) {
	if (this != &other) {
		_type = other._type;
		_xp = other._xp;
	}
	return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	AMateria::use(target);
	std::cout << "* heals "
		<< target.getName()
		<< "`s wounds *"
		<< std::endl;
}