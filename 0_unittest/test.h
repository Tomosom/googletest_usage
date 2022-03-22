#ifndef __TEST_H__
#define __TEST_H__

#include "gtest.h"

using namespace std;

typedef struct module_unittest_opt {
	char cfg_path[256];
	char ext_path[256];
} module_unittest_opt_s;

#define TEST_MODULE(suite_name, case_name) \
	TEST(suite_name, case_name) \
	{ module_##suite_name##_##case_name(NULL); }

#define TEST_MODULE_WITH_CFG(suite_name, case_name, cfg_name) \
	TEST(suite_name, case_name) \
	{ module_##suite_name##_##case_name(&s_opt_map[#cfg_name]); }

void module_suite1_case1(module_unittest_opt_s *opt);
void module_suite1_case2(module_unittest_opt_s *opt);
void module_suite2_case1(module_unittest_opt_s *opt);
void module_suite2_case2(module_unittest_opt_s *opt);

#endif
