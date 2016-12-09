#include "TListNode.h"

template <class T> TListNode<T>::TListNode() {
    next = nullptr;
}

template <class T> TListNode<T>::TListNode(T item) {
    this->item = item;
    next = nullptr;
}


template <class T> void TListNode<T>::SetNext(TListNode<T> next) {
    this->next = next;
}

template <class T> TListNode<T>* TListNode<T>::GetNext() {
    return next;
}

template <class T> T TListNode<T>::GetItem() {
    return item;
}

template <class T> void TListNode<T>::SetItem(T item) {
    this->item = item;
}

//template class TListNode<void *>;
