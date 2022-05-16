#ifndef VECTOR_INSTANCIATION_HPP
# define VECTOR_INSTANCIATION_HPP

typedef typename ft::vector::allocator_type	allocator_type;

template<class T>
explicit ft::vector::vector(const allocator_type& alloc = allocator_type()) :
	_allocator(alloc),
	_begin(NULL),
	_end(NULL),
	_pastEnd(NULL)
{
	return ;
}

#endif // VECTOR_CONSTRUCTORS_DESTRUCTOR_HPP
