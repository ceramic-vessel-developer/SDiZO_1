//
// Created by kacpe on 18.03.2023.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "double_linked_list.h"

double_linked_list::double_linked_list(int size) {
    srand((unsigned) time(nullptr));

    for (int i = 0; i < size; ++i) {
        add_back(rand()%1000);
    }
}

void double_linked_list::add_front(int item) {
    dll_elem* node = new dll_elem();

    node->value = item;
    node->previous = nullptr;
    node->next = first;

    if (first){
        first->previous = node;
    }else{
        last = node;
    }
    first = node;
}

void double_linked_list::add_back(int item) {
    dll_elem* node = new dll_elem();

    node->value = item;
    node->previous = last;
    node->next = nullptr;

    if (last){
        last->next = node;
    }else{
        first = node;
    }
    last = node;
}

void double_linked_list::add(int item, int index) {
    dll_elem* node = new dll_elem();

    dll_elem* current_node = search(index);

    node->value = item;
    node->next = current_node;

    if (current_node) {

        node->previous = current_node->previous;
        if (!current_node->previous){
            first = node;
            return;
        }

        current_node->previous->next = node;

        current_node->previous = node;


    }else if (index == 0){
        node->previous = nullptr;
        node->next = nullptr;
        first = node;
        last = node;
    } else{
        last->next = node;
        node->previous = last;
        last = node;
    }
}

bool double_linked_list::delete_front() {
    if(!first)return false;

    dll_elem* temp = first->next;
    delete first;
    if (temp){
        temp->previous = nullptr;
    }
    first = temp;
    return true;
}

bool double_linked_list::delete_back() {
    if (!last) return false;

    dll_elem* temp = last->previous;

    delete last;

    temp->next = nullptr;
    last = temp;

    return true;
}

bool double_linked_list::delete_with_index(int index) {
    if (!last) return false;

    dll_elem* temp = search(index);
    if (temp->next and temp->previous){
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
    }else if (temp->next){
        first = temp->next;
        temp->next->previous = nullptr;
    }else if (temp->previous){
        last = temp->previous;
        temp->previous->next = nullptr;
    }
    delete temp;

    return true;
}

int double_linked_list::select(int index) {
    dll_elem* temp = search(index);
    return temp->value;
}

void double_linked_list::show() {
    dll_elem* temp = first;
    while(temp){
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

double_linked_list::dll_elem *double_linked_list::search(int index) {

    dll_elem* temp;
    temp = first;
    if (temp){
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
    }
    return temp;
}
