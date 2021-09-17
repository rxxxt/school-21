#include "NinjaTrap.hpp"

int main() {
	std::srand(time(0));
	FragTrap	*robik = new FragTrap("Robik");
	ScavTrap	*lelik = new ScavTrap("Lelik");
	ClapTrap	*walle = new ClapTrap();
	NinjaTrap	*hattoriHanzo = new NinjaTrap("Hattori Hanzo");
	NinjaTrap	*sanadaYukimura = new NinjaTrap("Sanada Yukimura");

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

	{
		hattoriHanzo->rangedAttack(sanadaYukimura->getName());
		sanadaYukimura->takeDamage(37);
		sanadaYukimura->beRepaired(15);
		sanadaYukimura->meleeAttack(hattoriHanzo->getName());
		hattoriHanzo->takeDamage(41);
		hattoriHanzo->beRepaired(100);
		hattoriHanzo->ninjaShoebox(*robik);
		hattoriHanzo->ninjaShoebox(*lelik);
		hattoriHanzo->ninjaShoebox(*walle);
		hattoriHanzo->ninjaShoebox(*sanadaYukimura);
	}

	delete	lelik;
	delete	robik;
	delete	hattoriHanzo;
	delete	sanadaYukimura;
	return 0;
}