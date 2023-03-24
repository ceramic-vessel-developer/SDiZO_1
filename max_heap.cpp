//
// Created by kacpe on 19.03.2023.
//

#include <iostream>
#include "max_heap.h"
#include "cmath"

max_heap::max_heap(int size) {
    heap_size = size;
    heap_max_size = size + size/2;
    heap_array = new int(heap_max_size);
    srand((unsigned ) time(NULL));
    for (int i = 0; i < size; ++i) {
        heap_array[i] = rand()%100;
    }
    show();
    for (int i = (size-2)/2; i >=0 ; --i) {
        heap_fix_down(i);
    }
}

void max_heap::add(int item) {
    heap_array[heap_size] = item;
    heap_size++;

    if (heap_size == heap_max_size){
        heap_max_size = heap_max_size + heap_max_size/2;
        int* temp = new int(heap_max_size);
        for (int i = 0; i < heap_size; ++i) {
            temp[i] = heap_array[i];
        }
        delete [] heap_array;
        heap_array = temp;
    }
    heap_fix_up();
}

void max_heap::delete_root() {
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
            break;
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
    int pos = 0, e = 0;
    for( int i=0; i<heap_size; i++ ) { // n = arr length

        if( heap_array[i] == -1 )
            std::cout << ' ';
        else
            std::cout << heap_array[i] << ' ';


        if( pos == 0 ) {
            pos = pow(2, e); // returns 2^e
            e++;
        }

        if( pos == 1 )
            std::cout << std::endl;
        pos--;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int* max_heap::search(int item) {
    for (int i = 0; i <heap_size ; ++i) {
        if (heap_array[i] = item){
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
