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
		c = (rand() % ('@' - 'Z')) + 'A';
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

template<class U>
void	display_it_relationals(const U & m1,
		const U & m2,
		std::string context)

{
	std::cout << std::boolalpha;
	std::cout << FMT1 << "display_it_relationals() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;
	std::cout << FMT2 << "(m1 == m2)\t=\t" << (m1 == m2) << std::endl;
	std::cout << FMT2 << "(m1 != m2)\t=\t" << (m1 != m2) << std::endl;
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

	map<K, T>				m1;
	map<K, T>::iterator		it;
	map<K, T>::iterator		ite;
	K						key1;

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

	it = m1.begin();
	ite = m1.end();
	while (it != ite)
	{
		key1 = it->first;
		std::cout << FMT1 << "key1 = it->first;" << std::endl;
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
		it++;
	}
	context = "replaced values in existing keys";
	display_capacity(m1, context);
	display_content(m1, context);
}

void	modifiers(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tMODIFIERS\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	std::list<pair<K, T> >				l;
	map<K, T>							m;
	map<K, T>							m2;
	K									k;
	T									t;
	map<K, T>::value_type				val;
	pair<map<K, T>::iterator, bool>		ins_ret;
	size_t								i;
	map<K, T>::iterator					it;
	map<K, T>::iterator					tmp;
	map<K, T>::const_iterator			cite;

	//	insert(val);
	
	i = 0;
	std::cout << FMT1 << "insert(val)" << std::endl;
	while (i < N)
	{
		k = rand_K();
		ins_ret = m.insert(pair<K, T>(k, TVAL1));
		if (ins_ret.second == true)
			std::cout << FMT2 << "insert " << k << " succeeded" << std::endl;
		else
			std::cout << FMT2 << "insert " << k << " failed" << std::endl;
		i++;
	}
	std::cout << std::endl;
	context = "inserted N random keys with VAL1";
	display_capacity(m, context);
	display_content(m, context);

	it = m.begin();
	cite = m.end();
	while (it != cite)
	{
		k = it->first;
		ins_ret = m.insert(pair<K, T>(k, TVAL3));
		if (ins_ret.second == true)
			std::cout << FMT2 << "insert " << k << " succeeded" << std::endl;
		else
			std::cout << FMT2 << "insert " << k << " failed" << std::endl;
		it++;
	}
	std::cout << std::endl;
	context = "tried to insert existing keys with VAL3";
	display_capacity(m, context);
	display_content(m, context);

	//	insert(it pos, val);
	std::cout << FMT1 << "insert(pos, val)" << std::endl;
	it = m.begin();
	cite = m.end();
	i = 0;
	while (it != cite)
	{
		if (i % 2 == 0)
			m.insert(it, pair<K, T>(rand_K(), TVAL2));
		it++;
		i++;
	}
	display_content(m, context);
	display_capacity(m, context);
	
	//	insert(first, last)
	std::cout << FMT1 << "insert(first, last)" << std::endl;
	std::cout << FMT1 << "creating a list of N random elems" << std::endl;
	i = 0;
	while (i < N)
	{
		k = rand_K();
		if (i % 3 == 0)
			t = TVAL1;
		else if (i % 3 == 1)
			t = TVAL2;
		else
			t = TVAL3;
		l.push_front(pair<K, T>(k, t));
		i++;
	}
	std::cout << FMT2 << "inserting list l in map m" << std::endl << std::endl;
	m.insert(l.begin(), l.end());
	display_content(m, context);
	display_capacity(m, context);

	//	erase(it pos);
	m.erase(m.begin());
	cite = m.end();
	cite--;
	context = "erased m.begin() and last element";
	display_content(m, context);
	display_capacity(m, context);

	i = 0;
	it = m.begin();
	cite = m.end();
	while (it != cite)
	{
		tmp = it;
		if (i % 2 == 0)
		{
			tmp++;
			m.erase(it);
		}
		else
			tmp++;
		it = tmp;
		i++;
	}
	context = "erased one out of two elements";
	display_content(m, context);
	display_capacity(m, context);

	it = m.begin();
	cite = m.end();
	while (it != cite)
	{
		tmp = it;
		if (it->second == TVAL1)
		{
			tmp++;
			m.erase(it);
		}
		else
			tmp++;
		it = tmp;
		i++;
	}
	context = "erased all elements with TVAL1 value";
	display_content(m, context);
	display_capacity(m, context);

	m2 = m;
	//	erase(first, last)
	it = m.begin();
	i = 0;
	while (i < m.size() / 2)
	{
		it++;
		i++;
	}
	m.erase(it, m.end());
	context = "erased second half of m";
	display_content(m, context);
	display_capacity(m, context);

	//	erase(key)
	k = m.begin()->first;
	i = m.erase(k);
	context = "erased first elem by key";
	display_content(m, context);
	display_capacity(m, context);
	std::cout << FMT2 << "erased " << i << " element" << std::endl;
 
	k = rand_K();
	i = m.erase(k);
	context = "erased random key by key";
	display_content(m, context);
	display_capacity(m, context);
	std::cout << FMT2 << "erased " << i << " element" << std::endl;

	//	swap(m)
	m.swap(m2);
	context = "swapped m2 and m";
	display_content(m, context);
	display_capacity(m, context);
	display_relationals(m, m2, context);

	// clear()
	m.clear();
	m2.clear();
	context = "cleared m and m2";
	display_content(m, context);
	display_capacity(m, context);
	display_relationals(m, m2, context);
}

