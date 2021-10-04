# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course - Lab 06

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


# Command: make Stocks_1
Stocks_1.o: Stocks_1.cpp
	$(PP) $(CXXFLAGS) -c Stocks_1.cpp -o $@
	
Stocks_1_objs := Stocks_1.o

Stocks_1: $(Stocks_1_objs)
	$(PP) $(CXXFLAGS) -o Stocks_1 $(Stocks_1_objs)


# Command: make Stocks
Stocks.o: Stocks.cpp
	$(PP) $(CXXFLAGS) -c Stocks.cpp -o $@
	
Stocks_objs := Stocks.o

Stocks: $(Stocks_objs)
	$(PP) $(CXXFLAGS) -o Stocks $(Stocks_objs)


# Command: make Product
ProductObjs := $(OBJECTS)/Product.o

Product: $(ProductObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Product $(ProductObjs)
	$(EXE)/./Product

$(OBJECTS)/Product.o: $(PROG)/Product.cpp $(CLASSES)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/Product.cpp -o $@

	


# Command: make maxSub1
maxSub1Objs := $(OBJECTS)/maxSub1.o

maxSub1: $(maxSub1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxSub1 $(maxSub1Objs)
	$(EXE)/./maxSub1

$(OBJECTS)/maxSub1.o: $(PROG)/maxSub1.cpp $(CLASSES)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/maxSub1.cpp -o $@



# Command: make maxSub2
maxSub2Objs := $(OBJECTS)/maxSub2.o

maxSub2: $(maxSub2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxSub2 $(maxSub2Objs)
	$(EXE)/./maxSub2

$(OBJECTS)/maxSub2.o: $(PROG)/maxSub2.cpp $(CLASSES)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/maxSub2.cpp -o $@



# Command: make maxSub3
maxSub3Objs := $(OBJECTS)/maxSub3.o

maxSub3: $(maxSub3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxSub3 $(maxSub3Objs)
	$(EXE)/./maxSub3

$(OBJECTS)/maxSub3.o: $(PROG)/maxSub3.cpp $(CLASSES)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/maxSub3.cpp -o $@



# Command: make maxSub4
maxSub4Objs := $(OBJECTS)/maxSub4.o

maxSub4: $(maxSub4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxSub4 $(maxSub4Objs)
	$(EXE)/./maxSub4

$(OBJECTS)/maxSub4.o: $(PROG)/maxSub4.cpp $(CLASSES)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/maxSub4.cpp -o $@



# Command: make maxSub
maxSubObjs := $(OBJECTS)/maxSub.o

maxSub: $(maxSubObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxSub $(maxSubObjs)
	$(EXE)/./maxSub

$(OBJECTS)/maxSub.o: $(PROG)/maxSub.cpp $(CLASSES)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/maxSub.cpp -o $@



# Command: make maxProd1
maxProd1Objs := $(OBJECTS)/maxProd1.o

maxProd1: $(maxProd1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxProd1 $(maxProd1Objs)
	$(EXE)/./maxProd1

$(OBJECTS)/maxProd1.o: $(PROG)/maxProd1.cpp $(CLASSES)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/maxProd1.cpp -o $@



# Command: make maxProd
maxProdObjs := $(OBJECTS)/maxProd.o

maxProd: $(maxProdObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxProd $(maxProdObjs)
	$(EXE)/./maxProd

$(OBJECTS)/maxProd.o: $(PROG)/maxProd.cpp $(CLASSES)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(PROG)/maxProd.cpp -o $@


# Make all
all: Stocks_1 Stocks

# Make clean
clean :
	rm -rf *.o Stocks_1 Stocks
