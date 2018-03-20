//
// Created by Oleksii Pilkevych on 3/11/2018.
//

#ifndef SDIZO_PROJ_1_DYNAMICARRAY_H
#define SDIZO_PROJ_1_DYNAMICARRAY_H

#include "IndexedDataStructure.h"

class DynamicArray : public IndexedDataStructure {
private:
    int size;
    int *array;

public:
    DynamicArray();

    DynamicArray(int input_array[], int input_size);

    int getElementValue(int index) override;

    int search(int value) override;

    void addFirst(int value) override;

    void addLast(int value) override;

    void insert(int value, int index) override;

    void removeFirst() override;

    void removeLast() override;

    void removeOnIndex(int index) override;

    void swap(int index_1, int index_2) override;

    void print() override;

    int getSize() override;
};


#endif //SDIZO_PROJ_1_DynamicArray_H
