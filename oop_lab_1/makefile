CC = g++
FLAGS = -std=c++11 -Wall -g
FIGURES_CPP = Pentagon.cpp Hexagon.cpp Octagon.cpp
FIGURES_H = Pentagon.h Hexagon.h Octagon.h

all: lab1

lab1:  $(FIGURES_H) $(FIGURES_CPP) main.cpp
	$(CC) $(FLAGS) main.cpp $(FIGURES_CPP) $(STRUCTS_CPP) -o lab1
