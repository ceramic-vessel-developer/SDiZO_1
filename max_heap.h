//
// Created by kacpe on 19.03.2023.
//

#ifndef SDIZO_1_MAX_HEAP_H
#define SDIZO_1_MAX_HEAP_H


#include "dynamic_array.h"

class max_heap {
private:
    int* heap_array;
    int heap_max_size;
    int heap_size;

    int len(int number);
public:
    max_heap(int size);

    void add(int item);

    void delete_root();

    void heap_fix_up();
    void heap_fix_down(int counter);

    void show();
    int search(int item);


};


#endif //SDIZO_1_MAX_HEAP_H
