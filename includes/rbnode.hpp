#ifndef RBNODE_HPP
# define RBNODE_HPP

# define BLK 0
# define RED 1

template<class T>
class RBnode
{
public:
	T							_pair;
	RBnode						*_p;
	RBnode						*_l;
	RBnode						*_r;
	bool						_col;

	RBnode(void) :
		_p(NULL),
		_l(NULL),
		_r(NULL),
		_col(RED)
	{}

	RBnode(T value) :
		_pair(value),
		_p(NULL),
		_l(NULL),
		_r(NULL),
		_col(RED)
	{}

};	// class RBnode

#endif // RBNODE_HPP
