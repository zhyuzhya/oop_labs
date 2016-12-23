#include "TAllocationBlock.h"
#include <iostream>

TAllocationBlock::TAllocationBlock(size_t size, size_t count) {
    this->size = size;
    this->count = count;
    usedBlocks = (char *) malloc(size * count);
    freeBlocks = new TList<void >(count);

    for (size_t i = 0; i < count; ++i) {
        freeBlocks->SetByPos(i, (usedBlocks + i * size));
    }
    freeCount = count;
}

void *TAllocationBlock::Allocate() {
    void *result = nullptr;
    if (freeCount > 0) {
        result =  (freeBlocks->Get(freeCount - 1));
        freeCount--;
    } else {
        std::cout << "Can't allocate\n";
    }
    return result;
}

void TAllocationBlock::Deallocate(void *pointer) {
    freeBlocks->SetByPos(freeCount, pointer);
    freeCount++;
}

bool TAllocationBlock::HasFreeBlocks() {
    return freeCount > 0;
}

TAllocationBlock::~TAllocationBlock() {
    if (freeCount > count) {
        std::cout << "TAllocationBlock: memory leak?\n";
    } else {
        std::cout << "TAllocationBlock: memory freed\n";
    }
    delete freeBlocks;
    free(usedBlocks);
}

