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
	typedef T										value_type;
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

	private:
	Iter	_iterator;

	public:
	reverse_iterator(void) :
		_iterator(NULL)
	{
	}
	reverse_iterator(const reverse_iterator/*<Iter>*/ & src) :
		_iterator(src._iterator)
	{
	}
	explicit reverse_iterator(const Iter & src) :
		_iterator(src)
	{
	}
	reverse_iterator &	operator=(const revserse_iterator & rhs)
	{
		_iterator = src._iterator;
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
	reverse_iterator	operator++(void);
	reverse_iterator &	operator++(int);
	reverse_iterator	operator--(void);
	reverse_iterator &	operator--(int);
	reverse_iterator	operator+=(void);
	reverse_iterator	operator-=(void);
	reverse_iterator	operator+(difference_type n);
	reverse_iterator	operator-(difference_type n);
	difference_type		operator-(const reverse_iterator & rhs) const;

	bool	operator==(const reverse_iterator & rhs) const;
	bool	operator!=(const reverse_iterator & rhs) const;
	bool	operator<(const reverse_iterator & rhs) const;
	bool	operator>(const reverse_iterator & rhs) const;
	bool	operator<=(const reverse_iterator & rhs) const;
	bool	operator>=(const reverse_iterator & rhs) const;

	reference	operator[](difference_type n) const;
	


	
};



} // namespace ft

# endif // ITERATOR_UTILS_HPP
