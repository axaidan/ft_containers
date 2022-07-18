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
		_col(RED)				{}

	RBnode(T value) :
		_pair(value),
		_p(NULL),
		_l(NULL),
		_r(NULL),
		_col(RED)				{}

	RBnode(const RBnode & src) :
		_pair(src._pair),
		_p(src._p),
		_l(src._l),
		_r(src._r),
		_col(src._col)			{}

	RBnode &	operator=(const RBnode & rhs)
	{
		_pair = rhs._pair;
		_p = rhs._p;
		_l = rhs._l;
		_r = rhs._r;
		_col = rhs._col;
		return (*this);
	}


};	// class RBnode

#endif // RBNODE_HPP
