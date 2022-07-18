#include "map.hpp"
#include <iostream>
#include "vector.hpp"

typedef typename	ft::map<int, float>::node	node;


int main(void)
{
	ft::map<int, float>								test;
	ft::map<int, float>::iterator					it;
	ft::map<int, float>::const_iterator				ite;
	ft::pair<ft::map<int, float>::iterator, bool>	insert_ret;
	node *											n;

	std::cerr << std::boolalpha;

	it = test.begin();
	ite = test.end();
	while (it != ite)
	{
		std::cerr << it->first << std::endl;
		it++;
	}
	
	test[-10] = 13.37f;
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

	++it;
	std::cerr << "=== ++it :" << std::endl;
	std::cerr << "=== (*it).first\t\t=\t" << (*it).first << std::endl;
	int 	i;
	for (i = 0, it = test.begin() ; i < 8 ; i++, ++it)
		std::cerr << "=== (*it).first\t\t=\t" << (*it).first << std::endl;

	test.graphic_visualization(test._root, 0);
	

	it = test.begin();
	ite = test.end();
	while (it != ite)
	{
		std::cerr << it->first << std::endl;
		it++;
	}
	it = test.find(10);
	std::cerr << "=== it = test.find(10) :" << std::endl;
	std::cerr << "=== (*it).first\t\t=\t" << (*it).first << std::endl;
	it = test.find(99);
	std::cerr << "=== it = test.find(99) :" << std::endl;
	std::cerr << "=== (*it).first\t\t=\t" << (*it).first << std::endl;
	std::cerr << "=== (it == test.end())\t=\t" << (it == test.end()) << std::endl;

	std::cerr << "=== test[99] = 1000.0f :" << std::endl;
	test[99] = 1000.0f;
	std::cerr << "=== it = test.find(99) :" << std::endl;
	it = test.find(99);
	std::cerr << "=== (*it).first\t\t=\t" << (*it).first << std::endl;
	std::cerr << "=== (*it).second\t=\t" << (*it).second << std::endl;
	std::cerr << "=== (it == test.end())\t=\t" << (it == test.end()) << std::endl;
	test.graphic_visualization(test._root, 0);





	return(0);
}
