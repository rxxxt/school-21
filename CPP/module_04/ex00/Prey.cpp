#include "Prey.hpp"

Prey::Prey() {}

Prey::Prey(std::string name) : Victim(name) {
	std::cout << BGREEN << "😎😎😎\n" << RESET;
}

Prey::~Prey() {
	std::cout << BRED << "🥶🥶🥶...\n" << RESET;
}

Prey::Prey(const Prey &other) : Victim(other) {}

Prey & Prey::operator=(const Prey &other) {
	if (this != &other)
		this->_name = other._name;
	return *this;
}

void Prey::getPolymorphed() const {
	std::cout << BYELLOW << _name << " has been turned into a little gray mouse!\n" << RESET;
}
