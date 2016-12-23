#include <cstdlib>
#include <iostream>

#include "Pentagon.h"
#include "TTreeItem.h"
#include "TBinTree.h"

void menu() {
    printf("Меню программы\n");
    printf("1 - вставить элемент\n");
    printf("2 - найти элемент\n");
    printf("3 - удалить элемент\n");
    printf("4 - вывести содержимое контейнера\n");
    printf("Ctrl-D - выход из программы\n");
}

int main () {
    int check;
    TBinTree *tree = new TBinTree;
    Pentagon pentagon, father;
    menu();
    while (std::cin >> check) {
        switch (check)
            {
                case 1:
                    std::cout << "Введите сторону отца" << std::endl;
                    std::cout << "Или любое число, если элемент первый в дереве";
                    std::cout << std::endl;
                    std::cin >> father;
                    std::cout << "Введите элемент" << std::endl;
                    std::cin >> pentagon;
                    tree->push(father, pentagon);
                    break;
                case 2:
                    if (tree->empty()) {
                        std::cout << "Дерево пусто, искать нечего";
                        std::cout << std::endl;
                        break;
                    }
                    std::cout << "Введите элемент" << std::endl;
                    std::cin >> pentagon;
                    tree->find(pentagon);
                    break;
                case 3:
                    if (tree->empty()) {
                        std::cout << "Дерево пусто, удалять нечего";
                        std::cout << std::endl;
                        break;
                    }
                    std::cout << "Введите элемент" << std::endl;
                    std::cin >> pentagon;
                    tree->del(pentagon);
                    break;
                case 4:
                    if (tree->empty()) {
                        std::cout << "Дерево пусто, выводить нечего";
                        std::cout << std::endl;
                        break;
                    }
                    std::cout << *tree << std::endl;
                    break;
                default:
                    std::cout << "Неверная команда" << std::endl;

            }
        menu();
    }
    return 0;
}
