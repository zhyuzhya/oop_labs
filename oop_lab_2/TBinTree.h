#ifndef TBINTREE_H
#define TBINTREE_h

#include "Pentagon.h"
#include "TTreeItem.h"

class TBinTree {
public:
    TBinTree();
    TBinTree(const TBinTree& orig);

    void push(Pentagon &father, Pentagon &pentagon);
    void find(Pentagon &pentagon);
    void del(Pentagon &pentagon);
    bool empty();

    friend std::ostream& operator<<(std::ostream& os, const TBinTree& obj);
    virtual ~TBinTree();
private:
    TTreeItem *root;
};

#endif
