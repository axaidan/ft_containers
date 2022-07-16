#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "iterator_utils.hpp"
# include "pair.hpp"

namespace ft
{

// IN map.hpp
// typedef ft::MapIterator<value_type, node>			iterator;
template<class T, class RBnode>
class MapIterator	: public ft::iterator_traits<T*>
{

public:
typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
typedef typename ft::iterator_traits<T*>::value_type		value_type;
typedef typename ft::iterator_traits<T*>::pointer			pointer;
typedef typename ft::iterator_traits<T*>::reference			reference;
typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;
typedef RBnode	*											node_ptr;
//typedef MapIterator<const value_type, node>				const_iterator;

private:
node_ptr	_node;
node_ptr	_nil;		
node_ptr	_root;		

/************************************************/
/*	CONSTRUCTION / DESTRUCTION / ASSIGNATION	*/
/************************************************/
public:
MapIterator(void) :
	_node(NULL),
	_nil(NULL),
	_root(NULL)
{}

MapIterator(const MapIterator & src) :
	_node(src._node),
	_nil(src._nil),
	_root(src._root)
{}

MapIterator(const node_ptr & ptr, const node_ptr & nil,
		const node_ptr & root) :
	_node(ptr),
	_nil(nil),
	_root(root)
{}

/*
MapIterator(node_ptr ptr) :
	_node(ptr)				{}
*/


virtual ~MapIterator(void)		{}

/****************/
/*	OPERATORS	*/
/****************/
MapIterator &	operator=(const MapIterator & rhs)
{
	_node = rhs._node;
	_nil = rhs._nil;
	_root = rhs._root;
	return (*this);
}

reference		operator*(void) const	{return (_node->_pair);}

pointer			operator->(void) const	{return (&(this->operator*()));}

// ++it
MapIterator &	operator++(void)
{
	node_ptr	y;
	node_ptr	x;

	if (_node->_r != _nil)
	{
		_node = tree_min(_node->_r);
		return (*this);
	}
	x = _node;
	y = _node->_p;
	while (y != _nil && x == y->_r)
	{
		x = y;
		y = y->_p;
	}	
	_node = y;
	return (*this);
}

/********************/
/*	PRIVATE HELPERS	*/
/********************/
private:
node_ptr	tree_min(node_ptr x)
{
    while (x->_l != _nil)
        x = x->_l;
    return (x);
}

node_ptr	tree_max(node_ptr x)
{
    while (x->_r != _nil)
        x = x->_r;
    return (x);
}



};		//	class MapIterator


}		//	namespace ft

#endif	//	MAP_ITERATOR_HPP
