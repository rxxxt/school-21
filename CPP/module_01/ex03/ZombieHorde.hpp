#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {

private:
	Zombie *_zombies;
	int		_n;

public:
	ZombieHorde(int n);
	~ZombieHorde();
	std::string	nameGenerator();
	void		announce();
};


#endif