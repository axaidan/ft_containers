#include "ContainsAlloc.hpp"
#include <iostream>

std::ostream &	operator<<(std::ostream & o, ContainsAlloc const & rhs)
{
	o << rhs.getAlloc()[0];
	return (o);
}
