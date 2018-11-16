CXX = g++
CXXFLAGS = -g -o0 --std=c++11

dutch_flag: dutch_flag.o
	$(CXX) $(CXXFLAGS) dutch_flag.cpp -o dutch_flag.exe

sliding_window: sliding_window.o
	$(CXX) $(CXXFLAGS) sliding_window.cpp -o sliding_window.exe

permutation: permutation.o 
	$(CXX) $(CXXFLAGS) permutation.cpp -o permutation.exe

count_element_in_sorted: count_element_in_sorted.o
	$(CXX) $(CXXFLAGS) count_element_in_sorted.cpp -o count_element_in_sorted.exe
	
longest_cons: longest_cons.o
	$(CXX) $(CXXFLAGS) longest_cons.cpp -o longest_cons.exe
	
clean:
	rm *.exe *.o