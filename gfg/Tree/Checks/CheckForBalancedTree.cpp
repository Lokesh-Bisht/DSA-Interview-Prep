/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1?page=1&category[]=Tree&sortBy=submissions
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
    if (leftSubTreeHeight == -1 || rightSubTreeHeight == -1) return -1;
    if (abs(leftSubTreeHeight - rightSubTreeHeight) > 1) {
        return -1;
    }
    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
}

bool isBST(Node* root) {
    return dfs(root) != -1;
}