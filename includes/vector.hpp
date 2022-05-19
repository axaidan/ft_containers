#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <iterator>
# include <vector>
# include <stdexcept>
# include <iomanip>			// !!!
# include <iostream>		// !!!
# include "type_utils.hpp"

namespace ft
{
template < class T, class Allocator = std::allocator<T> >
class vector
{
public:
	typedef T													value_type;
	typedef Allocator											allocator_type;

	typedef typename Allocator::reference						reference;
	typedef typename Allocator::const_reference					const_reference;
	typedef typename Allocator::pointer							pointer;
	typedef typename Allocator::const_pointer					const_pointer;
	
	typedef	size_t												size_type;
	typedef ptrdiff_t											difference_type;
	typedef typename std::vector<value_type>::iterator			iterator;
	typedef typename std::vector<value_type>::const_iterator	const_iterator;

	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

private:
	allocator_type	_allocator;
	pointer			_begin;
	pointer			_end;
	pointer			_capacity;

public:
//	CONSTRUCTORS
//	default (1)
explicit	vector(const allocator_type& alloc = allocator_type()) :
	_allocator(alloc),
	_begin(NULL),
	_end(NULL),
	_capacity(NULL)
{
//	std::cerr << "VECTOR DEFAULT CONSTRUCTOR" << std::endl;
	return ;
}

//	fill (2)
explicit	vector(size_type n, const value_type& val = value_type(),
             const allocator_type& alloc = allocator_type()) :
	_allocator(alloc),
	_begin(this->_allocator.allocate(n)),
	_end(_begin + n),
	_capacity(_end)
{
//	std::cerr << "VECTOR FILL CONSTRUCTOR" << std::endl;
	pointer	tmp;

	tmp = _begin;
	while (tmp < _end)
	{
		*tmp = val;
		tmp++;
	}
	return ;
}

//	range (3)
template <class InpIt>
vector(typename ft::enable_if<!ft::is_integral<InpIt>::value, InpIt>::type first,
		InpIt last,
		const allocator_type& alloc = allocator_type()) :
	_allocator(alloc)
{
//	std::cerr << "VECTOR RANGE CONSTRUCTOR" << std::endl;
	pointer		tmp;
	InpIt		bckpFirst;
	size_type	size;
	bckpFirst = first;
	for (size = 0 ; first != last ; size++, first++)
		;
	tmp = _allocator.allocate(size);
	first = bckpFirst;
	size = 0;
	while (first != last)
	{
		*(tmp + size) = *first;
		size++;
		first++;
	}
	_begin = tmp;
	_end = _begin + size;
	_capacity = _end;
}

//	copy (4)
vector (const vector& src) :
	_allocator(src.get_allocator()),
	_begin(_allocator.allocate(src.size())),
	_end(_begin + src.size()),
	_capacity(_end + 1)
{
//	std::cerr << "VECTOR COPY CONSTRUCTOR" << std::endl;
	const_iterator	it;
	const_iterator	ite;
	pointer			tmp;

	it = src.begin();
	ite = src.end();
	tmp = _begin;
	while (it != ite)
	{
		*tmp = *it;	
		tmp++;
		it++;
	}
}


//	DESTRUCTOR
~vector(void)
{
	pointer	tmpBegin;

	tmpBegin = _begin;
	while (tmpBegin < _end)
	{
		_allocator.destroy(tmpBegin);
		tmpBegin++;
	}
	//std::cerr << "VECTOR DESTRUCTOR, ABOUT TO deallocate()" << std::endl;
	_allocator.deallocate(_begin, capacity());
}

//	ITERATORS
iterator				begin(void)
{
	iterator				it(_begin);
	return (it);
}

const_iterator			begin(void) const
{
	const_iterator			it(_begin);
	return (it);
}

iterator				end(void)
{
	iterator				it(_end);
	return (it);
}

const_iterator			end(void) const
{
	const_iterator			it(_end);
	return (it);
}

reverse_iterator		rbegin(void)
{
	reverse_iterator		it(_begin);
	return (it);
}

const_reverse_iterator	rbegin(void) const
{
	const_reverse_iterator	it(_begin);
	return (it);
}

reverse_iterator		rend(void)
{
	reverse_iterator		it(_end);
	return (it);
}

const_reverse_iterator	rend(void) const
{
	const_reverse_iterator	it(_end);
	return (it);
}


//	CAPACITY
size_type		size(void)		const	{return (_end - _begin);}
size_type		max_size(void)	const	{return (_allocator.max_size());}
size_type		capacity(void)	const	{return (_capacity - _begin);}
bool			empty(void)		const	{return (_begin == _end);}

void			resize(size_type n, value_type val = value_type())
{
	pointer	tmp;

	if (n == size())
		return ;
	if (n < size())
	{
		for (tmp = _begin + n ; tmp < _end ; tmp++)
			_allocator.destroy(tmp);
		_end = _begin + n;
		return ;
	}
	if (n > capacity())
		reserve(n);
	tmp = _end;
	_end = _begin + n;
	while(tmp < _end)
	{
		*tmp = val;
		tmp++;
	}
}

void			reserve(size_type n)
{
	pointer		tmpBegin;
	pointer		tmpEnd;
	pointer		tmpCapacity;
	size_t		i;

	if (n <= capacity())
		return ;
	if (n > max_size())
		throw std::length_error("vector::length_error");
	tmpBegin = _allocator.allocate(n);
	tmpEnd = tmpBegin + size();
	tmpCapacity = tmpBegin + n;
	for (i = 0 ; i < size() ; i++)
		tmpBegin[i] = _begin[i];
	_allocator.deallocate(_begin, size());
	_begin = tmpBegin;
	_end = tmpEnd;
	_capacity = tmpCapacity;
}

//	ELEMENT ACCESS

reference		at(size_type n)
{
	if (n >= size())
		throw(std::out_of_range("vector::out_of_range"));
	return (*(_begin + n));
}

const_reference at(size_type n) const
{
	if (n >= size())
		throw(std::out_of_range("vector::out_of_range"));
	return (*(_begin + n));
}

reference		operator[](size_type n)			{return (*(_begin + n));}
const_reference	operator[](size_type n) const	{return (*(_begin + n));}
//	UNDEF BEHAV IF V IS EMPTY
reference		front(void)						{return (*_begin);}
const_reference	front(void)	const				{return (*_begin);}
//	UNDEF BEHAV IF V IS EMPTY
reference		back(void)				{return (*(_begin + size() - 1));}
const_reference	back(void)	const		{return (*(_begin + size() - 1));}

//	ALLOCATOR
allocator_type	get_allocator(void) const	{return (_allocator);}

//	DEBUG
void			print_values(void) const
{
	pointer	tmp;
	
	tmp = _begin;
	std::cout << "=== CONTENTS:" << std::endl;
	while (tmp != _end)
	{
		std::cout << "vector[" << std::setw(4)
			<< tmp - _begin << "] = " 
			<< *tmp << std::endl;
		tmp++;
	}
	std::cout << std::endl;
}

};
}

#endif // VECTOR_HPP
