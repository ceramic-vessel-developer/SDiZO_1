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

avl::Node *avl::search(Node* node,int key) {
    if (node == nullptr){
        std::cout <<"There is no such key in that tree!\n";
    }
    if (key < node->value){
        return search(node->left, key);
    }else if (key > node->value){
        return search(node->right,key);
    }else{
        return node;
    }
}

avl::Node* avl::delete_node(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root->value) {
        root->left = delete_node(root->left, key);
    }else if (key > root->value) {
        root->right = delete_node(root->right, key);
    }else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }else {
                *root = *temp;
            }
            delete temp;
        }else {
            Node* temp = succesor(root->right);
            root->value = temp->value;
            root->right = delete_node(root->right, temp->value);
        }
    }
    if (root == nullptr) {
        return root;
    }
    root->height = 1 + std::max(get_height(root->left), get_height(root->right));
    int balance = balance_factor(root);
    if (balance > 1 && balance_factor(root->left) >= 0) {
        return rotate_right(root);
    }
    if (balance > 1 && balance_factor(root->left) < 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }
    if (balance < -1 && balance_factor(root->right) <= 0) {
        return rotate_left(root);
    }
    if (balance < -1 && balance_factor(root->right) > 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }
    return root;
}

avl::Node* avl::succesor(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void avl::remove(int key){
    delete_node(root,key);
}

int *avl::select(int key) {
    return &search(root,key)->value;
}
