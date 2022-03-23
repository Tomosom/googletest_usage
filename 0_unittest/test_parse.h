#ifndef TEST_PARSE_H
#define TEST_PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <iostream>
#include <sys/time.h>
#include <map>

#include "test.h"
#include "cJSON.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct module_sub_param {
	char name[3][256];
	int square[2][3];
	int cube[2][2][2];
	double score[3];
} module_sub_param_s;

typedef struct module_param {
	int pipe;
	char input_path[256];
	char output_path[256];
	char md5[64];
	double db;
	module_sub_param_s sub_param;
} module_param_s;

void print_param(module_param_s *param);

int module_unittest_json_str_parse(char *p_dest, cJSON *p_item_obj, const char *p_key);
int module_unittest_json_int_parse(int *p_dest, cJSON *p_item_obj, const char *p_key);
int module_unittest_json_double_parse(double *p_dest, cJSON *p_item_obj, const char *p_key);
int module_unittest_json_str_array_parse(char (*p_dest)[256], cJSON *p_arr_obj, int dest_size); // todo: 类型需强制为char(*)[256]
int module_unittest_json_int_array_parse(int *p_dest, cJSON *p_arr_obj, int dest_size); // todo: 类型需强制为int
int module_unittest_json_double_array_parse(double *p_dest, cJSON *p_arr_obj, int dest_size); // todo: 类型需强制为double

int module_unittest_opt_parse(int argc, char **argv,
	std::map<std::string, module_unittest_opt_s> &p_opt_map);

#ifdef __cplusplus
}
#endif

#endif
