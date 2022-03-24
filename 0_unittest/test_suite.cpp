#include <stdio.h>
#include "test.h"
#include "test_parse.h"

#define module_pointer_check_return_void(ptr, ...) do { \
	if (ptr == NULL) { \
		printf(__VA_ARGS__); \
		return; \
	} \
} while (0)

void module_suite1_case1(module_unittest_opt_s *opt)
{
	module_param_fmt_01_s param = {0};
	module_pointer_check_return_void(opt, "");
	printf("cfg_path:%s\n", opt->cfg_path);
	printf("ext_path:%s\n", opt->ext_path);
	module_unittest_fmt_01_parse(opt->cfg_path, &param);
	print_param_fmt_01(&param);
}

void module_suite1_case2(module_unittest_opt_s *opt)
{
	module_param_fmt_01_s param = {0};
	module_pointer_check_return_void(opt, "");
	printf("cfg_path:%s\n", opt->cfg_path);
	printf("ext_path:%s\n", opt->ext_path);
	module_unittest_fmt_01_parse(opt->cfg_path, &param);
	print_param_fmt_01(&param);
}

void module_suite2_case1(module_unittest_opt_s *opt)
{
	module_param_fmt_02_s param = {0};
	module_pointer_check_return_void(opt, "");
	printf("cfg_path:%s\n", opt->cfg_path);
	printf("ext_path:%s\n", opt->ext_path);
	module_unittest_fmt_02_parse(opt->cfg_path, &param);
	print_param_fmt_02(&param);
}

void module_suite2_case2(module_unittest_opt_s *opt)
{
	module_param_fmt_02_s param = {0};
	module_pointer_check_return_void(opt, "");
	printf("cfg_path:%s\n", opt->cfg_path);
	printf("ext_path:%s\n", opt->ext_path);
	module_unittest_fmt_02_parse(opt->cfg_path, &param);
	print_param_fmt_02(&param);
}
