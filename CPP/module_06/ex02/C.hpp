#ifndef C_HPP
# define C_HPP

# include <iostream>
# include "Base.hpp"


class C : public Base {

};


std::ostream& operator<<(std::ostream &o, const C&);

#endif
