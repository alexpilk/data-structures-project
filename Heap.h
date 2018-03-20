//
// Created by Oleksii Pilkevych on 3/12/2018.
//

#ifndef SDIZO_PROJ_1_HEAP_H
#define SDIZO_PROJ_1_HEAP_H


#include <cstdlib>
#include <iostream>

#include "IndexedDataStructure.h"
#include "List.h"
#include "DynamicArray.h"

class Heap : public DataStructure{
private:
    IndexedDataStructure* array;
public:
    Heap();
    explicit Heap(IndexedDataStructure* input_array);
    void buildHeap();
    void heapify(int size, int root_index);
    bool search(int value);
    bool search(int value, int start_node_index, int size);
    int findMax();
    int extract();
    int getSize();
    void insert(int value);
    void print() override;
};


#endif //SDIZO_PROJ_1_HEAP_H
