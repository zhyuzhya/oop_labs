#ifndef TBINTREE_H
#define TBINTREE_h

#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "TTreeItem.h"

#include <memory>

class TBinTree {
public:
    TBinTree();
    TBinTree(const TBinTree& orig);

    void push(int FID, int ID, std::shared_ptr<Figure> figure);
    std::shared_ptr<Figure> get(int ID);
    int check(int ID);

    void del(int ID);
    bool empty();

    friend std::ostream& operator<<(std::ostream& os, const TBinTree& obj);

    virtual ~TBinTree();
private:
    TTreeItem *root;
};

#endif
