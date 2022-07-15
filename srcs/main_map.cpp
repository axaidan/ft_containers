#include "map.hpp"
#include <iostream>

int main(void)
{
	ft::map<int, float>								test;
	ft::map<int, float>::iterator					it;
	ft::pair<ft::map<int, float>::iterator, bool>	insert_ret;
	std::cerr << std::boolalpha;
	
	insert_ret = test.insert(ft::make_pair(1, 3.14));
	std::cerr << "first insert status = " << insert_ret.second << "\n";
	insert_ret = test.insert(ft::make_pair(1, 500.500));
	std::cerr << "second insert status = " << insert_ret.second << "\n";
	insert_ret = test.insert(ft::make_pair(2, 3.14));
	std::cerr << "third insert status = " << insert_ret.second << "\n";

	insert_ret = test.insert(ft::make_pair(22, 3.14));
	insert_ret = test.insert(ft::make_pair(12, 3.14));
	insert_ret = test.insert(ft::make_pair(-2, 3.14));
	insert_ret = test.insert(ft::make_pair(21, 3.14));
	insert_ret = test.insert(ft::make_pair(25, 3.14));
	insert_ret = test.insert(ft::make_pair(10, 3.14));

	return(0);
}
