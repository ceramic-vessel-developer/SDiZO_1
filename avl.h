//
// Created by kacpe on 01.05.2023.
//

#ifndef SDIZO_1_AVL_H
#define SDIZO_1_AVL_H


class avl {
private:
    struct Node{
        int value;
        Node* right = nullptr;
        Node* left = nullptr;
        int height = 1;
    };
    Node* root = nullptr;
public:
    avl(int size);

    Node* insert(Node* node, int key);

    Node *rotate_right(Node *node);

    Node *rotate_left(Node *node);

    void update_height(Node *node);

    int balance_factor(Node *node);

    int maximum(int a, int b);

    void print_tree(Node *root, int indent);

    void show();

    void add(int value);

    int get_height(Node *node);

    Node* search(Node* node,int key);

    Node *delete_node(Node *root, int key);

    Node *succesor(Node *node);

    void remove(int key);
};


#endif //SDIZO_1_AVL_H
