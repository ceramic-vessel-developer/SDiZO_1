//
// Created by kacpe on 18.03.2023.
//

#include <iostream>
#include <fstream>
#include "dynamic_array.h"





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

int* dynamic_array::select(int value) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) {
            return &array[i];
        }
    }
    return nullptr;
}

void dynamic_array::show() {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i]<<" ";
    }
    std::cout<<std::endl;

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

dynamic_array::dynamic_array(std::string file) {
    std::string path = "../input_files/"+file;
    std::fstream f;
    int input, i=0;

    f.open(path);
    if (f.is_open()){
        f >> input;
        array = new int[input];
        this->size = input;
        while (f >> input){
            if (i >= size) break;
            array[i] = input;
            i++;
        }
        f.close();
    }else{
        std::cout << "Plik nie zostal otwarty poprawnie" << std::endl;
    }

}

dynamic_array::~dynamic_array() {
    delete array;
}



