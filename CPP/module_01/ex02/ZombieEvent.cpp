#include "ZombieEvent.hpp"

void	ZombieEvent::setZombieType(std::string type) {
	_type = type;
}

Zombie*	ZombieEvent::newZombie(std::string name) {
	return new Zombie(name, _type);
}

Zombie ZombieEvent::randomChump(void) {
	std::string randomName[9] = {
			"Alfred",
			"Leonard",
			"Helmut",
			"Richard",
			"Ambrosius",
			"Gertrude",
			"Caroline",
			"Beatrice",
			"Theresa"
	};

	return Zombie(randomName[rand() % 9], _type);
}
