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
    for (int i = 0; i < size; ++i) {
        heap_array[i] = rand()%100;
    }
    for (int i = (size-2)/2; i >=0 ; --i) {
        heap_fix_down(i);
    }
}

void max_heap::add(int item) {

}

void max_heap::delete_root() {

}

void max_heap::heap_fix_up() {

}

void max_heap::heap_fix_down(int counter) {
    if (counter*2+2 < heap_size){
        int left_child = heap_array[2*counter+1];
        int right_child = heap_array[2*counter+2];

        if (right_child > left_child){
            if (right_child > heap_array[counter]){
                heap_array[2*counter+2] = heap_array[counter];
                heap_array[counter] = right_child;
            }
        }else if(right_child <= left_child){
            if (left_child > heap_array[counter]){
                heap_array[2*counter+1] = heap_array[counter];
                heap_array[counter] = left_child;
            }
        }
    } else if(counter*2+1 < heap_size){
        int left_child = heap_array[2*counter+1];
        if (left_child > heap_array[counter]){
            heap_array[2*counter+1] = heap_array[counter];
            heap_array[counter] = left_child;
        }
    }



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

}

int max_heap::search(int item) {
    return 0;
}

int max_heap::len(int number) {
    int length = 0;
    do {
        ++length;
        number /= 10;
    } while (number);
    return length;
}
