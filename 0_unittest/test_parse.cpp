#include "test_parse.h"
#include "cJSON.h"

#define CFG_PATH "--module_cfgpath="

void print_param(module_param_s *param)
{
	printf("pipe: %d\n",		param->pipe);
	printf("input_path: %s\n",	param->input_path);
	printf("output_path: %s\n",	param->output_path);

	printf("md5: ");
	for (int i = 0; i < 64; i++) {
		printf("%c", param->md5[i]);
	}
	printf("\n");

	printf("square: %d,%d,%d,%d,%d,%d\n",
		param->sub_param.square[0][0],
		param->sub_param.square[0][1],
		param->sub_param.square[0][2],
		param->sub_param.square[1][0],
		param->sub_param.square[1][1],
		param->sub_param.square[1][2]);

	printf("cube: %d,%d,%d,%d,%d,%d,%d,%d,\n",
		param->sub_param.cube[0][0][0],
		param->sub_param.cube[0][0][1],
		param->sub_param.cube[0][1][0],
		param->sub_param.cube[0][1][1],
		param->sub_param.cube[1][0][0],
		param->sub_param.cube[1][0][1],
		param->sub_param.cube[1][1][0],
		param->sub_param.cube[1][1][1]);
}

static int module_unittest_json_str_parse(char *p_dest, cJSON *p_item_obj, const char *p_key)
{
	cJSON *p_obj = NULL;
	p_obj = cJSON_GetObjectItem(p_item_obj, p_key);
	if (p_obj == NULL) {
		return -1;
	}
	memcpy(p_dest, p_obj->valuestring, strlen(p_obj->valuestring));
	return 0;
}

static int module_unittest_json_int_parse(void *p_dest, cJSON *p_item_obj, const char *p_key)
{
	cJSON *p_obj = NULL;
	p_obj = cJSON_GetObjectItem(p_item_obj, p_key);
	if (p_obj == NULL) {
		return -1;
	}
	*(int *)p_dest = p_obj->valueint;
	return 0;
}

static int vdec_unittest_path_parse(char *p_path,
	std::map<std::string, module_unittest_opt_s> &p_opt_map)
{

	return 0;
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

	return vdec_unittest_path_parse(path, p_opt_map);
}
