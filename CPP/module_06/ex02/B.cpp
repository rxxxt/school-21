#include "B.hpp"

std::ostream& operator<<(std::ostream &os, const B&) {
	os << "B" << std::endl;
	return os;
}