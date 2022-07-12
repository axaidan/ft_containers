#include "pair.hpp"
#include "vector.hpp"
#include <utility>
#include <iostream>
#include <string>

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
#ifdef C_STR
 typedef const std::string T_FRST;
 typedef const std::string T_SCND;
 #define VAL1 "quarante deux"
 #define VAL2 "moins 1"
 #define VAL3 "mille"
#endif

std::pair<T_FRST, T_SCND>	s1;
ft::pair<T_FRST, T_SCND>	f1;

template<class T, class U>
bool	testMemberEq(T s,
		U f,
		std::string context)
{
	std::string		format;
	bool			ret = true;

	format = "=== ";
	std::cout << format << "in \"" << context << "\" context:\n";
	format = "===\t";
	if (f.first != s.first)
	{
		std::cout << format << "first members are different\n";
		ret = false;
	}
	if (f.second != s.second)
	{
		std::cout << format << "second members are different\n";
		ret = false;
	}
	if (ret == true)
		std::cout << format << "OK - members are equal\n";
	std::cout << "\n";
	return (ret);
}

bool	testConstnessComparisons(void)
{
	std::pair<const std::string, const std::string>	stdConstTest1(VAL1, VAL2);
	std::pair<std::string, std::string>				stdConstTest2(VAL1, VAL2);
	ft::pair<const std::string, const std::string>	ftConstTest1(VAL1, VAL2);
	ft::pair<std::string, std::string>				ftConstTest2(VAL1, VAL2);
	bool ret = true;

	if (!testMemberEq(stdConstTest1, ftConstTest1, "same Cness, diff NS"))
		ret = false;
	if (!testMemberEq(stdConstTest1, stdConstTest2, "diff Cness, NS std"))
		ret = false;
	if (!testMemberEq(stdConstTest1, stdConstTest2, "diff Cness, NS ft"))
		ret = false;
	if (!testMemberEq(stdConstTest1, ftConstTest2, "diff Cness, diff NS"))
		ret = false;
	if (ret == true)
		std::cout << "=== testConstnessComparisons OK\n";
	return (ret);
}

int main(void)
{
	testMemberEq(s1, f1, "pair 1 - empty initialization");

	testConstnessComparisons();
	
	// test copy construction
	// test implicit conversion construction
	// test assignation

	return(0);
}
