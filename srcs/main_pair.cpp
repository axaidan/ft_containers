#include "pair.hpp"
#include "vector.hpp"

#include <utility>
#include <iostream>
#include <string>

#define FMT "===\t"
#define CTXT_FMT "=== "

#ifdef STR
 typedef std::string T_FRST;
 typedef std::string T_SCND;
 #define VAL1 "quarante deux"
 #define VAL2 "moins 1"
 #define VAL3 "mille"
#endif
#ifdef INT
 typedef int T_FRST;
 typedef int T_SCND;
 #define VAL1 42
 #define VAL2 -1
 #define VAL3 1000
#endif
#ifdef FLT
 typedef float T_FRST;
 typedef float T_SCND;
 #define VAL1 42.42f
 #define VAL2 -1.1f
 #define VAL3 1000.9f
#endif
#ifdef CAL
 #include "ContainsAlloc.hpp"
 typedef typename ContainsAlloc T_FRST
 typedef typename ContainsAlloc T_SCND
 #define VAL1 "quarante deux"
 #define VAL2 "moins 1"
 #define VAL3 "mille"
#endif


std::pair<T_FRST, T_SCND>	s1;
ft::pair<T_FRST, T_SCND>	f1;

template<class T, class U>
bool	testPairMemberEq(T s,
		U f,
		std::string context)
{
	bool			ret = true;

	std::cout << CTXT_FMT << "in \"" << context << "\" context:\n";
	if (f.first != s.first)
	{
		std::cout << FMT << "first members are different\n";
		ret = false;
	}
	else
		std::cout << FMT << s.first << " " << f.first << "\n";
	if (f.second != s.second)
	{
		std::cout << FMT << "second members are different\n";
		ret = false;
	}
	else
		std::cout << FMT << s.second << " " << f.second << "\n";
	if (ret == true)
		std::cout << FMT << "OK - members are equal\n";
//	std::cout << "\n";
	return (ret);
}

bool	testConstnessComparisons(void)
{
	std::pair<const T_FRST, const T_SCND>	stdConstTest1(VAL1, VAL2);
	std::pair<T_FRST, T_SCND>				stdConstTest2(VAL1, VAL2);
	ft::pair<const T_FRST, const T_SCND>	ftConstTest1(VAL1, VAL2);
	ft::pair<T_FRST, T_SCND>				ftConstTest2(VAL1, VAL2);
	bool ret = true;

	std::cout << "TESTING CONSTNESS COMPARISONS:\n";
	if (!testPairMemberEq(stdConstTest1, ftConstTest1, "same Cness, diff NS"))
		ret = false;
	if (!testPairMemberEq(stdConstTest1, stdConstTest2, "diff Cness, NS std"))
		ret = false;
	if (!testPairMemberEq(stdConstTest1, stdConstTest2, "diff Cness, NS ft"))
		ret = false;
	if (!testPairMemberEq(stdConstTest1, ftConstTest2, "diff Cness, diff NS"))
		ret = false;
	if (ret == true)
		std::cout << "=== testConstnessComparisons OK\n";
	std::cout << "\n";
	return (ret);
}

bool	testMakePair(void)
{
	
	bool	ret = true;
	std::pair<T_FRST, T_SCND>	s_pair = std::make_pair(VAL1, VAL2);
	ft::pair<T_FRST, T_SCND>	f_pair = ft::make_pair(VAL1, VAL2);
	ft::pair<T_FRST, T_SCND>	f_pair3 = ft::make_pair(VAL3, VAL1);
	ft::pair<T_FRST, T_SCND>	f_pair2 = ft::make_pair(VAL3, VAL1);

	std::cout << "TESTING make_pair():\n";
	if (!testPairMemberEq(s_pair, f_pair, "std::make_pair and ft::make_pair"))
		ret = false;
	if (!testPairMemberEq(f_pair2, f_pair3, "ft::make_pair and ft::make_pair"))
		ret = false;
	if (ret == true)
		std::cout << "TESTING make_pair() OK\n";
	std::cout << "\n";
	return (ret);
}

bool	testCopyConstruction(void)
{
	bool	ret = true;
	std::cout << "TESTING COPY CONSTRUCTION():\n";
	ft::pair<T_FRST, T_SCND>	f_pair(f1);
	std::pair<T_FRST, T_SCND>	s_pair(s1);

	if (!testPairMemberEq(s_pair, f_pair, "std and ft copy construction"))
		ret = false;
	if (ret == true)
		std::cout << "TESTING COPY CONSTRUCTION OK\n";
	std::cout << "\n";
	return (ret);
}

void	changeGlobalPairValues(T_FRST frstVal, T_SCND scndVal)
{
	std::cout << "CHANGING GLOBAL PAIR VALUES TO:\n";
	std::cout << FMT << "first\t= " << frstVal << "\n";
	std::cout << FMT << "second\t= " << scndVal << "\n";
	std::cout << "\n";

	f1.first = frstVal;
	f1.second = scndVal;
	s1.first = frstVal;
	s1.second = scndVal;
}

bool	testAssignation(void)
{
	bool	ret = true;
	std::cout << "TESTING ASSIGNATION:\n";
	ft::pair<T_FRST, T_SCND>	f_pair;
	std::pair<T_FRST, T_SCND>	s_pair;

	s_pair = s1;
	f_pair = f1;
	if (!testPairMemberEq(s_pair, f_pair, "std and ft assignation"))
		ret = false;
	if (ret == true)
		std::cout << "TESTING ASSIGNATION OK\n";
	std::cout << "\n";
	return (ret);
}

bool	testRelationalOperators(void)
{
	bool	ret = true;
	std::cout << "TESTING RELATIONAL OPERATORS:\n";
	ft::pair<T_FRST, T_SCND>	f_pair(f1);
	std::pair<T_FRST, T_SCND>	s_pair(s1);
	//std::pair<T_FRST, T_SCND>	s_pair(f_pair.first, f_pair.second);

	if ((s_pair == s1) != (f_pair == f1))
	{
		ret = false;
		std::cout << FMT << "== test failed\n";
	}
	else
		std::cout << FMT << "== test passed\n";
	if ((s_pair != s1) != (f_pair != f1))
	{
		ret = false;
		std::cout << FMT << "!= test failed\n";
	}
	else
		std::cout << FMT << "!= test passed\n";
	if ((s_pair < s1) != (f_pair < f1))
	{
		ret = false;
		std::cout << FMT << "< test failed\n";
	}
	else
		std::cout << FMT << "< test passed\n";
	if ((s_pair <= s1) != (f_pair <= f1))
	{
		ret = false;
		std::cout << FMT << "<= test failed\n";
	}
	else
		std::cout << FMT << "<= test passed\n";
	if ((s_pair > s1) != (f_pair > f1))
	{
		ret = false;
		std::cout << FMT << "> test failed\n";
	}
	else
		std::cout << FMT << "> test passed\n";
	if ((s_pair >= s1) != (f_pair >= f1))
	{
		ret = false;
		std::cout << FMT << ">= test failed\n";
	}
	else
		std::cout << FMT << ">= test passed\n";
	if (ret == true)
		std::cout << "TESTING RELATIONAL OPERATORS OK\n";
	std::cout << "\n";
	return (ret);

}

int main(void)
{
	testPairMemberEq(s1, f1, "pair 1 - empty initialization");

	testConstnessComparisons();
	testMakePair();
	changeGlobalPairValues(VAL3, VAL2);
	testCopyConstruction();
	testAssignation();
	testRelationalOperators();

	return(0);
}
