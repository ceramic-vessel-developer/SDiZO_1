//
// Created by kacpe on 18.03.2023.
//

#include <iostream>
#include "dynamic_array.h"



dynamic_array::dynamic_array(int* static_array, int static_size) {
    array = static_array;
    size = static_size;
}

void dynamic_array::add_front(int item) {
    int* temp = new int[size+1];
    temp[0] = item;
    for (int i = 0; i < size; ++i) {
        temp[i+1] = array[i];
    }
    delete[] array;
    array = temp;
    size++;
}

void dynamic_array::add_back(int item) {
    int* temp = new int[size+1];
    temp[size] = item;
    for (int i = 0; i < size; ++i) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    size++;
}

void dynamic_array::add(int item, int index) {
    int* temp = new int[size+1];
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
    if (size == 0 or index+1 > size){
        return;
    }
    int* temp = new int[size-1];
    for (int i = 0; i <index ; ++i) {
        temp[i] = array[i];
    }
    for (int i = index; i <size+1 ; ++i) {
        temp[i] = array[i+1];
    }
    delete[] array;
    array = temp;
    size--;
}

void dynamic_array::delete_back() {
    if (size == 0) return;
    int* temp = new int[size-1];
    for (int i = 0; i <size-1 ; ++i) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    size--;
}

void dynamic_array::delete_front() {
    if (size == 0) return;
    int* temp = new int[size-1];
    for (int i = 0; i <size-1 ; ++i) {
        temp[i] = array[i+1];
    }
    delete[] array;
    array = temp;
    size--;
}

int dynamic_array::select(int index) {
    if (index+1>size){
        std::cout << "Indeks poza zakresem" << std::endl;
        return 0;
    }
    return array[index];
}

void dynamic_array::show() {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i]<<" ";
    }
    std::cout<<std::endl;

}

void dynamic_array::swap(int index_a, int index_b) {
    int temp = array[index_a];
    array[index_a] = array[index_b];
    array[index_b] = temp;
}

int dynamic_array::get_size() {
    return size;
}

dynamic_array::dynamic_array(int size) {
    if (size < 0) size = 0;

    array = new int[size];
    this->size = size;
    srand((unsigned) time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i] = rand();
    }

}



