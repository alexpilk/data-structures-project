//
// Created by Drasik on 3/11/2018.
//

#include "List.h"
#include <iostream>
#include "IndexError.h"

using namespace std;

List::List() {
    head = nullptr;
    size = 0;
}

List::Element *List::getElement(int index) {
    if (index >= size) {
        throw IndexError();
    }
    Element *current_element = head;
    for (int i = 0; i < index; i++) {
        current_element = current_element->next;
    }
    return current_element;
}

int List::getElementValue(int index) {
    Element *element = getElement(index);
    return element->value;
}

int List::getSize() {
    return size;
}

void List::addFirst(int value) {
    auto *new_element = new Element(value);
    if (size == 0) {
        head = new_element;
    } else {
        Element *head_copy = head;
        head = new_element;
        head->next = head_copy;
        head_copy->prev = head;
    }
    size++;
}

void List::addLast(int value) {
    auto *new_element = new Element(value);
    if (size == 0) {
        head = new_element;
    } else {
        Element *old_element = getElement(size - 1);
        new_element->prev = old_element;
        old_element->next = new_element;
    }
    size++;
}

void List::insert(int value, int index) {
    if (index == 0) {
        addFirst(value);
    } else if (index == size) {
        addLast(value);
    } else {
        Element *old_element = getElement(index);
        auto *new_element = new Element(value);
        new_element->next = old_element;
        new_element->prev = old_element->prev;
        old_element->prev = new_element;
        new_element->prev->next = new_element;
        size++;
    }
}

void List::removeFirst() {
    removeOnIndex(0);
}

void List::removeLast() {
    removeOnIndex(size - 1);
}

void List::removeOnIndex(int index) {
    Element *element_to_remove = getElement(index);
    // reset head if removing the first element
    if (index == 0)
        head = element_to_remove->next;
    else
        // otherwise make `prev` element point to `next` element
        element_to_remove->prev->next = element_to_remove->next;
    // make `next` element point to `prev` element if not removing the last one
    if (index != size - 1)
        element_to_remove->next->prev = element_to_remove->prev;
    delete (element_to_remove);
    size--;
}

void List::print() {
    cout << "[";
    Element *temp = head;
    while (temp->next != nullptr) {
        cout << temp->value << ", ";
        temp = temp->next;
    }
    cout << temp->value << "]" << endl;
}

void List::swap(int index_1, int index_2) {
    Element* element_1 = getElement(index_1);
    Element* element_2 = getElement(index_2);
    int temp = element_1->value;
    element_1->value = element_2->value;
    element_2->value = temp;
}
