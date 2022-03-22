#include "test.h"


class Arithmetic
{
public:
	int add(int a, int b) {
		return a + b;
	}
	int mul(int a, int b) {
		return a * b;
	}
};

class Algorithm
{
public:
	int factorial(int n)
	{
		if (n < 0) {
			return 0;
		}
		if (n == 1 || n == 0) {
			return 1;
		} else {
			return(factorial(n - 1) * n);
		}
	}
};


class Suite3:public testing::Test
{
public:
	virtual void SetUp()
	{
		cout << "setup_case" << endl;
	}
	virtual void TearDown()
	{
		cout << "teardown_case" << endl;
	}
	Arithmetic arithmetic;
	Algorithm alg;
protected:
	static void SetUpTestCase()
	{
		cout << "setup_suite" << endl;
	}
	static void TearDownTestCase()
	{
		cout << "teardown_suite" << endl;
	}
};

TEST_F(Suite3, add_0)
{
	EXPECT_EQ(arithmetic.add(1, 2), 3);
}

TEST_F(Suite3, mul_0)
{
	EXPECT_EQ(arithmetic.mul(1, 2), 2);
}

TEST_F(Suite3, mix_0)
{
	EXPECT_EQ(arithmetic.mul(1, 2), 2);
	EXPECT_EQ(arithmetic.add(1, 2), 3);
}

TEST_F(Suite3, alg)
{
	EXPECT_EQ(alg.factorial(0), 1);
	EXPECT_EQ(alg.factorial(1), 1);
	EXPECT_EQ(alg.factorial(2), 2);
	EXPECT_EQ(alg.factorial(3), 6);
	EXPECT_EQ(alg.factorial(4), 24);
	EXPECT_EQ(alg.factorial(5), 120);
}
