//
// Created by kacpe on 19.03.2023.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "max_heap.h"
#include "cmath"

max_heap::max_heap(int size) {
    if (size<0) size = 0;
    heap_size = size;
    heap_max_size = size + size/2;
    if (heap_max_size == 0) heap_max_size = 1;
    heap_array = new int[heap_max_size];
    srand((unsigned ) time(NULL));
    for (int i = 0; i < size; ++i) {
        heap_array[i] = rand()%99999;
    }
    for (int i = (size-2)/2; i >=0 ; --i) {
        heap_fix_down(i);
    }
}

void max_heap::add(int item) {
    heap_array[heap_size] = item;
    heap_size++;

    if (heap_size == heap_max_size){
        heap_max_size = heap_max_size + heap_max_size/2;
        int* temp = new int[heap_max_size];
        for (int i = 0; i < heap_size; ++i) {
            temp[i] = heap_array[i];
        }
        delete [] heap_array;
        heap_array = temp;
    }
    heap_fix_up();
}

void max_heap::delete_root() {
    if (heap_size == 0) return;
    heap_array[0] = heap_array[heap_size-1];
    heap_array[heap_size-1] = 0;
    heap_size--;
    heap_fix_down();
}

void max_heap::heap_fix_up() {
    int index = heap_size -1;
    int item = heap_array[index];
    int parent;

    while (index != 0){
        parent = heap_array[index/2];
        if (item > parent){
            heap_array[index] = parent;
            heap_array[index/2] = item;
            index = index/2;
        } else{
            return;
        }
    }
}

int max_heap::heap_fix_down_floyd(int counter) {
    if (counter*2+2 < heap_size){
        int left_child = heap_array[2*counter+1];
        int right_child = heap_array[2*counter+2];

        if (right_child > left_child){
            if (right_child > heap_array[counter]){
                heap_array[2*counter+2] = heap_array[counter];
                heap_array[counter] = right_child;
                return 2*counter+2;
            }
        }else if(right_child <= left_child){
            if (left_child > heap_array[counter]){
                heap_array[2*counter+1] = heap_array[counter];
                heap_array[counter] = left_child;
                return 2*counter+1;
            }
        }
    } else if(counter*2+1 < heap_size){
        int left_child = heap_array[2*counter+1];
        if (left_child > heap_array[counter]){
            heap_array[2*counter+1] = heap_array[counter];
            heap_array[counter] = left_child;
            return 2*counter+1;
        }
    }
    return counter;
}

void max_heap::show() {
    print_heap(0,0);
}

void max_heap::print_heap(int i, int indent) {
    if (i < heap_size) {
        print_heap(2*i+2, indent + 4);
        std::cout << std::setw(indent) << " ";
        std::cout << heap_array[i] << std::endl;
        print_heap(2*i+1, indent + 4);
    }
}

int* max_heap::search(int item) {
    for (int i = 0; i <heap_size ; ++i) {
        if (heap_array[i] == item){
            return &heap_array[i];
        }
    }
    return nullptr;
}

int max_heap::len(int number) {
    int length = 0;
    do {
        ++length;
        number /= 10;
    } while (number);
    return length;
}

void max_heap::heap_fix_down(int index) {
    int new_index = index;
    do {
        index = new_index;
        new_index = heap_fix_down_floyd(index);
    } while (index != new_index);
}

max_heap::~max_heap() {
    delete[] heap_array;
}

max_heap::max_heap(std::string file) {
    std::string path = "../input_files/"+file;
    std::fstream f;
    int input, i = 0;

    f.open(path);
    if (f.is_open()){
        f >> input;
        heap_size = input;
        heap_max_size = input + input/2;
        heap_array = new int[heap_max_size];

        while (f >> input){
            if (i >= heap_size) break;
            heap_array[i] = input;
            i++;
        }

        for (i = (heap_size-2)/2; i >=0 ; --i) {
            heap_fix_down(i);
        }
        f.close();
    }else{
        std::cout << "Plik nie zostal otwarty poprawnie" << std::endl;
    }

}
