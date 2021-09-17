#include "ZombieHorde.hpp"

int	main() {
	std::srand(time(0));
	ZombieHorde	zombieHorde(10);
	zombieHorde.announce();
	return (0);
}