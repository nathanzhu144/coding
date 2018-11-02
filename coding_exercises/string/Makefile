CXX = g++
CXXFLAGS = -g -o0 --std=c++11

sort_chars_by_frequency:
	$(CXX) $(CXXFLAGS) sort_chars_by_frequency.cpp -o sort_chars_by_frequency.exe
	
add_strings:
	$(CXX) $(CXXFLAGS) add_strings.cpp -o add_strings.exe
	
strcpy: strcpy.o
	$(CXX) $(CXXFLAGS) strcpy.cpp -o strcpy.exe

longest_substring_without_repeat: longest_substring_without_repeat.o
	$(CXX) $(CXXFLAGS) longest_substring_without_repeat.cpp -o longest_substring_without_repeat.exe

clean:
	rm *.exe *.o