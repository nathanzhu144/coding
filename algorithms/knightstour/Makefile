
CXX = g++
CXXFLAGS = -g -o0 --std=c++11 -Wall -Werror

knightstour: knightstour.o
	$(CXX) $(CXXFLAGS) knightstour.cpp -o knightstour.exe

mod_knightstour: knightstour_mod.o
	$(CXX) $(CXXFLAGS) knightstour_mod.cpp -o knightstour_mod.exe

clean:
	rm -rf *.exe *.o