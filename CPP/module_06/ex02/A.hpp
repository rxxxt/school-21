#ifndef A_HPP
# define A_HPP

# include <iostream>
# include "Base.hpp"


class A : public Base {

};


std::ostream& operator<<(std::ostream &o, const A&);

#endif
