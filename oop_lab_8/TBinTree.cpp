#include "TBinTree.h"
#include "TTreeItem.h"
#include "TIterator.h"
#include <iostream>
#include <memory>
#include <thread>
#include <future>

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

template <class T> void QSortR(std::shared_ptr<T>* a, int n) {
    int i = 0, j = n;
    std::shared_ptr<T> temp, p;
    p = a[n >> 1];
    do {
        while (a[i]->Square() < p->Square()) {
            i++;
        }
        while (a[j]->Square() > p->Square()) {
            j--;
        }
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        std::async(std::launch::async, QSortR<T>, a, j);
    }
    if (n > i) {
        std::async(std::launch::async, QSortR<T>, a + i, n - i);
    }
}

template <class T> void QSortRS(std::shared_ptr<T>* a, int n) {
    int i = 0, j = n;
    std::shared_ptr<T> temp, p;
    p = a[n >> 1];
    do {
        while (a[i]->Square() < p->Square()) {
            i++;
        }
        while (a[j]->Square() > p->Square()) {
            j--;
        }
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        QSortR(a, j);
    }
    if (n > i) {
        QSortR(a + i, n - i);
    }
}

template <class T> void TBinTree<T>::QuickSort() {
    int size = 0;
    for (auto i: *this) {
        ++size;
    }
    std::shared_ptr<T> *a = new std::shared_ptr<T> [size];
    int j = 0;
    for (auto i: *this) {
        a[j++] = i->GetFigure();
    }
    std::async(std::launch::async, QSortR<T>, a, size - 1);
    j = 0;
    for (auto i: *this) {
        i->SetFigure(a[j++]);
    }
}

template <class T> void TBinTree<T>::QuickSortS() {
    int size = 0;
    for (auto i: *this) {
        ++size;
    }
    std::shared_ptr<T> *a = new std::shared_ptr<T> [size];
    int j = 0;
    for (auto i: *this) {
        a[j++] = i->GetFigure();
    }
    QSortRS(a, size - 1);
    j = 0;
    for (auto i: *this) {
        i->SetFigure(a[j++]);
    }
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
    return TIterator<TTreeItem<T>, T>(nullptr);
}

#include "Figure.h"
template class TBinTree<Figure>;
template std::ostream& operator << (std::ostream& os, const TBinTree<Figure>& obj);
