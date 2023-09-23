CXX = g++
CXXFALGS = -Wall -02

myprogram: main.cpp Stack&Queue.hpp Sort.hpp shuffle.hpp magicitems.txt
	$(CXX) $(CXXFALGS) -o myprogram main.cpp Stack&Queue.hpp Sort.hpp shuffle.hpp magicitems.txt

clean:
	rm -f myprogram