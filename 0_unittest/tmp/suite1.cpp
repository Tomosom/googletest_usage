#include "test.h"

int add(int a, int b)
{
	return a + b;
}

TEST(Suite1, test0)
{
	EXPECT_EQ(add(2, 3), 5);
}

TEST(Suite1, test1)
{
	EXPECT_EQ(add(2, 3), 5);
}

TEST(Suite1, test3)
{
	EXPECT_EQ(add(2, 3), 5);
}

