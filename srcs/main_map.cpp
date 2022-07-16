#include "map.hpp"
#include <iostream>

typedef typename	ft::map<int, float>::node	node;

int main(void)
{
	ft::map<int, float>								test;
	ft::map<int, float>::iterator					it;
	ft::pair<ft::map<int, float>::iterator, bool>	insert_ret;
	node *											n;

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

	test.data_visualization(test._root);
	test.graphic_visualization(test._root, 0);

	n = test.tree_min(test._root);
	std::cerr << "=== tree_min()'s key is :\t" << n->_pair.first << std::endl;
	n = test.tree_max(test._root);
	std::cerr << "=== tree_max()'s key is :\t" << n->_pair.first << std::endl;

	it = test.begin();
	std::cerr << "=== it = test.begin();" << std::endl;
	std::cerr << "=== (*it).first\t\t=\t" << (*it).first << std::endl;
	std::cerr << "=== (*it).second\t=\t" << (*it).second << std::endl;
	std::cerr << "=== it->first\t\t=\t" << it->first << std::endl;
	std::cerr << "=== it->second\t\t=\t" << it->second << std::endl;





	return(0);
}
