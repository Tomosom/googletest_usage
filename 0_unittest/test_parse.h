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

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct module_sub_param {
	unsigned int square[2][3];
	unsigned int cube[2][2][2];
} module_sub_param_s;

typedef struct module_param {
	char input_path[256];
	char output_path[256];
	char md5[64];
	int pipe;
	module_sub_param_s sub_param;
} module_param_s;

int module_unittest_opt_parse(int argc, char **argv,
	std::map<std::string, module_unittest_opt_s> &p_opt_map);

#ifdef __cplusplus
}
#endif

#endif
