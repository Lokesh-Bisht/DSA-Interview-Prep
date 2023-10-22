/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1?page=1&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(h)
*/

#include <cstdio>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

int dfs(Node* root) {
    if (!root) {
        return 0;
    }
    int leftSubTreeHeight = dfs(root->left);
    int rightSubTreeHeight = dfs(root->right);
    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
}

int getHeight(Node* root) {
    if (!root) {
        return 0;
    }
    return dfs(root);
}