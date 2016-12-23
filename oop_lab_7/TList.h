#ifndef TLIST_H
#define TLIST_H

#include <memory>
#include <cstdlib>
#include <iostream>

template <class T> class TListNode {
    public:
        TListNode();
        TListNode(T* item);
        //установка следующего за узлом узла
        void SetNext(TListNode<T>* next);
        //получение следующего за узлом узла
        TListNode<T>* GetNext();
        //получение объекта, хранящегося в узле
        T* GetItem();
        //установка объекта, хранящегося в узле
        void SetItem(T* item);
        template <class A> friend std::ostream& operator<<(std::ostream &os, TListNode<A>& node) {
            os << *node.item;
            return os;
        }
        virtual ~TListNode();
    private:
        T* item;
        TListNode<T>* next;
};

template <class T> class TList {
    public:
        TList();
        TList(size_t size);
        void Insert(int pos, T* item);
        void Delete(int pos);
        TListNode<T>* Find(int pos);
        T* Get(int pos);
        void SetByPos(int pos, T* item);
        void PushBack(T* value);
        template <class A> friend std::ostream& operator<<(std::ostream &os, TList<A>& list) {
            TListNode<A>* node = list.head;
            while (node) {
                os << "[" << *node << "] ";
                node = node->GetNext();
            }
            return os;
        }
        int Size() {
            return size;
        }

        virtual ~TList();
    private:
        TListNode<T> *head;
        int size;
};

template <class T> TListNode<T>::TListNode() {
    next = nullptr;
    item = nullptr;
}

template <class T> TListNode<T>::TListNode(T* item) {
    this->item = item;
    next = nullptr;
}


template <class T> void TListNode<T>::SetNext(TListNode<T>* next) {
    this->next = next;
}

template <class T> TListNode<T>* TListNode<T>::GetNext() {
    return next;
}

template <class T> T* TListNode<T>::GetItem() {
    return item;
}

template <class T> void TListNode<T>::SetItem(T* item) {
    this->item = item;
}

template <class T> TListNode<T>::~TListNode() {
}
template <class T> TList<T>::TList() {
    head = nullptr;
    size = 0;
}

template <class T> TList<T>::TList(size_t size) {
    head = new TListNode<T>;
    TListNode<T>* iter = head;
    for (size_t i = 1; i < size; ++i) {
        TListNode<T>* node = new TListNode<T>;
        iter->SetNext(node);
        iter = node;
    }
    this->size = size;
}

template <class T> void TList<T>::Insert(int pos, T* item) {
    if (pos > size) {
        return;
    }
    if (!pos) {
        TListNode<T>* node = new TListNode<T>(item);
        node->SetNext(head);
        head = node;
        ++size;
        return;
    }
    if (pos == size) {
        TListNode<T>* left = this->Find(pos - 1);
        TListNode<T>* node = new TListNode<T>(item);
        left->SetNext(node);
        node->SetNext(nullptr);
        ++size;
        return;
    }
    TListNode<T>* left = this->Find(pos - 1);
    TListNode<T>* right = left->GetNext();
    TListNode<T>* node = new TListNode<T>(item);
    left->SetNext(node);
    node->SetNext(right);
    ++size;
}

template <class T> void TList<T>::PushBack(T* value) {
    TListNode<T>* node = head;
    int p = 0;
    while (node && node->GetItem()->Square() < value->Square()) {
        node = node->GetNext();
        p++;
    }
    this->Insert(p, value);
}

template <class T> void TList<T>::SetByPos(int pos, T* item) {
    TListNode<T>* node = this->Find(pos);
    node->SetItem(item);
}


template <class T> void TList<T>::Delete(int pos) {
    TListNode<T>* node = this->Find(pos);
    if (node == head) {
        head = head->GetNext();
        node = nullptr;
        size--;
        return;
    }
    TListNode<T>* left = this->Find(pos - 1);
    left->SetNext(node->GetNext());
    delete node;
    size--;
}

template <class T> TListNode<T>* TList<T>::Find(int pos) {
    TListNode<T>* node = head;
    int i = 0;
    while (node && i < pos) {
        node = node->GetNext();
        ++i;
    }
    return node;
}
    

template <class T> T* TList<T>::Get(int pos) {
    TListNode<T>* node = head;
    int i = 0;
    while (i < pos) {
        ++i;
        node = node->GetNext();
    }
    return node->GetItem();
}

template <class T> TList<T>::~TList() {
    TListNode<T>* node = head;
    while (node) {
        if (node->GetNext()) {
            TListNode<T>* next = node->GetNext();
            delete node;
            node = next;
        } else {
            break;
        }
    }
}
#endif
