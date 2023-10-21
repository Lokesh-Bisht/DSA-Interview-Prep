/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/symmetric-tree/1?page=2&category[]=Tree&sortBy=submissions
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

bool dfs(Node* root, Node* root2) {
    if (!root && !root2) {
        return true;
    }
    if (root && root2 && root->data == root2->data) {
        return dfs(root->left, root2->right) && dfs(root->right, root2->left);
    }
    return false;
}

bool isMirror(Node* root) {
    return dfs(root, root);
}