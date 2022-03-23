#include "test.h"
#include "test_parse.h"

static std::map<std::string, module_unittest_opt_s> s_opt_map;

class GlobalTest:public testing::Environment
{
public:
	virtual void SetUp()
	{
		cout << "global_setup" << endl;
	}
	virtual void TearDown()
	{
		cout << "global_teardown" << endl;
	}
};

TEST_MODULE_WITH_CFG(suite1, case1, config1);
TEST_MODULE_WITH_CFG(suite1, case2, config2);
TEST_MODULE_WITH_CFG(suite2, case1, config1);
TEST_MODULE_WITH_CFG(suite2, case2, config2);

// ./test.exe --module_cfgpath=./config/test_path.cfg
int main(int argc, char **argv)
{
	module_unittest_opt_parse(argc, argv, s_opt_map);
	testing::GTEST_FLAG(color) = "yes";
	testing::GTEST_FLAG(output) = "xml:./test.xml";
	testing::InitGoogleTest(&argc, argv);
	testing::AddGlobalTestEnvironment(new GlobalTest());
	return RUN_ALL_TESTS();
}
