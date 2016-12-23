#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H

#include <cstdlib>
#include "TList.h"


class TAllocationBlock {
    public:
        TAllocationBlock(size_t size, size_t count);
        void *Allocate();
        void Deallocate(void *pointer);
        bool HasFreeBlocks();
        virtual ~TAllocationBlock();
    private:
        size_t size;
        size_t count;
        char *usedBlocks;
        TList<void >* freeBlocks;
        size_t freeCount;
};

#endif
