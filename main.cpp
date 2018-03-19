#include <iostream>
#include "List.h"
#include "DynamicArray.h"
#include "Heap.h"
#include "utils.h"
#include "chrono"
#include "random"
#include "IndexError.h"

using namespace std;

void test_list() {
    cout << "Testing linked list" << endl;
    List my_list = List();
    my_list.addFirst(1);
    my_list.print();
    my_list.addFirst(4);
    my_list.print();
    my_list.addFirst(5);
    my_list.print();
    my_list.addLast(6);
    my_list.print();
    my_list.insert(9, 2);
    my_list.print();
    my_list.removeOnIndex(2);
    my_list.print();
    my_list.removeFirst();
    my_list.print();
    my_list.removeLast();
    my_list.print();
    cout << my_list.getSize() << endl;
}

void test_dynamic_array() {
    cout << "Testing dynamic array" << endl;
    DynamicArray my_array = DynamicArray();
    my_array.print();
    my_array.addFirst(3);
    my_array.print();
    my_array.addLast(4);
    my_array.print();
    my_array.addLast(6);
    my_array.print();
    my_array.insert(5, 2);
    my_array.print();
    my_array.removeOnIndex(1);
    my_array.print();
    my_array.removeFirst();
    my_array.removeLast();
    my_array.print();
};

void test_heap() {
    cout << "Testing heap" << endl;
    int base_array[] = {2, 9, 4, 4, 2, 6, 4, 5, 5, 6, 7, 8, 1, 9, 5};
    int base_array_size = getArraySize(base_array);
    auto *input_array = new List(base_array, base_array_size);
    Heap my_heap = Heap(input_array);
    my_heap.insert(80);
    my_heap.insert(800);
    my_heap.print();
    int extracted = my_heap.extract();
    cout << "Extracted: " << extracted << endl;
    my_heap.print();
}

void list_vs_array(int repetitions) {
    long long int time_taken;
    int ARRAY_SIZE = 75000;
    int bottom_limit = 0;
    int top_limit = 100000;
    int value_to_add = 50000;
    int insert_index = ARRAY_SIZE / 2;
    cout << "Add F\tAdd L\tIns\tRem F\tRem L\tRem IND" << endl;
    for (int i = 0; i < repetitions; ++i) {
        int start_array[ARRAY_SIZE];
        fillWithRandomValues(start_array, ARRAY_SIZE, 0, 1);
        // List
        auto *my_list = new List(start_array, ARRAY_SIZE);
        time_taken = measure(my_list, my_list->addFirst, value_to_add);
        time_taken = measure(my_list, my_list->addLast, value_to_add);
        time_taken = measure(my_list, my_list->insert, value_to_add, insert_index);

        time_taken = measure(my_list, my_list->removeFirst);
        time_taken = measure(my_list, my_list->removeLast);
        time_taken = measure(my_list, my_list->removeOnIndex, insert_index);
        cout << endl;
    }
}


void heap_measurements(int repetitions) {
    long long int time_taken;
    int ARRAY_SIZE = 100000;
    int bottom_limit = 0;
    int top_limit = 100000;
    int mid_value = 50000;
    int insert_index = ARRAY_SIZE / 2;
    cout << "Ins min\tIns max\tIns middle\tExtract" << endl;

    for (int i = 0; i < repetitions; ++i) {
        int start_array[ARRAY_SIZE];
        fillWithRandomValues(start_array, ARRAY_SIZE, 0, 1);
        auto *input_array = new DynamicArray(start_array, ARRAY_SIZE);
        auto *my_heap = new Heap(input_array);
        time_taken = measure(my_heap, my_heap->insert, bottom_limit);
        time_taken = measure(my_heap, my_heap->insert, top_limit);
        time_taken = measure(my_heap, my_heap->insert, mid_value);
        time_taken = measure(my_heap, my_heap->extract);
        cout << endl;
    }

//    cout << "LIns min\tIns max\tIns middle\tExtract" << endl;
//    auto *input_list = new List(start_array, ARRAY_SIZE);
//    auto *my_heap_list = new Heap(input_list);
//
//    for (int i = 0; i < repetitions; ++i) {
//        time_taken = measure(my_heap_list, my_heap_list->insert, bottom_limit);
//        time_taken = measure(my_heap_list, my_heap_list->insert, top_limit);
//        time_taken = measure(my_heap_list, my_heap_list->insert, mid_value);
//        time_taken = measure(my_heap_list, my_heap_list->extract);
//        cout << endl;
//    }
}

void menu() {
    int start_option;
    do {
        cout << "Choose a data structure: dynamic array, list, heap (1-3). Enter 0 to exit:" << endl;
        cin >> start_option;
        if (start_option == 0)
            break;
        if (start_option == 1 or start_option == 2) {
            IndexedDataStructure *structure;
            switch (start_option) {
                case 1:
                    structure = new DynamicArray();
                    break;
                case 2:
                    structure = new List();
                    break;
                default:
                    continue;
            }
            int action;
            do {
                cout << "Available actions: insert, remove (1-2). Enter 0 to exit:" << endl;
                cin >> action;
                if (action == 0)
                    break;
                int index;
                cout << "Choose index (enter -1 to access the last element):" << endl;
                cin >> index;
                try {
                    switch (action) {
                        case 1:
                            int value;
                            cout << "Enter value:" << endl;
                            cin >> value;
                            if (index == -1)
                                structure->addLast(value);
                            else
                                structure->insert(value, index);
                            break;
                        case 2:
                            if (index == -1)
                                structure->addLast(value);
                            else
                                structure->removeOnIndex(index);
                            break;
                        default:
                            continue;
                    }
                } catch (IndexError &e) {
                    cout << "Index " << index << " out of range" << endl;
                }
                structure->print();
            } while (action != 0);
        } else if (start_option == 3) {
            int action;
            auto *array = new DynamicArray();
            auto *heap = new Heap(array);
            do {
                try {
                    cout << "Available actions: insert, extract (1-2). Enter 0 to exit:" << endl;
                    cin >> action;
                    if (action == 0)
                        break;
                    else if (action == 1) {
                        int value;
                        cout << "Enter value:" << endl;
                        cin >> value;
                        heap->insert(value);
                    } else if (action == 2) {
                        int value = heap->extract();
                        cout << "Extracted " << value << endl;
                    }
                    heap->print();
                } catch (IndexError &e) {
                    cout << "Cannot extract value from an empty heap" << endl;
                }
            } while (action != 0);
        }
    } while (start_option != 0);
}

int main() {
//    list_vs_array(100);
    heap_measurements(100);
//    menu();
    return 0;
}
