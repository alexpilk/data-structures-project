//
// Created by Oleksii Pilkevych on 3/12/2018.
//

#include "Heap.h"
#include "IndexError.h"
#include "cmath"

using namespace std;

Heap::Heap() = default;

Heap::Heap(IndexedDataStructure *input_array) {
    array = input_array;
    buildHeap();
}

void Heap::buildHeap() {
    // index of the rightmost node on second to last level
    int start_index = getSize() / 2 - 1;
    for (int i = start_index; i >= 0; i--)
        heapify(getSize(), i);
}

void Heap::heapify(int size, int root_index) {
    int largest_index = root_index;
    int left_index = 2 * root_index + 1;
    int right_index = 2 * root_index + 2;
    int largest_node, left_node, right_node;

    if (left_index < size) {
        left_node = array->getElementValue(left_index);
        largest_node = array->getElementValue(largest_index);
        if (left_node > largest_node)
            largest_index = left_index;
    }

    if (right_index < size) {
        right_node = array->getElementValue(right_index);
        largest_node = array->getElementValue(largest_index);
        if (right_node > largest_node)
            largest_index = right_index;
    }

    if (largest_index != root_index) {
        array->swap(root_index, largest_index);
        heapify(size, largest_index);
    }
}

int Heap::findMax() {
    if (getSize() > 0)
        return array->getElementValue(0);
    else
        throw IndexError();
}

bool Heap::search(int value) {
    int size = getSize();
    if (getSize() > 0) {
        if (findMax() > value) {
            int root_index = 0;
            return search(value, root_index, size);
        }
    };
    return false;
}

bool Heap::search(int value, int start_node_index, int size) {
    int node_value = array->getElementValue(start_node_index);
    if (node_value == value)
        return true;
    else if (node_value < value)
        return false;
    bool found = false;
    int left_index = 2 * start_node_index + 1;
    int right_index = 2 * start_node_index + 2;
    if (left_index < size) {
        found = search(value, left_index, size);
    }
    if (!found && right_index < size) {
        found = search(value, right_index, size);
    }
    return found;
}

int Heap::extract() {
    int output_element = findMax();
    array->removeFirst();
    buildHeap();
    return output_element;
}

int Heap::getSize() {
    return array->getSize();
}

void Heap::insert(int value) {
    array->addLast(value);
    int size = getSize();
    int element_index = size - 1;
    int parent_index;
    while (element_index > 0) {
        parent_index = int(floor(element_index / 2));
        if (array->getElementValue(element_index) > array->getElementValue(parent_index)) {
            array->swap(parent_index, element_index);
            element_index = parent_index;
        } else {
            break;
        }
    };
}

void Heap::print() {
    int level = 0;
    int node_counter = 0;
    for (int i = 0; i < array->getSize(); i++) {
        if (node_counter >= pow(2, level)) {
            level++;
            node_counter = 0;
            cout << ")" << endl;
        }
        if (node_counter % 2 == 0) {
            if (node_counter == 0) {
                cout << "(";
            } else {
                cout << ")(";
            }
        } else {
            cout << ",";
        }
        cout << array->getElementValue(i);
        node_counter++;
    }
    if (getSize() > 0)
        cout << ")" << endl;
}

