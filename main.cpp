#include <iostream>
#include "List.h"
#include "DynamicArray.h"
#include "Heap.h"
#include "utils.h"

using namespace std;

void test_list(){
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
    int base_array[] = {2, 3, 4, 4, 5, 6, 4, 5, 5, 6, 7, 8, 8, 9, 5};
    int base_array_size = getArraySize(base_array);
    auto* input_array = new DynamicArray(base_array, base_array_size);
    Heap my_heap = Heap(input_array);
    my_heap.print();
}

int main(){
//    test_list();
//    test_dynamic_array();
    test_heap();
    return 0;
}
