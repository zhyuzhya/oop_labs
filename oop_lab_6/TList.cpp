#include "TList.h"


template <class T> TList<T>::TList() {
    head = nullptr;
    size = 0;
}

template <class T> TList<T>::TList(size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (!i) {
            head = new TListNode<T>;
            break;
        }
        TListNode<T> node = new TListNode<T>;
        TListNode<T> iter = head;
        while (iter->GetNext()) {
            iter = iter->GetNext();
        }
        iter->SetNext(node);
    }
    this->size = size;
}

template <class T> void TList<T>::Insert(int pos, T item) {
    if (pos > size) {
        return;
    }
    if (!pos) {
        TListNode<T> node = new TListNode<T>(item);
        node->SetNext(head);
        head = node;
        ++size;
        return;
    }
    if (pos == size) {
        TListNode<T> left = this->Find(pos);
        TListNode<T> node = new TListNode<T>(item);
        left->SetNext(node);
        node->SetNext(nullptr);
        ++size;
        return;
    }
    TListNode<T> left = this->Find(pos - 1);
    TListNode<T> right = left->GetNext();
    TListNode<T> node = new TListNode<T>(item);
    left->SetNext(node);
    node->SetNext(right);
    ++size;
}

template <class T> void TList<T>::SetByPos(int pos, T item) {
    TListNode<T> node = this->Find(pos);
    node->SetItem(item);
}


template <class T> void TList<T>::Delete(int pos) {
    TListNode<T> node = this->Find(pos);
    if (node == head) {
        head = head->GetNext();
        delete node;
        return;
    }
    TListNode<T> left = this->Find(pos - 1);
    left->SetNext(node->GetNext());
    delete node;
}

template <class T> int TList<T>::Find(T item) {
    TListNode<T> node = head;
    int i = 0;
    while (node && node->item != item) {
        node = node->GetNext();
        ++i;
    } if (node) {
        return i;
    } else {
        return -1;
    }
}

template <class T> T TList<T>::Get(int pos) {
    TListNode<T> node = head;
    int i = 0;
    while (i < pos) {
        ++i;
        node = node->GetNext();
    }
    return node->GetItem();
}

template <class T> TList<T>::~TList() {
    TListNode<T> node = head;
    for (int i = 0; i < size; ++i) {
        if (node->GetNext()) {
            TListNode<T> next = node->GetNext();
            delete node;
            node = next;
        } else {
            delete node;
        }
    }
}

//#include <cstdlib>
//template class TList<void *>;
