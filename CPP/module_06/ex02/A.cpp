#include "A.hpp"

std::ostream& operator<<(std::ostream &os, const A&) {
	os << "A" << std::endl;
	return os;
}