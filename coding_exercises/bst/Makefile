CXX = g++
CXXFLAGS = -g -o0 --std=c++11

bst_symmetry: bst_symmetry.o
	$(CXX) $(CXXFLAGS) bst_symmetry.cpp -o bst_symmetry.exe

bst_diameter: bst_diameter.o
	$(CXX) $(CXXFLAGS) bst_diameter.cpp -o bst_diameter.exe

bst_width: bst_width.o
	$(CXX) $(CXXFLAGS) bst_width.cpp -o bst_width.exe
	
bst_invert: bst_invert.o
	$(CXX) $(CXXFLAGS) bst_invert.cpp -o bst_invert.exe

bst_to_circular_dll: bst_to_circular_dll.o
	$(CXX) $(CXXFLAGS) bst_to_circular_dll.cpp -o bst_to_circular_dll.exe

bst_inorder: bst_inorder.o
	$(CXX) $(CXXFLAGS) bst_inorder.cpp -o bst_inorder.exe

bst_isfoldable: bst_isfoldable.o
	$(CXX) $(CXXFLAGS) bst_isfoldable.cpp -o bst_isfoldable.exe
	
clean:
	rm *.exe *.o