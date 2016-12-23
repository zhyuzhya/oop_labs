#include <cstdlib>
#include <iostream>
#include <memory>

#include "Figure.h"
#include "TBinTree.h"

void menu() {
    std::cout << "Menu:\n";
    std::cout << "h - help\n";
    std::cout << "i - insert figure(5/6/8, Side)\n";
    std::cout << "d - delete figures by square(S < square will be deleted)\n";
    std::cout << "D - delete figures by type(5,6,8)\n";
    std::cout << "p - print out tree\n";
    std::cout << "Ctrl-D - exit\n";
}

int main () {
    int newCheck;
    char check;
    TBinTree<TList<Figure>, Figure>* tree = new TBinTree<TList<Figure>, Figure>;
    Pentagon *pentagon = new Pentagon;
    Hexagon *hexagon = new Hexagon;
    Octagon *octagon = new Octagon;
    Figure* figPtr;
    menu();
    while (std::cin >> check) {
        switch (check)
            {
                //вставка
                case 'i':
                    std::cin >> newCheck;
                    if (newCheck == 5) {
                        std::cin >> *pentagon;
                        figPtr = (Figure*)(pentagon);
                        tree->InsertSubitem(figPtr); 
                        pentagon = new Pentagon;
                    } else if (newCheck == 6) {
                        std::cin >> *hexagon;
                        figPtr = (Figure*)(hexagon);
                        tree->InsertSubitem(figPtr); 
                        hexagon = new Hexagon;
                    } else if (newCheck == 8) {
                        std::cin >> *octagon;
                        figPtr = (Figure*)(octagon);
                        tree->InsertSubitem(figPtr); 
                        octagon = new Octagon;
                    } else {
                        std::cout << "Error, try again\n";
                    }
                    break;
                
                case 'D': //удаление по типу
                    std::cin >> newCheck;
                    if (newCheck == 5) {
                        figPtr = (Figure*)(pentagon);
                        tree->DeleteByType(figPtr);
                        pentagon = new Pentagon;
                    } else if (newCheck == 6) {
                        figPtr = (Figure*)(hexagon);
                        tree->DeleteByType(figPtr);
                        hexagon = new Hexagon;
                    } else if (newCheck == 8) {
                        figPtr = (Figure*)(octagon);
                        tree->DeleteByType(figPtr);
                        octagon = new Octagon;
                    } else {
                        std::cout << "Error, try again\n";
                    }
                    tree->CheckEmpty();
                    break;
                case 'd': //удаление с площадью < square
                    double square;
                    std::cout << "Every figure with S < square will be deleted\n";
                    std::cout << "Enter square (double):\n";
                    std::cin >> square;
                    tree->DeleteBySquare(square);
                    tree->CheckEmpty();
                    break;
                case 'p': //печать дерева-списков
                    if (tree->empty()) {
                        std::cout << "Tree is empty";
                        std::cout << std::endl;
                        break;
                    }
                    for (auto i : *tree) std::cout << *i << std::endl;
                    break;
                case 'h': //подсказка
                    menu();
                    break;
                default:
                    std::cout << "Wrong key\n";

            }
    }
    std::cout << "\b";
    return 0;
}