void	iterator_functions(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tITERATORS\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	map<K, T>								m;
	//	CONSTRUCTION
	map<K, T>::iterator						it;
	map<K, T>::iterator						ite(it);
	map<K, T>::const_iterator				cit;
	map<K, T>::const_iterator				cite(cit);
	map<K, T>::reverse_iterator				rit;
	map<K, T>::reverse_iterator				rite(rit);
	map<K, T>::const_reverse_iterator		crit;
	map<K, T>::const_reverse_iterator		crite(crit);

	rand_insert(m);
	context = "created new map";
	display_capacity(m, context);
	display_content(m, context);

	//	ITERATION / DEREFERENCING
	std::cout << FMT1 << "iterator iteration" << std::endl;
	it = m.begin();
	cite = m.end();
	while (it != cite)
	{
		std::cout << FMT2 << it->first << std::endl;
		it++;
	}
	std::cout << std::endl;
	std::cout << FMT1 << "reverse_iterator iteration" << std::endl;
	rit = m.rbegin();
	crite = m.rend();
	while (rit != crite)
	{
		std::cout << FMT2 << rit->first << std::endl;
		rit++;
	}
	std::cout << std::endl;
	std::cout << FMT1 << "const_iterator iteration" << std::endl;
	cit = m.begin();
	cite = m.end();
	while (cit != cite)
	{
		std::cout << FMT2 << cit->first << std::endl;
		cit++;
	}
	std::cout << std::endl;
	std::cout << FMT1 << "const_reverse_iterator iteration" << std::endl;
	crit = m.rbegin();
	crite = m.rend();
	while (crit != crite)
	{
		std::cout << FMT2 << crit->first << std::endl;
		crit++;
	}
	std::cout << std::endl;

	//	RELATIONALS
	ite = it;
	context = "ite = it; it and ite relationals";
	display_it_relationals(it, ite, context);
	it--;
	context = "it--; it and ite relationals";
	display_it_relationals(it, ite, context);
	cite = cit;
	context = "cite = cit; cit and cite relationals";
	display_it_relationals(cit, cite, context);
	cit--;
	context = "cit--; cit and cite relationals";
	display_it_relationals(cit, cite, context);

	rite = rit;
	context = "rite = rit; rit and rite relationals";
	display_it_relationals(rit, rite, context);
	rit--;
	context = "rit--; rit and rite relationals";
	display_it_relationals(rit, rite, context);
	crite = crit;
	context = "crite = crit; crit and crite relationals";
	display_it_relationals(crit, crite, context);
	crit--;
	context = "crit--; crit and crite relationals";
	display_it_relationals(crit, crite, context);

	//	ASSIGNATION
	it = m.begin();
	cit = m.begin();
	rit = m.rbegin();
	crit = m.rbegin();

	ite = it;
	it->second = TVAL3;
	std::cout << FMT1 << "ite = it; *it = VAL3;" << std::endl;
	std::cout << FMT1 << "(ite == it)\t=\t" << (ite == it) << std::endl;
	std::cout << std::endl;
	rite = rit;
	rit->second = TVAL1;
	std::cout << FMT1 << "rite = rit; *rit = VAL1;" << std::endl;
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
	it = m.begin();
	ite = m.end();
	std::cout << FMT2 << "*(it++)\t=\t" << (it++)->first << std::endl;
	std::cout << FMT2 << "*(--it)\t=\t" << (--it)->first << std::endl;
	std::cout << FMT2 << "*(++it)\t=\t" << (++it)->first << std::endl;
	std::cout << FMT2 << "*(it--)\t=\t" << (it--)->first << std::endl;
	it++;
	std::cout << std::endl;

	std::cout << FMT1 << "reverse weird iteration" << std::endl;
	rit = m.rbegin();
	rite = m.rend();
	std::cout << FMT2 << "*(rit++)\t=\t" << (rit++)->first << std::endl;
	std::cout << FMT2 << "*(--rit)\t=\t" << (--rit)->first << std::endl;
	std::cout << FMT2 << "*(++rit)\t=\t" << (++rit)->first << std::endl;
	std::cout << FMT2 << "*(rit--)\t=\t" << (rit--)->first << std::endl;
	rit++;
	std::cout << std::endl;

}

