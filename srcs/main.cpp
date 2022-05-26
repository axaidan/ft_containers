#include "vector.hpp"
#include "stack.hpp"
#include "ContainsAlloc.hpp"
#include <vector>
#include <iostream>
#include <string>


std::ostream & operator<<(std::ostream &o, ContainsAlloc const & rhs)
{
	o << rhs.getAlloc();
	return (o);
}

template<class T>
void	compareCapacityFunctions(ft::vector<T> &m, std::vector<T> &s,
		std::string name)
{
	std::cout << std::boolalpha;

	std::cout << "=== FOR " << name << std::endl;
	if (m.size() == s.size())
		std::cout << "=== size() are equal" << std::endl;
	else
		std::cout << "=== size() are NOT equal" << std::endl
			<< "m =\t" << m.size()
			<< "\ts =\t" << s.size() << std::endl;
	if (m.empty() == s.empty())
		std::cout << "=== empty() are equal" << std::endl;
	else
		std::cout << "=== empty() are NOT equal" << std::endl
			<< "m =\t" << m.empty()
			<< "\ts =\t" << s.empty() << std::endl;
	if (m.max_size() == s.max_size())
		std::cout << "=== max_size() are equal" << std::endl;
	else
		std::cout << "=== max_size() are NOT equal" << std::endl
			<< "m =\t" << m.max_size()
			<< "\ts =\t" << s.max_size() << std::endl;
	if (m.capacity() == s.capacity())
		std::cout << "=== capacity() are equal" << std::endl;
	else
		std::cout << "=== capacity() are NOT equal" << std::endl
			<< "m =\t" << m.capacity()
			<< "\ts =\t" << s.capacity() << std::endl;
	std::cout << std::endl;
}

template<class T>
bool	compareValues(ft::vector<T> m, std::vector<T> s);

template<class T>
bool	printVectorValues(ft::vector<T> m, std::vector<T> s);

int main(void)
{
	// EMPTY
	ft::vector<ContainsAlloc>			m;
	std::vector<ContainsAlloc>		s;


	compareCapacityFunctions(m, s, "m");

	ft::vector<ContainsAlloc>		m2(10);
	std::vector<ContainsAlloc>		s2(10);

	compareCapacityFunctions(m2, s2, "2");

	ft::vector<ContainsAlloc>		m3(s2.begin(), s2.end());
	std::vector<ContainsAlloc>		s3(s2.begin(), s2.end());

	compareCapacityFunctions(m3, s3, "3");
	m3.reserve(20);
	std::cerr << "MAIN - SF AFTER FT?" << std::endl;
	s3.reserve(20);
	std::cerr << "MAIN - SF AFTER STD?" << std::endl;
	m3.resize(30, "3");
	std::cerr << "MAIN - SF AFTER FT?" << std::endl;
	s3.resize(30, "3");
	std::cerr << "MAIN - SF AFTER STD?" << std::endl;
	compareCapacityFunctions(m3, s3, "3 after resize()");

	ft::vector<ContainsAlloc>		m4(42, "quarante deux");
	std::vector<ContainsAlloc>		s4(42, "quarante deux");
	m4.print_values();
	std::cout << "modifying" << std::endl;
	s4[41] = "-1000";
	m4[41] = "-1000";
	std::cout << "printing" << std::endl;
	std::cout << "s[41] = " << s4[41] << std::endl;
	std::cout << "m[41] = " << m4[41] << std::endl;
	std::cout << "s.back() = " << s4.back() << std::endl;
	std::cout << "m.back() = " << m4.back() << std::endl;
	s4[0] = "2222";
	m4[0] = "2222";
	std::cout << "s.front() = " << s4.front() << std::endl;
	std::cout << "m.front() = " << m4.front() << std::endl;
//	compareCapacityFunctions(m4, s4, "4");
	m.insert(m.begin(), "quarante deux");
	std::cerr << "MAIN - SF AFTER FT?" << std::endl;
	s.insert(s.begin(), "quarante deux");
	std::cerr << "MAIN - SF AFTER STD?" << std::endl;
	compareCapacityFunctions(m, s, "after insert(single)in empty");
}
