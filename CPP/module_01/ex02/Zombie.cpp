#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name, std::string type) {
	_name = name;
	_type = type;
}

void	Zombie::announce(void) {
	std::cout << "<" << _name << " (" << _type << ")>" << " Braiiiiiiinnnssss...\n";
}
