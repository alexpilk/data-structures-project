//
// Created by Drasik on 3/11/2018.
//
#include <iostream>
#include "DynamicArray.h"
#include "IndexError.h"

using namespace std;

DynamicArray::DynamicArray() {
    size = 0;
//    int ar[0] = {};
    array = new int[0];
}

int DynamicArray::getElement(int index) {
    return array[index];
}

void DynamicArray::addFirst(int value) {
    insert(value, 0);
}

void DynamicArray::addLast(int value) {
    insert(value, size);
}

void DynamicArray::insert(int value, int index) {
    if (index > size)
        throw IndexError();
    size++;
    auto *new_array = new int[size];
    for (int i = 0; i < index; ++i) {
        new_array[i] = array[i];
    }
    new_array[index] = value;
    for (int i = index + 1; i < size; i++) {
        new_array[i] = array[i - 1];
    }
    array = new_array;
}

void DynamicArray::removeFirst() {
    removeOnIndex(0);
}

void DynamicArray::removeLast() {
    removeOnIndex(size-1);
}

void DynamicArray::removeOnIndex(int index) {
    if (index > size-1)
        throw IndexError();
    size--;
    auto *new_array = new int[size];
    for (int i = 0; i < index; ++i) {
        new_array[i] = array[i];
    }
    for (int i = index + 1; i < size; i++) {
        new_array[i] = array[i - 1];
    }
    array = new_array;
}

void DynamicArray::print() {
    cout << "[";
    for (int i = 0; i < size - 1; i++) {
        cout << array[i] << ", ";
    }
    if (size != 0)
        cout << array[size - 1];
    cout << "]" << endl;
}

int DynamicArray::getSize() {
    return 0;
}
