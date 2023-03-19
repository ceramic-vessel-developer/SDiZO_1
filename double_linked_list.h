//
// Created by kacpe on 18.03.2023.
//

#ifndef SDIZO_1_DOUBLE_LINKED_LIST_H
#define SDIZO_1_DOUBLE_LINKED_LIST_H


class double_linked_list {
private:
    struct dll_elem{
        int value;
        dll_elem* previous;
        dll_elem* next;
    };
    dll_elem* first = nullptr;
    dll_elem* last = nullptr;

    dll_elem* search(int index);
public:
    double_linked_list(int size);

    void add_front(int item);
    void add_back(int item);
    void add(int item, int index);

    bool delete_front();
    bool delete_back();
    bool delete_with_index(int index);

    int select(int index);

    void show();


};


#endif //SDIZO_1_DOUBLE_LINKED_LIST_H
