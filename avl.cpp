//
// Created by kacpe on 01.05.2023.
//

#include <iostream>
#include <iomanip>
#include "avl.h"
int avl::balance_factor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return get_height(node->left) - get_height(node->right);
}
int avl::get_height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

void avl::update_height(Node* node) {
    node->height = maximum(get_height(node->left), get_height(node->right)) + 1;
}
int avl::maximum(int a, int b)
{
    return (a > b)? a : b;
}
avl::Node* avl::rotate_left(Node* node) {
    Node* new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;
    update_height(node);
    update_height(new_root);
    if (node == root){
        root = new_root;
    }
    return new_root;
}

avl::Node* avl::rotate_right(Node* node) {
    Node* new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;
    update_height(node);
    update_height(new_root);
    if (node == root){
        root = new_root;
    }
    return new_root;
}

avl::Node* avl::insert(Node* node, int value) {
    if (node == nullptr) {
        Node* temp = new Node;
        temp->value = value;
        return temp;
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } else {
        return node;
    }
    update_height(node);
    int bf = balance_factor(node);
    if (bf > 1 && value < node->left->value) {
        return rotate_right(node);
    }
    if (bf < -1 && value > node->right->value) {
        return rotate_left(node);
    }
    if (bf > 1 && value > node->left->value) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    if (bf < -1 && value < node->right->value) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}
void avl::print_tree(Node* node, int indent = 0) {
    if (node != nullptr) {
        if (node->right) {
            print_tree(node->right, indent + 4);
        }
        if (indent > 0) {
            std::cout << std::setw(indent) << ' ';
        }
        if (node->right) {
            std::cout << " /\n" << std::setw(indent) << ' ';
        }
        std::cout << node->value <<" ("<<node->height<<")\n ";
        if (node->left) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            print_tree(node->left, indent + 4);
        }
    }
}

void avl::show() {
    print_tree(root);
}

void avl::add(int value) {
    if (not root){
        Node* temp = new Node;
        temp->value = value;
        root = temp;
        return;
    }
    insert(root,value);
}

avl::avl(int size) {
    for (int i = 0; i < size; ++i) {
        add(i);
    }
}
