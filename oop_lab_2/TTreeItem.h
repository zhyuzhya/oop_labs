#ifndef TTREEITEM_H
#define TTREEITEM_H

#include "Pentagon.h"

class TTreeItem {
public:
    TTreeItem(const Pentagon& pentagon);
    TTreeItem(const TTreeItem& orig);
    TTreeItem* find(Pentagon &pentagon);
    void push(TTreeItem *item);

    friend std::ostream& operator<<(std::ostream& os, const TTreeItem& obj);
    virtual ~TTreeItem();
private:
    Pentagon pentagon;
    TTreeItem *left;
    TTreeItem *right;
    TTreeItem *fath;
};

#endif
