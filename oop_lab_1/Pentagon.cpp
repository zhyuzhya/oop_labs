#include "Pentagon.h"
#include <iostream>
#include <cmath>

Pentagon::Pentagon() : Pentagon(0) {
}

Pentagon::Pentagon(size_t a) : side(a) {
	std::cout << "Pentagon created with side = " << side << std::endl;
}

Pentagon::Pentagon(std::istream &is) {
	is >> side;
}

Pentagon::Pentagon(const Pentagon& orig) {
	std::cout << "Pentagon copy created" << std::endl;
	side = orig.side;
}

double Pentagon::Square() {
	return 0.25 * side * side * sqrt(25 + 10 * sqrt(5));
}

void Pentagon::Print() {
	std::cout << "Side of pentagon a = " << side << std::endl;
}

Pentagon::~Pentagon() {
	std::cout << "Pentagon deleted" << std::endl;
}