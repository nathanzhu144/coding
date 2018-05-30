CXX = g++
CXXFLAGS = -g -o0 --std=c++11


move_semantics: move_semantics.o
	$(CXX) $(CXXFLAGS) move_semantics.cpp -o move_semantics.exe

static: 
	cppcheck --language=c++ --enable=all --suppress=missingIncludeSystem *.c* *.h*]