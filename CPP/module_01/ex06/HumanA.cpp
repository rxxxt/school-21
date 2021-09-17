#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon & weapon) : _weapon(weapon) {
	_name = name;
}

void HumanA::attack() {
	std::cout << BOLD_BLUE << _name << RESET << GRAY << " attacks with his " << BOLD_RED << _weapon.getType() << std::endl;
}