CC = g++
FLAGS = -std=c++11 -Wall
FIGURES_CPP = Pentagon.cpp Hexagon.cpp Octagon.cpp
FIGURES_H = Pentagon.h Hexagon.h Octagon.h
STRUCTS_CPP = TBinTree.cpp TTreeItem.cpp 
STRUCTS_H = TBinTree.h TTreeItem.h TIterator.h 

all: lab5

lab5:  $(FIGURES_H) $(FIGURES_CPP) $(STRUCTS_CPP) $(STRUCTS_H) main2.cpp
	$(CC) $(FLAGS) main2.cpp $(FIGURES_CPP) $(STRUCTS_CPP) -o lab5


