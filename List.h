//
// Created by Drasik on 3/11/2018.
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

    Element *getElement(int index);

    int getElementValue(int index);

    void addFirst(int value);

    void addLast(int value);

    void insert(int value, int index);

    void removeFirst();

    void removeLast();

    void removeOnIndex(int index);

    void swap(int index_1, int index_2);

    void print() override;

    int getSize();
};


#endif //SDIZO_PROJ_1_LIST_H
