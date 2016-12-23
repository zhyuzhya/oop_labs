
#ifndef OCTAGON_H
#define OCTAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

//8-угольник
class Octagon : public Figure {
public:
	Octagon();
	Octagon(std::istream &is);
	Octagon(size_t a);
	Octagon(const Octagon& orig);

	double Square() override;
	void Print() override;

	virtual ~Octagon();
private:
	size_t side;
};

#endif
