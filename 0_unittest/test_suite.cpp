#include <stdio.h>
#include "test.h"
#include "test_parse.h"

#define module_pointer_check_return_void(ptr, ...) do { \
	if (ptr == NULL) { \
		printf(__VA_ARGS__); \
		return; \
	} \
} while (0)

static int module_unittest_path_parse(const char *cfg_path, module_param_s *param)
{
	int ret = 0;
	FILE *p_file = NULL;
	unsigned int file_len = 0;
	char *p_buf = NULL;
	cJSON *p_json = NULL;
	cJSON *p_sub_param = NULL;
	cJSON *p_name = NULL, *p_square = NULL, *p_cube = NULL, *p_score = NULL;

	p_file = fopen(cfg_path, "rb");
	if (p_file == NULL) {
		printf("fopen error\n");
		return -1;
	}

	fseek(p_file, 0, SEEK_END);
	file_len = ftell(p_file);
	fseek(p_file, 0, SEEK_SET);
	p_buf = (char *)malloc(file_len + 1);
	if (p_buf == NULL) {
		ret = -1;
		goto end;
	}

	fread(p_buf, 1 ,file_len, p_file);
	p_json = cJSON_Parse(p_buf);
	if (p_json == NULL) {
		printf("cjson parse error\n");
		goto end;
	}

	module_unittest_json_int_parse(&param->pipe, p_json, "pipe");
	module_unittest_json_str_parse(param->input_path, p_json, "input_path");
	module_unittest_json_str_parse(param->output_path, p_json, "output_path");
	module_unittest_json_str_parse(param->md5, p_json, "md5");
	module_unittest_json_double_parse(&param->db, p_json, "db");

	p_sub_param = cJSON_GetObjectItem(p_json, "sub_param");
	p_name = cJSON_GetObjectItem(p_sub_param, "name");
	module_unittest_json_str_array_parse(&param->sub_param.name[0], p_name, 3);

	p_square = cJSON_GetObjectItem(p_sub_param, "square");
	module_unittest_json_int_array_parse(&param->sub_param.square[0][0], p_square, 6);

	p_cube = cJSON_GetObjectItem(p_sub_param, "cube");
	module_unittest_json_int_array_parse(&param->sub_param.cube[0][0][0], p_cube, 8);

	p_score = cJSON_GetObjectItem(p_sub_param, "score");
	module_unittest_json_double_array_parse(param->sub_param.score, p_score, 3);

end:
	if (p_json) {
		cJSON_Delete(p_json);
	}
	if (p_buf) {
		free(p_buf);
	}
	fclose(p_file);

	return ret;
}

void module_suite1_case1(module_unittest_opt_s *opt)
{
	module_param_s param = {0};
	module_pointer_check_return_void(opt, "");
	printf("cfg_path:%s\n", opt->cfg_path);
	printf("ext_path:%s\n", opt->ext_path);

	module_unittest_path_parse(opt->cfg_path, &param);
	print_param(&param);
}

void module_suite1_case2(module_unittest_opt_s *opt)
{
	module_param_s param = {0};
	module_pointer_check_return_void(opt, "");
	printf("cfg_path:%s\n", opt->cfg_path);
	printf("ext_path:%s\n", opt->ext_path);

	module_unittest_path_parse(opt->cfg_path, &param);
	print_param(&param);
}

void module_suite2_case1(module_unittest_opt_s *opt)
{
	module_pointer_check_return_void(opt, "");
	printf("cfg_path:%s\n", opt->cfg_path);
	printf("ext_path:%s\n", opt->ext_path);
}

void module_suite2_case2(module_unittest_opt_s *opt)
{
	module_pointer_check_return_void(opt, "");
	printf("cfg_path:%s\n", opt->cfg_path);
	printf("ext_path:%s\n", opt->ext_path);
}
