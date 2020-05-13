all: test

test: Sort.o
	c++ -std=c++11 Sort.o -o test

Sort.o: Sort.cpp Sort.h
	c++ -std=c++11 -c Sort.cpp

clean:
	rm -f *.o test
