#include "FragTrap.hpp"

int main()
{
	std::srand(time(0));
	FragTrap	*robik = new FragTrap("Robik");
	FragTrap	*cloneRobik = new FragTrap(*robik);

	robik->rangedAttack("Lelik");
	robik->meleeAttack("Lelik");
	robik->vaulthunter_dot_exe("Lelik");
	robik->takeDamage(4);
	robik->takeDamage(70);
	robik->takeDamage(70);
	robik->beRepaired(85);
	robik->vaulthunter_dot_exe("Lelik");
	robik->vaulthunter_dot_exe("Lelik");
	cloneRobik->vaulthunter_dot_exe("Lelik");
	cloneRobik->vaulthunter_dot_exe("Lelik");
	cloneRobik->vaulthunter_dot_exe("Lelik");
	cloneRobik->vaulthunter_dot_exe("Lelik");
	delete	cloneRobik;
	delete	robik;
	return 0;
}