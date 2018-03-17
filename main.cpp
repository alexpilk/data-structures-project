#include <iostream>
#include "List.h"
#include "DynamicArray.h"
#include "Heap.h"
#include "utils.h"
#include "chrono"

using namespace std;
void test_list(){
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

void test_dynamic_array(){
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

void test_heap(){
    cout << "Testing heap" << endl;
    int base_array[] = {2, 9, 4, 4, 2, 6, 4, 5, 5, 6, 7, 8, 1, 9, 5};
    int base_array_size = getArraySize(base_array);
    auto* input_array = new List(base_array, base_array_size);
    Heap my_heap = Heap(input_array);
    my_heap.insert(80);
    my_heap.insert(800);
    my_heap.print();
    int extracted = my_heap.extract();
    cout << "Extracted: " << extracted << endl;
    my_heap.print();
}

template<class T, typename ReturnType, typename... Args>
double measure(T* my_list, ReturnType (T::*func)(Args...), Args... args){
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    (my_list->*func)(args...);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - begin).count();
}

int main(){
    int base_array[] = {2, 9, 4, 4, 2, 6, 4, 5, 5, 6, 7, 8, 1, 9, 5};
    auto* my_list = new List(base_array, getArraySize(base_array));
    my_list->print();
    double time = measure(my_list, my_list->getSize);
    my_list->print();
    cout << time << endl;
    return 0;
}
