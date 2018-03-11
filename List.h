//
// Created by Drasik on 3/11/2018.
//

#ifndef SDIZO_PROJ_1_LIST_H
#define SDIZO_PROJ_1_LIST_H

#include "DataStructure.h"

class List : public DataStructure {
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

    void addFirst(int value);

    void addLast(int value);

    void insert(int value, int index);

    void removeFirst();

    void removeLast();

    void removeOnIndex(int index);

    void print() override;

    int getSize();
};


#endif //SDIZO_PROJ_1_LIST_H
