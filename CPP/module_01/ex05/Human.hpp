#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human {

private:
	Brain	_brain;

public:
	Brain &	getBrain();
	std::string	identify();
};

#endif
