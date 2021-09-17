#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Parent") {
	std::cout << BCYAN << "<" << _name << ">" << RESET << GRAY << " ClapTrap robot is constructed!\n" << RESET;
}

ClapTrap::ClapTrap(std::string name,
					unsigned int hitPoints,
					unsigned int maxHitPoints,
					unsigned int energyPoints,
					unsigned int maxEnergyPoints,
					unsigned int level,
					unsigned int meleeAttackDamage,
					unsigned int rangedAttackDamage,
					unsigned int armorDamageReduction) :
					_name(name),
					_hitPoints(hitPoints),
					_maxHitPoints(maxHitPoints),
					_energyPoints(energyPoints),
					_maxEnergyPoints(maxEnergyPoints),
					_level(level),
					_meleeAttackDamage(meleeAttackDamage),
					_rangedAttackDamage(rangedAttackDamage),
					_armorDamageReduction(armorDamageReduction) {
	std::cout << BCYAN << "<" << name << ">" << RESET << GRAY << " ClapTrap robot is constructed!\n" << RESET;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
			_name(other._name),
			_hitPoints(other._hitPoints),
			_maxHitPoints(other._maxHitPoints),
			_energyPoints(other._energyPoints),
			_maxEnergyPoints(other._maxEnergyPoints),
			_level(other._level),
			_meleeAttackDamage(other._meleeAttackDamage),
			_rangedAttackDamage(other._rangedAttackDamage),
			_armorDamageReduction(other._armorDamageReduction) {
	std::cout << GREEN << "Cloning " << BYELLOW << "<" << _name << ">" << RESET << GREEN << " was successful\n";
	if (_name.find("'s clone") > _name.length())
		_name += "'s clone";
	}

ClapTrap &ClapTrap::operator=(ClapTrap const & other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_maxHitPoints = other._maxHitPoints;
		this->_energyPoints = other._energyPoints;
		this->_maxEnergyPoints = other._maxEnergyPoints;
		this->_level = other._level;
		this->_meleeAttackDamage = other._meleeAttackDamage;
		this->_rangedAttackDamage = other._rangedAttackDamage;
		this->_armorDamageReduction = other._armorDamageReduction;
	}
	return *this;
}

void ClapTrap::rangedAttack(const std::string & target) {
	if (_hitPoints > 0) {
		std::cout << GRAY << "ClapTrap " << BYELLOW << "<" << _name << ">" << RESET << GRAY " attacks "
				  << BYELLOW "<" << target << ">" << RESET << GRAY << " at range, causing <";
		if (_rangedAttackDamage < _hitPoints)
			std::cout << _rangedAttackDamage;
		else
			std::cout << _hitPoints;
		std::cout << "> points of damage!\n";
	}
}

void ClapTrap::meleeAttack(const std::string &target) {
	if (_hitPoints > 0) {
		std::cout << GRAY << "ClapTrap " << BYELLOW << "<" << _name << ">" << RESET << GRAY " attacks "
				  << BYELLOW "<" << target << ">" << RESET << GRAY << " in melee, dealing <";
		if (_meleeAttackDamage < _hitPoints)
			std::cout << _meleeAttackDamage;
		else
			std::cout << _hitPoints;
		std::cout << "> points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		std::cout << GRAY << "ClapTrap " << BYELLOW << "<" << _name << ">" << RESET << GRAY << " takes <";
		if (amount <= _armorDamageReduction)
			std::cout << "0> points of damage!\n";
		else if (amount - _armorDamageReduction < _hitPoints) {
			_hitPoints -= (amount - _armorDamageReduction);
			std::cout << amount - _armorDamageReduction << "> points of damage!\n";
		}
		else {
			std::cout << _hitPoints << "> critical points of damage and dies!\n";
			_hitPoints = 0;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << GRAY << "ClapTrap " << BYELLOW << "<" << _name << ">" << RESET;
	if (_hitPoints == 0)
		std::cout << GRAY << " is dead!\n";
	else if (_hitPoints < _maxHitPoints) {
		std::cout << GRAY << " has got <";
		if (_hitPoints + amount > _maxHitPoints) {
			std::cout << _maxHitPoints - _hitPoints;
			_hitPoints = _maxHitPoints;
		}
		else {
			std::cout << amount;
			_hitPoints += amount;
		}
		std::cout << "> health points!\n" << RESET;
	}
}

std::string ClapTrap::getName() {
	return _name;
}

void ClapTrap::charger() {
	if (_hitPoints > 0) {
		if (_energyPoints < _maxEnergyPoints)
			_energyPoints = _maxEnergyPoints;
	}
}

void ClapTrap::levelUp() {
	if (_hitPoints > 0) {
		_level += 1;
	}
}
