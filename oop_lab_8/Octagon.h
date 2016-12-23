#ifndef OCTAGON_H
#define OCTAGON_H

#include <iostream>
#include "Figure.h"

class Octagon : public Figure {
public:
    Octagon();
    Octagon(size_t a);
    Octagon(const Octagon& orig);
    double Square() override;
    void Print() override;
    friend std::istream& operator >> (std::istream &is, Octagon& pent);
    friend std::ostream& operator <<(std::ostream &os, const Octagon& oct);
    Octagon& operator= (const Octagon& orig);
    bool operator== (const Octagon& right);
private:
    size_t side;
};

#endif