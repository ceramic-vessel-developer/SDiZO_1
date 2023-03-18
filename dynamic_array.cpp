//
// Created by kacpe on 18.03.2023.
//

#include "dynamic_array.h"
#include "cstdlib"



dynamic_array::dynamic_array(int* static_array, int static_size) {
    array = static_array;
    size = static_size;
}

void dynamic_array::add_front(int item) {
    int* temp = new int(size+1);
    temp[0] = item;
    for (int i = 0; i < size; ++i) {
        temp[i+1] = array[i];
    }
    delete[] array;
    array = temp;
    size++;
}

void dynamic_array::add_back(int item) {
    int* temp = new int(size+1);
    temp[size] = item;
    for (int i = 0; i < size; ++i) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    size++;
}

void dynamic_array::add(int item, int index) {
    int* temp = new int(size+1);
    for (int i = 0; i < index; ++i) {
        temp[i] = array[i];
    }
    temp[index] = item;
    for (int i = index; i <size ; ++i) {
        temp[i+1] = array[i];
    }
    delete[] array;
    array = temp;
    size++;
}

void dynamic_array::delete_with_index(int index) {
    int* temp = new int(size-1);
    for (int i = 0; i <index ; ++i) {
        temp[i] = array[i];
    }
    for (int i = index+1; i <size ; ++i) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    size--;
}

void dynamic_array::delete_back() {
    int* temp = new int(size-1);
    for (int i = 0; i <size-1 ; ++i) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    size--;
}

void dynamic_array::delete_front() {
    int* temp = new int(size-1);
    for (int i = 0; i <size-1 ; ++i) {
        temp[i] = array[i+1];
    }
    delete[] array;
    array = temp;
    size--;
}

int dynamic_array::select(int index) {
    return array[index];
}



