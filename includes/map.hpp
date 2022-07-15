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
//	DEBUG HEADERS
# include <iostream>
# include <iomanip>
# include <cstdlib>

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

/****************/
/*	TYPES		*/
/****************/
public:
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

/****************/
/*	ATTRIBUTES	*/
/****************/
private:
allocator_type			_pairAlloc;
node_allocator			_nodeAlloc;
key_compare				_keyComp;
node					*_nil;
public:
node					*_root;
private:
size_type				_size;

public:
/************************************************/
/*	1 CONSTRUCTION / DESTRUCTION / ASSIGNATION	*/
/************************************************/
explicit	map(const key_compare & comp = key_compare(),
				const allocator_type & alloc = allocator_type()) :
	_pairAlloc(alloc),
	_nodeAlloc(std::allocator<node>()),
	_keyComp(comp),
	_nil(_nodeAlloc.allocate(1)),
	_root(_nil),
	_size(0)
{
	_nodeAlloc.construct(_nil, ft::pair<const key_type, mapped_type>());
	_nil->_col = BLK;
}

template <class InputIterator>
map(InputIterator first, InputIterator last,
	const key_compare& comp = key_compare(),
	const allocator_type& alloc = allocator_type());
map(const map& x);
~map(void);
map &	operator=(const map & x);

/****************/
/*	2 ITERATORS	*/
/****************/
iterator					begin(void);
const_iterator				begin(void) const;
iterator					end(void);
const_iterator				end(void) const;
reverse_iterator			rbegin(void);
const_reverse_iterator		rbegin(void) const;
reverse_iterator			rend(void);
const_reverse_iterator		rend(void) const;

/****************/
/*	3 CAPACITY	*/
/****************/
bool						empty(void) const;
size_type					size(void) const;
size_type					max_size(void) const;

/************************/
/*	4 ELEMENT ACCESS	*/
/************************/
mapped_type&				operator[](const key_type& k);

/****************/
/*	5 MODIFIERS	*/
/****************/
ft::pair<iterator, bool>	insert(const value_type& val)
{
	node *	x;
	node *	y;
	node *	z;

	y = _nil;
	x = _root;
	while (x != _nil)
	{
		if (x->_pair.first == val.first)
			return (make_pair(x, false));
		y = x;
		if (_keyComp(val.first, x->_pair.first))
			x = x->_l;
		else
			x = x->_r;
	}
	z = _nodeAlloc.allocate(1);
	_nodeAlloc.construct(z, val);
	z->_p = y;
	if (y == _nil)
		_root = z;
	else if (_keyComp(z->_pair.first, y->_pair.first))
		y->_l = z;
	else
		y->_r = z;
	z->_l = _nil;
	z->_r = _nil;
	z->_col = RED;
	insert_fixup(z);
	_size++;
	return (make_pair(z, true));
}

iterator	insert(iterator position, const value_type& val);
template<class InputIterator>
void		insert(InputIterator first, InputIterator last);

void		erase(iterator position);
size_type	erase(const key_type & k);
void		erase(iterator first, iterator last);

void		swap(map& x);
void		clear(void);

/********************/
/*	6 OBERSEVERS	*/
/************&*******/
key_compare		key_comp(void) const {return (key_compare());}
value_compare	value_comp(void) const {return (value_compare());}


/****^^^^************/
/*	7 OPERATIONS	*/
/********************/
iterator		find(const key_type& k);
const_iterator	find(const key_type& k) const;
size_type		count(const key_type& k) const;
iterator		lower_bound(const key_type& k);
const_iterator	lower_bound(const key_type& k) const;
iterator		upper_bound(const key_type& k);
const_iterator	upper_bound(const key_type& k) const;
pair<const_iterator, const_iterator>	equal_range(const key_type& k) const;
pair<iterator, iterator>				equal_range(const key_type& k);

private:
/************************/
/*	8 PRIVATE HELPERS	*/
/************************/
void	insert_fixup(node * z)
{
	node *	y;
	while (z->_p->_col == RED)
	{
		if (z->_p == z->_p->_p->_l)
		{
			y = z->_p->_p->_r;
			if (y ->_col == RED)
			{
				z->_p->_col = BLK;
				y->_col = BLK;
				z->_p->_p->_col = RED;
				z = z->_p->_p;
			}
			else
			{
				if (z == z->_p->_r)
				{
					z = z->_p;
					left_rotate(z);
				}
				z->_p->_col = BLK;
				z->_p->_p->_col = RED;
				right_rotate(z->_p->_p);
			}
		}
		else
		{
			y = z->_p->_p->_l;
			if (y ->_col == RED)
			{
				z->_p->_col = BLK;
				y->_col = BLK;
				z->_p->_p->_col = RED;
				z = z->_p->_p;
			}
			else
			{
				if (z == z->_p->_l)
				{
					z = z->_p;
					right_rotate(z);
				}
				z->_p->_col = BLK;
				z->_p->_p->_col = RED;
				left_rotate(z->_p->_p);
			}
		}
	}
	_root->_col = BLK;
}

void	left_rotate(node * x)
{
	node *	y;

	y = x->_r;
	x->_r = y->_l;
	if (y->_l != _nil)
		y->_l->_p = x;
	y->_p = x->_p;
	if (x->_p == _nil)
		_root = y;
	else if (x == x->_p->_l)
		x->_p->_l = y;
	else
		x->_p->_r = y;
	y->_l = x;
	x->_p = y;
}

void	right_rotate(node * x)
{
	node *	y;

	y = x->_l;
	x->_l = y->_r;
	if (y->_r != _nil)
		y->_r->_p = x;
	y->_p = x->_p;
	if (x->_p == _nil)
		_root = y;
	else if (x == x->_p->_r)
		x->_p->_r = y;
	else
		x->_p->_l = y;
	y->_r = x;
	x->_p = y;
}

public:
/************/
/*	9 DEBUG	*/
/************/
void	print_node(char role, node * x, int depth)
{
	(void)depth;
	while (depth > 0)
	{
		std::cout << "\t";
		depth--;
	}
	(void)role;
	std::cout << role << ":[";
	if (x->_col == RED)
		 std::cout << "\033[31m";
	std::cout << std::setw(10);
	if (x == _nil)
		std::cout << "== NIL ==";
	else
		std::cout << x->_pair.first;
	std::cout << "\033[0m";
	std::cout << "]\t";
}

void	data_visualization(node * x)
{
	if (x != _nil)
	{
		data_visualization(x->_l);
		if (x == _root)
			print_node('R', x, 0);
		else
			print_node('N', x, 0);
		print_node('L', x->_l, 0);
		print_node('R', x->_r, 0);
		print_node('P', x->_p, 0);
		std::cout << std::endl;
		data_visualization(x->_r);
	}
}

void	graphic_visualization(node * x, int depth)
{
	if (x != _nil)
	{
		graphic_visualization(x->_r, depth + 1);
		if (x == _root)
			print_node('R', x, depth);
		else
			print_node(' ', x, depth);
		std::cout << std::endl;
		graphic_visualization(x->_l, depth + 1);
	}
}

};		// class map

}		// namespace ft

#endif	// MAP_HPP
