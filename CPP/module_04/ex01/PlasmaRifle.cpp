#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() :
		AWeapon("Plasma Rifle",
				5,
				21) {}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &other) :
		AWeapon(other) {}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_apcost = other._apcost;
		this->_damage = other._damage;
	}
	return *this;
}

PlasmaRifle::~PlasmaRifle() {}

void PlasmaRifle::attack() const {
	std::cout << BBLUE << "* piouuu piouuu piouuu *\n" << RESET;
}
