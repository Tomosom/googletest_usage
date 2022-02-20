CFLAGS=-I../googletest-release-1.11.0/googletest/include
CFLAGS+=-I../googletest-release-1.11.0/googletest/include/gtest
INC_FLAGS=-L../googletest-release-1.11.0/lib -lgtest -lpthread

#CPP=/opt/vs-linux/x86-arm/gcc-linaro-7.5.0-aarch64-linux-gnu/bin/aarch64-linux-gnu-g++
CPP=g++

all :
	$(CPP) $(CFLAGS) -o test test.cc $(INC_FLAGS)

clean :
	rm -rf test