void	observers(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tOBSERVERS\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	map<K, T>					m;
	map<K, T>::iterator			it;
	map<K, T>::iterator			it2;
	map<K, T>::iterator			ite;

	rand_insert(m);
	rand_insert(m);

	std::cout << FMT1 << "rand_insert()ed m twice" << std::endl;

	context = "rand_insert()ed m twice2";
	display_content(m, context);
	display_capacity(m, context);

	//	key_comp()
	map<K, T>::key_compare		k_comp;

	it = m.begin();
	ite = m.end();
	ite--;
	k_comp = m.key_comp();
	std::cout << FMT1 << "comparing key with next key" << std::endl;
	while (it != ite)
	{
		it2 = it;
		it2++;
		std::cout << FMT2 << "k_comp(it->first, it2->first)\t=\t"
		   	<< k_comp(it->first, it2->first)
			<< std::endl;
		std::cout << FMT2 << "k_comp(it2->first, it->first)\t=\t"
		   	<< k_comp(it2->first, it->first)
			<< std::endl;
		it++;
	}
	std::cout << std::endl;
	
	//	value_comp()
	map<K, T>::value_compare	v_comp = m.value_comp();

	it = m.begin();
	ite = m.end();
	ite--;
	std::cout << FMT1 << "comparing key with next key" << std::endl;
	while (it != ite)
	{
		it2 = it;
		it2++;
		std::cout << FMT2 << "v_comp(it->first, it2->first)\t=\t"
		   	<< v_comp(*it, *it2)
			<< std::endl;
		std::cout << FMT2 << "v_comp(it2->first, it1->first)\t=\t"
		   	<< v_comp(*it2, *it)
			<< std::endl;
		it++;
	}
	std::cout << std::endl;
}

