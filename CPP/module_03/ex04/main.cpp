#include "SuperTrap.hpp"

int main() {
	std::srand(time(0));
	SuperTrap	*super = new SuperTrap("SuperPuper");
	FragTrap	*robik = new FragTrap("Robik");
	ScavTrap	*lelik = new ScavTrap("Lelik");
	ClapTrap	*walle = new ClapTrap();
	NinjaTrap	*hattoriHanzo = new NinjaTrap("Hattori Hanzo");

	super->rangedAttack("Lelik");
	super->meleeAttack("Lelik");
	super->vaulthunter_dot_exe("Lelik");
	super->vaulthunter_dot_exe("Lelik");
	super->vaulthunter_dot_exe("Lelik");
	super->vaulthunter_dot_exe("Lelik");
	super->vaulthunter_dot_exe("Lelik");
	super->takeDamage(4);
	super->takeDamage(70);
	super->beRepaired(85);
	super->ninjaShoebox(*robik);
	super->ninjaShoebox(*lelik);
	super->ninjaShoebox(*walle);
	super->ninjaShoebox(*hattoriHanzo);

	delete	lelik;
	delete	robik;
	delete	hattoriHanzo;
	delete	super;
	return 0;
}