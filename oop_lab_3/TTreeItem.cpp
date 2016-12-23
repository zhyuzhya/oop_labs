#include "TTreeItem.h"
#include <memory>


TTreeItem::TTreeItem(std::shared_ptr<Figure> figure, int ID) {
    this->figure = figure;
    this->ID = ID;
    this->left = nullptr;
    this->right = nullptr;
    this->fath = nullptr;
}


TTreeItem::TTreeItem(const TTreeItem& orig) {
    this->figure = orig.figure;
    this->ID = orig.ID;
    this->left= orig.left;
    this->right= orig.right;
    this->fath = orig.fath;
}

TTreeItem* TTreeItem::find(int ID) {
    if (!this) {
        return nullptr;
    }
    if (this->ID == ID) {
        return this;
    } 
    TTreeItem* p = this->left->find(ID);
    if (p) {
        return p;
    } else {
        return this->right->find(ID);
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

std::shared_ptr<Figure> TTreeItem::GetFigure() {
    return this->figure;
}


TTreeItem::~TTreeItem() {
    if (this->fath == nullptr) {
        return;
    } else {
        if (this->fath->left == this) {
            this->fath->left = nullptr;
        } else 
        if (this->fath->right == this) {
            this->fath->right = nullptr;
        }
    }
    delete left;
    delete right;
}

std::ostream& operator<<(std::ostream& os, const TTreeItem& obj) {
    os << "ID = " << obj.ID << ", ";
    os << *obj.figure;
    return os;
}

void TTreeItem::print(std::ostream& os) {
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
