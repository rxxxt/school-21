#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
}

void HumanB::setWeapon(Weapon & weapon) {
	_weapon = & weapon;
}

void HumanB::attack() {
	std::cout << BOLD_GREEN << _name << RESET << GRAY << " attacks with his " << BOLD_RED << _weapon->getType() << std::endl;
}
