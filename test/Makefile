CFLAGS=-I../googletest-release-1.11.0/googletest/include
CFLAGS+=-I../googletest-release-1.11.0/googletest/include/gtest
INC_FLAGS=-L../googletest-release-1.11.0/lib -lgtest -lpthread
all :
	g++ $(CFLAGS) -o test test.cc $(INC_FLAGS)

clean :
	rm -rf test
