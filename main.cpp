#include <iostream>
#include "List.h"

using namespace std;
int main(){
    List my_list = List();
    my_list.addFirst(1);
    my_list.addFirst(4);
    my_list.addFirst(5);
    my_list.addLast(6);
    my_list.insert(9, 0);
    my_list.print();
    my_list.removeOnIndex(2);
    my_list.removeFirst();
    my_list.removeLast();
    my_list.print();
    cout << my_list.getSize() << endl;
    return 0;
};
