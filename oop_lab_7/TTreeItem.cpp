#include "TTreeItem.h"
#include <memory>

template <class T> TTreeItem<T>::TTreeItem() {
    figure = nullptr;
    left = nullptr;
    right = nullptr;
    fath = nullptr;
}

template <class T> TTreeItem<T>::TTreeItem(T* figure) {
    this->figure = figure;
    this->left = nullptr;
    this->right = nullptr;
    this->fath = nullptr;
}

template <class T> TAllocationBlock
TTreeItem<T>::ItemAllocator(sizeof(TTreeItem<T>), 100);



template <class T> void TTreeItem<T>::PushStruct(T* item) {
    figure = item;
}

template <class T> void TTreeItem<T>::Push(TTreeItem<T> *item) {
    this->left = item;
    item->fath = this;
}

template <class T> T* TTreeItem<T>::GetFigure() {
    return this->figure;
}

template <class T> TTreeItem<T>* TTreeItem<T>::GetLeft() {
    return left;
}


template <class T> TTreeItem<T>::~TTreeItem() {
    delete figure;
    figure = nullptr;
    if (fath) {
        fath->left = this->left;
    }
}

template <class T> TTreeItem<T>* TTreeItem<T>::FindMostLeft() {
    if (this->left == nullptr) {
        return this;
    } else {
        return this->left->FindMostLeft();
    }
}

template <class T> TTreeItem<T>* TTreeItem<T>::FindMostRight() {
    if (this->right == nullptr) {
        return this;
    } else {
        return this->right->FindMostRight();
    }
}

template <class T> TTreeItem<T>* TTreeItem<T>::GetNext() {
    TTreeItem<T>* thisRoot = this;
    while (thisRoot->fath != nullptr) {
        thisRoot = thisRoot->fath;
    }
    TTreeItem<T>* mostRight = thisRoot->FindMostRight();
    if (this == mostRight) {
        return nullptr;
    }
    if (this->right == nullptr) {
        TTreeItem<T>* ptr = this;
        while (ptr->fath->left != ptr) {
            ptr = ptr->fath;
            if (ptr == thisRoot) {
                break;
            }
        }
        return ptr->fath;
    } else {
        return this->right->FindMostLeft();
    }
}

template <class T> std::ostream& operator<<(std::ostream& os, const TTreeItem<T>& obj) {
    os << *obj.figure;
    return os;
}

template <class T> void * TTreeItem<T>::operator new(size_t size) {
    return ItemAllocator.Allocate();
}

template <class T> void TTreeItem<T>::operator delete(void * p) {
    return ItemAllocator.Deallocate(p);
}

template <class T> void TTreeItem<T>::Print(std::ostream& os) {
    static int level = 0;
    level++;
    if (this->left) {
        this->left->Print(os);
    }
    
    for (int i = 0; i < level; ++i) {
        os << '\t';
    }
    os << *this << std::endl;
    if (this->right) {
        this->right->Print(os);
    }
    level--;

}

#include "Figure.h"
#include "TList.h"
template class TTreeItem<TList<Figure>>;
template std::ostream& operator <<(std::ostream& os, const TTreeItem<TList<Figure>>& obj);
