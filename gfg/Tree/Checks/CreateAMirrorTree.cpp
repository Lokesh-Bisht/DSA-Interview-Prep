/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/mirror-tree/1?page=1&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(h)
*/

#include <cstdio>

using namespace std;

struct Node {
    int data;
    Node* left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void mirror(Node* root) {
    if (!root) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}