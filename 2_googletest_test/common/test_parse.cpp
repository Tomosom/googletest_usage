#include "test_parse.h"

#define CFG_PATH "--vdec-cfgpath="

int test_opt_parse(int argc, char **argv,
	std::map<std::string, struct test_opt> &p_opt_map)
{
	//int c = 0, option_index = 0;
	char path[256];

	memset(path, 0, sizeof(path));

	for (int i = 0; i < argc; i++) {
		if (argv[i] != NULL
			&& strlen(argv[i]) >= strlen(CFG_PATH)
			&& strncmp(argv[i], CFG_PATH, strlen(CFG_PATH)) == 0) {
			strcpy(path, argv[i] + strlen(CFG_PATH));
			printf("cfg_path = %s\n", path);
		}
	}

	//return vdec_unittest_path_parse(path, p_opt_map);
	return 0;
}