void	operations(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tOPERATIONS\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	map<K, T>							m;
	map<K, T>							cm;
	map<K, T>::iterator					it;
	map<K, T>::iterator					ite;
	map<K, T>::iterator					ret;
	map<K, T>::const_iterator			cit;
	map<K, T>::const_iterator			cite;
	map<K, T>::const_iterator			cret;
	size_t								i;
	K									k;

	//	find(k)
	rand_insert(m);
	rand_insert(m);

	context = "rand_insert()ed m twice2";
	display_content(m, context);
	display_capacity(m, context);

	it = m.begin();
	ite = m.end();

	std::cout << FMT1 << "find(existing k) and change value" << std::endl;
	while (it != ite)
	{
		ret = m.find(it->first);
		if (ret == m.end())
			std::cout << FMT2 << it->first << " NOT FOUND" << std::endl;
		else
			std::cout << FMT2 << it->first << " FOUND" << std::endl;
		ret->second = TVAL2;
		it++;
	}
	std::cout << std::endl;

	context = "changed value while finding";
	display_content(m, context);
	display_capacity(m, context);

	std::cout << FMT1 << "find(probably non existing k)" << std::endl;
	i = 0;
	while (i < N)
	{
		k = rand_K();
		ret = m.find(k);
		if (ret == m.end())
			std::cout << FMT2 << k << " NOT FOUND" << std::endl;
		else
			std::cout << FMT2 << k << " FOUND" << std::endl;
		i++;
	}
	std::cout << std::endl;

	const	map<K, T>	m2(m);

	cit = m.begin();
	cite = m.end();
	std::cout << FMT1 << "const find(existing k)" << std::endl;
	while (cit != cite)
	{
		cret = m2.find(cit->first);
		if (cret == m2.end())
			std::cout << FMT2 << cit->first << " NOT FOUND" << std::endl;
		else
			std::cout << FMT2 << cit->first << " FOUND" << std::endl;
		//cret->second = TVAL2;	//	WON'T COMPILE
		cit++;
	}
	std::cout << std::endl;

	std::cout << FMT1 << "const find(probably non existing k)" << std::endl;
	i = 0;
	while (i < N)
	{
		k = rand_K();
		cret = m2.find(k);
		if (cret == m2.end())
			std::cout << FMT2 << k << " NOT FOUND" << std::endl;
		else
			std::cout << FMT2 << k << " FOUND" << std::endl;
		i++;
	}
	std::cout << std::endl;

	//	count(k)
	k = m.begin()->first;

	std::cout << FMT1 << "count(existing k) "
		<< k << std::endl;
	std::cout << FMT2 << "m.count(k)\t=\t" << m.count(k) << std::endl;
	std::cout << std::endl;
	k = rand_K();
	std::cout << FMT1 << "count(probably non existing k) "
		<< k << std::endl;
	std::cout << FMT2 << "m.count(k)\t=\t" << m.count(k) << std::endl;
	std::cout << std::endl;

	//	upper_bound(k)
	it = m.begin();
	i = 0;
	while (i < m.size() / 2)
	{
		it++;
		i++;
	}
	k = it->first;
	std::cout << FMT1 << "upper_bound(existing k) "
		<< k << std::endl;
	ret = m.upper_bound(k);
	std::cout << FMT2 << "m.upper_bound(k)\t=\t" << ret->first
		<< std::endl;
	std::cout << std::endl;
	k = rand_K();
	std::cout << FMT1 << "upper_bound(probably non existing k) "
		<< k << std::endl;
	ret = m.upper_bound(k);
	if (ret == m.end())
		std::cout << FMT2 << "m.upper_bound(k)\t=\t" << "NO UPPER_BOUND"
			<< std::endl;
	else
		std::cout << FMT2 << "m.upper_bound(k)\t=\t"
			<< ret->first
			<< std::endl;
	std::cout << std::endl;
	//lower_bound(k)
	k = it->first;
	std::cout << FMT1 << "lower_bound(existing k) "
		<< k << std::endl;
	ret = m.lower_bound(k);
	std::cout << FMT2 << "m.lower_bound(k)\t=\t" << ret->first
		<< std::endl;
	std::cout << std::endl;
	k = rand_K();
	std::cout << FMT1 << "lower_bound(probably non existing k) "
		<< k << std::endl;
	ret = m.lower_bound(k);
	if (ret == m.end())
		std::cout << FMT2 << "m.lower_bound(k)\t=\t" << "NO LOWER_BOUND"
			<< std::endl;
	else
		std::cout << FMT2 << "m.lower_bound(k)\t=\t"
			<< ret->first
			<< std::endl;
	std::cout << std::endl;

	//	equal_range(k)
	pair<map<K, T>::iterator, map<K, T>::iterator>	pret;
	pret = m.equal_range(k);

	k = it->first;
	std::cout << FMT1 << "equal_range(existing k) "
		<< k << std::endl;
	pret = m.equal_range(k);
	if (pret.first == pret.second)
		std::cout << FMT2 << "0 element with key "
			<< k << " in map m" << std::endl;
	else
		std::cout << FMT2 <<"1 element with key "
			<< k << " in map m" << std::endl;
	std::cout << std::endl;

	k = rand_K();
	std::cout << FMT1 << "equal_range(probably non existing k) "
		<< k << std::endl;
	pret = m.equal_range(k);
	if (pret.first == pret.second)
		std::cout << FMT2 << "0 element with key "
			<< k << " in map m" << std::endl;
	else
		std::cout << FMT2 <<"1 element with key "
			<< k << " in map m" << std::endl;
	std::cout << std::endl;
}

int		main(void)
{
	srand(N);
	construction();
	assignation();
	element_access();
	modifiers();
	iterator_functions();
	observers();
	operations();
	return (0);
}
