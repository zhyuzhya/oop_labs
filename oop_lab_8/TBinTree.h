#ifndef TBINTREE_H
#define TBINTREE_h

#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "TTreeItem.h"
#include "TIterator.h"

#include <memory>

template <class T> class TBinTree {
public:
    TBinTree();
    TBinTree(const TBinTree<T>& orig);

    void push(int FID, int ID, std::shared_ptr<T> figure);
    std::shared_ptr<T> get(int ID);
    int check(int ID);
    void QuickSort();
    void QuickSortS();

    void del(int ID);
    
    TIterator<TTreeItem<T>, T> begin();
    TIterator<TTreeItem<T>, T> end();
    bool empty();

    template <class A> friend std::ostream& operator<<(std::ostream& os, const TBinTree<A>& obj);

    virtual ~TBinTree();
private:
    TTreeItem<T> *root;
};

#endif
