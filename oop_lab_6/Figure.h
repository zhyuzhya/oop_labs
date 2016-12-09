#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
//#include "TAllocationBlock.h"

class Figure {
public:
	virtual double Square() = 0;
    virtual void Print() = 0;
    virtual ~Figure() {};
    friend std::ostream& operator <<(std::ostream &os, Figure& fig) {
        fig.Print();
        return os;
    }
    /*
    void * operator new(size_t size) {
        return FigureItemAllocator.Allocate();
    }
    void operator delete(void *p) {
        FigureItemAllocator.Deallocate(p);
    }
    TAllocationBlock Figure::FigureItemAllocator(sizeof(Figure), 100);
    */
private:
    //static TAllocationBlock FigureItemAllocator;
};

#endif
