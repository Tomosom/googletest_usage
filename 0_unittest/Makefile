#CPP=/opt/vs-linux/x86-arm/gcc-linaro-7.5.0-aarch64-linux-gnu/bin/aarch64-linux-gnu-g++
CPP=g++

INCS	:= \
	-I../1_googletest-release-1.11.0/googletest/include \
	-I../1_googletest-release-1.11.0/googletest/include/gtest \
	-I../2_json \
	-I../3_md5 \

SRCS	:= \
	test.cpp \
	test_parse.cpp \
	test_01_basic.cpp \

LIB_FLAGS:= \
	-L../1_googletest-release-1.11.0/lib -lgtest \
	-L../2_json -lcjson \
	-L../3_md5 -lmd5 \
	-lpthread \

CFLAGS+=$(INCS)

all :
	$(CPP) $(CFLAGS) -o test $(SRCS) $(LIB_FLAGS)

prepare:
	cd ../1_googletest-release-1.11.0;cmake -G"Unix Makefiles" CMakeLists.txt;make
	cd ../2_json;make
	cd ../3_md5;make

clean:
	$(RM) test *.xml
