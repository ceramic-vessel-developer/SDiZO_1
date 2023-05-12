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
    Node* NIL = new Node{nullptr, nullptr, nullptr, 'B', 0};
    Node* root = NIL;
public:
    red_black_tree();
    red_black_tree(int size);

    void left_rotate(Node* x);

    void right_rotate(Node *y);

    void rb_insert_fixup(Node *z);

    void rb_insert(Node *z);

    void rb_transplant(Node *u, Node *v);

    Node *tree_minimum(Node *node);

    void rb_delete_fixup(Node *x);

    void rb_delete(Node *z);

    Node *create_node(int data);

    void print_tree(Node* node, int indent = 0);
    void show();

    void add(int key);
    void deleteNode(int key);
    int *select(int key);

    Node *search(Node *node, int key);
};


#endif //SDIZO_1_RED_BLACK_TREE_H
