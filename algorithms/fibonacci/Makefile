CXX = g++
CXXFLAGS = -g -o0 --std=c++11 -Wall -Werror


fibonacci: fibonacci.o
	$(CXX) $(CXXFLAGS) fibonacci.cpp -o fibonacci.exe

badfibonacci: badfibonacci.o
	$(CXX) $(CXXFLAGS) badfibonacci.cpp -o badfibonacci.exe

clean:
	rm *.exe *.o