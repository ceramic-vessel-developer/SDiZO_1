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

}

void red_black_tree::rotate_left(red_black_tree::Node *node) {

}

void red_black_tree::show_inorder() {

}
