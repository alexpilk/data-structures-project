//
// Created by Drasik on 3/12/2018.
//

#ifndef SDIZO_PROJ_1_HEAP_H
#define SDIZO_PROJ_1_HEAP_H


#include <cstdlib>
#include <iostream>

#include "IndexedDataStructure.h"
#include "List.h"
#include "DynamicArray.h"

class Heap : DataStructure{
private:
    IndexedDataStructure* array;
    int size;
    int capacity;
public:
    Heap();
    explicit Heap(DynamicArray* input_array);
    explicit Heap(List* input_array);
    void heapify(IndexedDataStructure* arr, int n, int i);
    int findMax();
    int extract();
    void insert(int value);
    void print();
};


#endif //SDIZO_PROJ_1_HEAP_H
