#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <cstddef>
# include "iterator_utils.hpp"

namespace ft {
	
template<class T>
//class random_access_iterator<ft::random_access_iterator_tag, T>
//class VectorIterator<ft::random_access_iterator_tag, T>
/*
class VectorIterator : ft::iterator<ft::random_access_iterator_tag, T>
{
	public:
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category			iterator_category;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type					value_type;
	typedef	typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type				difference_type;
	typedef T*		pointer;
	typedef T&		reference;
	*/
class VectorIterator : public ft::iterator_traits<T*>
{
	typedef typename ft::iterator_traits<T*>::difference_type		difference_type;
	typedef typename ft::iterator_traits<T*>::value_type			value_type;
	typedef typename ft::iterator_traits<T*>::pointer				pointer;
	typedef typename ft::iterator_traits<T*>::reference			reference;
	typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;


	private:
	pointer	_ptr;

	public:
	VectorIterator(void) :
		_ptr(NULL)
	{}

	VectorIterator(const VectorIterator & src) :
		_ptr(src._ptr)
	{}

	VectorIterator(pointer ptr) :
		_ptr(ptr)
	{}

	virtual ~VectorIterator(void)
	{}

	VectorIterator &	operator=(const VectorIterator rhs)
	{
		_ptr = rhs._ptr;
		return (*this);
	}

	pointer				base(void) const
	{
		return (_ptr);
	}

	reference			operator*(void) const
	{
		return (*_ptr);
	}

	pointer				operator->(void) // const???
	{
		return (&(this->operator*())); // wtf?
	}

	//	PRE-INCREMENT
	VectorIterator &	operator++(void)
	{
		++_ptr;
		return (*this);
	}

	//	POST-INCREMENT
	VectorIterator		operator++(int)
	{
		VectorIterator	tmp(*this);
		++_ptr;
		return (tmp);
	}

	//	PRE-DECREMENT
	VectorIterator &	operator--(void)
	{
		--_ptr;
		return (*this);
	}

	//	POST-DECREMENT
	VectorIterator		operator--(int)
	{
		VectorIterator	tmp(*this);
		--_ptr;
		return (tmp);
	}

	VectorIterator	operator+(difference_type n) const
	{
		VectorIterator	tmp(_ptr + n);
		return (tmp);
	}
	VectorIterator	operator-(difference_type n) const
	{
		VectorIterator	tmp(_ptr - n);
		return (tmp);
	}
	VectorIterator	&operator+=(difference_type n)
	{
		_ptr += n;
		return (*this);
	}
	VectorIterator	&operator-=(difference_type n)
	{
		_ptr -= n;
		return (*this);
	}
	difference_type	operator-(const VectorIterator & rhs) const
	{
		return (_ptr - rhs._ptr);
	}
	reference		operator[](difference_type n) const
	{
		return (*(_ptr + n));
	}

}; // class VectorIterator

template<class T>
bool	operator==(const ft::VectorIterator<T> & lhs,
		const ft::VectorIterator<T> & rhs)
{
	return (lhs.base() == rhs.base());
}
template<class T>
bool	operator!=(const ft::VectorIterator<T> & lhs,
		const ft::VectorIterator<T> & rhs)
{
	return (lhs.base() != rhs.base());
}
template<class T>
bool	operator<(const ft::VectorIterator<T> & lhs,
		const ft::VectorIterator<T> & rhs)
{
	return (lhs.base() < rhs.base());
}
template<class T>
bool	operator>(const ft::VectorIterator<T> & lhs,
		const ft::VectorIterator<T> & rhs)
{
	return (lhs.base() > rhs.base());
}
template<class T>
bool	operator<=(const ft::VectorIterator<T> & lhs,
		const ft::VectorIterator<T> & rhs)
{
	return (lhs.base() <= rhs.base());
}
template<class T>
bool	operator>=(const ft::VectorIterator<T> & lhs,
		const ft::VectorIterator<T> & rhs)
{
	return (lhs.base() >= rhs.base());
}

} // namespace ft

#endif // VECTOR_ITERATOR_HPP
