#include "TBinTree.h"
#include "TTreeItem.h"
#include "TIterator.h"
#include <iostream>
#include <memory>


template <class T> TBinTree<T>::TBinTree() : root(nullptr) {
}

template <class T> TBinTree<T>::TBinTree(const TBinTree<T>& orig) {
    root = orig.root;
    std::cout << "Tree copied" << std::endl;
}


template <class T> void TBinTree<T>::push(int FID, int ID, std::shared_ptr<T> figure) {
    if (this->empty()) {
        root = new TTreeItem<T>(figure, ID);
        return;
    }
    TTreeItem<T> *newFather = root->find(FID);
    if (!newFather) {
        std::cout << "Error:couldn't find the father" << std::endl;
        return;
    }
    TTreeItem<T> *other = new TTreeItem<T>(figure, ID);
    newFather->push(other);
}

template <class T> std::shared_ptr<T> TBinTree<T>::get(int ID) {
    TTreeItem<T> *p = root->find(ID);
    std::shared_ptr<T> pent = p->GetFigure();
    return pent;
}

template <class T> int TBinTree<T>::check(int ID) {
    TTreeItem<T> *p = root->find(ID);
    return (p != nullptr);
} 


template <class T> void TBinTree<T>::del(int ID) {
    TTreeItem<T> *p = root->find(ID);
    if (p == root) {
        delete root;
        this->root  = nullptr;
        return;
    }
    if (!p) {
        std::cout << "Error: figure not found" << std::endl;
        return;
    }
    delete p;
}

template <class T> bool TBinTree<T>::empty() {
    return (root == nullptr);
}

template <class T> TBinTree<T>::~TBinTree() {
    delete root;
}

template <class T> std::ostream& operator<<(std::ostream& os, const TBinTree<T>& obj) {
    TTreeItem<T> *rt = obj.root;
    rt->print(os);
    return os;
}

template <class T> TIterator<TTreeItem<T>, T> TBinTree<T>::begin() {
    TTreeItem<T>* mostLeft;
    mostLeft = this->root->findMostLeft();
    return TIterator<TTreeItem<T>, T>(mostLeft);
}

template <class T> TIterator<TTreeItem<T>, T> TBinTree<T>::end() {
    //TTreeItem<T>* mostRight;
    //mostRight = this->root->findMostRight();
    return TIterator<TTreeItem<T>, T>(nullptr);
}

#include "Figure.h"
template class TBinTree<Figure>;
template std::ostream& operator << (std::ostream& os, const TBinTree<Figure>& obj);
