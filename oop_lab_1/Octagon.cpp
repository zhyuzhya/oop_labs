#include "Octagon.h"
#include <iostream>
#include <cmath>

Octagon::Octagon() : Octagon(0) {
}

Octagon::Octagon(size_t a) : side(a) {
	std::cout << "Octagon created with side = " << side << std::endl;
}

Octagon::Octagon(std::istream &is) {
	is >> side;
}

Octagon::Octagon(const Octagon& orig) {
	std::cout << "Octagon copy created" << std::endl;
	side = orig.side;
}

double Octagon::Square() {
	return 2 * (1 + sqrt(2)) * side * side;
}

void Octagon::Print() {
	std::cout << "Side of Octagon a = " << side << std::endl;
}

Octagon::~Octagon() {
	std::cout << "Octagon deleted" << std::endl;
}