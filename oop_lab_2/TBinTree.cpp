#include "TBinTree.h"
#include "TTreeItem.h"
#include "Pentagon.h"
#include <iostream>

TBinTree::TBinTree() : root(nullptr) {
}

TBinTree::TBinTree(const TBinTree& orig) {
    root = orig.root;
    std::cout << "Дерево скопировано" << std::endl;
}


//получаем 5уг, который нужно вставить и отца, к которому его добавить
void TBinTree::push(Pentagon &father, Pentagon &pentagon) {
    if (this->empty()) {
        root = new TTreeItem(pentagon);
        return;
    }
    TTreeItem *newFather = root->find(father);
    if (!newFather) {
        std::cout << "Ошибка: oтец не найден" << std::endl;
        return;
    }
    TTreeItem *other = new TTreeItem(pentagon);
    newFather->push(other);
}

void TBinTree::find(Pentagon &pentagon) {
    TTreeItem *p = root->find(pentagon);
    if (p) {
        std::cout << "Элемент найден:"<< std::endl << *p << std::endl;
    } else {
        std::cout << "Элемент не найден" << std::endl;
    }
}

void TBinTree::del(Pentagon &pentagon) {
    TTreeItem *p = root->find(pentagon);
    if (p == root) {
        this->root  = nullptr;
        return;
    }
    if (!p) {
        std::cout << "Ошибка: удаляемый элемент не найден" << std::endl;
        return;
    }
    delete p;
}

bool TBinTree::empty() {
    return (root == nullptr);
}

TBinTree::~TBinTree() {
    delete root;
    std::cout << "Дерево удалено" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const TBinTree& obj) {
    TTreeItem *rt = obj.root;
    os << *rt;
    os << std::endl;
    return os;
}
