#ifndef TTREEITEM_H
#define TTREEITEM_H

#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include <memory>

class TTreeItem {
public:
    TTreeItem(std::shared_ptr<Figure> figure, int ID);
    TTreeItem(const TTreeItem& orig);
    TTreeItem* find(int ID);
    void print(std::ostream& os);
    void push(TTreeItem *item);
    std::shared_ptr<Figure> GetFigure();

    friend std::ostream& operator<<(std::ostream& os, const TTreeItem& obj);
    virtual ~TTreeItem();
private:
    std::shared_ptr<Figure> figure;
    int ID;
    TTreeItem *left;
    TTreeItem *right;
    TTreeItem *fath;
};

#endif
