#include "ContainsAlloc.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <list>

#ifndef STD
 #define NAMESPACE ft
 #include "map.hpp"
#else
 #define NAMESPACE std
 #include <map>
#endif

/*
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
*/

#ifdef STRING
# define K std::string
# define KVAL1 std::string("trois virg quatorze")
# define KVAL2 std::string("moins un virgule un")
# define KVAL3 std::string("zero virgule zero")
# define LEN 11
#else
# define K int
# define KVAL1 314
# define KVAL2 -1
# define KVAL3 0
#endif

#define T		float
#define TVAL1	3.14f
#define TVAL2	-1.1f
#define TVAL3	0.0f

#define P		NAMESPACE::pair<K, T>

#ifndef N
 #define N 10			//	NOT 0 OR SEGFAULT
						//	NOT < 0	OR LONG
#endif

#define FMT1	"===\t"
#define FMT2	"\t===\t"


using namespace NAMESPACE;

std::string		context;

K		rand_K(void)
{
	K			k;
	static int	sign = 0;

#ifdef STRING
	size_t	i = 0;
	char	c;
	while (i < LEN - 1)
	{
		//c = (rand() % (126 - 33)) + 33;
		c = (rand() % ('A' - 'Z')) + 'A';
		k.push_back(c);
		i++;
	}
	k[LEN - 1] = '\0';
#else
	k = rand();
	k = k % ((N * 10) + 1);
	if (sign % 2 == 0)
		k = -k;
#endif
	sign++;
	return (k);
}

void	rand_insert(map<K, T> & m)
{
	pair<K, T>	p;
	int	 		n;

	for (int i = 0 ; i < N ; i++)
	{
		n = rand();

		p.first = rand_K();

		n %= 3;
		if (n == 1)
			p.second = TVAL1;
		else if (n == 2)
			p.second = TVAL2;
		else
			p.second = TVAL3;
		m.insert(p);
	}
}

void	display_capacity(const ::map<K, T> & m, std::string context)
{
	std::cout << std::boolalpha;
	std::cout << FMT1 << "display_capacity() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;
	std::cout << FMT2 << "m.empty()\t=\t" << m.empty() << std::endl;
	std::cout << FMT2 << "m.size()\t=\t" << m.size() << std::endl;
	std::cout << FMT2 << "m.max_size()\t=\t" << m.max_size() << std::endl;
	std::cout << std::endl;
}

void	display_content(const ::map<K, T> & m, std::string context)
{
	std::cout << FMT1 << "display_content() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;
	::map<K, T>::const_iterator	it	=	m.begin();
	::map<K, T>::const_iterator	ite	=	m.end();

	if (m.empty() == true)
	{
		std::cout << FMT2 << "NO CONTENT" << std::endl << std::endl;
		return ;
	}
	while (it != ite)
	{
		std::cout << FMT2 << "m[" << std::setw(7) << it->first
			<< "]\t=\t" << it->second << std::endl;
		it++;
	}
	std::cout << std::endl;
}

template<class U>
void	display_relationals(const U & m1,
		const U & m2,
		std::string context)

{
	std::cout << std::boolalpha;
	std::cout << FMT1 << "display_relationals() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;
	std::cout << FMT2 << "(m1 == m2)\t=\t" << (m1 == m2) << std::endl;
	std::cout << FMT2 << "(m1 != m2)\t=\t" << (m1 != m2) << std::endl;
	std::cout << FMT2 << "(m1 <  m2)\t=\t" << (m1 < m2) << std::endl;
	std::cout << FMT2 << "(m1 <= m2)\t=\t" << (m1 <= m2) << std::endl;
	std::cout << FMT2 << "(m1 >  m2)\t=\t" << (m1 >  m2) << std::endl;
	std::cout << FMT2 << "(m1 >= m2)\t=\t" << (m1 >= m2) << std::endl;
	std::cout << std::endl;
}

