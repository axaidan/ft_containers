#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <stdexcept>
# include <functional>
# include <cstddef>

# include "type_utils.hpp"
# include "cmp_utils.hpp"
# include "pair.hpp"
# include "rbnode.hpp"
# include "map_iterator.hpp"

# define BLK 0
# define RED 1

//	# include "rbtree.hpp"

namespace ft
{

template <
class Key,											// map::key_type
class T,											// map::mapped_type
class Compare = std::less<Key>,						// map::key_compare
class Alloc = std::allocator<pair<const Key,T> >	// map::allocator_type
>
class map
{

public:
//	typedefs
typedef	Key											key_type;
typedef T											mapped_type;
typedef	ft::pair<const key_type, mapped_type>		value_type;
typedef	Compare										key_compare;
typedef RBnode<value_type>							node;
typedef std::allocator<node>						node_allocator;
typedef	Alloc										allocator_type;
typedef typename allocator_type::reference			reference;
typedef typename allocator_type::const_reference	const_reference;
typedef	typename allocator_type::pointer			pointer;
typedef typename allocator_type::const_pointer		const_pointer;
typedef ft::MapIterator<value_type, node>			iterator;
typedef ft::MapIterator<const value_type, node>		const_iterator;
typedef	ft::reverse_iterator<iterator>				reverse_iterator;
typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
typedef	size_t										size_type;
typedef ptrdiff_t									difference_type;

class value_compare
//: public std::binary_function<value_type, value_type, bool>
{
// in C++98, it is required to inherit binary_function<T, T, bool>
friend class map;
protected:
	Compare		comp;
	value_compare(Compare c) : comp(c) {}
	// constructed with map's comparison object
public:
	typedef bool			result_type;
	typedef value_type		first_argument_type;
	typedef value_type		second_argument_type;
	bool operator() (const value_type& x, const value_type& y) const
	{ return comp(x.first, y.first); }
};

private:
allocator_type			_pairAlloc;
node_allocator			_nodeAlloc;
key_compare				_keyComp;
node					*_nil;
node					*_root;
size_type				_size;

public:
explicit	map(const key_compare & comp = key_compare(),
				const allocator_type & alloc = allocator_type()) :
	_pairAlloc(alloc),
	_nodeAlloc(std::allocator<node>()),
	_keyComp(comp),
	_nil(_nodeAlloc.allocate(1)),
	_root(_nil),
	_size(0)
{}

ft::pair<iterator, bool>	insert(const value_type& val)
{
	// ALLOCATE AND CONSTRUCT z AT THE END OF FIRST LOOP
	// USE val TO COMPARE
	node *	x;
	node *	y;
	node *	z;

	y = _nil;
	x = _root;
	z = _nodeAlloc.allocate(1);
	_nodeAlloc.construct(z, val);
	while (x != _nil)
	{
		if (x->_value.first == z->_value.first)
			return (make_pair(x, false));
		y = x;
		if (_keyComp(z->_value.first, x->_value.first))
		//if (z->_value.first < x->_value.first)
			x = x->_left;
		else
			x = x->_right;
	}
	z->_parent = y;
	if (y == _nil)
		_root = z;
	else if (_keyComp(z->_value.first, y->_value.first))
		y->_left = z;
	else
		y->_right = z;
	z->_left = _nil;
	z->_right = _nil;
	z->_color = RED;
	return (make_pair(z, true));
}

key_compare	key_comp(void) const {return (key_compare());}

private:
void	insert_fixup(const map & m, node * n);

};		// class map

}		// namespace ft

#endif	// MAP_HPP
