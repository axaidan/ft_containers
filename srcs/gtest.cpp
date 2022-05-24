#include "vector.hpp"
#include <vector>

#include <iostream>
#include <gtest/gtest.h>
#include "ContainsAlloc.hpp"

#ifdef INT
	typedef int T;
	#define VALUE_ONE 42
	#define VALUE_TWO -100
	#define VALUE_THREE -1
#endif
#ifdef STRING
	typedef std::string T;
	#define VALUE_ONE "quarante deux"
	#define VALUE_TWO "moins cent"
	#define VALUE_THREE "moins un"
#endif
#ifdef FLOAT
	typedef float T;
	#define VALUE_ONE 42.0f
	#define VALUE_TWO -100.0f
	#define VALUE_THREE -1.0f
#endif
#ifdef CUSTOM
	typedef ContainsAlloc T;
	#define VALUE_ONE "quarante deux"
	#define VALUE_TWO "moins cent"
	#define VALUE_THREE "moins un"
#endif

#define N 50 

std::ostream & operator<<(std::ostream &o, ContainsAlloc const & rhs)
{
    o << rhs.getAlloc();
    return (o);
}

 
ft::vector<T>		ft_v;
std::vector<T>		std_v;
ft::vector<T>		ft_v2;

void	modifyCapacity(size_t reserveArg)
{
	ft_v.reserve(reserveArg);
	std_v.reserve(reserveArg);
}

bool	valuesAreEqual(size_t *j)
{
	std::vector<T>::iterator	stdIt = std_v.begin();
	ft::vector<T>::iterator		ftIt = ft_v.begin();
	std::vector<T>::iterator	stdItE = std_v.end();
	ft::vector<T>::iterator		ftItE = ft_v.end();
	size_t						i = 0;
	while (ftIt != ftItE)
	{
		if (*ftIt != *stdIt)
		{
			*j = i;
			return (false);
		}			
		i++;
		stdIt++;
		ftIt++;
	}
	return (true);
}

bool	valuesAreEqual(ft::vector<T> f, std::vector<T> s, size_t *j)
{
	std::vector<T>::iterator	stdIt = s.begin();
	std::vector<T>::iterator	stdItE = s.end();
	ft::vector<T>::iterator		ftIt = f.begin();
	ft::vector<T>::iterator		ftItE = f.end();
	size_t						i = 0;
	while (ftIt != ftItE)
	{
		if (*ftIt != *stdIt)
		{
			*j = i;
			return (false);
		}			
		i++;
		stdIt++;
		ftIt++;
	}
	return (true);
}

class CapacityFunctions : public ::testing::Test
{
	protected:
		void TEST_CAPACITY_FUNCTIONS(void)
		{
			EXPECT_EQ(ft_v.empty(), std_v.empty()) << "=== empty() differ:"
				<< "ftv = " << ft_v.empty()
				<< "\tstd_v = " << std_v.empty() ;
			EXPECT_EQ(ft_v.size(), std_v.size()) << "=== size() differ:"
				<< "ftv = " << ft_v.size()
				<< "\tstd_v = " << std_v.size() ;
			EXPECT_EQ(ft_v.capacity(), std_v.capacity())
				<< "=== capacity() differ:"
				<< "ftv = " << ft_v.capacity()
				<< "\tstd_v = " << std_v.capacity() ;
			EXPECT_EQ(ft_v.max_size(), std_v.max_size())
				<< "=== max_size() differ:"
				<< "ftv = " << ft_v.max_size()
				<< "\tstd_v = " << std_v.max_size() ;
		}

		void TEST_EQUALITY(void)
		{
			size_t	i;
			ASSERT_TRUE(valuesAreEqual(&i))
				<< "=== valuesAreEqual(): "
				<< "at " << i
				<< "\tft_v[i] = " << ft_v[i]
				<< "\tstd_v[i] = " << std_v[i] ;
		}

		void TEST_ACCESS_FUNCTIONS(void)
		{
			ASSERT_FALSE(ft_v.empty()) << "=== TEST_ACCESS_FUNCTIONS: "
				<< "ft_v.empty is empty";
			ASSERT_FALSE(std_v.empty()) << "=== TEST_ACCESS_FUNCTIONS: "
				<< "std_v.empty is empty";
			EXPECT_EQ(ft_v.front(), std_v.front())
				<< "=== front(): "
				<< "ft_v = " << ft_v.front() 
				<< "std_v = " << std_v.front() ;
			EXPECT_EQ(ft_v.back(), std_v.back())
				<< "=== back(): "
				<< "ft_v = " << ft_v.back() 
				<< "std_v = " << std_v.back() ;
			EXPECT_EQ(ft_v.at(ft_v.size() % 2), std_v.at(std_v.size() % 2))
				<< "=== at(" << ft_v.size() % 2 << ") "
				<< "ft_v = " << ft_v.at(ft_v.size() % 2) 
				<< "std_v = " << std_v.at(ft_v.size() % 2);
		}