/*
void	display_elem_access(const vector<T> & v,
		std::string context)
{
	std::cout << std::boolalpha;
	std::cout << FMT1 << "display_elem_access() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;

	if (v.empty() == true)
	{
		std::cout << FMT2 << "NO CONTENT" << std::endl << std::endl;
		return ;
	}
	std::cout << FMT2 << "v.front()\t=\t" << v.front() << std::endl;
	std::cout << FMT2 << "v.at(0)\t\t=\t" << v.at(0) << std::endl;
	std::cout << FMT2 << "v[0]\t\t=\t" << v[0] << std::endl;
	std::cout << FMT2 << "v.back()\t=\t" << v.back() << std::endl;
	std::cout << FMT2 << "v.at(size()-1)\t=\t" << v.at(v.size() - 1)
		<< std::endl;
	std::cout << FMT2 << "v[v.size()-1]\t=\t" << v[v.size() - 1]
		<< std::endl;
	std::cout << std::endl;
}

void	display_iterator_functions(vector<T> & v,
		std::string context)
{
	//	UNDEFINED IF EMPTY VECTOR
	std::cout << std::boolalpha;
	std::cout << FMT1 << "display_iterator_functions() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;
	std::cout << FMT2 << "*(v.begin())\t=\t" << *(v.begin()) << std::endl;
	std::cout << FMT2 << "*(v.end() - 1)\t=\t" << *(v.end() - 1) << std::endl;
	std::cout << FMT2 << "*(v.rbegin())\t=\t" << *(v.rbegin()) << std::endl;
	std::cout << FMT2 << "*(v.rend() - 1)\t=\t" << *(v.rend() - 1) << std::endl;
	std::cout << std::endl;
}
*/

void	construction(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tCONSTRUCTION\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	//	CONSTRUCTORS
	//	map(void)	
	::map<K, T>	m;
 	context = "default constructed empty map m";
	display_capacity(m, context);
	display_content(m, context);

	rand_insert(m);
	context = "rand_insert()ed values in m";
	display_capacity(m, context);
	display_content(m, context);

	//	map(first, last)
	::map<K, T>	m_range1(m.begin(), m.end());
	context = "range constructed from m begin/end";
	display_capacity(m_range1, context);
	display_content(m_range1, context);

	//	map(same_it, same_it)
	::map<K, T>	m_range2(m.begin(), m.begin());
	context = "range constructed from m begin/begin";
	display_capacity(m_range2, context);
	display_content(m_range2, context);

	//	map(begin, begin + size() / 2)
	::map<K, T>::iterator 	it = m.begin();
	for (size_t i = 0 ; i < m.size() / 2 ; i++)
		it++;
	::map<K, T>	m_range3(m.begin(), it);
	context = "range constructed from m begin/half";
	display_capacity(m_range3, context);
	display_content(m_range3, context);
	::map<K, T>	m_range4(it, m.end());
	context = "range constructed from m half/end";
	display_capacity(m_range4, context);
	display_content(m_range4, context);

	//	map(src)
	::map<K, T>	m_copy(m_range1);
	context = "copy constructed from m_range1";
	display_capacity(m_copy, context);
	display_content(m_copy, context);
	display_relationals(m, m_copy, context);
}

