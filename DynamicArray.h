//
// Created by Drasik on 3/11/2018.
//

#ifndef SDIZO_PROJ_1_DYNAMICARRAY_H
#define SDIZO_PROJ_1_DYNAMICARRAY_H

#include "DataStructure.h"

class DynamicArray : public DataStructure {
private:
    int size;
    int *array;

public:
    DynamicArray();

    int getElement(int index);

    void addFirst(int value);

    void addLast(int value);

    void insert(int value, int index);

    void removeFirst();

    void removeLast();

    void removeOnIndex(int index);

    void print() override;

    int getSize();
};


#endif //SDIZO_PROJ_1_DynamicArray_H
