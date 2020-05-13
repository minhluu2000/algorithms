all: test

test: Collection.o Collection_test.o Stress_ball.o
	c++ -std=c++11 Collection.o Collection_test.o Stress_ball.o -o test

Collection.o: Collection.cpp Collection.h
	c++ -std=c++11 -c Collection.cpp

Collection_test.o: Collection_test.cpp Collection_test.h
	c++ -std=c++11 -c Collection_test.cpp

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball.cpp

clean:
	rm -f *.o test
