all: main

main: BSTree.o BSTree_main.o 
	c++ -std=c++11 BSTree.o BSTree_main.o -o main

BSTree.o: BSTree.cpp BSTree.h 
	c++ -std=c++11 -c -g BSTree.cpp

BSTree_main.o: BSTree_main.cpp
	c++ -std=c++11 -c -g BSTree_main.cpp

clean:
	rm *.o data-output-files/*.txt main
