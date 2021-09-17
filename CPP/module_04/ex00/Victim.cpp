#include "Victim.hpp"

Victim::Victim() {}

Victim::Victim(std::string name) : _name(name) {
	std::cout << BGREEN << "Some random victim called " << _name << " just appeared!\n" << RESET;
}

Victim::~Victim() {
	std::cout << BRED << "Victim " << _name << " just died for no apparent reason!\n" << RESET;
}

Victim::Victim(const Victim &other) : _name(other._name) {}

Victim & Victim::operator=(const Victim &other) {
	if (this != &other)
		this->_name = other._name;
	return *this;
}

std::string Victim::getName() const {
	return _name;
}

void Victim::getPolymorphed() const {
	std::cout << BYELLOW << _name << " has been turned into a cute little sheep!\n" << RESET;
}

std::ostream	&operator<<(std::ostream &o, Victim const &victim) {
	o << BYELLOW << "I'm " << victim.getName() << " and I like otters!\n" << RESET;
	return o;
}
