#ifndef RBTREE_HPP
# define RBTREE_HPP

# include "rbnode.hpp"

template<class K, class M>
class RBtree
{

public:
	typedef RBnode<K, M>	node;

private:
	node					*_root;

public:
	RBtree(void) :
		_root(NULL)
	{}

	RBtree(const RBtree & src) :
		_root(src._root)
	{}






}

#endif // RBTREE_HPP
