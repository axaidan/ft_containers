#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <iterator>
# include <vector>
# include <stdexcept>

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
	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type()) :
		_allocator(alloc)
	{
		size_t	size;
		for (size = 0 ; first != last ; size++, first++)
			;
		_begin = _allocator.allocate(size);
		_end = _begin + size;
		_capacity = _end;
	}

	//	copy (4)
	/*
	vector (const vector& src) :
		_allocator(src.get_allocator()),
		_begin(_allocator.allocate(src.size())),
		_end(_begin + _src.size()),
		_capacity(_end + 1)
	{


		for (pointer tmp = _begin ; tmp < _end ; tmp++)

	}
	*/


	//	DESTRUCTOR
	~vector(void)
	{
		_allocator.deallocate(_begin, this->size());
	}

	
	//	CAPACITY
	size_type		size(void) const
	{
		return (_end - _begin);
	}

	size_type		max_size(void) const
	{
		return (_allocator.max_size());
	}

	/*
	If n is smaller than the current container size,
	the content is reduced to its first n elements,
	removing those beyond (and destroying them).

	If n is greater than the current container size,
	the content is expanded by inserting at the end as many elements
	as needed to reach a size of n.
	If val is specified, the new elements are initialized as
	copies of val, otherwise, they are value-initialized.

	If n is also greater than the current container capacity,
	an automatic reallocation of the allocated storage space
	takes place.
	*/
	void			resize(size_type n, value_type val = value_type())
	{
		pointer	tmp;

		if (n == size())
			return ;
		if (n < size())
		{
			for (tmp = _begin + n ; tmp < _end ; tmp++)
				tmp->~value_type();
			_end = _begin + n;
			return ;
		}
		if (n > size() && n <= capacity())
		{
			tmp = _end;
			_end = _begin + n;
			while (tmp < _end)
			{
				*tmp = val;
				tmp++;
			}
			return ;
		}
		if (n > capacity())
		{
			reserve(n);
			tmp = _end;
			_end = _begin + n;
			while(tmp < _end)
			{
				*tmp = val;
				tmp++;
			}
			return ;
		}
	}

	size_type		capacity(void) const
	{
		return (_capacity - _begin);
	}

	bool			empty(void) const
	{
		return (_begin == _end);
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
			throw std::length_error("reserve: std::length_error");
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

	//	ALLOCATOR
	allocator_type	get_allocator(void) const
	{
		return (_allocator);
	}
};
}

#endif // VECTOR_HPP
