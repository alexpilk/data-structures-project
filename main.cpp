#include <iostream>
#include "List.h"
#include "DynamicArray.h"

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
int main(){
//    test_list();
    DynamicArray my_array = DynamicArray();
    my_array.print();
    my_array.insert(4, 0);
    my_array.insert(5, 1);
    my_array.print();
    return 0;
};
