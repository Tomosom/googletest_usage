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

#ifdef __cplusplus
extern "C"
{
#endif

struct test_opt {
	char cfg_path[256];
	char ext_path[256];
};

#ifdef __cplusplus
}
#endif

#endif
