#include "TTreeItem.h"
#include <memory>


template <class T> TTreeItem<T>::TTreeItem(std::shared_ptr<T> figure, int ID) {
    this->figure = figure;
    this->ID = ID;
    this->left = nullptr;
    this->right = nullptr;
    this->fath = nullptr;
}

template <class T> TAllocationBlock
TTreeItem<T>::ItemAllocator(sizeof(TTreeItem<T>), 100);


template <class T> TTreeItem<T>::TTreeItem(const TTreeItem<T>& orig) {
    this->figure = orig.figure;
    this->ID = orig.ID;
    this->left= orig.left;
    this->right= orig.right;
    this->fath = orig.fath;
}

template <class T> TTreeItem<T>* TTreeItem<T>::find(int ID) {
    if (!this) {
        return nullptr;
    }
    if (this->ID == ID) {
        return this;
    } 
    TTreeItem<T>* p = this->left->find(ID);
    if (p) {
        return p;
    } else {
        return this->right->find(ID);
    }
    
}

template <class T> void TTreeItem<T>::push(TTreeItem<T> *item) {
    if (!(this->left)) {
        this->left = item;
        item->fath = this;
    } else
    if (!(this->right)) {
        this->right = item;
        item->fath = this;
    } else {
        std::cout << "Can't push\n" << std::endl;
    }
}

template <class T> std::shared_ptr<T> TTreeItem<T>::GetFigure() {
    return this->figure;
}


template <class T> TTreeItem<T>::~TTreeItem() {
    if (this->fath) {
        if (this->fath->left == this) {
            this->fath->left = nullptr;
        } else 
        if (this->fath->right == this) {
            this->fath->right = nullptr;
        }
    }
    if (left) {
        delete left;
    }
    if (right) {
        delete right;
    }
}

template <class T> TTreeItem<T>* TTreeItem<T>::findMostLeft() {
    if (this->left == nullptr) {
        return this;
    } else {
        return this->left->findMostLeft();
    }
}

template <class T> TTreeItem<T>* TTreeItem<T>::findMostRight() {
    if (this->right == nullptr) {
        return this;
    } else {
        return this->right->findMostRight();
    }
}

template <class T> TTreeItem<T>* TTreeItem<T>::getNext() {
    TTreeItem<T>* thisRoot = this;
    while (thisRoot->fath != nullptr) {
        thisRoot = thisRoot->fath;
    }
    TTreeItem<T>* mostRight = thisRoot->findMostRight();
    if (this == mostRight) {
        return nullptr;
    }
    if (this->right == nullptr) {
        TTreeItem<T>* ptr = this;
        while (ptr->fath->left != ptr) {
            ptr = ptr->fath;
        }
        return ptr->fath;
    } else {
        return this->right->findMostLeft();
    }
}

template <class T> std::ostream& operator<<(std::ostream& os, const TTreeItem<T>& obj) {
    os << "ID = " << obj.ID << ", ";
    os << *obj.figure;
    return os;
}

template <class T> void * TTreeItem<T>::operator new(size_t size) {
    return ItemAllocator.Allocate();
}

template <class T> void TTreeItem<T>::operator delete(void * p) {
    return ItemAllocator.Deallocate(p);
}

template <class T> void TTreeItem<T>::print(std::ostream& os) {
    static int level = 0;
    level++;
    if (this->left) {
        this->left->print(os);
    }
    
    for (int i = 0; i < level; ++i) {
        os << '\t';
    }
    os << *this << std::endl;
    if (this->right) {
        this->right->print(os);
    }
    level--;

}

#include "Figure.h"
template class TTreeItem<Figure>;
template std::ostream& operator <<(std::ostream& os, const TTreeItem<Figure>& obj);
