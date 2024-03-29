#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <iterator>
# include <vector>

namespace ft
{
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
