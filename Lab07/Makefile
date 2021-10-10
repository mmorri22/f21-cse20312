# This is the Makefile for the CSE 20312 course - Lab 07

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

	
# Command: make testMinHeap
find_kth.o: find_kth.cpp
	$(PP) $(CXXFLAGS) -c find_kth.cpp -o $@
	
find_kthObjs := find_kth.o 

find_kth: $(find_kthObjs)
	$(PP) $(CXXFLAGS) -o find_kth $(find_kthObjs)
	


# Command: make find_median
find_median_Objs := find_median.o 

find_median: $(find_median_Objs)
	$(PP) $(CXXFLAGS) -o find_median $(find_median_Objs)

find_median.o: find_median.cpp
	$(PP) $(CXXFLAGS) -c find_median.cpp -o $@


# Command: make find_median_sol
find_median_sol_Objs := find_median_sol.o 

find_median_sol: $(find_median_sol_Objs)
	$(PP) $(CXXFLAGS) -o find_median_sol $(find_median_sol_Objs)

find_median_sol.o: find_median_sol.cpp
	$(PP) $(CXXFLAGS) -c find_median_sol.cpp -o $@


# Make all
all: find_kth find_median
	

# Make clean
clean :
	rm -rf *.o find_kth find_median find_median_sol