void	assignation(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tASSIGNATION\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;
//	ASSIGNATION
	map<K, T>	m1;
	map<K, T>	m2;
	map<K, T>	m3;

	context = "(rand_insert() * 2) filling m1";
	rand_insert(m1);
	display_capacity(m2, context);
	display_content(m2, context);

	m2 = m1;
	context = "map<K, T> m1(N, VAL3); m2 = m1; with m1 bigger than m2";
	display_capacity(m2, context);
	display_content(m2, context);
	display_relationals(m1, m2, context);
	m2 = m3;
	context = "map<K, T> m3; m2 = m3; m2 is empty";
	display_capacity(m2, context);
	display_content(m2, context);
	display_relationals(m1, m2, context);
	rand_insert(m3);
	context = "rand_insert(m3);";
	display_capacity(m3, context);
	display_content(m3, context);
	display_relationals(m1, m3, context);
//	m3 = m3;	//	WON'T COMPILE AT SCHOOL
//	context = "m3 = m3; self assignation test";
//	display_capacity(m3, context);
//	display_content(m3, context);
	m3 = m1 = m2;
	context = "m3 = m2 = m1; multiple assignations test";
	display_capacity(m3, context);
	display_content(m3, context);
	display_relationals(m1, m3, context);
}

void	element_access(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tELEMENT ACCESS\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	map<K, T>		m1;
	K				key1;

	m1[KVAL1] = TVAL1;
	m1[KVAL2] = TVAL2;
	m1[KVAL3] = TVAL3;
	context = "m1[KVAL1] = VAL1; m1[KVAL2] = VAL2; m1[KVAL3] = VAL3;"; 
	display_capacity(m1, context);
	display_content(m1, context);
	
	context = "rand_insert() filling m1";
	rand_insert(m1);
	rand_insert(m1);
	display_capacity(m1, context);
	display_content(m1, context);

	key1 = m1.begin()->first;
//	while (it != ite)
//	{
	std::cout << FMT1 << "key1 = m1.begin().first;" << std::endl;
	if (m1[key1] == TVAL1)
	{
		m1[key1] = TVAL3;
		std::cout << FMT2 << "m1[key1] = TVAL3;" << std::endl;
	}
	else
	{
		m1[key1] = TVAL1;
		std::cout << FMT2 << "m1[key1] = TVAL1;" << std::endl;
	}
//	}
	context = "replaced existing key with another value";
	display_capacity(m1, context);
	display_content(m1, context);
}

