#CPP=/opt/vs-linux/x86-arm/gcc-linaro-7.5.0-aarch64-linux-gnu/bin/aarch64-linux-gnu-g++
CPP=g++

INCS	:= \
	-I../0_googletest-release-1.11.0/googletest/include \
	-I../0_googletest-release-1.11.0/googletest/include/gtest \
	-I../json \
	-Icommon \

SRCS	:= \
	common/md5.c \
	common/test_parse.cpp \
	test.cpp \
	test_01_basic.cpp \

LIB_FLAGS:= \
	-L../0_googletest-release-1.11.0/lib -lgtest \
	-L../json -lcjson \
	-lpthread \

CFLAGS+=$(INCS)

all :
	$(CPP) $(CFLAGS) -o test $(SRCS) $(LIB_FLAGS)

prepare:
	cd ../0_googletest-release-1.11.0;cmake -G"Unix Makefiles" CMakeLists.txt;make
	cd ../json;make

clean:
	$(RM) test *.xml
