//
// Created by kacpe on 18.03.2023.
//

#ifndef SDIZO_1_DYNAMIC_ARRAY_H
#define SDIZO_1_DYNAMIC_ARRAY_H



class dynamic_array {
private:
    int* array = nullptr;
    int size;
public:

    dynamic_array(int* static_array, int static_size);

    void add_front(int item);
    void add_back(int item);
    void add(int item, int index);

    void delete_front();
    void delete_back();
    void delete_with_index(int index);

    int select(int index);

    void show();



};


#endif //SDIZO_1_DYNAMIC_ARRAY_H
