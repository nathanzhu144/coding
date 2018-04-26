
CXX = g++
CXXFLAGS = -g -o0 --std=c++11 -Wall -Werror

index_extra_array_element: index_extra_array_element.o
	$(CXX) $(CXXFLAGS) index_extra_array_element.cpp -o index_extra_array_element.exe

stock_span: stock_span.o
	$(CXX) $(CXXFLAGS) stock_span.cpp -o stock_span.exe

nqueens: nqueens.o
	$(CXX) $(CXXFLAGS) nqueens.cpp -o nqueens.exe

clean:
	rm *.exe *.o