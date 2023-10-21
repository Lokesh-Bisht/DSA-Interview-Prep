/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/check-for-bst/1?page=1&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(h)
*/

#include <cstdio>
#include<stack>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

bool isBST(Node* root, Node* min, Node* max) {
    if (!root) {
        return true;
    }
    if ((max != NULL && max->data <= root->data) || (min != NULL && min->data >= root->data)) {
        return false;
    }
    return dfs(root->left, min, root) && dfs(root->right, root, max);
}


bool checkIfBST(Node* root) {
    if (!root) {
        return true;
    }
    return isBST(root, NULL, NULL);
}