#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < MAXMATERIA; ++i)
		_materia[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	for (int i = 0; i < MAXMATERIA; ++i) {
		if (other._materia[i] != nullptr)
			_materia[i] = other._materia[i]->clone();
		else
			_materia[i] = nullptr;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	if (this != &other) {
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

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAXMATERIA; ++i)
		delete _materia[i];
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < MAXMATERIA; ++i) {
		if (_materia[i] == materia)
			break;
		if (_materia[i] == nullptr) {
			_materia[i] = materia;
			break;
		}
	}
}

AMateria * MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < MAXMATERIA; ++i) {
		if (_materia[i] != nullptr && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return nullptr;
}
