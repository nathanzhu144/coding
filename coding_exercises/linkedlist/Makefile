CXX = g++
CXXFLAGS = -g -o0 --std=c++11

reverse_linked: reverse_linked.o
	$(CXX) $(CXXFLAGS) reverse_linked.cpp -o reverse_linked.exe

sum_linked: sum_linked.o
	$(CXX) $(CXXFLAGS) sum_linked.cpp -o sum_linked.exe
	
loop_exist_linked: loop_exist_linked.o
	$(CXX) $(CXXFLAGS) loop_exist_linked.cpp -o loop_exist_linked.exe
	
clean:
	rm *.exe *.o