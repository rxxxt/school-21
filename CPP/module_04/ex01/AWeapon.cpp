#include "AWeapon.hpp"

AWeapon::AWeapon() {}

AWeapon::AWeapon(const std::string &name, int apcost, int damage) :
		_name(name),
		_apcost(apcost),
		_damage(damage) {}

AWeapon::AWeapon(const AWeapon &other) :
		_name(other._name),
		_apcost(other._apcost),
		_damage(other._damage) {}

AWeapon	&AWeapon::operator=(AWeapon const &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_apcost = other._apcost;
		this->_damage = other._damage;
	}
	return *this;
}

AWeapon::~AWeapon() {}

const std::string &AWeapon::getName() const {
	return _name;
}

int AWeapon::getAPCost() const {
	return _apcost;
}

int AWeapon::getDamage() const {
	return _damage;
}
