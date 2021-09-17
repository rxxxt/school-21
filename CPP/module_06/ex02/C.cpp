#include "C.hpp"

std::ostream& operator<<(std::ostream &os, const C&) {
	os << "C" << std::endl;
	return os;
}
