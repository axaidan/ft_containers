#include "map.hpp"
#include <iostream>

int main(void)
{
	ft::map<int, float>								test;
	ft::map<int, float>::iterator					it;
	ft::pair<ft::map<int, float>::iterator, bool>	insert_ret;
	
	insert_ret = test.insert(ft::make_pair(1, 3.14));
	std::cout << "first insert status = " << insert_ret.second << "\n";
	insert_ret = test.insert(ft::make_pair(1, 500.500));
	std::cout << "first insert status = " << insert_ret.second << "\n";
	

	return(0);
}
