#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout <<  me->getXPOfMateria(0) << std::endl;
	std::cout <<  me->getXPOfMateria(1) << std::endl;
	me->use(0, *bob);
	std::cout <<  me->getXPOfMateria(0) << std::endl;
	me->use(1, *bob);
	std::cout <<  me->getXPOfMateria(1) << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}