/*
void	modifiers(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tMODIFIERS\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	vector<T>					v;
	vector<T>::iterator			it;
	vector<T>::const_iterator	cit;
	std::list<T>				l;

	//	push_back(val);
	for (int i = 0 ; i < N * 2 ; i++)
		v.push_back(VAL2);
	context = "pushed back N * 2 elements";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	//	pop_back();	// undef behavior if v empty
	for (int i = 0 ; i < N ; i++)
		v.pop_back();
	context = "pop_back()ed N last elements";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	//	insert(it pos, val);
	int							i;
	i = 0;
	for (it = v.begin() ; it != v.end() ; it += 1, i++)
		if (i % 2 == 0)
			it = v.insert(it, VAL3); 
	context = "inserted VAL3 between each element";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	size_t						cpct;
	cpct = v.capacity();
	while (v.size() < cpct + N)
		v.insert(v.begin(), VAL2);
	context = "inserted VAL3 until reallocation => while (v.size() < cpct + N)";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	//	insert(it pos, n, val);
	v.insert(v.end(), N, VAL1);
	v.insert(v.end(), N, VAL2);
	v.insert(v.end(), N, VAL3);
	context = "inserted N*VAL1, N*VAL2, N*VAL3 at v.end()";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	//	insert(it pos, first, last);
	vector<T>		v2(v);
	v.insert(v.end() - v.size() / 2, v.begin(), v.end());
	context = "inserted v in the middle of itself";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	for (int i = 1 ; i < N ; i++)
		l.push_back(VAL1);
	v.insert(v.end(), l.begin(), l.end());
	context = "inserted a list l at the end of v";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	//	erase(it pos);
	v.erase(v.begin());
	context = "erased v.begin()";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	it = v.begin();
	i = 0;
	while (it != v.end())
	{
		if (i % 2 == 0)
			v.erase(it);
		i++;
		it++;
	}
	context = "erased all pair indexes";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	
	//	erase(first, last);
	v.erase(v.begin(), v.begin() + v.size() / 2);
	context = "erased first half of vector";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	vector<T>	copy(v);
	
	v.erase(v.begin(), v.end());
	context = "erased all elements";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	//	assign(first, last);
	v.assign(copy.begin(), copy.end());
	context = "assigned copy to v";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	display_relationals(v, copy, context);

	//	assign(n, val);
	v.assign(N * 5, VAL1);
	context = "assigned (N * 5) VAL1";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);

	//	swap(vector x);
	v.swap(copy);
	context = "swapped v and copy";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	display_relationals(v, copy, context);
	
	v.swap(v);
	context = "v self swap";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	
	v.swap(copy);
	copy.clear();
	v.swap(copy);
	context = "swapped v with cleared copy";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
}

void	iterator_functions(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tITERATORS\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	vector<T>								v;
	//	CONSTRUCTION
	vector<T>::iterator						it;
	vector<T>::iterator						ite(it);
	vector<T>::const_iterator				cit;
	vector<T>::const_iterator				cite(cit);
	vector<T>::reverse_iterator				rit;
	vector<T>::reverse_iterator				rite(rit);
	vector<T>::const_reverse_iterator		crit;
	vector<T>::const_reverse_iterator		crite(crit);

	rand_insert(v);
	v.insert(v.end(), N, VAL1);
	v.insert(v.end() - v.size() / 2, N, VAL2);
	context = "created new vector";
	display_capacity(v, context);
	display_content(v, context);
	display_elem_access(v, context);
	display_iterator_functions(v, context);

	//	ITERATION / DEREFERENCING
	std::cout << FMT1 << "iterator iteration" << std::endl;
	it = v.begin();
	cite = v.end();
	while (it != cite)
	{
		std::cout << FMT2 << *it << std::endl;
		it++;
	}
	std::cout << std::endl;
	std::cout << FMT1 << "reverse_iterator iteration" << std::endl;
	rit = v.rbegin();
	crite = v.rend();
	while (rit != crite)
	{
		std::cout << FMT2 << *rit << std::endl;
		rit++;
	}
	std::cout << std::endl;
	std::cout << FMT1 << "const_iterator iteration" << std::endl;
	cit = v.begin();
	cite = v.end();
	while (cit != cite)
	{
		std::cout << FMT2 << *cit << std::endl;
		cit++;
	}
	std::cout << std::endl;
	std::cout << FMT1 << "const_reverse_iterator iteration" << std::endl;
	crit = v.rbegin();
	crite = v.rend();
	while (crit != crite)
	{
		std::cout << FMT2 << *crit << std::endl;
		crit++;
	}
	std::cout << std::endl;

	//	RELATIONALS
	ite = it;
	context = "ite = it; it and ite relationals";
	display_relationals(it, ite, context);
	it--;
	context = "it--; it and ite relationals";
	display_relationals(it, ite, context);
	cite = cit;
	context = "cite = cit; cit and cite relationals";
	display_relationals(cit, cite, context);
	cit--;
	context = "cit--; cit and cite relationals";
	display_relationals(cit, cite, context);

	rite = rit;
	context = "rite = rit; rit and rite relationals";
	display_relationals(rit, rite, context);
	rit--;
	context = "rit--; rit and rite relationals";
	display_relationals(rit, rite, context);
	crite = crit;
	context = "crite = crit; crit and crite relationals";
	display_relationals(crit, crite, context);
	crit--;
	context = "crit--; crit and crite relationals";
	display_relationals(crit, crite, context);

	//	ASSIGNATION
	it = v.begin();
	cit = v.begin();
	rit = v.rbegin();
	crit = v.rbegin();

	ite = it;
	*it = VAL3;
	std::cout << FMT1 << "ite = it; *it = VAL3;" << std::endl;
	std::cout << FMT1 << "(*ite == VAL3)\t=\t" << (*ite == VAL3) << std::endl;
	std::cout << FMT1 << "(ite == it)\t=\t" << (ite == it) << std::endl;
	std::cout << std::endl;
	rite = rit;
	*rit = VAL1;
	std::cout << FMT1 << "rite = rit; *rit = VAL1;" << std::endl;
	std::cout << FMT1 << "(*rite == VAL1)\t=\t" << (*rite == VAL1) << std::endl;
	std::cout << FMT1 << "(rite == rit)\t=\t" << (rite == rit) << std::endl;
	std::cout << std::endl;
	cite = cit;
//	*cit = VAL3;	// WON'T COMPILE
	std::cout << FMT1 << "cite = cit;" << std::endl;
	std::cout << FMT1 << "(cite == cit)\t=\t" << (cite == cit) << std::endl;
	std::cout << std::endl;
	crite = crit;
//	*crit = VAL1;	// WON'T COMPILE
	std::cout << FMT1 << "crite = crit;" << std::endl;
	std::cout << FMT1 << "(cite == crit)\t=\t" << (crite == crit) << std::endl;
	std::cout << std::endl;
	
	//	PRE/POST WEIRD ITERATION
	std::cout << FMT1 << "weird iteration" << std::endl;
	it = v.begin();
	ite = v.end();
	std::cout << FMT2 << "*(it++)\t=\t" << *(it++) << std::endl;
	std::cout << FMT2 << "*(--it)\t=\t" << *(--it) << std::endl;
	std::cout << FMT2 << "*(++it)\t=\t" << *(++it) << std::endl;
	std::cout << FMT2 << "*(it--)\t=\t" << *(it--) << std::endl;
	it++;
	std::cout << std::endl;

	std::cout << FMT1 << "reverse weird iteration" << std::endl;
	rit = v.rbegin();
	rite = v.rend();
	std::cout << FMT2 << "*(rit++)\t=\t" << *(rit++) << std::endl;
	std::cout << FMT2 << "*(--rit)\t=\t" << *(--rit) << std::endl;
	std::cout << FMT2 << "*(++rit)\t=\t" << *(++rit) << std::endl;
	std::cout << FMT2 << "*(rit--)\t=\t" << *(rit--) << std::endl;
	rit++;
	std::cout << std::endl;

	//	it + n
	it = v.begin();
	std::cout << FMT1 << "it = v.begin();" << std::endl;
	std::cout << FMT2 << "*(it + size() / 2)\t=\t" << *(it + v.size() / 2) << std::endl;
	//	it += n
	it += v.size() / 2;
	std::cout << FMT1 << "*it += size() / 2;" << std::endl;
	std::cout << FMT2 << "*it\t\t\t=\t" << *it <<  std::endl;
	//	it - n
	std::cout << FMT2 << "*(it - size() / 2)\t=\t" << *(it - v.size() / 2) << std::endl;
	//	it-= n
	std::cout << FMT1 << "*it -= size() / 2;" << std::endl;
	std::cout << FMT2 << "*it\t\t\t=\t" << *it << std::endl;
	std::cout << std::endl;
	//	it[]
	it = v.begin();
	size_t	i	= 0;
	while (i < v.size())
	{
		if (i % 3 == 0)
			it[i] = VAL1;
		else if (i % 3 == 1)
			it[i] = VAL2;
		else
			it[i] = VAL3;
		std::cout << FMT1 << "it[" << std::setw(8) << i << "]\t=\t" << it[i] << std::endl;
		i++;
	}
}
*/

void	map_test(void)
{
	::map<K, T>		m;
	::map<K, T>		m2;
	context = "map_test";

	rand_insert(m);
	m2 = m;
	display_capacity(m, context);
	display_content(m, context);
	display_relationals(m, m2, context);
}

int		main(void)
{
	srand(N);
//	map_test();
	construction();
	assignation();
	element_access();
	/*
	modifiers();
	iterator_functions();
	obervers();
	operations();
	*/
	return (0);
}
