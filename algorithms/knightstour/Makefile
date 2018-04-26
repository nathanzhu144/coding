
CXX = g++
CXXFLAGS = -g -o0 --std=c++11
main: knightstour.o knightstour_main.o
	$(CXX) $(CXXFLAGS) knightstour.cpp knightstour_main.cpp -o knightstour_main.exe

test: knightstour.o knightstour_test.o
	$(CXX) $(CXXFLAGS) knightstour.cpp knightstour_test.cpp -o knightstour_test.exe

mod_knightstour: knightstour_mod.o
	$(CXX) $(CXXFLAGS) knightstour_mod.cpp -o knightstour_mod.exe

clean:
	rm -rf *.exe *.o