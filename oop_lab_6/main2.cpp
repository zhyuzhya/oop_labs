#include <cstdlib>
#include <iostream>
#include <memory>

#include "Figure.h"
#include "TBinTree.h"

void menu() {
    std::cout << "Menu:\n";
    std::cout << "h - help\n";
    std::cout << "i - insert figure\n";
    std::cout << "f - find figure\n";
    std::cout << "d - delete figure\n";
    std::cout << "p - print out tree\n";
    std::cout << "Ctrl-D - exit\n";
}

int main () {
    int ID, FID;
    char check;
    std::shared_ptr<TBinTree<Figure>> tree (new (TBinTree<Figure>));
    Pentagon *pentagon = new Pentagon;
    Hexagon *hexagon = new Hexagon;
    Octagon *octagon = new Octagon;
    std::shared_ptr<Figure> figPtr;
    menu();
    std::cout << ">";
    while (std::cin >> check) {
        switch (check)
            {
                case 'i':
                    std::cout << "FID, ID, 5/6/8, SIDE:\n";
                    std::cout << "ID - id of new element, FID - id of father of new element\n";
                    std::cout << "if element is the first, FID - any number\n";
                    int newCheck;
                    std::cin >> FID;
                    std::cin >> ID;
                    std::cin >> newCheck;
                    if (newCheck == 5) {
                        std::cin >> *pentagon;
                        figPtr = std::shared_ptr<Figure>(pentagon);
                        tree->push(FID, ID, figPtr); 
                        pentagon = new Pentagon;
                    } else if (newCheck == 6) {
                        std::cin >> *hexagon;
                        figPtr = std::shared_ptr<Figure>(hexagon);
                        tree->push(FID, ID, figPtr); 
                        hexagon = new Hexagon;
                    } else if (newCheck == 8) {
                        std::cin >> *octagon;
                        figPtr = std::shared_ptr<Figure>(octagon);
                        tree->push(FID, ID, figPtr); 
                        octagon = new Octagon;
                    } else {
                        std::cin >> newCheck;
                        std::cout << "Error, try again\n";
                    }
                    break;
                case 'f':
                    if (tree->empty()) {
                        std::cout << "Tree is empty";
                        std::cout << std::endl;
                        break;
                    }
                    std::cout << "Enter ID\n";
                    std::cin >> ID;
                    if (tree->check(ID)) {
                        figPtr = tree->get(ID);
                        std::cout << "Found:\n";
                        std::cout << *figPtr << std::endl;
                    } else {
                        std::cout << "Not found\n";
                    }
                    break;
                case 'd':
                    if (tree->empty()) {
                        std::cout << "Tree is empty";
                        std::cout << std::endl;
                        break;
                    }
                    std::cout << "Enter ID\n";
                    std::cin >> ID;
                    tree->del(ID);
                    break;
                case 'p':
                    if (tree->empty()) {
                        std::cout << "Tree is empty";
                        std::cout << std::endl;
                        break;
                    }
                    for (auto i : *tree) std::cout << *i << std::endl;
                    break;
                case 'h':
                    menu();
                    break;
                default:
                    std::cout << "Wrong key\n";

            }
        std::cout << ">";
    }
    std::cout << "\b";
    return 0;
}
