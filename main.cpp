#include <iostream>
#include "dynamic_array.h"
#include "double_linked_list.h"
#include "max_heap.h"

int main() {
    max_heap* test = new max_heap(7);
    test->show();

    test->add(13);
    test->show();

    test->delete_root();
    test->show();

    int* temp = test->search(13);
    std::cout << *temp;

    return 0;
}
