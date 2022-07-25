#include "ContainsAlloc.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <list>

#ifndef STD
 #define NAMESPACE ft
 #include "vector.hpp"
#else
 #define NAMESPACE std
 #include <vector>
#endif

#define T int
#define VAL1 42
#define VAL2 1337
#define VAL3 -1

#define FORMAT1	"===\t"
#define FORMAT2	"\t===\t"

#define N 10

using namespace NAMESPACE;

::vector<T>		g_v1;
::vector<T>		g_v2;
std::list<T>	g_l1;
std::string		context;

void	rand_push_back(vector<T> & v)
{
	int	n;

	for (int i = 0 ; i < N * 2 ; i++)
	{
		n = rand() % 3;
		if (n == 1)
			v.push_back(VAL1);
		else if (n == 2)
			v.push_back(VAL2);
		else
			v.push_back(VAL3);
	}
}

void	display_capacity(const ::vector<T> & v, std::string context)
{
	std::cout << std::boolalpha;
	std::cout << FORMAT1 << "display_capacity() :" << std::endl;
	std::cout << FORMAT1 << "CONTEXT : " << context << std::endl;
	std::cout << FORMAT2 << "v.empty()\t=\t" << v.empty() << std::endl;
	std::cout << FORMAT2 << "v.size()\t=\t" << v.size() << std::endl;
	std::cout << FORMAT2 << "v.capacity()\t=\t" << v.capacity() << std::endl;
	std::cout << FORMAT2 << "v.max_size()\t=\t" << v.max_size() << std::endl;
	std::cout << std::endl;
}

void	display_content(const ::vector<T> & v, std::string context)
{
	std::cout << FORMAT1 << "display_content() :" << std::endl;
	std::cout << FORMAT1 << "CONTEXT : " << context << std::endl;
	::vector<T>::const_iterator	it	=	v.begin();
	::vector<T>::const_iterator	ite	=	v.end();
	size_t						i	=	0;

	if (v.empty() == true)
	{
		std::cout << FORMAT2 << "NO CONTENT" << std::endl << std::endl;
		return ;
	}
	while (it != ite)
	{
		std::cout << FORMAT2 << "v[" << std::setw(7) << i 
			<< "]\t=\t" << v[i] << std::endl;
		it++;
		i++;
	}
	std::cout << std::endl;
}

void	display_relationals(const vector<T> & v1,
		const vector<T> & v2,
		std::string context)
{
	std::cout << std::boolalpha;
	std::cout << FORMAT1 << "display_relationals() :" << std::endl;
	std::cout << FORMAT1 << "CONTEXT : " << context << std::endl;
	std::cout << FORMAT2 << "(v1 == v2)\t=\t" << (v1 == v2) << std::endl;
	std::cout << FORMAT2 << "(v1 != v2)\t=\t" << (v1 != v2) << std::endl;
	std::cout << FORMAT2 << "(v1 <  v2)\t=\t" << (v1 < v2) << std::endl;
	std::cout << FORMAT2 << "(v1 <= v2)\t=\t" << (v1 <= v2) << std::endl;
	std::cout << FORMAT2 << "(v1 >  v2)\t=\t" << (v1 >  v2) << std::endl;
	std::cout << FORMAT2 << "(v1 >= v2)\t=\t" << (v1 >= v2) << std::endl;
	std::cout << std::endl;
}

void	display_elem_access(const vector<T> & v,
		std::string context)
{
	std::cout << std::boolalpha;
	std::cout << FORMAT1 << "display_elem_access() :" << std::endl;
	std::cout << FORMAT1 << "CONTEXT : " << context << std::endl;

	if (v.empty() == true)
	{
		std::cout << FORMAT2 << "NO CONTENT" << std::endl << std::endl;
		return ;
	}
	std::cout << FORMAT2 << "v.front()\t=\t" << v.front() << std::endl;
	std::cout << FORMAT2 << "v.at(0)\t\t=\t" << v.at(0) << std::endl;
	std::cout << FORMAT2 << "v[0]\t\t=\t" << v[0] << std::endl;
	std::cout << FORMAT2 << "v.back()\t=\t" << v.back() << std::endl;
	std::cout << FORMAT2 << "v.at(size()-1)\t=\t" << v.at(v.size() - 1)
		<< std::endl;
	std::cout << FORMAT2 << "v[v.size()-1]\t=\t" << v[v.size() - 1]
		<< std::endl;
	std::cout << std::endl;
}

void	construction(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tCONSTRUCTION\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	//	CONSTRUCTORS
	//	vector(void)	
	::vector<T>	v;
 	context = "default constructed empty vector";
	display_capacity(v, context);
	display_content(v, context);

	//	vector(n, val)
	::vector<T>	v_fill1(10, VAL1);
	context = "fill constructed 10 elems";
	display_capacity(v_fill1, context);
	display_content(v_fill1, context);
	::vector<T>	v_fill2(0, VAL1);
	context = "fill constructed 0 elem";
	display_capacity(v_fill2, context);
	display_content(v_fill2, context);
	//	vector(first, last)
	::vector<T>	v_range1(v_fill1.begin(), v_fill1.end() - 2);
	context = "range constructed from v_fill1 begin/end - 2";
	display_capacity(v_range1, context);
	display_content(v_range1, context);

	::vector<T>	v_range2(v_fill1.begin(), v_fill1.begin());
	context = "range constructed from v_fill1 begin/begin";
	display_capacity(v_range2, context);
	display_content(v_range2, context);

	//	vector(src)
	::vector<T>	v_copy(v_fill1);
	context = "copy constructed from v_fill1";
	display_capacity(v_copy, context);
	display_content(v_copy, context);
	display_relationals(v_fill1, v_copy, context);
}

