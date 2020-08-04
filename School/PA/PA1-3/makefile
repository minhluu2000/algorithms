all: test

test: Collection_test.o Stress_ball.o Jeans.o
	c++ -std=c++11 Collection_test.o Stress_ball.o Jeans.o -o test

Collection_test.o: Collection_test.cpp
	c++ -std=c++11 -c Collection_test.cpp
	
Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball.cpp

Jeans.o: Jeans.cpp Jeans.h
	c++ -std=c++11 -c Jeans.cpp

clean:
	rm -f *.o test
