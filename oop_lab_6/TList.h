#ifndef TLIST_H
#define TLIST_H


#include <memory>
#include <cstdlib>

template <class T> class TListNode {
    public:
        TListNode();
        //создание узла с заданным объектом
        TListNode(T item);
        //установить следующий за узлом узел
        void SetNext(TListNode<T>* next);
        //получить следующий за узлом узел
        TListNode<T>* GetNext();
        //получить хранящийся в узле объект
        T GetItem();
        //присвоить хранящемуся в узле объекту значение
        void SetItem(T item);
    private:
        T item;
        TListNode<T>* next;
};

template <class T> class TList {
    public:
        TList();
        //создание списка из size узлов
        TList(size_t size);
        //вставка объекта с item на позицию pos в списке
        void Insert(int pos, T item);
        //удаление элемента с pos-позиции
        void Delete(int pos);
        //поиск узла, находящегося на заданной позиции
        TListNode<T>* Find(int pos);
        //получение объекта, хранящегося в узле заданной позиции
        T Get(int pos);
        //присваивание объеткту, на заданной позиции, заданного значения
        void SetByPos(int pos, T item);

        virtual ~TList();
    private:
        TListNode<T> *head;
        int size;
};

template <class T> TListNode<T>::TListNode() {
    next = nullptr;
}

template <class T> TListNode<T>::TListNode(T item) {
    this->item = item;
    next = nullptr;
}


template <class T> void TListNode<T>::SetNext(TListNode<T>* next) {
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
        TListNode<T>* left = this->Find(pos);
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

template <class T> void TList<T>::SetByPos(int pos, T item) {
    TListNode<T>* node = this->Find(pos);
    node->SetItem(item);
}


template <class T> void TList<T>::Delete(int pos) {
    TListNode<T>* node = this->Find(pos);
    if (node == head) {
        head = head->GetNext();
        delete node;
        return;
    }
    TListNode<T>* left = this->Find(pos - 1);
    left->SetNext(node->GetNext());
    delete node;
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
    

template <class T> T TList<T>::Get(int pos) {
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
    for (int i = 0; i < size; ++i) {
        if (node->GetNext()) {
            TListNode<T>* next = node->GetNext();
            delete node;
            node = next;
        } else {
            delete node;
        }
    }
}
#endif
