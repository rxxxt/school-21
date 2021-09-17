#include "Squad.hpp"

Squad::Squad() :
		_numberOfUnits(0),
		_pSpaceMarine(nullptr) {}

Squad::Squad(Squad const &other) :
		_numberOfUnits(other._numberOfUnits),
		_pSpaceMarine(nullptr) {
	if (_numberOfUnits > 0) {
		_pSpaceMarine = new ISpaceMarine*[_numberOfUnits];
		for (int i = 0; i < _numberOfUnits; i += 1)
			_pSpaceMarine[i] = other._pSpaceMarine[i];
	}
}

Squad &Squad::operator=(Squad const &other) {
	if (this != &other) {
//		this->~Squad();
		for (int i = 0; i < _numberOfUnits; i += 1)
			delete _pSpaceMarine[i];
		delete [] _pSpaceMarine;
		_numberOfUnits = other._numberOfUnits;
		_pSpaceMarine = nullptr;
		if (_numberOfUnits > 0) {
			_pSpaceMarine = new ISpaceMarine*[_numberOfUnits];
			for (int i = 0; i < _numberOfUnits; i += 1)
				_pSpaceMarine[i] = other._pSpaceMarine[i];
		}
	}
	return *this;
}

Squad::~Squad() {
	for (int i = 0; i < _numberOfUnits; i += 1)
		delete _pSpaceMarine[i];
	delete [] _pSpaceMarine;
}

int Squad::getCount() const {
	return _numberOfUnits;
}

ISpaceMarine* Squad::getUnit(int number) const {
	if (number >= 0 && number < _numberOfUnits)
		return _pSpaceMarine[number];
	return nullptr;
}

int Squad::push(ISpaceMarine *spaceMarine) {
	if (spaceMarine == nullptr)
		return _numberOfUnits;
	for (int i = 0; i < _numberOfUnits; i += 1) {
		if (spaceMarine == _pSpaceMarine[i])
			return _numberOfUnits;
	}
	ISpaceMarine **pSpaceMarine = new ISpaceMarine*[_numberOfUnits + 1];
	for (int i = 0; i < _numberOfUnits; i += 1)
		pSpaceMarine[i] = _pSpaceMarine[i];
	pSpaceMarine[_numberOfUnits] = spaceMarine;
	_numberOfUnits += 1;
	delete [] _pSpaceMarine;
	_pSpaceMarine = pSpaceMarine;
	return _numberOfUnits;
}
