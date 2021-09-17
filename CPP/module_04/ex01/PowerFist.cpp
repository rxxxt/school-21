#include "PowerFist.hpp"

PowerFist::PowerFist() :
		AWeapon("Power Fist",
				8,
				50) {}

PowerFist::PowerFist(const PowerFist &other) :
		AWeapon(other) {}

PowerFist & PowerFist::operator=(const PowerFist &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_apcost = other._apcost;
		this->_damage = other._damage;
	}
	return *this;
}

PowerFist::~PowerFist() {}

void PowerFist::attack() const {
	std::cout << BRED << "* pschhh... SBAM! *\n" << RESET;
}
