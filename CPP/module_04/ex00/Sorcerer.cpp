#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << BGREEN << _name << ", " << _title << ", is born!\n" << RESET;
}

Sorcerer::~Sorcerer() {
	std::cout << BRED << _name << ", " << _title << ", is dead. Consequences will never be the same!\n" << RESET;
}

Sorcerer::Sorcerer(const Sorcerer &other) : _name(other._name), _title(other._title) {}

Sorcerer &Sorcerer::operator=(const Sorcerer &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_title = other._title;
	}
	return *this;
}

std::string Sorcerer::getName() const {
	return _name;
}

std::string Sorcerer::getTitle() const {
	return _title;
}

void Sorcerer::polymorph(Victim const &victim) const {
	victim.getPolymorphed();
}

std::ostream	&operator<<(std::ostream &o, Sorcerer const &sorcerer) {
	o << BYELLOW << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!\n" << RESET;
	return o;
}
