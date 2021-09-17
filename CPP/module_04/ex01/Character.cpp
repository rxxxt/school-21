#include "Character.hpp"

Character::Character() {}

Character::Character(std::string const &name) :
		_name(name),
		_weapon(nullptr),
		_actionPoints(40),
		_maxAP(40),
		_restoringDefaultAP(10) {}

Character::Character(Character const &other) :
		_name(other._name),
		_weapon(other._weapon),
		_actionPoints(other._actionPoints),
		_maxAP(other._maxAP),
		_restoringDefaultAP(other._restoringDefaultAP) {}

Character &Character::operator=(Character const &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_weapon = other._weapon;
		this->_actionPoints = other._actionPoints;
		this->_maxAP = other._maxAP;
		this->_restoringDefaultAP = other._restoringDefaultAP;
	}
	return *this;
}

Character::~Character() {}

const std::string &Character::getName() const {
	return _name;
}

AWeapon *Character::getWeapon() const {
	return _weapon;
}

int Character::getActionPoints() const {
	return _actionPoints;
}

void Character::recoverAP() {
	if (_actionPoints < _maxAP)
	{
		if (_actionPoints + _restoringDefaultAP >= _maxAP)
			_actionPoints = _maxAP;
		else
			_actionPoints += _restoringDefaultAP;
	}
}

void Character::equip(AWeapon *weapon) {
	_weapon = weapon;
}

void Character::attack(Enemy *enemy) {
	if (_weapon != nullptr && _actionPoints >= _weapon->getAPCost()) {
		std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
		_weapon->attack();
		_actionPoints -= _weapon->getAPCost();
		enemy->takeDamage(_weapon->getDamage());
		if (enemy->getHp() == 0)
			delete enemy;
	}
}


std::ostream &operator<<(std::ostream &os, Character const &character) {
	os << character.getName() << " has " << character.getActionPoints() << " AP and ";
	if (character.getWeapon() != nullptr)
		os << "wields a " << character.getWeapon()->getName();
	else
		os << "is unarmed";
	os << std::endl;
	return os;
}
