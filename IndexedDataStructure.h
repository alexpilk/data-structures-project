//
// Created by Oleksii Pilkevych on 3/14/2018.
//

#ifndef SDIZO_PROJ_1_INDEXEDDATASTRUCTURE_H
#define SDIZO_PROJ_1_INDEXEDDATASTRUCTURE_H

#include "DataStructure.h"

class IndexedDataStructure : public DataStructure{

public:
    virtual int getElementValue(int index) = 0;

    virtual int search(int value) = 0;

    virtual void addFirst(int value) = 0;

    virtual void addLast(int value) = 0;

    virtual void insert(int value, int index) = 0;

    virtual void removeFirst() = 0;

    virtual void removeLast() = 0;

    virtual void removeOnIndex(int index) = 0;

    virtual void swap(int index_1, int index_2) = 0;

    virtual int getSize() = 0;
};


#endif //SDIZO_PROJ_1_INDEXEDDATASTRUCTURE_H
