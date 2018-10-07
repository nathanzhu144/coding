CXX = g++
CXXFLAGS = -g -o0 --std=c++11

dutch_flag: dutch_flag.o
	$(CXX) $(CXXFLAGS) dutch_flag.cpp -o dutch_flag.exe

sliding_window: sliding_window.o
	$(CXX) $(CXXFLAGS) sliding_window.cpp -o sliding_window.exe
	
clean:
	rm *.exe *.o