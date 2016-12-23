#ifndef TTREEITEM_H
#define TTREEITEM_H

#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include <memory>

template <class T> class TTreeItem {
public:
    TTreeItem(std::shared_ptr<T> figure, int ID);
    TTreeItem(const TTreeItem<T>& orig);
    TTreeItem<T>* find(int ID);
    void print(std::ostream& os);
    void push(TTreeItem<T> *item);
    std::shared_ptr<T> GetFigure();
    void SetFigure(std::shared_ptr<T> fig);
    TTreeItem<T>* findMostLeft();
    TTreeItem<T>* findMostRight();
    TTreeItem<T>* getNext();

    template <class A> friend std::ostream& operator<<(std::ostream& os, const TTreeItem<A>& obj);
    virtual ~TTreeItem();
private:
    std::shared_ptr<T> figure;
    int ID;
    TTreeItem<T> *left;
    TTreeItem<T> *right;
    TTreeItem<T> *fath;
};

#endif
