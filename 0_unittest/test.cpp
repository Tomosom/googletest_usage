#include "test.h"
#include "test_parse.h"

static std::map<std::string, module_unittest_opt_s> s_opt_map;

class GlobalTest:public testing::Environment
{
public:
	virtual void SetUp()
	{
		cout << "setup_global" << endl;
	}
	virtual void TearDown()
	{
		cout << "teardown_global" << endl;
	}
};

TEST_MODULE(suite1, case1);
TEST_MODULE(suite1, case2);
TEST_MODULE(suite2, case1);
TEST_MODULE(suite2, case2);

// ./test.exe --module_cfgpath=./config/test.cfg
int main(int argc, char **argv)
{
	module_unittest_opt_parse(argc, argv, s_opt_map);
	testing::GTEST_FLAG(color) = "yes";
	testing::GTEST_FLAG(output) = "xml:./test.xml";
	testing::InitGoogleTest(&argc, argv);
	testing::AddGlobalTestEnvironment(new GlobalTest());
	return RUN_ALL_TESTS();
}
