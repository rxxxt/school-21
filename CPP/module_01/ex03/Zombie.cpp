#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name, std::string type) {
	_name = name;
	_type = type;
}

void	Zombie::setName(std::string name) {
	_name = name;
}

void	Zombie::setType(std::string type) {
	_type = type;
}

void	Zombie::announce(void) {
	std::cout << "<" << _name << " (" << _type << ")>" << " Braiiiiiiinnnssss...\n";
}
