#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "iterator_utils.hpp"

namespace ft
{

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
node_ptr	_node_ptr;


public:
MapIterator(void) :
	_node_ptr(NULL)
{}

MapIterator(const MapIterator & src) :
	_node_ptr(src._node_ptr)
{}

// THIS CONSTRUCTOR SHOULD BE private OR friendED
MapIterator(node_ptr ptr) :
	_node_ptr(ptr)
{}


MapIterator &	operator=(const MapIterator & rhs)
{
	_node_ptr = rhs._node_ptr;
	return (*this);
}

virtual ~MapIterator(void)
{}

};		//	class MapIterator


}		//	namespace ft

#endif	//	MAP_ITERATOR_HPP
