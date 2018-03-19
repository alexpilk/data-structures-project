#include <iostream>
#include <fstream>
#include "List.h"
#include "DynamicArray.h"
#include "Heap.h"
#include "utils.h"
#include "IndexError.h"

using namespace std;


void menu() {
    int start_option;
    string file_name;
    int *base_array;
    do {
        cout << "Choose a data structure: dynamic array (1), list (2), heap (3). Enter 0 to exit:" << endl;
        cin >> start_option;
        if (start_option == 0)
            break;
        if (start_option == 1 or start_option == 2) {
            IndexedDataStructure *structure;
            switch (start_option) {
                case 1: {
                    file_name = "array.txt";
                    pair<int *, int> input_data = parse_file(file_name, base_array);
                    structure = new DynamicArray(input_data.first, input_data.second);
                    break;
                }
                case 2: {
                    file_name = "list.txt";
                    pair<int *, int> input_data = parse_file(file_name, base_array);
                    structure = new List(input_data.first, input_data.second);
                    break;
                }
                default:
                    continue;
            }
            cout << "Read data structure from file: ";
            structure->print();
            int action;
            do {
                cout << "Available actions: insert (1), remove (2). Enter 0 to exit:" << endl;
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
                            if (structure->getSize() == 0){
                                cout << "Cannot remove value from an empty list/array." << endl;
                                break;
                            }
                            if (index == -1)
                                structure->removeLast();
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
            file_name = "heap.txt";
            pair<int *, int> input_data = parse_file(file_name, base_array);
            auto *array = new DynamicArray(input_data.first, input_data.second);
            auto *heap = new Heap(array);
            cout << "Read heap structure from file:" << endl;
            heap->print();
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
    menu();
    return 0;
}
