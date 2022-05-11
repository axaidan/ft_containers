#ifndef STACK_HPP
# define STACK_HPP

# include <vector>
# include <iostream>

namespace ft
{
	template<class T, class Container = std::vector<T> >
		class stack
		{
			// MEMBER TYPES
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

			public:
			//	CONSTRUCTION / DESTRUCTION / ASSIGNATION
			explicit	stack( const Container & cont = Container() ) :
				c(cont)												{ return ; }

			~stack(void)											{ is->c.~Container(); }

			stack&		operator=( const stack& other )
			{
				this->c = other.c;
				return (*this);
			}

			//	MEMBER FUNCTIONS
			bool			empty() const							{ return (this->c.empty()); }
			size_type		size() const							{ return (this->c.size()); }
			void			push( const value_type & value )		{ this->c.push_back(value); }
			void			pop( void )								{ this->c.pop_back(); }
			reference		top( void )								{ return (this->c.back()); }
			const_reference	top( void ) const						{ return (this->c.back()); }

			//	OPERATORS OVERLOAD
			bool operator==(const stack<T, Container> & rhs )
			{
				if (this == &rhs) return (true);
				else return (this->c == rhs.c);
			}
			bool operator!=(const stack<T, Container> & rhs )
			{
				if (this == &rhs) return (false);
				else return (this->c != rhs.c);
			}
			bool operator<(const stack<T, Container> & rhs )
			{
				if (this == &rhs) return (false);
				else return (this->c < rhs.c);
			}	
			bool operator>(const stack<T, Container> & rhs )
			{
				if (this == &rhs) return (false);
				else return (this->c > rhs.c);
			}	
			bool operator<=(const stack<T, Container> & rhs )
			{
				if (this == &rhs) return (true);
				else return (this->c <= rhs.c);
			}	
			bool operator>=(const stack<T, Container> & rhs )
			{
				if (this == &rhs) return (true);
				else return (this->c >= rhs.c);
			}	

			//	MEMBER OBJECTS
			protected:
			Container	c;
		};
}

#endif // STACK_HPP