		void TEST_ITERATORS_FUNCTIONS(void)
		{
			ASSERT_EQ(ft_v.empty(), std_v.empty())
				<< "=== TEST_IRERATORS_FUNCTIONS: "
				<< "empti()ness status differ for ft_v and std_v";
			if (std_v.empty() == false)
			{
			EXPECT_EQ(*ft_v.begin(), *std_v.begin())
				<< "=== begin(): "
				<< "ft_v = " << *ft_v.begin()
				<< "std_v = " << *std_v.begin();
			EXPECT_EQ(*(ft_v.end() - 1), *(std_v.end() - 1))
				<< "=== end() - 1: "
				<< "ft_v = " << *(ft_v.end() - 1)
				<< "std_v = " << *(std_v.end() - 1);
			/*
			EXPECT_EQ(*ft_v.rbegin(), *std_v.rbegin())
			EXPECT_EQ(*ft_v.rend(), *std_v.rend())
			*/
			}
			else
			{
				EXPECT_EQ(ft_v.begin(), ft_v.end())
					<< "=== TEST_ITERATORS_FUNCTIONS: "
					<< "begin() != end() for empty ft_v";
				EXPECT_EQ(std_v.begin(), std_v.end())
					<< "=== TEST_ITERATORS_FUNCTIONS: "
					<< "begin() != end() for empty std_v";
			}
		}
};

TEST_F(CapacityFunctions, empty)
{
	TEST_CAPACITY_FUNCTIONS();
	TEST_EQUALITY();
	TEST_ITERATORS_FUNCTIONS();
}

TEST_F(CapacityFunctions, reserve20)
{
	ft_v.reserve(2);
	std_v.reserve(2);
	TEST_CAPACITY_FUNCTIONS();
	TEST_EQUALITY();
	TEST_ITERATORS_FUNCTIONS();
}

TEST_F(CapacityFunctions, resize5Value)
{
	T	val(VALUE_ONE);

	ft_v.resize(5, val);
	std_v.resize(5, val);
	TEST_CAPACITY_FUNCTIONS();
	TEST_EQUALITY();
	TEST_ACCESS_FUNCTIONS();
	TEST_ITERATORS_FUNCTIONS();
}

TEST_F(CapacityFunctions, insertOneValue)
{
	T	val1(VALUE_ONE);
	T	val2(VALUE_TWO);

	ft_v.insert(ft_v.end(), val1);
	std_v.insert(std_v.end(), val1);
	ft_v.insert(ft_v.end(), val1);
	std_v.insert(std_v.end(), val1);
	ft_v.insert(ft_v.begin() + 1, val2);
	std_v.insert(std_v.begin() + 1, val2);
	ft_v.insert(ft_v.begin() + 1, val1);
	std_v.insert(std_v.begin() + 1, val1);
	TEST_CAPACITY_FUNCTIONS();
	TEST_EQUALITY();
	TEST_ACCESS_FUNCTIONS();
}

/*
TEST_F(CapacityFunctions, insertFill)
{
	T val = T(VALUE_THREE);

	ft_v.insert(ft_v.begin(), 2, val);
	std_v.insert(std_v.begin(), 2, val);
	TEST_CAPACITY_FUNCTIONS();
	TEST_EQUALITY();

	std::cout << "=== IN MAIN - SF?" << std::endl;
	ft_v.insert(ft_v.end(), 80, val);
	std_v.insert(std_v.end(), 80, val);
	TEST_CAPACITY_FUNCTIONS();
	TEST_EQUALITY();
}
*/

TEST_F(CapacityFunctions, insertSingleEmpty)
{
	ft::vector<T>	ft_empty;
	std::vector<T>	std_empty;
	size_t			index;
	T				val(VALUE_THREE);

	ft_empty.insert(ft_empty.begin(), val);
	std_empty.insert(std_empty.begin(), val);
	EXPECT_EQ(ft_empty.size(), std_empty.size()) << "=== size() differ:"
				<< "ft_empty = " << ft_empty.size()
				<< "\tstd_empty= " << std_empty.size() ;
	EXPECT_EQ(ft_empty.capacity(), std_empty.capacity()) << "=== capacity() differ:"
				<< "ft_empty = " << ft_empty.capacity()
				<< "\tstd_empty= " << std_empty.capacity() ;
	EXPECT_EQ(ft_empty.empty(), std_empty.empty()) << "=== empty() differ:"
				<< "ft_empty = " << ft_empty.empty()
				<< "\tstd_empty= " << std_empty.empty() ;;
	std::cerr << "=== IN MAIN - SF?" << std::endl;
	EXPECT_EQ(valuesAreEqual(ft_empty, std_empty, &index), true)
				<< "=== valuesAreEqual(): "
				<< "at " << index
				<< "\tft_v[i] = " << ft_v[index]
				<< "\tstd_v[i] = " << std_v[index] ;
}

TEST_F(CapacityFunctions, insertFillEmpty)
{
	ft::vector<T>	ft_empty;
	std::vector<T>	std_empty;
	size_t			index;
	T				val(VALUE_THREE);

	ft_empty.insert(ft_empty.end(), 10, val);
	std_empty.insert(std_empty.end(), 10, val);
	EXPECT_EQ(ft_empty.size(), std_empty.size()) << "=== size() differ:"
				<< "ft_empty = " << ft_empty.size()
				<< "\tstd_empty= " << std_empty.size() ;
	EXPECT_EQ(ft_empty.capacity(), std_empty.capacity()) << "=== capacity() differ:"
				<< "ft_empty = " << ft_empty.capacity()
				<< "\tstd_empty= " << std_empty.capacity() ;
	EXPECT_EQ(ft_empty.empty(), std_empty.empty()) << "=== empty() differ:"
				<< "ft_empty = " << ft_empty.empty()
				<< "\tstd_empty= " << std_empty.empty() ;;
	EXPECT_EQ(valuesAreEqual(ft_empty, std_empty, &index), true)
				<< "=== valuesAreEqual(): "
				<< "at " << index
				<< "\tft_v[i] = " << ft_v[index]
				<< "\tstd_v[i] = " << std_v[index] ;
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
