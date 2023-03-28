//
// Created by kacpe on 28.03.2023.
//

#ifndef SDIZO_1_RED_BLACK_TREE_H
#define SDIZO_1_RED_BLACK_TREE_H


class red_black_tree {
private:
    struct Node{
        Node* parent;
        Node* left;
        Node* right;
        char colour = 'R';
        int data;
    };
    Node* root = nullptr;
public:
    red_black_tree();

    void add(int value);
    void del(int value);
    Node* search(int value);

    void rotate_right(Node* node);
    void rotate_left(Node* node);

    void show_inorder();

    void show();
};


#endif //SDIZO_1_RED_BLACK_TREE_H
