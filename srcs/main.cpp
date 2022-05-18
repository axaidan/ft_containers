#include "vector.hpp"
#include "stack.hpp"
#include <vector>
#include <iostream>
#include <string>

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
	ft::vector<int>			m;
	std::vector<int>		s;

	compareCapacityFunctions(m, s, "m");

	ft::vector<int>		m2(10);
	std::vector<int>	s2(10);

	compareCapacityFunctions(m2, s2, "2");

	ft::vector<int>		m3(s2.begin(), s2.end());
	std::vector<int>	s3(s2.begin(), s2.end());

	compareCapacityFunctions(m3, s3, "3");
	m3.reserve(20);
	s3.reserve(20);
	m3.resize(5, 3);
	s3.resize(5, 3);
	compareCapacityFunctions(m3, s3, "3 after resize()");

	ft::vector<int>		m4(42, 42);
	std::vector<int>	s4(42, 42);
	m4.print_values();
	compareCapacityFunctions(m4, s4, "4");

}
