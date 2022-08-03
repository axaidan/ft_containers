#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
template<class T, class Container = ft::vector<T> >
class stack
{
			public:

// MEMBER TYPES
typedef Container							container_type;
typedef typename Container::value_type		value_type;
typedef typename Container::size_type		size_type;
typedef typename Container::reference		reference;
typedef typename Container::const_reference	const_reference;

//	CONSTRUCTION / DESTRUCTION / ASSIGNATION
explicit	stack( const Container & cont = Container() ) :
	c(cont)												{ return ; }

~stack(void)											{ }

stack&		operator=( const stack& other )
{
	this->c = other.c;
	return (*this);
}

//	MEMBER FUNCTIONS
bool			empty( void ) const			{ return (this->c.empty()); }
size_type		size( void ) const			{ return (this->c.size()); }
void			push( const value_type & value )
{
	this->c.push_back(value);
}
void			pop( void )	
{
	this->c.pop_back();
}
reference		top( void )					{ return (this->c.back()); }
const_reference	top( void ) const			{ return (this->c.back()); }

template<class _T, class _Container>
friend bool operator==(const stack<_T, _Container>&, const stack<_T, _Container>&);
template<class _T, class _Container>
friend bool operator!=(const stack<_T, _Container>&, const stack<_T, _Container>&);
template<class _T, class _Container>
friend bool operator<(const stack<_T, _Container>&, const stack<_T, _Container>&);
template<class _T, class _Container>
friend bool operator>(const stack<_T, _Container>&, const stack<_T, _Container>&);
template<class _T, class _Container>
friend bool operator<=(const stack<_T, _Container>&, const stack<_T, _Container>&);
template<class _T, class _Container>
friend bool operator>=(const stack<_T, _Container>&, const stack<_T, _Container>&);

//	MEMBER OBJECTS
protected:
Container	c;

};		// class stack

template	<class T, class Container>
bool operator==(const stack<T, Container> & lhs, const stack<T, Container> & rhs )
{
	if (&lhs == &rhs) return (true);
	else
		return (lhs.c == rhs.c);
}
template	<class T, class Container>
bool operator!=(const stack<T, Container> & lhs, const stack<T, Container> & rhs )
{
	if (&lhs == &rhs) return (false);
	else 
		return (lhs.c != rhs.c);
}
template	<class T, class Container>
bool operator<(const stack<T, Container> & lhs, const stack<T, Container> & rhs )
{
	if (&lhs == &rhs) return (false);
	else 
		return (lhs.c < rhs.c);
}	
template	<class T, class Container>
bool operator>(const stack<T, Container> & lhs, const stack<T, Container> & rhs )
{
	if (&lhs == &rhs) return (false);
	else 
		return (lhs.c > rhs.c);
}	
template	<class T, class Container>
bool operator<=(const stack<T, Container> & lhs, const stack<T, Container> & rhs )
{
	if (&lhs == &rhs) return (true);
	else
		return (lhs.c <= rhs.c);
}	
template	<class T, class Container>
bool operator>=(const stack<T, Container> & lhs, const stack<T, Container> & rhs )
{
	if (&lhs == &rhs) return (true);
	else
		return (lhs.c >= rhs.c);
}

}		// namespace ft

#endif	// STACK_HPP
