#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"


class Character {

private:
	std::string	_name;
	AWeapon		*_weapon;
	int			_actionPoints;
	int 		_maxAP;
	int 		_restoringDefaultAP;

public:
	explicit Character(std::string const &name);
	Character(Character const &other);
	Character &operator=(Character const &other);
	~Character();

	const std::string &getName() const;
	AWeapon *getWeapon() const;
	int getActionPoints() const;
	void recoverAP();
	void equip(AWeapon *weapon);
	void attack(Enemy *enemy);

private:
	Character();

};


std::ostream	&operator<<(std::ostream &os, Character const &character);

#endif
