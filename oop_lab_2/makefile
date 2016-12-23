CC = g++
FLAGS = -std=c++11 -Wall -g
FIGURES_CPP = Pentagon.cpp 
FIGURES_H = Pentagon.h 

STRUCTS_CPP = TBinTree.cpp TTreeItem.cpp 
STRUCTS_H = TBinTree.h TTreeItem.h 

all: lab2

lab2:  $(FIGURES_H) $(FIGURES_CPP) $(STRUCTS_CPP) $(STRUCTS_H) main.cpp
	$(CC) $(FLAGS) main.cpp $(FIGURES_CPP) $(STRUCTS_CPP) -o lab2
