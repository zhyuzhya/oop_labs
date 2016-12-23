#ifndef TLISTNODE_H
#define TLISTNODE_H


template <class T> class TListNode {
    public:
        TListNode();
        TListNode(T item);
        void SetNext(TListNode<T> next);
        TListNode<T>* GetNext();
        T GetItem();
        void SetItem(T item);
    private:
        T item;
        TListNode<T> next;
};

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
#endif
