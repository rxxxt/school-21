#include "Enemy.hpp"

Enemy::Enemy() {}

Enemy::Enemy(int hp, const std::string &type) :
		_hp(hp),
		_type(type) {}

Enemy::Enemy(Enemy const &other) :
		_hp(other._hp),
		_type(other._type) {}

Enemy &Enemy::operator=(Enemy const &other) {
	if (this != &other) {
		this->_hp = other._hp;
		this->_type = other._type;
	}
	return *this;
}

Enemy::~Enemy() {}

int Enemy::getHp() const {
	return _hp;
}

const std::string &Enemy::getType() const {
	return _type;
}

void Enemy::takeDamage(int damage) {
	if (damage >= _hp)
		_hp = 0;
	else if (damage > 0)
		_hp -= damage;
}
