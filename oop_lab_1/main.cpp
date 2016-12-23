#include <cstdlib>
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"

int main() {
	std::cout << "Enter Pentagon's (5-angles) side: ";
	Figure *pentagon = new Pentagon(std::cin);
	pentagon->Print();
	std::cout << "Pentagon's square = " << pentagon->Square() << std::endl;
	delete pentagon;

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Enter Hexagon's (6-angles) side: ";
	Figure *hexagon = new Hexagon(std::cin);
	hexagon->Print();
	std::cout << "Hexagon's square = " << hexagon->Square() << std::endl;
	delete hexagon;

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Enter Octagon's (8-angles) side: ";
	Figure *octagon = new Octagon(std::cin);
	octagon->Print();
	std::cout << "Octagon's square = " << octagon->Square() << std::endl;
	delete octagon;

	return 0;
}