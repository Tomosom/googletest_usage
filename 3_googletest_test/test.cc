#include "gtest.h"

int add(int a, int b)
{
	return a + b;
}

TEST(testSuit1, test0)
{
	EXPECT_EQ(add(2, 3), 5);
}

TEST(testSuit1, test1)
{
	EXPECT_EQ(add(2, 3), 6);
}

TEST(testSuit2, test0)
{
	EXPECT_EQ(add(2, 3), 6);
}

TEST(testSuit2, test1)
{
	EXPECT_EQ(add(2, 3), 6);
}

TEST(testSuit2, test2)
{
	EXPECT_EQ(add(2, 3), 6);
}

TEST(testSuit2, test3)
{
	EXPECT_EQ(add(2, 3), 6);
}

TEST(testSuit2, test4)
{
	EXPECT_EQ(add(2, 3), 6);
}

TEST(testSuit2, test5)
{
	EXPECT_EQ(add(2, 3), 6);
}

TEST(testSuit2, test6)
{
	EXPECT_EQ(add(2, 3), 6);
}

TEST(testSuit2, test7)
{
	EXPECT_EQ(add(2, 3), 6);
}

int main(int argc, char **argv)
{
	testing::GTEST_FLAG(color) = "yes";
	testing::GTEST_FLAG(output) = "xml:./test.xml";
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
