#include "TBinTree.h"
#include "TTreeItem.h"
#include "TIterator.h"
#include <iostream>
#include <memory>
#include <typeinfo>

#define MAX_CONT_SIZE 5

template <class T, class TT> TBinTree<T, TT>::TBinTree() : root(nullptr) {
}



template <class T, class TT> TBinTree<T, TT>::~TBinTree() {
    delete root;
}

template <class T, class TT> void TBinTree<T, TT>::InsertSubitem(TT* value) {
    if (!root) {
        root = new TTreeItem<T>;
        T* list = new T;
        list->PushBack(value);
        root->PushStruct(list);
        return;
    }
    TTreeItem<T>* node = root;
    while (node->GetFigure()->Size() == MAX_CONT_SIZE && node->GetLeft()) {
        node = node->GetLeft();
    }
    if (node->GetFigure()->Size() == MAX_CONT_SIZE) {
        T* list = new T;
        TTreeItem<T>* item = new TTreeItem<T>;
        list->PushBack(value);
        item->PushStruct(list);
        node->Push(item);
    } else {
        T* list = node->GetFigure();
        list->PushBack(value);
    }

}

template <class T, class TT> void TBinTree<T, TT>::DeleteBySquare(double square) {
    for (auto i: *this) {
        int j = 0;
        while (j < i->GetFigure()->Size()) {
            TT* fig = i->GetFigure()->Get(j);
            if (fig->Square() < square) {
                i->GetFigure()->Delete(j--);
            }
            j++;
        }
    }
}

template <class T, class TT> void TBinTree<T, TT>::DeleteByType(TT *type) {
    for (auto i: *this) {
        int j = 0;
        while (j < i->GetFigure()->Size()) {
            TT* fig = i->GetFigure()->Get(j);
            if (typeid(*fig) == typeid(*type)) {
                i->GetFigure()->Delete(j--);
            }
            j++;
        }
    }
}
template <class T, class TT> 
void TBinTree<T, TT>::CheckEmpty() {
    for (auto i: *this) {
        if (!i->GetFigure()->Size()) {
            delete i;
        }
    }
}


template <class T, class TT> bool TBinTree<T, TT>::empty() {
    return (root == nullptr);

}

template <class T, class TT> std::ostream& operator<<(std::ostream& os, const TBinTree<T, TT>& obj) {

    TTreeItem<T> *rt = obj.root;
    rt->Print(os);
    return os;
}

template <class T, class TT> TIterator<TTreeItem<T>, TT> TBinTree<T, TT>::begin() {
    TTreeItem<T>* mostLeft;
    mostLeft = this->root->FindMostLeft();
    return TIterator<TTreeItem<T>, TT>(mostLeft);
}

template <class T, class TT> TIterator<TTreeItem<T>, TT> TBinTree<T, TT>::end() {
    return TIterator<TTreeItem<T>, TT>(nullptr);
}

#include "Figure.h"
#include "TList.h"
template class TBinTree<TList<Figure>, Figure>;
template std::ostream& operator << (std::ostream& os, const TBinTree<TList<Figure>, Figure>& obj);
