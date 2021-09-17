#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>


class Enemy {

protected:
	int			_hp;
	std::string	_type;

public:
	Enemy(int hp, std::string const &type);
	Enemy(Enemy const &other);
	Enemy &operator=(Enemy const &other);
	virtual	~Enemy();

	int getHp() const;
	const std::string &getType() const;
	virtual void takeDamage(int damage);

private:
	Enemy();

};


#endif
