#include "Pentagon.h"
#include <iostream>
#include <cmath>
 
Pentagon::Pentagon() : Pentagon(0) {
}
 
Pentagon::Pentagon(size_t a) : side(a) {
}
 
 
Pentagon::Pentagon(const Pentagon& orig) {
    side = orig.side;
}


Pentagon& Pentagon::operator=(const Pentagon& right) {
    if (this == &right) {
        return *this;
    }
    side = right.side;
    return *this;
}


Pentagon& Pentagon::operator++() {
    side++;
    return *this;
}

Pentagon operator+(const Pentagon& left, const Pentagon& right) {
    return Pentagon(left.side + right.side);
}
 
 
Pentagon::~Pentagon() {
}

std::ostream& operator<<(std::ostream& os, const Pentagon& obj) {
    os << obj.side << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Pentagon& obj) {
    is >> obj.side;
    return is;
}
