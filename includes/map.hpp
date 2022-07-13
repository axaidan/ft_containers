#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <stdexcept>

# include "type_utils.hpp"
# include "cmp_utils.hpp"
# include "pair.hpp"

//	# include "rbtree.hpp"
//	# include "node.hpp"
//	# include "map_iterator.hpp"

namespace ft
{

template < class Key,						// map::key_type
class T,									// map::mapped_type
class Compare = less<Key>,					// map::key_compare
class Alloc = allocator<pair<const Key,T> >	// map::allocator_type
>
class map
{

public:
//	typedefs
typedef	Key									key_type;
typedef T									mapped_type;
typedef	pair<const key_type, mapped_type>	value_type;
typedef	Compare								key_compare;

class value_compare
{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
friend class map;
protected:
	Compare		comp;
	value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
public:
	typedef bool			result_type;
	typedef value_type		first_argument_type;
	typedef value_type		second_argument_type;
	bool operator() (const value_type& x, const value_type& y) const
	{ return comp(x.first, y.first); }
};

typedef	Alloc								allocator_type;
typedef allocator_type::reference			reference;
typedef allocator_type::const_reference		const_reference;
typedef	allocator_type::pointer				pointer;
typedef alocator_type::const_pointer		const_pointer;
/*
typedef xxx									iterator;
typedef	xxx									const_iterator;
typedef	reverse_iterator<iterator>			reverse_iterator;
typedef	const_reverse_iterator<iterator>	const_reverse_iterator;
*/
typedef	size_t								size_type;
typedef ptrdiff_t							difference_type;

private:
//	attributes

public:
//	functions

};		// class map

}		// namespace ft

#endif	// MAP_HPP
