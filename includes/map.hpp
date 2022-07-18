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
//class Compare = std::greater<Key>,						// map::key_compare
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
typedef RBnode<value_type>							node;			//priv
typedef std::allocator<node>						node_allocator;	//priv
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
public:
node					*_nil;
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
//	_nil(_nodeAlloc.allocate(1)),
	_nil(_new_nil()),
	_root(_nil),
	_size(0)
{
	// SHOULDN'T _nil'S _p, _r, _l ALSO BE _nil ?
//	_nodeAlloc.construct(_nil, value_type());
//	_nil->_col = BLK;
}

template <class InputIterator>
map(InputIterator first, InputIterator last,
	const key_compare& comp = key_compare(),
	const allocator_type& alloc = allocator_type());

//	1 - ALLOCATE NEW _nil
//	2 - insert(src.begin(), src.end())
map(const map & src);


~map(void)
{}

map &	operator=(const map & x);

/****************/
/*	2 ITERATORS	*/
/****************/
iterator					begin(void)
{
	iterator	it(_tree_min(_root), _nil, _root);
	return (it);
}

const_iterator				begin(void) const
{
	const_iterator	it(_tree_min(_root), _nil, _root);
	return (it);
}

// 1:
// _nil->_p == _tree_max() ? 
// 2:
// RETURN _nil AND TO _tree_max() WHEN --
// => WHAT HAPPENS IN CASE OF revser_iterator ?
iterator					end(void)
{
	iterator	it(_nil, _nil, _root);
	return (it);
}
const_iterator				end(void) const
{
	const_iterator	it(_nil, _nil, _root);
	return (it);
}

reverse_iterator			rbegin(void);
const_reverse_iterator		rbegin(void) const;
reverse_iterator			rend(void);
const_reverse_iterator		rend(void) const;

/****************/
/*	3 CAPACITY	*/
/****************/
bool						empty(void) const		{return (_root == _nil);}
size_type					size(void) const		{return (_size);}
size_type					max_size(void) const;

/************************/
/*	4 ELEMENT ACCESS	*/
/************************/
mapped_type&				operator[](const key_type& key)
{
	ft::pair<iterator, bool>	insert_ret;

	insert_ret = insert(value_type(key, mapped_type()));
	return (insert_ret.first->second);
}

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
			return (make_pair(iterator(x, _nil, _root), false));
		y = x;
		if (_keyComp(val.first, x->_pair.first))
			x = x->_l;
		else
			x = x->_r;
	}
	/*
	z = _nodeAlloc.allocate(1);
	_nodeAlloc.construct(z, val);
	*/
	z = _new_node(val);
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
	_insert_fixup(z);
	_size++;
	return (make_pair(iterator(z, _nil, _root), true));
}

iterator	insert(iterator position, const value_type& val);
template	<class InputIterator>
void		insert(InputIterator first, InputIterator last);

void		erase(iterator position);
size_type	erase(const key_type & k);
void		erase(iterator first, iterator last);

void		swap(map& x);
void		clear(void);

/********************/
/*	6 OBSERVERS		*/
/************&*******/
key_compare		key_comp(void) const	{return (key_compare());}
value_compare	value_comp(void) const	{return (value_compare());}

/****^^^^************/
/*	7 OPERATIONS	*/
/********************/
iterator		find(const key_type& key)
{return (iterator(_tree_search(_root, key), _nil, _root));}

const_iterator	find(const key_type & key) const
{return (const_iterator(_tree_search(_root, key), _nil, _root));}

size_type		count(const key_type & key) const;
iterator		lower_bound(const key_type & key);
const_iterator	lower_bound(const key_type & key) const;
iterator		upper_bound(const key_type & key);
const_iterator	upper_bound(const key_type & key) const;
pair<const_iterator, const_iterator>	equal_range(const key_type & key) const;
pair<iterator, iterator>				equal_range(const key_type & key);

/************************/
/*	8 PRIVATE HELPERS	*/
/************************/
private:
void	_insert_fixup(node * z)
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
					_left_rotate(z);
				}
				z->_p->_col = BLK;
				z->_p->_p->_col = RED;
				_right_rotate(z->_p->_p);
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
					_right_rotate(z);
				}
				z->_p->_col = BLK;
				z->_p->_p->_col = RED;
				_left_rotate(z->_p->_p);
			}
		}
	}
	_root->_col = BLK;
}

void	_left_rotate(node * x)
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

void	_right_rotate(node * x)
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

node *	_tree_search(node * x, const key_type & key)
{
	while (x != _nil && key != x->_pair.first)
	{
		if (_keyComp(key, x->_pair.first))
			x = x->_l;
		else
			x = x->_r;
	}
	return (x);
}
void	_transplant(node * u, node *v)
{
	if (u->_p == _nil)
		_root = v;
	else if (u == u->_p->_l)
		u->_p->_l = v;
	else
		u->_p->_r = v;
	v->_p = u->_p;
}

node *	_new_node(const value_type & val = value_type())
{
	node *	n;
	n = _nodeAlloc.allocate(1);
	_nodeAlloc.construct(n, node(val));
	n->_p = _nil;
	n->_l = _nil;
	n->_r = _nil;
	n->_col = RED;
	return (n);
}

node *	_new_nil(const value_type & val = value_type())
{
	node *	n;
	n = _nodeAlloc.allocate(1);
	_nodeAlloc.construct(n, node(val));
	n->_p = _nil;
	n->_l = _nil;
	n->_r = _nil;
	n->_col = BLK;
	return (n);
}


public:		//	!!!
node *	_tree_min(node * x)
{
	while (x != _nil && x->_l != _nil)
		x = x->_l;
	return (x);
}

node *	_tree_max(node * x)
{
	while (x != _nil && x->_r != _nil)
		x = x->_r;
	return (x);
}

/************/
/*	9 DEBUG	*/
/************/
public:
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
		std::cout << std::left <<  x->_pair.first;
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
