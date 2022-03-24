#include <stdio.h>
#include "test_parse.h"

int module_unittest_fmt_02_parse(const char *cfg_path, module_param_fmt_02_s *param)
{
	int ret = 0;
	FILE *p_file = NULL;
	unsigned int file_len = 0;
	char *p_buf = NULL;
	cJSON *p_json = NULL;
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
	module_unittest_json_str_parse(param->path, p_json, "path");
	module_unittest_json_double_parse(&param->db, p_json, "db");

	p_name = cJSON_GetObjectItem(p_json, "name");
	module_unittest_json_str_array_parse(&param->name[0], p_name, 3);

	p_square = cJSON_GetObjectItem(p_json, "square");
	module_unittest_json_int_array_parse(&param->square[0][0], p_square, 6);

	p_score = cJSON_GetObjectItem(p_json, "score");
	module_unittest_json_double_array_parse(param->score, p_score, 3);

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