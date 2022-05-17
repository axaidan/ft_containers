#include "vector.hpp"
#include "stack.hpp"

#include <vector>
#include <iostream>
#include <list>

#include <gtest/gtest.h>

// CAPACITY
TEST(vectorCapacity, defaultCnst)
{
	ft::vector<int>		f1;
	std::vector<int>	s1;
	EXPECT_EQ(f1.size(), s1.size()) << "size() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.empty(), s1.empty()) << "empty() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.max_size(), s1.max_size()) << "max_size() differ: "
		<< f1.max_size() << "\t" << s1.max_size();
	EXPECT_EQ(f1.capacity(), s1.capacity()) << "capacity() differ: "
		<< f1.capacity() << "\t" << s1.capacity();
}

TEST(vectorCapacity, fillCnst1Param)
{
	ft::vector<int>		f1(100);
	std::vector<int>	s1(100);
	EXPECT_EQ(f1.size(), s1.size()) << "size() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.empty(), s1.empty()) << "empty() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.max_size(), s1.max_size()) << "max_size() differ: "
		<< f1.max_size() << "\t" << s1.max_size();
	EXPECT_EQ(f1.capacity(), s1.capacity()) << "capacity() differ: "
		<< f1.capacity() << "\t" << s1.capacity();
}

TEST(vectorCapacity, rangeCnst2Param)
{
	std::list<int>		refList(20);
	ft::vector<int>		f1(refList.begin(), refList.end());
	std::vector<int>	s1(refList.begin(), refList.end());
	EXPECT_EQ(f1.size(), s1.size()) << "size() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.empty(), s1.empty()) << "empty() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.max_size(), s1.max_size()) << "max_size() differ: "
		<< f1.max_size() << "\t" << s1.max_size();
	EXPECT_EQ(f1.capacity(), s1.capacity()) << "capacity() differ: "
		<< f1.capacity() << "\t" << s1.capacity();
	f1.reserve(25);
	s1.reserve(25);
	EXPECT_EQ(f1.size(), s1.size()) << "size() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.empty(), s1.empty()) << "empty() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.max_size(), s1.max_size()) << "max_size() differ: "
		<< f1.max_size() << "\t" << s1.max_size();
	EXPECT_EQ(f1.capacity(), s1.capacity()) << "capacity() differ: "
		<< f1.capacity() << "\t" << s1.capacity();
	f1.resize(5);
	s1.resize(5);
	EXPECT_EQ(f1.size(), s1.size()) << "size() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.empty(), s1.empty()) << "empty() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.max_size(), s1.max_size()) << "max_size() differ: "
		<< f1.max_size() << "\t" << s1.max_size();
	EXPECT_EQ(f1.capacity(), s1.capacity()) << "capacity() differ: "
		<< f1.capacity() << "\t" << s1.capacity();
	f1.resize(10, 5);
	s1.resize(10, 5);
	EXPECT_EQ(f1.size(), s1.size()) << "size() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.empty(), s1.empty()) << "empty() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.max_size(), s1.max_size()) << "max_size() differ: "
		<< f1.max_size() << "\t" << s1.max_size();
	EXPECT_EQ(f1.capacity(), s1.capacity()) << "capacity() differ: "
		<< f1.capacity() << "\t" << s1.capacity();
	f1.resize(500, 10);
	s1.resize(500, 10);
	EXPECT_EQ(f1.size(), s1.size()) << "size() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.empty(), s1.empty()) << "empty() differ: "
		<< f1.size() << "\t" << s1.size();
	EXPECT_EQ(f1.max_size(), s1.max_size()) << "max_size() differ: "
		<< f1.max_size() << "\t" << s1.max_size();
	EXPECT_EQ(f1.capacity(), s1.capacity()) << "capacity() differ: "
		<< f1.capacity() << "\t" << s1.capacity();


}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
