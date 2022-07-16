#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "iterator_utils.hpp"

namespace ft
{

	/*
template <
class Key,											// map::key_type
class T,											// map::mapped_type
class Compare = std::less<Key>,						// map::key_compare
class Alloc = std::allocator<pair<const Key,T> >	// map::allocator_type
>
*/

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
node_ptr	_node_ptr;
node_ptr	_nil;		
node_ptr	_root;		

/************************************************/
/*	CONSTRUCTION / DESTRUCTION / ASSIGNATION	*/
/************************************************/
public:
MapIterator(void) :
	_node_ptr(NULL),
	_nil(NULL),
	_root(NULL)					{}

MapIterator(const MapIterator & src) :
	_node_ptr(src._node_ptr),
	_nil(src._nil),
	_root(src._root)			{}

MapIterator(node_ptr ptr, node_ptr nil, node_ptr root) :
	_node_ptr(ptr),
	_nil(nil),
	_root(root)					{}

virtual ~MapIterator(void)		{}

/****************/
/*	OPERATORS	*/
/****************/
MapIterator &	operator=(const MapIterator & rhs)
{
	_node_ptr = rhs._node_ptr;
	return (*this);
}

reference		operator*(void) const	{return (_node_ptr->_pair);}

pointer			operator->(void) const	{return (&(this->operator*()));}

// ++it
/*
MapIterator &	operator++(void)
{
	if (_node_ptr->_r != _map._nil);
}
*/




};		//	class MapIterator


}		//	namespace ft

#endif	//	MAP_ITERATOR_HPP
