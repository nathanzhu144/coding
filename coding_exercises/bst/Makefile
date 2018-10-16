CXX = g++
CXXFLAGS = -g -o0 --std=c++11

bst_symmetry: bst_symmetry.o
	$(CXX) $(CXXFLAGS) bst_symmetry.cpp -o bst_symmetry.exe

bst_invert: bst_invert.o
	$(CXX) $(CXXFLAGS) bst_invert.cpp -o bst_invert.exe

bst_to_circular_dll: bst_to_circular_dll.o
	$(CXX) $(CXXFLAGS) bst_to_circular_dll.cpp -o bst_to_circular_dll.exe

bst_inorder: bst_inorder.o
	$(CXX) $(CXXFLAGS) bst_inorder.cpp -o bst_inorder.exe

clean:
	rm *.exe *.o