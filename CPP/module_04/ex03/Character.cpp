#include "Character.hpp"

Character::Character() {}

Character::Character(std::string name) :
		_name(name) {
	for (int i = 0; i < MAXMATERIA; ++i)
		_materia[i] = nullptr;
}

Character::Character(Character const &other) :
		_name(other._name) {
	for (int i = 0; i < MAXMATERIA; ++i) {
		if (other._materia[i] != nullptr)
			_materia[i] = other._materia[i]->clone();
		else
			_materia[i] = nullptr;
	}
}

Character &Character::operator=(Character const &other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < MAXMATERIA; ++i) {
			if (_materia[i] != nullptr)
				delete _materia[i];
			if (other._materia[i] != nullptr)
				_materia[i] = other._materia[i]->clone();
			else
				_materia[i] = nullptr;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < MAXMATERIA; ++i)
		delete _materia[i];
}

const std::string & Character::getName() const {
	return _name;
}

void Character::equip(AMateria *materia) {
	for (int i = 0; i < MAXMATERIA; ++i) {
		if (_materia[i] == materia)
			break;
		if (_materia[i] == nullptr) {
			_materia[i] = materia;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < MAXMATERIA && _materia[idx] != nullptr)
		_materia[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target) {
	if (_materia[idx] != nullptr)
		_materia[idx]->use(target);
}

unsigned int Character::getXPOfMateria(int idx) {
	if (idx >= 0 && idx < MAXMATERIA && _materia[idx] != nullptr)
		return _materia[idx]->getXP();
	return 0;
}
