#include "Hexagon.h"
#include <iostream>
#include <cmath>

Hexagon::Hexagon() : Hexagon(0) {
}

Hexagon::Hexagon(size_t a) : side(a) {
	std::cout << "Hexagon created with side = " << side << std::endl;
}

Hexagon::Hexagon(std::istream &is) {
	is >> side;
}

Hexagon::Hexagon(const Hexagon& orig) {
	std::cout << "Hexagon copy created" << std::endl;
	side = orig.side;
}

double Hexagon::Square() {
	return 0.5 * 3 * sqrt(3) * side * side;
}

void Hexagon::Print() {
	std::cout << "Side of Hexagon a = " << side << std::endl;
}

Hexagon::~Hexagon() {
	std::cout << "Hexagon deleted" << std::endl;
}