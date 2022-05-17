#include "vector.hpp"
#include "stack.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	// EMPTY
	ft::vector<int>			m;
	std::vector<int>		s;

	std::cout << std::boolalpha;

	std::cout << "m.size()\t=\t" << m.size() << std::endl;
	std::cout << "s.size()\t=\t" << s.size() << std::endl;
	std::cout << "m.empty()\t=\t" << m.empty() << std::endl;
	std::cout << "s.empty()\t=\t" << s.empty() << std::endl;

	ft::vector<int>		m2(10);
	std::vector<int>	s2(10);

	std::cout << "m2.size()\t=\t" << m2.size() << std::endl;
	std::cout << "s2.size()\t=\t" << s2.size() << std::endl;
	std::cout << "m2.empty()\t=\t" << m2.empty() << std::endl;
	std::cout << "s2.empty()\t=\t" << s2.empty() << std::endl;

	ft::vector<int>		m3(s2.begin(), s2.end());
	std::vector<int>	s3(s2.begin(), s2.end());

	std::cout << "m3.size()\t=\t" << m3.size() << std::endl;
	std::cout << "s3.size()\t=\t" << s3.size() << std::endl;
	std::cout << "m3.empty()\t=\t" << m3.empty() << std::endl;
	std::cout << "s3.empty()\t=\t" << s3.empty() << std::endl;

	
}
