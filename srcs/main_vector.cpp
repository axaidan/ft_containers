#include "ContainsAlloc.hpp"

#include <iostream>
#include <iomanip>
#include <string>

#ifndef STD
 #define NAMESPACE ft
 #include "vector.hpp"
#else
 #define NAMESPACE std
 #include <vector>
#endif

#define T int
#define VAL1 42
#define VAL2 0
#define VAL3 -1000

#define FORMAT1	"===\t"
#define FORMAT2	"\t===\t"

using namespace NAMESPACE;

::vector<T>	g_v;

void	display_capacity(::vector<T> & v, std::string context)
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

void	display_content(::vector<T> & v, std::string context)
{
	std::cout << FORMAT1 << "display_content() :" << std::endl;
	std::cout << FORMAT1 << "CONTEXT : " << context << std::endl;
	::vector<T>::iterator	it	=	v.begin();
	::vector<T>::iterator	ite	=	v.end();
	size_t					i	=	0;

	if (v.empty() == true)
		std::cout << FORMAT2 << "NO CONTENT" << std::endl;
	while (it != ite)
	{
		std::cout << FORMAT2 << "v[" << std::setw(7) << i 
			<< "]\t=\t" << v[i] << std::endl;
		it++;
		i++;
	}
	std::cout << std::endl;
}

void	display_relationals(vector<T> & v1, vector<T> & v2,
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
	std::cout << FORMAT2 << "(v1 <= v2)\t=\t" << (v1 >= v2) << std::endl;
	std::cout << std::endl;
}

void	construction_assignation(void)
{
	std::string	context;

	std::cout << "=========================================" << std::endl;
	std::cout << "=	CONSTRUCTION/ASSIGNATION	=" << std::endl;
	std::cout << "=========================================" << std::endl;
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
	::vector<T>	v_copy(v_fill1);
	context = "copy constructed from v_fill1";
	display_capacity(v_copy, context);
	display_content(v_copy, context);
	display_relationals(v_fill1, v_copy, context);
	//	ASSIGNATION
	v_copy = v_range1;
	context = "v_copy = v_range1";
	display_capacity(v_copy, context);
	display_content(v_copy, context);
	display_relationals(v_copy, v_range1, context);
}

int		main(void)
{

	construction_assignation();
	
	return (0);
}
