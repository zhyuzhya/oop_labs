#ifndef TTREEITEM_H
#define TTREEITEM_H

#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include <memory>
#include "TAllocationBlock.h"

template <class T> class TTreeItem {
public:
    TTreeItem();
    TTreeItem(T* figure);
    TTreeItem<T>* Find(int ID);
    void Print(std::ostream& os);
    void Push(TTreeItem<T> *item);
    T* GetFigure();
    TTreeItem<T>* FindMostLeft();
    TTreeItem<T>* FindMostRight();
    TTreeItem<T>* GetNext();
    TTreeItem<T>* GetLeft();
    void PushStruct(T* item);

    template <class A> friend std::ostream& operator<<(std::ostream& os, const TTreeItem<A>& obj);
    void * operator new(size_t size);
    void operator delete(void *p);
    virtual ~TTreeItem();
private:
    T* figure;
    int ID;
    TTreeItem<T> *left;
    TTreeItem<T> *right;
    TTreeItem<T> *fath;
    static TAllocationBlock ItemAllocator;
};

#endif
