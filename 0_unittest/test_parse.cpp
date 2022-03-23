#include "test_parse.h"

#define CFG_PATH "--module_cfgpath="

void print_param(module_param_s *param)
{
	printf("\nprint param start\n");
	printf("pipe: %d\n",		param->pipe);
	printf("input_path: %s\n",	param->input_path);
	printf("output_path: %s\n",	param->output_path);
	printf("md5: ");
	for (int i = 0; i < 64; i++) {
		printf("%c", param->md5[i]);
	}
	printf("\n");
	printf("db: %lf\n", param->db);

	printf("name: %s,%s,%s\n",
		param->sub_param.name[0],
		param->sub_param.name[1],
		param->sub_param.name[2]);

	printf("square: %d,%d,%d,%d,%d,%d\n",
		param->sub_param.square[0][0],
		param->sub_param.square[0][1],
		param->sub_param.square[0][2],
		param->sub_param.square[1][0],
		param->sub_param.square[1][1],
		param->sub_param.square[1][2]);

	printf("cube: %d,%d,%d,%d,%d,%d,%d,%d\n",
		param->sub_param.cube[0][0][0],
		param->sub_param.cube[0][0][1],
		param->sub_param.cube[0][1][0],
		param->sub_param.cube[0][1][1],
		param->sub_param.cube[1][0][0],
		param->sub_param.cube[1][0][1],
		param->sub_param.cube[1][1][0],
		param->sub_param.cube[1][1][1]);

	printf("score: %lf,%lf,%lf\n",
		param->sub_param.score[0],
		param->sub_param.score[1],
		param->sub_param.score[2]);
}

int module_unittest_json_str_parse(char *p_dest, cJSON *p_item_obj, const char *p_key)
{
	cJSON *p_obj = NULL;
	p_obj = cJSON_GetObjectItem(p_item_obj, p_key);
	if (p_obj == NULL) {
		return -1;
	}
	memcpy(p_dest, p_obj->valuestring, strlen(p_obj->valuestring));
	return 0;
}

int module_unittest_json_int_parse(int *p_dest, cJSON *p_item_obj, const char *p_key)
{
	cJSON *p_obj = NULL;
	p_obj = cJSON_GetObjectItem(p_item_obj, p_key);
	if (p_obj == NULL) {
		return -1;
	}
	*p_dest = p_obj->valueint;
	return 0;
}

int module_unittest_json_double_parse(double *p_dest, cJSON *p_item_obj, const char *p_key)
{
	cJSON *p_obj = NULL;
	p_obj = cJSON_GetObjectItem(p_item_obj, p_key);
	if (p_obj == NULL) {
		return -1;
	}
	*p_dest = p_obj->valuedouble;
	return 0;
}

int module_unittest_json_str_array_parse(char (*p_dest)[256], cJSON *p_arr_obj, int dest_size)
{
	int obj_size;

	obj_size = cJSON_GetArraySize(p_arr_obj);
	if (obj_size < dest_size) {
		printf("json size error\n");
		return -1;
	}

	for (int i = 0; i < dest_size; i++) {
		cJSON *p_item = cJSON_GetArrayItem(p_arr_obj, i);
		memcpy(p_dest[i], p_item->valuestring, strlen(p_item->valuestring));
	}
	return 0;
}

int module_unittest_json_int_array_parse(int *p_dest, cJSON *p_arr_obj, int dest_size)
{
	int obj_size;

	obj_size = cJSON_GetArraySize(p_arr_obj);
	if (obj_size < dest_size) {
		printf("json size error\n");
		return -1;
	}

	for (int i = 0; i < dest_size; i++) {
		cJSON *p_item = cJSON_GetArrayItem(p_arr_obj, i);
		p_dest[i] = p_item->valueint;
	}
	return 0;
}

int module_unittest_json_double_array_parse(double *p_dest, cJSON *p_arr_obj, int dest_size)
{
	int obj_size;

	obj_size = cJSON_GetArraySize(p_arr_obj);
	if (obj_size < dest_size) {
		printf("json size error\n");
		return -1;
	}

	for (int i = 0; i < dest_size; i++) {
		cJSON *p_item = cJSON_GetArrayItem(p_arr_obj, i);
		p_dest[i] = p_item->valuedouble;
	}
	return 0;
}

static int module_unittest_path_parse(char *p_path,
	std::map<std::string, module_unittest_opt_s> &p_opt_map)
{
	int ret = -1;
	unsigned int file_len = 0, number = 0, i = 0;
	FILE *p_file = NULL;
	char *p_buf = NULL;
	cJSON *p_json = NULL, *p_arr_obj = NULL;
	char cfg_name[64];
	module_unittest_opt_s opt;

	p_file = fopen(p_path, "rb");
	if (p_file == NULL) {
		return -1;
	}

	fseek(p_file, 0, SEEK_END);
	file_len = ftell(p_file);
	fseek(p_file, 0, SEEK_SET);
	p_buf = (char *)malloc(file_len + 1);
	if (p_buf == NULL) {
		goto end;
	}

	fread(p_buf, 1 ,file_len, p_file);

	p_json = cJSON_Parse(p_buf);
	if (p_json == NULL) {
		goto end;
	}

	number = cJSON_GetArraySize(p_json);
	if (number == 0) {
		goto end;
	}

	for(i = 0; i < number; i++) {
		p_arr_obj = cJSON_GetArrayItem(p_json, i);
		memset(cfg_name, 0, sizeof(cfg_name));
		memset(&opt, 0, sizeof(module_unittest_opt_s));
		module_unittest_json_str_parse(cfg_name, p_arr_obj, "cfg_name");
		module_unittest_json_str_parse(opt.cfg_path, p_arr_obj, "cfg_path");
		module_unittest_json_str_parse(opt.ext_path, p_arr_obj, "ext_path");
		p_opt_map[cfg_name] = opt;
	}
	ret = 0;
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

int module_unittest_opt_parse(int argc, char **argv,
	std::map<std::string, module_unittest_opt_s> &p_opt_map)
{
	char path[256];

	memset(path, 0, sizeof(path));

	for (int i = 0; i < argc; i++) {
		if (argv[i] != NULL &&
			strlen(argv[i]) >= strlen(CFG_PATH) &&
			strncmp(argv[i], CFG_PATH, strlen(CFG_PATH)) == 0) {
			strcpy(path, argv[i] + strlen(CFG_PATH));
			printf("cfg_path = %s\n", path);
		}
	}

	return module_unittest_path_parse(path, p_opt_map);
}
