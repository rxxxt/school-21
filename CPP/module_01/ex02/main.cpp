#include "ZombieEvent.hpp"

int	main(void) {
	Zombie		*zombie;
	Zombie		zombies;
	ZombieEvent	zombieEvent;

	std::srand(time(0));

	std::cout << RED;
	zombie = new Zombie("Garry", "Cosmic");
	zombie->announce();
	delete zombie;

	std::cout << YELLOW;
	zombieEvent.setZombieType("Radiation");
	zombie = zombieEvent.newZombie("Emma");
	zombie->announce();
	delete zombie;

	std::cout << GREEN;
	zombieEvent.setZombieType("Pathogenic");
	zombie = zombieEvent.newZombie("Olivia");
	zombie->announce();
	delete zombie;

	std::cout << BLUE;
	zombieEvent.setZombieType("Combat");
	zombie = zombieEvent.newZombie("Abigail");
	zombie->announce();
	delete zombie;

	std::cout << std::endl;
	zombieEvent.setZombieType("Vegan");
	for (int i = 5; i < 9; i += 1) {
		std::cout << "\033[1;3" << i << "m";
		zombies = zombieEvent.randomChump();
		zombies.announce();
		std::cout << RESET;
	}
	std::cout << RESET;
	return (0);
}