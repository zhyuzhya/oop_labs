#include "TBinTree.h"
#include "TTreeItem.h"
#include <iostream>
#include <memory>

TBinTree::TBinTree() : root(nullptr) {
}

TBinTree::TBinTree(const TBinTree& orig) {
    root = orig.root;
    std::cout << "Tree copied" << std::endl;
}


//получаем 5уг, который нужно вставить и отца, к которому его добавить
void TBinTree::push(int FID, int ID, std::shared_ptr<Figure> figure) {
    if (this->empty()) {
        root = new TTreeItem(figure, ID);
        return;
    }
    TTreeItem *newFather = root->find(FID);
    if (!newFather) {
        std::cout << "Error:couldn't find the father" << std::endl;
        return;
    }
    TTreeItem *other = new TTreeItem(figure, ID);
    newFather->push(other);
}

std::shared_ptr<Figure> TBinTree::get(int ID) {
    TTreeItem *p = root->find(ID);
    std::shared_ptr<Figure> pent = p->GetFigure();
    return pent;
}

int TBinTree::check(int ID) {
    TTreeItem *p = root->find(ID);
    return (p != nullptr);
}


void TBinTree::del(int ID) {
    TTreeItem *p = root->find(ID);
    if (p == root) {
        this->root  = nullptr;
        return;
    }
    if (!p) {
        std::cout << "Error: figure not found" << std::endl;
        return;
    }
    delete p;
}

bool TBinTree::empty() {
    return (root == nullptr);
}

TBinTree::~TBinTree() {
    delete root;
}

std::ostream& operator<<(std::ostream& os, const TBinTree& obj) {
    TTreeItem *rt = obj.root;
    rt->print(os);
    return os;
}
