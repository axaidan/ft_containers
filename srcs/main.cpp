#include "vector.hpp"
#include "stack.hpp"
#include <iostream>

int main(void)
{
	ft::stack<int>	my_stack;
	int				i;

	for (i = 0 ; i < 50 ; i++)
		my_stack.push(i);
	for (; i >= 0 ; i++)
		my_stack.pop(i);
	std::cout << "size() = " << my_stack.size() << std::endl;

	return (0);
}
