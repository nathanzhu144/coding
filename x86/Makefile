CXX = g++
CXXFLAGS = -g -O0 --std=c++11


helloworld: helloworld.o
	$(CXX) $(CXXFLAGS) helloworld.cpp -o helloworld.exe

static: 
	cppcheck --language=c++ --enable=all --suppress=missingIncludeSystem *.c* *.h*]