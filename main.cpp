#include <iostream>
#include "dynamic_array.h"
#include "double_linked_list.h"

int main() {
    double_linked_list* list = new double_linked_list(10);
    list->show();

    list->add_front(1);
    list->show();

    list->add_back(2);
    list->show();

    list->add(3,2);
    list->show();

    list->add(4,2);
    list->show();

    list->add(5,0);
    list->show();

    list->delete_back();
    list->show();

    list->delete_front();
    list->show();

    list->delete_with_index(0);
    list->show();

    list->delete_with_index(11);
    list->show();

    list->delete_with_index(2);
    list->show();

    std::cout << list->select(0) << " " << list->select(3) << " " << list->select(9);


    return 0;
}
