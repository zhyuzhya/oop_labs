#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H

#include <cstdlib>
#include "TList.h"


class TAllocationBlock {
    public:
        //инициализация блока для count элементов, каждый из которых размером size
        TAllocationBlock(size_t size, size_t count);
        //выделение участка памяти, функция возвращает указатель на него
        void *Allocate();
        //функция получает указатель на участок памяти
        //и возвращает его в список свободных участков
        void Deallocate(void *pointer);
        //проверка: имеются ли свободные блоки
        bool HasFreeBlocks();
        //деструктор блока - проверка на утечку
        virtual ~TAllocationBlock();

    private:
        size_t size;
        size_t count;
        char *usedBlocks;
        TList<void *>* freeBlocks;
        size_t freeCount;
};

#endif
