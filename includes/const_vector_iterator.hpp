#ifndef CONST_VECTOR_ITERATOR_HPP
# define CONST_VECTOR_ITERATOR_HPP

# include <cstddef>
# include "iterator_utils.hpp"

namespace ft {

template<class T>
class	VectorIterator;
	
template<class T>
class ConstVectorIterator : public ft::iterator_traits<const T*>
{
	public:
	typedef typename ft::iterator_traits<const T*>::difference_type		difference_type;
	typedef typename ft::iterator_traits<const T*>::value_type			value_type;
	typedef typename ft::iterator_traits<const T*>::pointer				pointer;
	typedef typename ft::iterator_traits<const T*>::reference			reference;
	typedef typename ft::iterator_traits<const T*>::iterator_category	iterator_category;


	private:
	pointer	_ptr;

	pointer				base(void) const
	{
		return (_ptr);
	}

	public:
	ConstVectorIterator(void) :
		_ptr(NULL)
	{}

	ConstVectorIterator(const ConstVectorIterator<T> & src) :
		_ptr(src._ptr)
	{}

	ConstVectorIterator(const VectorIterator<T> & src) :
		_ptr(src._ptr)
	{}

	ConstVectorIterator(pointer ptr) :
		_ptr(ptr)
	{}

	virtual ~ConstVectorIterator(void)
	{}

	ConstVectorIterator &	operator=(const ConstVectorIterator rhs)
	{
		_ptr = rhs._ptr;
		return (*this);
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
	ConstVectorIterator &	operator++(void)
	{
		++_ptr;
		return (*this);
	}

	//	POST-INCREMENT
	ConstVectorIterator		operator++(int)
	{
		ConstVectorIterator	tmp(*this);
		++_ptr;
		return (tmp);
	}

	//	PRE-DECREMENT
	ConstVectorIterator &	operator--(void)
	{
		--_ptr;
		return (*this);
	}

	//	POST-DECREMENT
	ConstVectorIterator		operator--(int)
	{
		ConstVectorIterator	tmp(*this);
		--_ptr;
		return (tmp);
	}

	ConstVectorIterator	operator+(difference_type n) const
	{
		ConstVectorIterator	tmp(_ptr + n);
		return (tmp);
	}
	ConstVectorIterator	operator-(difference_type n) const
	{
		ConstVectorIterator	tmp(_ptr - n);
		return (tmp);
	}
	ConstVectorIterator	&operator+=(difference_type n)
	{
		_ptr += n;
		return (*this);
	}
	ConstVectorIterator	&operator-=(difference_type n)
	{
		_ptr -= n;
		return (*this);
	}
	difference_type	operator-(const ConstVectorIterator & rhs) const
	{
		return (_ptr - rhs._ptr);
	}
	reference		operator[](difference_type n) const
	{
		return (*(_ptr + n));
	}

	/*
	operator		ConstVectorIterator<const T>(void) const
    {
		std::cerr << "ConstVectorIterator.hpp - CONVERSION OPERATOR CALLED\n";
		return (ConstVectorIterator<const T>(this->_ptr));
	}
	*/

	bool	operator==(const ConstVectorIterator<T> & rhs) const
	{
		return (base() == rhs.base());
	}
	bool	operator!=(const ConstVectorIterator<T> & rhs) const
	{
		return (base() != rhs.base());
	}
	bool	operator<(const ConstVectorIterator<T> & rhs) const
	{
		return (base() < rhs.base());
	}
	bool	operator>(const ConstVectorIterator<T> & rhs) const
	{
		return (base() > rhs.base());
	}
	bool	operator<=(const ConstVectorIterator<T> & rhs) const
	{
		return (base() <= rhs.base());
	}
	bool	operator>=(const ConstVectorIterator<T> & rhs) const
	{
		return (base() >= rhs.base());
	}

}; // class ConstVectorIterator

/*
template<class T>
bool	operator==(const ConstVectorIterator<T> & lhs,
		const ConstVectorIterator<T> & rhs)
{
	return (lhs.base() == rhs.base());
}
//template<class TLeft, class TRight>
//bool	operator==(const ConstVectorIterator<TLeft> & lhs,
//		const ConstVectorIterator<TRight> & rhs)
//{
//	return (lhs.base() == rhs.base());
//}
template<class T>
bool	operator!=(const ConstVectorIterator<T> & lhs,
		const ConstVectorIterator<T> & rhs)
{
	return (lhs.base() != rhs.base());
}
template<class T>
bool	operator<(const ConstVectorIterator<T> & lhs,
		const ConstVectorIterator<T> & rhs)
{
	return (lhs.base() < rhs.base());
}
template<class T>
bool	operator>(const ConstVectorIterator<T> & lhs,
		const ConstVectorIterator<T> & rhs)
{
	return (lhs.base() > rhs.base());
}
template<class T>
bool	operator<=(const ConstVectorIterator<T> & lhs,
		const ConstVectorIterator<T> & rhs)
{
	return (lhs.base() <= rhs.base());
}
template<class T>
bool	operator>=(const ConstVectorIterator<T> & lhs,
		const ConstVectorIterator<T> & rhs)
{
	return (lhs.base() >= rhs.base());
}
*/

//	PASS ALL COMP OPERATORS IN CLASS DEF?

} // namespace ft

#endif // CONST_VECTOR_ITERATOR_HPP
