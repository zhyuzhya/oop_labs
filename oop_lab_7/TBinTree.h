#ifndef TBINTREE_H
#define TBINTREE_h

#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "TTreeItem.h"
#include "TIterator.h"

#include <memory>

template <class T, class TT> class TBinTree {
public:
    TBinTree();

    //Работа с  фигурами
    void InsertSubitem(TT *value);
    void DeleteByType(TT *value);
    void DeleteBySquare(double square);

    //Работа со списками
    void Push(T* value);
    bool Remove(T* value);
    void CheckEmpty();
    
    //Итераторы для перемещения по дереву
    TIterator<TTreeItem<T>, TT> begin();
    TIterator<TTreeItem<T>, TT> end();

    bool empty();

    template <class A, class AA> friend std::ostream& operator<<(std::ostream& os, const TBinTree<A, AA>& obj);

    virtual ~TBinTree();
private:
    TTreeItem<T> *root;
};

#endif
