#include "TTreeItem.h"


TTreeItem::TTreeItem(const Pentagon& pentagon) {
    this->pentagon = pentagon;
    this->left = nullptr;
    this->right = nullptr;
    this->fath = nullptr;
}


TTreeItem::TTreeItem(const TTreeItem& orig) {
    this->pentagon = orig.pentagon;
    this->left= orig.left;
    this->right= orig.right;
    this->fath = orig.fath;
}

TTreeItem* TTreeItem::find(Pentagon &pentagon) {
    if (!this) {
        return nullptr;
    }
    if (this->pentagon == pentagon) {
        return this;
    } 
    TTreeItem* p = this->left->find(pentagon);
    if (p) {
        return p;
    } else {
        return this->right->find(pentagon);
    }
    
}

void TTreeItem::push(TTreeItem *item) {
    if (!(this->left)) {
        this->left = item;
        item->fath = this;
    } else
    if (!(this->right)) {
        this->right = item;
        item->fath = this;
    } else {
        std::cout << "У элемента макс. детей, нельзя вставить" << std::endl;
    }
}


TTreeItem::~TTreeItem() {
    if (this == nullptr) {
        return;
    }
    if (this->fath->left == this) {
        this->fath->left = nullptr;
    } else 
    if (this->fath->right == this) {
        this->fath->right = nullptr;
    }
    delete left;
    delete right;
}

std::ostream& operator<<(std::ostream& os, const TTreeItem& obj) {
    static int level = 0;
    level++;
    if (obj.left) {
        os << *obj.left;
        os << std::endl;
    }
    
    for (int i = 0; i < level; ++i) {
        os << '\t';
    }
    os << obj.pentagon << std::endl;
    if (obj.right) {
        os << *obj.right;
        os << std::endl;
    }
    level--;
    return os;
}
