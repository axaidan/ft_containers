#ifndef RBNODE_HPP
# define RBNODE_HPP

# define B 0
# define R 1

template<class T>
class RBnode
{
public:
	RBnode						*_parent;
	RBnode						*_left;
	RBnode						*_right;
	T							_value;
	bool						_color;

	RBnode(void) :
		_parent(NULL),
		_left(NULL),
		_right(NULL),
		_color(R)
	{}

	RBnode(T value) :
		_value(value),
		_parent(NULL),
		_left(NULL),
		_right(NULL),
		_color(R)
	{}

};	// class RBnode

#endif // RBNODE_HPP
