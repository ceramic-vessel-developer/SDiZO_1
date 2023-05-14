//
// Created by kacpe on 30.04.2023.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "red_black_tree.h"
void red_black_tree::left_rotate(Node* node){
    Node* temp = node->right;
    node->right = temp->left;
    if (temp->left != NIL)
        temp->left->parent = node;
    temp->parent = node->parent;
    if (node->parent == NIL)
        root = temp;
    else if (node == node->parent->left)
        node->parent->left = temp;
    else
        node->parent->right = temp;
    temp->left = node;
    node->parent = temp;
}

void red_black_tree::right_rotate( Node* node){
    Node* temp = node->left;
    node->left = temp->right;
    if (temp->right != NIL)
        temp->right->parent = node;
    temp->parent = node->parent;
    if (node->parent == NIL)
        root = temp;
    else if (node == node->parent->right)
        node->parent->right = temp;
    else
        node->parent->left = temp;
    temp->right = node;
    node->parent = temp;
}

void red_black_tree::rb_insert_fixup(Node* node){
    while (node->parent->colour == 'R') {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            if (uncle->colour == 'R') {
                node->parent->colour = 'B';
                uncle->colour = 'B';
                node->parent->parent->colour = 'R';
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    left_rotate(node);
                }
                node->parent->colour = 'B';
                node->parent->parent->colour = 'R';
                right_rotate(node->parent->parent);
            }
        } else {
            Node* uncle = node->parent->parent->left;
            if (uncle->colour == 'R') {
                node->parent->colour = 'B';
                uncle->colour = 'B';
                node->parent->parent->colour = 'R';
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    right_rotate(node);
                }
                node->parent->colour = 'B';
                node->parent->parent->colour = 'R';
                left_rotate(node->parent->parent);
            }
        }
    }
    root->colour = 'B';
}

void red_black_tree::rb_insert(Node* new_node){
    Node* parent = NIL;
    Node* temp = root;
    while (temp != NIL) {
        parent = temp;
        if (new_node->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    new_node->parent = parent;
    if (parent == NIL)
        root = new_node;
    else if (new_node->data < parent->data)
        parent->left = new_node;
    else
        parent->right = new_node;
    new_node->left = NIL;
    new_node->right = NIL;
    new_node->colour = 'R';
    rb_insert_fixup(new_node);
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

void red_black_tree::rb_delete_fixup(Node* node) {
    while (node != root && node->colour == 'B') {
        if (node == node->parent->left) {
            Node* sibling = node->parent->right;
            if (sibling->colour == 'R') {
                sibling->colour = 'B';
                node->parent->colour = 'R';
                left_rotate(node->parent);
                sibling = node->parent->right;
            }
            if (sibling->left->colour == 'B' && sibling->right->colour == 'B') {
                sibling->colour = 'R';
                node = node->parent;
            } else {
                if (sibling->right->colour == 'B') {
                    sibling->left->colour = 'B';
                    sibling->colour = 'R';
                    right_rotate(sibling);
                    sibling = node->parent->right;
                }
                sibling->colour = node->parent->colour;
                node->parent->colour = 'B';
                sibling->right->colour = 'B';
                left_rotate(node->parent);
                node = root;
            }
        } else {
            Node* sibling = node->parent->left;
            if (sibling->colour == 'R') {
                sibling->colour = 'B';
                node->parent->colour = 'R';
                right_rotate(node->parent);
                sibling = node->parent->left;
            }
            if (sibling->right->colour == 'B' && sibling->left->colour == 'B') {
                sibling->colour = 'R';
                node = node->parent;
            } else {
                if (sibling->left->colour == 'B') {
                    sibling->right->colour = 'B';
                    sibling->colour = 'R';
                    left_rotate(sibling);
                    sibling = node->parent->left;
                }
                sibling->colour = node->parent->colour;
                node->parent->colour = 'B';
                sibling->left->colour = 'B';
                right_rotate(node->parent);
                node = root;
            }
        }
    }
    node->colour = 'B';
}

void red_black_tree::rb_delete( Node* node) {
    Node* succesor;
    Node* temp;
    char node_original_colour = node->colour;

    if (node->left == NIL) {
        temp = node->right;
        rb_transplant(node, node->right);
    } else if (node->right == NIL) {
        temp = node->left;
        rb_transplant(node, node->left);
    } else {
        succesor = tree_minimum(node->right);
        node_original_colour = succesor->colour;
        temp = succesor->right;
        if (succesor->parent == node)
            temp->parent = succesor;
        else {
            rb_transplant(succesor, succesor->right);
            succesor->right = node->right;
            succesor->right->parent = succesor;
        }
        rb_transplant(node, succesor);
        succesor->left = node->left;
        succesor->left->parent = succesor;
        succesor->colour = node->colour;
    }
    if (node_original_colour == 'B')
        rb_delete_fixup(temp);
    delete node;
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
    if (size <= 0) return;
    Node* temp = new Node;
    for (int i = 0; i < size; ++i) {
        temp = create_node(rand());
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
    if(root == NIL) return;
    print_tree(root);
}

red_black_tree::Node* red_black_tree::search(Node* node, int key) {
    Node* temp = node;

    while (temp != NIL){
        if (temp->data > key){
            temp = temp->left;
        }else if (temp->data < key){
            temp = temp->right;
        }else{
            return temp;
        }
    }
    return temp;
}

void red_black_tree::add(int key) {
    Node* temp = create_node(key);
    rb_insert(temp);
}

void red_black_tree::deleteNode(int key) {
    Node* temp = search(root,key);
    if (temp != NIL){
        rb_delete(temp);
    }
}

int *red_black_tree::select(int key) {
    Node* temp = search(root, key);
    return &temp->data;
}

red_black_tree::red_black_tree(std::string file) {
    std::string path = "../input_files/"+file;
    std::fstream f;
    int input;

    f.open(path);
    if (f.is_open()){
        f >> input;
        Node* temp = new Node;
        while (f >> input){
            temp = create_node(input);
            rb_insert(temp);
        }
        f.close();
    }else{
        std::cout << "Plik nie zostal otwarty poprawnie" << std::endl;
    }
}

void red_black_tree::clear(red_black_tree::Node *node) {
    if (node){
        clear(node->right);
        clear(node->left);
        delete node;
    }
}

red_black_tree::~red_black_tree() {
    clear(root);
}




