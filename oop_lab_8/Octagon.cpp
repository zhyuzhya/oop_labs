#include <iostream>
#include <cmath>
#include "Octagon.h"

Octagon::Octagon() : Octagon(0) {}

Octagon::Octagon(size_t a) : side(a) {}

Octagon::Octagon(const Octagon& orig) {
    side = orig.side;
}

double Octagon::Square() {
	return 2 * (1 + sqrt(2)) * side * side;
}

void Octagon::Print() {
    std::cout << "8-A side: " << side;
    std::cout << ", S = " << this->Square();
}

std::istream& operator >> (std::istream &is, Octagon& pent) {
    is >> pent.side;
    return is;
}

std::ostream& operator<<(std::ostream &os, const Octagon& pent) {
    os << "Octagon with side: " << pent.side;
    return os;
}

Octagon& Octagon::operator= (const Octagon& orig) {
    if (this == &orig)
        return *this;
    side = orig.side;
    return *this;
}

bool Octagon::operator== (const Octagon& right) {
    if (side == right.side)
        return true;
    return false;
}