void	assignation(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tASSIGNATION\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;
//	ASSIGNATION
	vector<T>	v1(N, VAL3);
	vector<T>	v2;
	vector<T>	v3;

	v2 = v1;
	context = "vector<T> v1(N, VAL3); v2 = v1; with v1 bigger than v2";
	display_capacity(v2, context);
	display_content(v2, context);
	display_relationals(v1, v2, context);
	v2 = v3;
	context = "vector<T> v3; v2 = v3; v2 is empty";
	display_capacity(v2, context);
	display_content(v2, context);
	display_relationals(v1, v2, context);
	rand_push_back(v3);
	context = "rand_push_back(v3);";
	display_capacity(v3, context);
	display_content(v3, context);
	display_relationals(v1, v3, context);
	v3 = v3;
	context = "v3 = v3; self assignation test";
	display_capacity(v3, context);
	display_content(v3, context);
	v3 = v1 = v2;
	context = "v3 = v2 = v1; multiple assignations test";
	display_capacity(v3, context);
	display_content(v3, context);
	display_relationals(v1, v3, context);
	display_relationals(v1, v2, context);
}

void	capacity_changes(void)
{

	std::cout << "=================================" << std::endl;
	std::cout << "=\tCAPACITY CHANGES\t=" << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << std::endl;

	vector<T>	v;

	rand_push_back(v);
	std::cout << FORMAT1 << "vector<T> v; rand_push_back(v);" << std::endl;
	//	resize
	//		if n < size
	v.resize(v.size() / 2);
	context = "v.resize(v.size() / 2); resizing with (n < size)";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	//		if n > size
	v.resize(v.size() * 3, VAL2);
	context = "v.resize(v.size() * 3); resizing with (n > size)";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	//		if n > size && n > capacity
	v.resize(v.capacity() + 3, VAL1);
	context = "v.resize(v.capacity() * 2); resizing with (n > capacity)";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	v.resize(N, VAL1);
	std::cout << FORMAT1 << "v.resize(N);" << std::endl;

	//		if n > capacity
	v.reserve(v.capacity() + 1);
	context = "v.reserve(v.capacity() + 1); reserving one more elem";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	//		if n == capacity
	v.reserve(v.capacity());
	context = "v.reserve(v.capacity()); reserving same capacity";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	//		if n < capacity
	v.reserve(v.capacity());
	context = "v.reserve(v.capacity() - 1); reserving lesser capacity";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	//		if n > max_size()
	try {
		v.reserve(v.capacity());
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	context = "v.reserve(v.max_size() + 1); exception thrown";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	
}

void	element_access(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tELEMENT ACCESS\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	vector<T>		v(N, VAL3);
	vector<T>		bckp(v);
	size_t			size;
	T				copy;

	copy = VAL2;
	rand_push_back(v);
	const vector<T>	const_v(v);
	size = v.size();

	//	operator[]
	std::cout << FORMAT1 << "operator[] access / assignation" << std::endl;
	for (size_t i = 0 ; i < size ; i++)
	{
		std::cout << FORMAT2 << v[i] << std::endl;
		v[i] = copy;
	}
	std::cout << std::endl;

	context = "v[i++] = copy; each member assigned";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	for (size_t i = 0 ; i < size ; i++)
	{
		copy = const_v[i];
//		const_v[i] = copy;	// 	WON'T COMPILE - const_reference
	}

	//	non-const access
	copy = v.front();
	v.front() = copy;
	copy = v.back();
	v.front() = copy;

	//	const access
	copy = const_v.front();
//	const_v.front() = copy;	// 	WON'T COMPILE - const_reference
	copy = const_v.back();
//	const_v.front() = copy;	// 	WON'T COMPILE - const_reference

	//	at() over-bounds exception test
	try {
		v.at(v.size());
	}
	catch (std::exception & e) {
		std::cerr << e.what();
	}

	copy = VAL3;
	v = const_v;
	//	at() retrieval and assignation
	std::cout << FORMAT1 << "at() access / assignation" << std::endl;
	for (size_t i = 0 ; i < size ; i++)
	{
		copy = v.at(i);
		v.at(i) = copy;
		copy = const_v.at(i);
		std::cout << FORMAT2 << copy << std::endl;
//		const_v.at(i) = copy;	// 	WON'T COMPILE - const_reference

	}
	context = "after at() retrieval and assignation test";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	context = "after at() retrieval and assignation test - const version";
	display_capacity(const_v, context);
	display_content(const_v, context);
	display_elem_access(const_v, context);
}

int		main(void)
{
	srand(N);
	construction();
	assignation();
	capacity_changes();
	element_access();

	
	return (0);
}
