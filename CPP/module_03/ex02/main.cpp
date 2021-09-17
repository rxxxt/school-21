#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::srand(time(0));
	FragTrap *robik = new FragTrap("Robik");
	ScavTrap *lelik = new ScavTrap("Lelik");

	{
		robik->rangedAttack("Lelik");
		robik->meleeAttack("Lelik");
		robik->vaulthunter_dot_exe("Lelik");
		robik->takeDamage(4);
		robik->takeDamage(70);
		robik->takeDamage(70);
		robik->beRepaired(85);
		robik->vaulthunter_dot_exe("Lelik");
		robik->vaulthunter_dot_exe("Lelik");
	}

	{
		lelik->rangedAttack("Robik");
		lelik->meleeAttack("Robik");
		lelik->challengeNewcomer("Robik");
		lelik->takeDamage(4);
		lelik->beRepaired(85);
		lelik->challengeNewcomer("Robik");
		lelik->challengeNewcomer("Robik");
		lelik->challengeNewcomer("Robik");
	}

	delete	lelik;
	delete	robik;
	return 0;
}