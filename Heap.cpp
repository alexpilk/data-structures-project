//
// Created by Drasik on 3/12/2018.
//

#include "Heap.h"
#include "IndexError.h"
#include "cmath"
#include "utils.h"

using namespace std;

Heap::Heap() {
    size = 0;
    capacity = 0;
}

Heap::Heap(DynamicArray* input_array) {
    array = input_array;
    size = array->getSize();
    for (int i = array->getSize() / 2 - 1; i >= 0; i--)
        heapify(array, array->getSize(), i);
}

Heap::Heap(List* input_array) {
    array = input_array;
}

void Heap::heapify(IndexedDataStructure* arr, int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr->getElementValue(l) > arr->getElementValue(largest))
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr->getElementValue(r) > arr->getElementValue(largest))
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        arr->print();
        arr->swap(i, largest);
        arr->print();
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

int Heap::findMax() {
    if (size > 0)
        return array->getElementValue(0);
    else
        throw IndexError();
}

int Heap::extract() {
    return 0;
}

void Heap::insert(int value) {

}

void Heap::print() {
    array->print();
    int level = 0;
    int node_counter = 0;
    for (int i = 0; i < array->getSize(); i++){
        if(node_counter >= pow(2, level)){
            level++;
            node_counter = 0;
            cout << ")" << endl;
        }
        if(node_counter % 2 == 0) {
            if(node_counter == 0) {
                cout << "(";
            } else {
                cout << ")(";
            }
        }
        cout << array->getElementValue(i);
        node_counter++;
    }
    cout << ")" << endl;
}

