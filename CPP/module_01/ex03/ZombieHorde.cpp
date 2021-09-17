#include "ZombieHorde.hpp"

std::string ZombieHorde::nameGenerator() {
	std::string randomName[13] = {
			"Alfred",
			"Leonard",
			"Helmut",
			"Richard",
			"Ambrosius",
			"Gertrude",
			"Caroline",
			"Beatrice",
			"Theresa",
			"Olivia",
			"Abigail",
			"Emma",
			"Garry"
	};

	return randomName[rand() % 13];
}

ZombieHorde::ZombieHorde(int n) {
	_zombies = new Zombie[n];

	_n = n;
	while (--n >= 0) {
		_zombies[n].setName(nameGenerator());
		_zombies[n].setType("Horde");
	}
}

ZombieHorde::~ZombieHorde() {
	delete [] _zombies;
}

void	ZombieHorde::announce() {
	for (int i = 0; i < _n; i += 1) {
		std::cout << "\033[1;3" << i % 8 + 1 << "m";
		_zombies[i].announce();
		std::cout << RESET;
	}
}
