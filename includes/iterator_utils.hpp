#ifndef ITERATOR_UTILS_HPP
# define ITERATOR_UTILS_HPP

# include <cstddef> 
namespace ft {

/********************/
/*	ITERATOR_TAGS	*/
/********************/
struct input_iterator_tag												{ };
struct output_iterator_tag												{ };
struct forward_iterator_tag:		public input_iterator_tag			{ };
struct bidirectional_iterator_tag:	public forward_iterator_tag			{ };
struct random_access_iterator_tag:	public bidirectional_iterator_tag	{ };

/********************/
/*	ITERATOR_TRAITS	*/
/********************/
template< class Iter >
struct iterator_traits
{
	typedef typename Iter::difference_type			difference_type;
	typedef typename Iter::value_type				value_type;
	typedef typename Iter::pointer					pointer;
	typedef typename Iter::reference				reference;
	typedef typename Iter::iterator_category		iterator_category;
};
		
template< class T >
struct iterator_traits<T*>
{
	typedef std::ptrdiff_t							difference_type;
	typedef T										value_type;
	typedef T*										pointer;
	typedef T&										reference;
	typedef typename ft::random_access_iterator_tag	iterator_category;
};
		
template< class T >
struct iterator_traits<const T*>
{
	typedef std::ptrdiff_t							difference_type;
	typedef const T									value_type;
	typedef const T*								pointer;
	typedef const T&								reference;
	typedef typename ft::random_access_iterator_tag	iterator_category;
};

/********************/
/*	CLASS_TEMPLATE	*/
/********************/
template<class Category,
	class T,
	class Distance = ptrdiff_t,
	class Pointer = T*,
	class Reference = T&>
		struct iterator {
			typedef Category  iterator_category;
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
		};

template<class Iter>
class reverse_iterator : public ft::iterator_traits<Iter>
{
	public:
	typedef typename ft::iterator_traits<Iter>::difference_type 	difference_type;
	typedef typename ft::iterator_traits<Iter>::value_type			value_type;
	typedef typename ft::iterator_traits<Iter>::pointer				pointer;
	typedef typename ft::iterator_traits<Iter>::reference			reference;
	typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;

	protected:
	Iter	_iterator;

	public:
	reverse_iterator(void) :
		_iterator(NULL)
	{
	}
	//explicit reverse_iterator(const Iter & src) :
	explicit reverse_iterator(const Iter & src) :
		_iterator(src)
	{
	}
	template<typename T>
	reverse_iterator(const reverse_iterator<T> & src) :
		_iterator(src.base())
	{
	}

	~reverse_iterator(void)
	{
	}
	reverse_iterator &	operator=(const reverse_iterator & rhs)
	{
		_iterator = rhs._iterator;
		return (*this);
	}
	Iter	base(void) const
	{
		return (_iterator);
	}
	reference			operator*(void) const
	{
		Iter	tmp(_iterator);
		tmp--;
		return (*tmp);
	}
	pointer				operator->(void) const
	{
		return (&(operator*()));
	}

	/************************/
	/*	MODIFYING OPERATORS	*/
	/************************/
	reverse_iterator	operator++(void)
	{
		reverse_iterator	tmp(*this);
		--_iterator;
		return (tmp);
	}	
	reverse_iterator &	operator++(int)
	{
		--_iterator;
		return (*this);
	}	
	reverse_iterator	operator--(void)
	{
		reverse_iterator	tmp(*this);
		_iterator++;
		return (tmp);
	}	
	reverse_iterator &	operator--(int)
	{
		++_iterator;
		return (*this);
	}	
	reverse_iterator	operator+(difference_type n) const
	{
		reverse_iterator	tmp(*this);
		tmp._iterator = tmp._iterator - n;
		return (tmp);
	}
	reverse_iterator	operator-(difference_type n) const
	{
		reverse_iterator	tmp(*this);
		tmp._iterator = tmp._iterator + n;
		return (tmp);
	}
	difference_type		operator-(const reverse_iterator & rhs) const
	{
//		return (base() - rhs.base());
		return (rhs.base() - base());
	}
	reverse_iterator	operator+=(difference_type n)
	{
		_iterator -= n;
		return (*this);
	}
	reverse_iterator	operator-=(difference_type n)
	{
		_iterator += n;
		return (*this);
	}

	/****************************/
	/*	COMPARISON OPERATORS	*/
	/****************************/
	bool	operator==(const reverse_iterator & rhs) const
	{
		return (base() == rhs.base());
	}
	bool	operator!=(const reverse_iterator & rhs) const
	{
		return (base() != rhs.base());
	}
	bool	operator<(const reverse_iterator & rhs) const
	{
		return (base() > rhs.base());
	}
	bool	operator>(const reverse_iterator & rhs) const
	{
		return (base() < rhs.base());
	}
	bool	operator<=(const reverse_iterator & rhs) const
	{
		return (base() >= rhs.base());
	}
	bool	operator>=(const reverse_iterator & rhs) const
	{
		return (base() <= rhs.base());
	}

	reference	operator[](difference_type n) const
	{
		return (_iterator[-n - 1]);
	}
	


	
};

/*
template<class T>
bool	operator==(const reverse_iterator<T> & lhs, const reverse_iterator<T> & rhs)
{
	return (lhs.base() == rhs.base());
}
template<class T>
bool	operator!=(const reverse_iterator<T> & lhs, const reverse_iterator<T> & rhs)
{
	return (lhs.base() != rhs.base());
}
template<class T>
bool	operator<(const reverse_iterator<T> & lhs, const reverse_iterator<T> & rhs)
{
	return (lhs.base() > rhs.base());
}
template<class T>
bool	operator>(const reverse_iterator<T> & lhs, const reverse_iterator<T> & rhs)
{
	return (lhs.base() < rhs.base());
}
template<class T>
bool	operator<=(const reverse_iterator<T> & lhs, const reverse_iterator<T> & rhs)
{
	return (lhs.base() >= rhs.base());
}
template<class T>
bool	operator>=(const reverse_iterator<T> & lhs, const reverse_iterator<T> & rhs)
{
	return (lhs.base() <= rhs.base());
}
*/

template<typename T>
reverse_iterator<T>	operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T> & rit)
{
	return (rit + n);
}

template<typename T>
typename reverse_iterator<T>::difference_type
operator-(const reverse_iterator<T> & lhs, const reverse_iterator<T> & rhs)
{
//	return (lhs.base() - rhs.base());
//	return (rhs.base() - lhs.base());
	std::cerr << "NON MEMBER OPERATOR-() CALLED\n";
	(void)rhs;
	(void)lhs;
	return (1000);

}





} // namespace ft

# endif // ITERATOR_UTILS_HPP
