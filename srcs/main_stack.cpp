#include "ContainsAlloc.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <list>

#ifndef STD
 #define NAMESPACE ft
 #include "stack.hpp"
#else
 #define NAMESPACE std
 #include <stack>
#endif

#ifdef CONTAINS_ALLOC
 #define T ContainsAlloc
 #define VAL1 ContainsAlloc("quarante deux")
 #define VAL2 ContainsAlloc("mille trois cent trente sept")
 #define VAL3 ContainsAlloc("moins un")
#else
	#ifdef STRING
	 #define T std::string
	 #define VAL1 std::string("quarante deux")
	 #define VAL2 std::string("mille trois cent")
	 #define VAL3 std::string("moins un")
	#else
		#ifdef FLOAT
		 #define T float
		 #define VAL1 1983.128f
		 #define VAL2 0.01f
		 #define VAL3 -3.14152589171f
		#else
		 #define T int
		 #define VAL1 42
		 #define VAL2 1337
		 #define VAL3 -1
		#endif
	#endif
#endif

#ifndef N
// #define N 10000		//	NOT 0 OR SEGFAULT
 #define N 100			//	NOT 0 OR SEGFAULT
						//	NOT < 0	OR LONG
#endif

#define FMT1	"===\t"
#define FMT2	"\t===\t"


using namespace NAMESPACE;

std::string		context;

template	<class U>
void	rand_push_back(U & v)
{
	int	n;

	for (int i = 0 ; i < N ; i++)
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

void	rand_push(stack<T> & v)
//template<Container = vector<T> >
//void	rand_push(stack<T, Container> & v)
{
	int	n;

	for (int i = 0 ; i < N ; i++)
	{
		n = rand() % 3;
		if (n == 1)
			v.push(VAL1);
		else if (n == 2)
			v.push(VAL2);
		else
			v.push(VAL3);
	}
}

template<class Container>
void	top_and_pop(stack<T, Container> &s, std::string context, int n = -1)
{
	int	i;

	std::cout << FMT1 << "top_and_pop() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;
	if (s.size() == 0)
			std::cout << FMT1 << "NO CONTENT" << std::endl;
	i = 0;
	if (n != -1)
		while (i < n)
		{
			std::cout << FMT1 << "s.top()\t=\t" << s.top()
				<< "\tpop()ing" << std::endl;
			s.pop();
			i++;
		}
	else
		while (s.size() != 0)
		{
			std::cout << FMT1 << "s.top()\t=\t" << s.top() 
				<< "\tpop()ing" << std::endl;
			s.pop();
		}
	std::cout << std::endl;
}

template<class Container>
void	display_capacity(const ::stack<T, Container> & v, std::string context)
{
	std::cout << std::boolalpha;
	std::cout << FMT1 << "display_capacity() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;
	std::cout << FMT2 << "v.empty()\t=\t" << v.empty() << std::endl;
	std::cout << FMT2 << "v.size()\t=\t" << v.size() << std::endl;
	std::cout << std::endl;
}

template<class U>
void	display_relationals(const U & v1,
		const U & v2,
		std::string context)
{
	std::cout << std::boolalpha;
	std::cout << FMT1 << "display_relationals() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;
	std::cout << FMT2 << "(v1 == v2)\t=\t" << (v1 == v2) << std::endl;
	std::cout << FMT2 << "(v1 != v2)\t=\t" << (v1 != v2) << std::endl;
	std::cout << FMT2 << "(v1 <  v2)\t=\t" << (v1 < v2) << std::endl;
	std::cout << FMT2 << "(v1 <= v2)\t=\t" << (v1 <= v2) << std::endl;
	std::cout << FMT2 << "(v1 >  v2)\t=\t" << (v1 >  v2) << std::endl;
	std::cout << FMT2 << "(v1 >= v2)\t=\t" << (v1 >= v2) << std::endl;
	std::cout << std::endl;
}

int		main(void)
{
	srand(N);
	stack<T>				sv;

	context = "created empty stack with default underlying container";
	display_capacity(sv, context);

	rand_push(sv);
	context = "rand_push()ed N elems";
	display_capacity(sv, context);

	context = "display and pop half";
	top_and_pop(sv, context, sv.size() / 2);
	display_capacity(sv, context);

	stack<T>				sv2;
	context = "created second empty stack with default underlying container";
	display_capacity(sv2, context);
	display_relationals(sv, sv2, context);

	std::list<T>	l;
	rand_push_back(l);
	context = "created an std::list, filled it with N elems, and a stack from it";

	stack<T, std::list<T> >	sl(l);
	display_capacity(sl, context);
	top_and_pop(sl, context);


	return (0);
}
