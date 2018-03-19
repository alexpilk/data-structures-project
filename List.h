//
// Created by Oleksii Pilkevych on 3/11/2018.
//

#ifndef SDIZO_PROJ_1_LIST_H
#define SDIZO_PROJ_1_LIST_H

#include "IndexedDataStructure.h"

class List : public IndexedDataStructure {
    struct Element {
        int value;
        Element *next;
        Element *prev;

        explicit Element(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
    };

private:
    int size;
    Element *head;

public:
    List();

    List(int input_array[], int input_size);

    Element *getElement(int index);

    int getElementValue(int index) override ;

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


#endif //SDIZO_PROJ_1_LIST_H
