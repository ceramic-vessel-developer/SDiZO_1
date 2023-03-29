//
// Created by kacpe on 28.03.2023.
//

#include <iostream>
#include "red_black_tree.h"

red_black_tree::red_black_tree() {
    root = new Node();
}

void red_black_tree::add(int value) {

}

void red_black_tree::del(int value) {

}

red_black_tree::Node *red_black_tree::search(int value) {
    return nullptr;
}

void red_black_tree::show() {
    std::cout << root->left << std::endl;
    if (not root->right||root->left->colour){
        std::cout << "y tak";
    }else{
        std::cout << root->left->colour;
    }

}

void red_black_tree::rotate_right(red_black_tree::Node *node) {
    Node* temp = node->left;

    temp->parent = node->parent;
    if (not node->parent) {
        root = temp;
    }else if (node == node->parent->left) {
        node->parent->left = temp;
    }else {
        node->parent->right = temp;
    }

    node->left = temp->right;
    if (node->left){
        node->left->parent = node;
    }
    temp->right = node;
    node->parent = node;
}

void red_black_tree::rotate_left(red_black_tree::Node *node) {
    Node* temp = node->right;

    temp->parent = node->parent;
    if (not node->parent) {
        root = temp;
    }else if (node == node->parent->left) {
        node->parent->left = temp;
    }else {
        node->parent->right = temp;
    }

    node->right = temp->left;
    if (node->right){
        node->right->parent = node;
    }
    temp->left = node;
    node->parent = node;

}

void red_black_tree::show_inorder() {

}

void red_black_tree::fix(red_black_tree::Node *node) {
    Node* parent = node->parent;

    if (not parent){
        node->colour = 'B';
        return;
    } else if (parent->colour == 'B'){
        return;
    }

    Node* grandparent = parent->parent;
    Node* uncle = nullptr;
    if (parent == grandparent->left){
        uncle = grandparent->right;
    }else{
        uncle = grandparent->left;
    }

    if (not uncle && uncle->colour == 'R'){
        parent->colour = 'B';
        uncle->colour = 'B';
        grandparent->colour = 'R';
        fix(grandparent);
    }else if ( parent == grandparent->right){
        if(node == parent->left){
            rotate_right(parent);
            parent = node;
        }
        rotate_left(grandparent);
        parent->colour = 'B';
        grandparent->colour = 'R';
    }else if (parent == grandparent->left){
        if (node == parent->right){
            rotate_left(parent);
            parent = node;
        }
        rotate_right(grandparent);
        parent->colour = 'B';
        grandparent->colour = 'R';
    }

}
