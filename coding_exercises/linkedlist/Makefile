CXX = g++
CXXFLAGS = -g -o0 --std=c++11

reverse_linked: reverse_linked.o
	$(CXX) $(CXXFLAGS) reverse_linked.cpp -o reverse_linked.exe

sum_linked: sum_linked.o
	$(CXX) $(CXXFLAGS) sum_linked.cpp -o sum_linked.exe
	
loop_exist_linked: loop_exist_linked.o
	$(CXX) $(CXXFLAGS) loop_exist_linked.cpp -o loop_exist_linked.exe

shift_linked: shift_linked.o
	$(CXX) $(CXXFLAGS) shift_linked.cpp -o shift_linked.exe

merge_list: merge_list.o
	$(CXX) $(CXXFLAGS) merge_list.cpp -o merge_list.exe

rearrange_list: rearrange_list.o
	$(CXX) $(CXXFLAGS) rearrange_list.cpp -o rearrange_list.exe

clean:
	rm *.exe *.o