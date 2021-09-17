#include "Peon.hpp"

Peon::Peon() {}

Peon::Peon(std::string name) : Victim(name) {
	std::cout << BGREEN << "Zog zog.\n" << RESET;
}

Peon::~Peon() {
	std::cout << BRED << "Bleuark...\n" << RESET;
}

Peon::Peon(const Peon &other) : Victim(other) {}

Peon & Peon::operator=(const Peon &other) {
	if (this != &other)
		this->_name = other._name;
	return *this;
}

void Peon::getPolymorphed() const {
	std::cout << BYELLOW << _name << " has been turned into a pink pony!\n" << RESET;
}
