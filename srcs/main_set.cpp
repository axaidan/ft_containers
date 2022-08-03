#include "ContainsAlloc.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <list>

#ifndef STD
 #define NAMESPACE ft
 #include "set.hpp"
#else
 #define NAMESPACE std
 #include <set>
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

void	rand_insert(set<K> & m)
{
	K			k;
	int	 		n;

	for (int i = 0 ; i < N ; i++)
	{
		n = rand();

		k = rand_K();

		m.insert(k);
	}
}

void	display_capacity(const ::set<K> & m, std::string context)
{
	std::cout << std::boolalpha;
	std::cout << FMT1 << "display_capacity() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;
	std::cout << FMT2 << "m.empty()\t=\t" << m.empty() << std::endl;
	std::cout << FMT2 << "m.size()\t=\t" << m.size() << std::endl;
	std::cout << FMT2 << "m.max_size()\t=\t" << m.max_size() << std::endl;
	std::cout << std::endl;
}

void	display_content(const ::set<K> & m, std::string context)
{
	std::cout << FMT1 << "display_content() :" << std::endl;
	std::cout << FMT1 << "CONTEXT : " << context << std::endl;
	::set<K>::const_iterator	it	=	m.begin();
	::set<K>::const_iterator	ite	=	m.end();

	if (m.empty() == true)
	{
		std::cout << FMT2 << "NO CONTENT" << std::endl << std::endl;
		return ;
	}
	while (it != ite)
	{
		std::cout << FMT2 << std::setw(7) << (*it)
			<< std::endl;
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
	//	set(void)	
	::set<K>	m;
 	context = "default constructed empty set m";
	display_capacity(m, context);
	display_content(m, context);

	rand_insert(m);
	context = "rand_insert()ed values in m";
	display_capacity(m, context);
	display_content(m, context);

	//	set(first, last)
	::set<K>	m_range1(m.begin(), m.end());
	context = "range constructed from m begin/end";
	display_capacity(m_range1, context);
	display_content(m_range1, context);

	//	set(same_it, same_it)
	::set<K>	m_range2(m.begin(), m.begin());
	context = "range constructed from m begin/begin";
	display_capacity(m_range2, context);
	display_content(m_range2, context);

	//	set(begin, begin + size() / 2)
	::set<K>::iterator 	it = m.begin();
	for (size_t i = 0 ; i < m.size() / 2 ; i++)
		it++;
	::set<K>	m_range3(m.begin(), it);
	context = "range constructed from m begin/half";
	display_capacity(m_range3, context);
	display_content(m_range3, context);
	::set<K>	m_range4(it, m.end());
	context = "range constructed from m half/end";
	display_capacity(m_range4, context);
	display_content(m_range4, context);

	//	set(src)
	::set<K>	m_copy(m_range1);
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
	set<K>	m1;
	set<K>	m2;
	set<K>	m3;

	context = "(rand_insert() * 2) filling m1";
	rand_insert(m1);
	display_capacity(m2, context);
	display_content(m2, context);

	m2 = m1;
	context = "set<K> m1(N, VAL3); m2 = m1; with m1 bigger than m2";
	display_capacity(m2, context);
	display_content(m2, context);
	display_relationals(m1, m2, context);
	m2 = m3;
	context = "set<K> m3; m2 = m3; m2 is empty";
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

void	modifiers(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tMODIFIERS\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	std::list<K>				l;
	set<K>							m;
	set<K>							m2;
	K									k;
	T									t;
	pair<set<K>::iterator, bool>		ins_ret;
	size_t								i;
	set<K>::iterator					it;
	set<K>::iterator					tmp;
	set<K>::const_iterator			cite;

	//	insert(val);
	
	i = 0;
	std::cout << FMT1 << "insert(val)" << std::endl;
	while (i < N)
	{
		k = rand_K();
		ins_ret = m.insert(k);
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
		k = (*it);
		ins_ret = m.insert(k);
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
			m.insert(it, k);
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
		l.push_front(k);
		i++;
	}
	std::cout << FMT2 << "inserting list l in set m" << std::endl << std::endl;
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
	k = *(m.begin());
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

	set<K>								m;
	//	CONSTRUCTION
	set<K>::iterator						it;
	set<K>::iterator						ite(it);
	set<K>::const_iterator				cit;
	set<K>::const_iterator				cite(cit);
	set<K>::reverse_iterator				rit;
	set<K>::reverse_iterator				rite(rit);
	set<K>::const_reverse_iterator		crit;
	set<K>::const_reverse_iterator		crite(crit);

	rand_insert(m);
	context = "created new set";
	display_capacity(m, context);
	display_content(m, context);

	//	ITERATION / DEREFERENCING
	std::cout << FMT1 << "iterator iteration" << std::endl;
	it = m.begin();
	cite = m.end();
	while (it != cite)
	{
//		*it = 10923;
		std::cout << FMT2 << (*it) << std::endl;
		it++;
	}
	std::cout << std::endl;
	std::cout << FMT1 << "reverse_iterator iteration" << std::endl;
	rit = m.rbegin();
	crite = m.rend();
	while (rit != crite)
	{
		std::cout << FMT2 << (*rit) << std::endl;
		rit++;
	}
	std::cout << std::endl;
	std::cout << FMT1 << "const_iterator iteration" << std::endl;
	cit = m.begin();
	cite = m.end();
	while (cit != cite)
	{
		std::cout << FMT2 << (*cit) << std::endl;
		cit++;
	}
	std::cout << std::endl;
	std::cout << FMT1 << "const_reverse_iterator iteration" << std::endl;
	crit = m.rbegin();
	crite = m.rend();
	while (crit != crite)
	{
		std::cout << FMT2 << (*crit) << std::endl;
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
	std::cout << FMT1 << "ite = it; *it = VAL3;" << std::endl;
	std::cout << FMT1 << "(ite == it)\t=\t" << (ite == it) << std::endl;
	std::cout << std::endl;
	rite = rit;
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
	std::cout << FMT2 << "*(it++)\t=\t" << *(it++) << std::endl;
	std::cout << FMT2 << "*(--it)\t=\t" << *(--it) << std::endl;
	std::cout << FMT2 << "*(++it)\t=\t" << *(++it) << std::endl;
	std::cout << FMT2 << "*(it--)\t=\t" << *(it--) << std::endl;
	it++;
	std::cout << std::endl;

	std::cout << FMT1 << "reverse weird iteration" << std::endl;
	rit = m.rbegin();
	rite = m.rend();
	std::cout << FMT2 << "*(rit++)\t=\t" << *(rit++) << std::endl;
	std::cout << FMT2 << "*(--rit)\t=\t" << *(--rit) << std::endl;
	std::cout << FMT2 << "*(++rit)\t=\t" << *(++rit) << std::endl;
	std::cout << FMT2 << "*(rit--)\t=\t" << *(rit--) << std::endl;
	rit++;
	std::cout << std::endl;

}

void	observers(void)
{
	std::cout << "=========================" << std::endl;
	std::cout << "=\tOBSERVERS\t=" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	set<K>					m;
	set<K>::iterator			it;
	set<K>::iterator			it2;
	set<K>::iterator			ite;

	rand_insert(m);
	rand_insert(m);

	std::cout << FMT1 << "rand_insert()ed m twice" << std::endl;

	context = "rand_insert()ed m twice2";
	display_content(m, context);
	display_capacity(m, context);

	//	key_comp()
	set<K>::key_compare		k_comp;

	it = m.begin();
	ite = m.end();
	ite--;
	k_comp = m.key_comp();
	std::cout << FMT1 << "comparing key with next key" << std::endl;
	while (it != ite)
	{
		it2 = it;
		it2++;
		std::cout << FMT2 << "k_comp((*it), (*it2))\t=\t"
		   	<< k_comp((*it), (*it2))
			<< std::endl;
		std::cout << FMT2 << "k_comp((*it2), (*it))\t=\t"
		   	<< k_comp((*it2), (*it))
			<< std::endl;
		it++;
	}
	std::cout << std::endl;
	
	//	value_comp()
	set<K>::value_compare	v_comp = m.value_comp();

	it = m.begin();
	ite = m.end();
	ite--;
	std::cout << FMT1 << "comparing key with next key" << std::endl;
	while (it != ite)
	{
		it2 = it;
		it2++;
		std::cout << FMT2 << "v_comp((*it), (*it2))\t=\t"
		   	<< v_comp(*it, *it2)
			<< std::endl;
		std::cout << FMT2 << "v_comp((*it2), (*it))\t=\t"
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

	set<K>							m;
	set<K>							cm;
	set<K>::iterator					it;
	set<K>::iterator					ite;
	set<K>::iterator					ret;
	set<K>::const_iterator			cit;
	set<K>::const_iterator			cite;
	set<K>::const_iterator			cret;
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
		ret = m.find((*it));
		if (ret == m.end())
			std::cout << FMT2 << (*it) << " NOT FOUND" << std::endl;
		else
			std::cout << FMT2 << (*it) << " FOUND" << std::endl;
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

	const	set<K>	m2(m);

	cit = m.begin();
	cite = m.end();
	std::cout << FMT1 << "const find(existing k)" << std::endl;
	while (cit != cite)
	{
		cret = m2.find((*cit));
		if (cret == m2.end())
			std::cout << FMT2 << (*cit) << " NOT FOUND" << std::endl;
		else
			std::cout << FMT2 << (*cit) << " FOUND" << std::endl;
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
	k = *(m.begin());

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
	k = (*it);
	std::cout << FMT1 << "upper_bound(existing k) "
		<< k << std::endl;
	ret = m.upper_bound(k);
	std::cout << FMT2 << "m.upper_bound(k)\t=\t" << *ret
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
			<< *ret
			<< std::endl;
	std::cout << std::endl;
	//lower_bound(k)
	k = (*it);
	std::cout << FMT1 << "lower_bound(existing k) "
		<< k << std::endl;
	ret = m.lower_bound(k);
	std::cout << FMT2 << "m.lower_bound(k)\t=\t" << *ret
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
			<< *ret
			<< std::endl;
	std::cout << std::endl;

	//	equal_range(k)
	pair<set<K>::iterator, set<K>::iterator>	pret;
	pret = m.equal_range(k);

	k = (*it);
	std::cout << FMT1 << "equal_range(existing k) "
		<< k << std::endl;
	pret = m.equal_range(k);
	if (pret.first == pret.second)
		std::cout << FMT2 << "0 element with key "
			<< k << " in set m" << std::endl;
	else
		std::cout << FMT2 <<"1 element with key "
			<< k << " in set m" << std::endl;
	std::cout << std::endl;

	k = rand_K();
	std::cout << FMT1 << "equal_range(probably non existing k) "
		<< k << std::endl;
	pret = m.equal_range(k);
	if (pret.first == pret.second)
		std::cout << FMT2 << "0 element with key "
			<< k << " in set m" << std::endl;
	else
		std::cout << FMT2 <<"1 element with key "
			<< k << " in set m" << std::endl;
	std::cout << std::endl;
}

int		main(void)
{
	srand(N);
	construction();
	assignation();
	modifiers();
	iterator_functions();
	observers();
	operations();
	/*
	*/
	return (0);
}
