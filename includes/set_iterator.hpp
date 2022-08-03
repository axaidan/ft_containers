#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP

# include "iterator_utils.hpp"

namespace ft
{

template	<class, class, class>
class 		set;

template<class T, class RBnode>
class SetIterator	: public ft::iterator_traits<T*>
{

template	<class, class, class>
friend		class set;

public:
typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
typedef typename ft::iterator_traits<T*>::value_type		value_type;
typedef typename ft::iterator_traits<T*>::pointer			pointer;
typedef typename ft::iterator_traits<T*>::reference			reference;
typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;
typedef RBnode	*											node_ptr;

private:
node_ptr	_node;
node_ptr	_nil;
node_ptr	_root;

/************************************************/
/*	CONSTRUCTION / DESTRUCTION / ASSIGNATION	*/
/************************************************/
public:
SetIterator(void) :
	_node(NULL),
	_nil(NULL),
	_root(NULL)					{}

SetIterator(const SetIterator & src) :
	_node(src._node),
	_nil(src._nil),
	_root(src._root)			{}

SetIterator(const node_ptr & ptr, const node_ptr & nil,
		const node_ptr & root) :
	_node(ptr),
	_nil(nil),
	_root(root)					{}

virtual ~SetIterator(void)		{}

pointer			base(void) const		{return (&(_node->_pair));}

/****************/
/*	OPERATORS	*/
/****************/
SetIterator &	operator=(const SetIterator & rhs)
{
	_node = rhs._node;
	_nil = rhs._nil;
	_root = rhs._root;
	return (*this);
}

reference		operator*(void) const	{return (_node->_pair);}
pointer			operator->(void) const	{return (&(this->operator*()));}

//	++it
SetIterator &	operator++(void)
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

//	it++
SetIterator		operator++(int)
{
	SetIterator	tmp(*this);
	operator++();
	return (tmp);
}

//	--it
SetIterator &	operator--(void)
{
	node_ptr	y;
	node_ptr	x;

	if (_node == _nil)
	{
		_node = tree_max(_root);
		return (*this);
	}
	if (_node->_l != _nil)
	{
		_node = tree_max(_node->_l);
		return (*this);
	}
	x = _node;
	y = _node->_p;
	while (y != _nil && x == y->_l)
	{
		x = y;
		y = y->_p;
	}	
	_node = y;
	return (*this);
}

//	it--
SetIterator		operator--(int)
{
	SetIterator	tmp(*this);
	operator--();
	return (tmp);
}

operator        SetIterator<const T, RBnode>(void) const
{return (SetIterator<const T, RBnode>(_node, _nil, _root));}

/********************/
/*	PRIVATE HELPERS	*/
/********************/
private:
node_ptr	tree_min(node_ptr x)
{
    while (x != _nil && x->_l != _nil)
        x = x->_l;
    return (x);
}

node_ptr	tree_max(node_ptr x)
{
    while (x != _nil && x->_r != _nil)
        x = x->_r;
    return (x);
}

node_ptr	_get_node(void) const
{return (_node);}

};		//	class SetIterator

template<class T, class U, class Node>
bool    operator==(const SetIterator<T, Node> & lhs,
        const SetIterator<U, Node> & rhs)
{return (lhs.base() == rhs.base());}

template<class T, class U, class Node>
bool    operator!=(const SetIterator<T, Node> & lhs,
        const SetIterator<U, Node> & rhs)
{return (lhs.base() != rhs.base());}

}		//	namespace ft

#endif	//	SET_ITERATOR_HPP
