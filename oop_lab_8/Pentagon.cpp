#include <iostream>
#include <cmath>
#include "Pentagon.h"

Pentagon::Pentagon() : Pentagon(0) {}

Pentagon::Pentagon(size_t a) : side(a) {}

Pentagon::Pentagon(const Pentagon& orig) {
    side = orig.side;
}

double Pentagon::Square() {
	return 0.25 * side * side * sqrt(25 + 10 * sqrt(5));
}

void Pentagon::Print() {
    std::cout << "5-A side: " << side;
    std::cout << ", S = " << this->Square();
}

std::istream& operator >> (std::istream &is, Pentagon& pent) {
    is >> pent.side;
    return is;
}

std::ostream& operator<<(std::ostream &os, const Pentagon& pent) {
    os << "Pentagon with side: " << pent.side;
    return os;
}

Pentagon& Pentagon::operator= (const Pentagon& orig) {
    if (this == &orig)
        return *this;
    side = orig.side;
    return *this;
}

bool Pentagon::operator== (const Pentagon& right) {
    if (side == right.side)
        return true;
    return false;
}
