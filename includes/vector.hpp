#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <iterator>
# include <vector>

namespace ft
{
template < class T, class Allocator = std::allocator<T> >
class vector
{
public:
	typedef T															value_type;
	typedef Allocator													allocator_type;

	typedef typename Allocator::reference								reference;
	typedef typename Allocator::const_reference							const_reference;
	typedef typename Allocator::pointer									pointer;
	typedef typename Allocator::const_pointer							const_pointer;
	
	typedef	size_t														size_type;
	typedef ptrdiff_t													difference_type;
//	typedef typename std::vector<value_type>::iterator					iterator;
	typedef typename std::vector<value_type>::iterator					iterator;
//	typedef typename std::vector<value_type>::const_iterator			const_iterator;
	typedef typename std::vector<value_type>::const_iterator			const_iterator;

	typedef std::reverse_iterator<iterator>			reverse_iterator;
//	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
//	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	//	CONSTRUCTORS
	//	default (1)
	explicit	vector(const allocator_type& alloc = allocator_type()) :
		_allocator(alloc),
		_begin(NULL),
		_end(NULL),
		_pastEnd(NULL)
	{
		return ;
	}

	//	fill (2)
	explicit	vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) :
		_allocator(alloc),
		_begin(this->_allocator.allocate(n)),
		_end(_begin + n),
		_pastEnd(_end + 1)
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
		_allocator(alloc),
		_begin(_allocator.allocate(last - first)),
		_end(_begin + (&(*last) - &(*first))),
		_pastEnd(_end + 1)
	{
		pointer	tmp;

		tmp = _begin;
		while (first < last)
		{
			*tmp = *first;
			tmp++;
			first++;
		}	
		return ;
	}

	//	copy (4)
	vector (const vector& x);

	//	DESTRUCTOR
	~vector(void)
	{
		_allocator.deallocate(_begin, this->size());
	}

	
	//	CAPACITY
	bool		empty(void) const
	{
		return (_begin == _end);
	}

	size_type	size(void) const
	{
		return (_end - _begin);
	}

private:
	allocator_type	_allocator;
	pointer			_begin;
	pointer			_end;
	pointer			_pastEnd;

	/*
class iterator {
public:
		typedef typename Allocator::difference_type		difference_type;
		typedef typename Allocator::value_type			value_type;
		typedef typename Allocator::reference			reference;
		typedef typename Allocator::pointer				pointer;
		typedef std::random_access_iterator_tag	iterator_category;

		iterator();
		iterator(const iterator&);
		~iterator();

		iterator& operator=(const iterator&);
		bool operator==(const iterator&) const;
		bool operator!=(const iterator&) const;
		bool operator<(const iterator&) const; //optional
		bool operator>(const iterator&) const; //optional
		bool operator<=(const iterator&) const; //optional
		bool operator>=(const iterator&) const; //optional

		iterator& operator++();
			iterator operator++(int); //optional
			iterator& operator--(); //optional
			iterator operator--(int); //optional
			iterator& operator+=(size_type); //optional
			iterator operator+(size_type) const; //optional
			friend iterator operator+(size_type, const iterator&); //optional
			iterator& operator-=(size_type); //optional
			iterator operator-(size_type) const; //optional
			difference_type operator-(iterator) const; //optional

			reference operator*() const;
			pointer operator->() const;
			reference operator[](size_type) const; //optional
	};
	*/

	/*
	class const_iterator {
	public:
			typedef typename Allocator::difference_type		difference_type;
			typedef typename Allocator::value_type			value_type;
			typedef typename Allocator::const_reference		reference;
			typedef typename Allocator::const_pointer		pointer;
			typedef std::random_access_iterator_tag			iterator_category;

			const_iterator ();
			const_iterator (const const_iterator&);
			const_iterator (const iterator&);
			~const_iterator();

			const_iterator& operator=(const const_iterator&);
			bool operator==(const const_iterator&) const;
			bool operator!=(const const_iterator&) const;
			bool operator<(const const_iterator&) const; //optional
			bool operator>(const const_iterator&) const; //optional
			bool operator<=(const const_iterator&) const; //optional
			bool operator>=(const const_iterator&) const; //optional

			const_iterator& operator++();
			const_iterator operator++(int); //optional
			const_iterator& operator--(); //optional
			const_iterator operator--(int); //optional
			const_iterator& operator+=(size_type); //optional
			const_iterator operator+(size_type) const; //optional
			friend const_iterator operator+(size_type, const const_iterator&); //optional
			const_iterator& operator-=(size_type); //optional
			const_iterator operator-(size_type) const; //optional
			difference_type operator-(const_iterator) const; //optional

			reference operator*() const;
			pointer operator->() const;
			reference operator[](size_type) const; //optional
	};
	*/
};
}

#endif // VECTOR_HPP
