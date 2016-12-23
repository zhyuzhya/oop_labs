
#ifndef PENTAGON_H
#define PENTAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

//5-真真真真
class Pentagon: public Figure{
public:
	Pentagon();
	Pentagon(std::istream &is);
	Pentagon(size_t a);
	Pentagon(const Pentagon& orig);

	double Square() override;
	void Print() override;

	virtual ~Pentagon();
private:
	size_t side;
};

#endif 
