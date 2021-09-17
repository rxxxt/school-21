#ifndef B_HPP
# define B_HPP

# include <iostream>
# include "Base.hpp"


class B : public Base {

};


std::ostream& operator<<(std::ostream &o, const B&);

#endif
