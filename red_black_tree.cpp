//
// Created by kacpe on 30.04.2023.
//

#include <iostream>
#include <iomanip>
#include "red_black_tree.h"
void red_black_tree::left_rotate(Node* x){
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NIL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void red_black_tree::right_rotate( Node* y){
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NIL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NIL)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    x->right = y;
    y->parent = x;
}

void red_black_tree::rb_insert_fixup(Node* z){
    while (z->parent->colour == 'R') {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y->colour == 'R') {
                z->parent->colour = 'B';
                y->colour = 'B';
                z->parent->parent->colour = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    left_rotate(z);
                }
                z->parent->colour = 'B';
                z->parent->parent->colour = 'R';
                right_rotate(z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y->colour == 'R') {
                z->parent->colour = 'B';
                y->colour = 'B';
                z->parent->parent->colour = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    right_rotate(z);
                }
                z->parent->colour = 'B';
                z->parent->parent->colour = 'R';
                left_rotate(z->parent->parent);
            }
        }
    }
    root->colour = 'B';
}

void red_black_tree::rb_insert(Node* z){
    Node* y = NIL;
    Node* x = root;
    while (x != NIL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NIL)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;
    z->left = NIL;
    z->right = NIL;
    z->colour = 'R';
    rb_insert_fixup(z);
}
void red_black_tree::rb_transplant( Node* u, Node* v) {
    if (u->parent == NIL)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

red_black_tree::Node* red_black_tree::tree_minimum(Node* node) {
    while (node->left != NIL)
        node = node->left;
    return node;
}

void red_black_tree::rb_delete_fixup(Node* x) {
    while (x != root && x->colour == 'B') {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->colour == 'R') {
                w->colour = 'B';
                x->parent->colour = 'R';
                left_rotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->colour == 'B' && w->right->colour == 'B') {
                w->colour = 'R';
                x = x->parent;
            } else {
                if (w->right->colour == 'B') {
                    w->left->colour = 'B';
                    w->colour = 'R';
                    right_rotate(w);
                    w = x->parent->right;
                }
                w->colour = x->parent->colour;
                x->parent->colour = 'B';
                w->right->colour = 'B';
                left_rotate(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->colour == 'R') {
                w->colour = 'B';
                x->parent->colour = 'R';
                right_rotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->colour == 'B' && w->left->colour == 'B') {
                w->colour = 'R';
                x = x->parent;
            } else {
                if (w->left->colour == 'B') {
                    w->right->colour = 'B';
                    w->colour = 'R';
                    left_rotate(w);
                    w = x->parent->left;
                }
                w->colour = x->parent->colour;
                x->parent->colour = 'B';
                w->left->colour = 'B';
                right_rotate(x->parent);
                x = root;
            }
        }
    }
    x->colour = 'B';
}
void red_black_tree::rb_delete( Node* z) {
    Node* y = z;
    Node* x;
    char y_original_colour = y->colour;

    if (z->left == NIL) {
        x = z->right;
        rb_transplant( z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        rb_transplant( z, z->left);
    } else {
        y = tree_minimum(z->right);
        y_original_colour = y->colour;
        x = y->right;
        if (y->parent == z)
            x->parent = y;
        else {
            rb_transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rb_transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->colour = z->colour;
    }
    if (y_original_colour == 'B')
        rb_delete_fixup(x);
    delete z;
}
red_black_tree::Node* red_black_tree::create_node(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->parent = NIL;
    new_node->left = NIL;
    new_node->right = NIL;
    return new_node;
}

red_black_tree::red_black_tree() = default;

red_black_tree::red_black_tree(int size) {
    Node* temp = new Node;
    for (int i = 0; i < size; ++i) {
        temp = create_node(i);
        rb_insert(temp);
    }
}

void red_black_tree::print_tree(Node* node, int indent) {
    if (node != NIL) {
        print_tree(node->right, indent + 4);
        std::cout << std::setw(indent) << " ";
        std::cout << node->data << " " << node->colour << std::endl;
        print_tree(node->left, indent + 4);
    }
}

void red_black_tree::show(){
    print_tree(root);
}
red_black_tree::Node* red_black_tree::search(Node* node, int key) {
    if (node == NIL || node->data == key)
        return node;

    if (key < node->data)
        return search(node->left, key);
    else
        return search(node->right, key);
}

void red_black_tree::add(int key) {
    Node* temp = create_node(key);
    rb_insert(temp);
}

void red_black_tree::deleteNode(int key) {
    Node* temp = search(root,key);
    if (temp != NIL){
        rb_delete(temp);
    } else{
        std::cout << "There is no such node in that tree!" << std::endl;
    }
}

int *red_black_tree::select(int key) {
    Node* temp = search(root, key);
    if (temp == NIL){
        std::cout << "There is no such key!" << std::endl;
    }
    return &temp->data;
}




