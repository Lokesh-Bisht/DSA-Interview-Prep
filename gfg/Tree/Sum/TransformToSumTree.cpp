/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1?page=3&category[]=Tree&sortBy=submissions
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

int dfs(Node* root) {
    if (!root) {
        return 0;
    }
    int leftSubTreeSum = dfs(root->left);
    int rightSubTreeSum = dfs(root->right);
    int tmp = root->data;
    root->data = leftSubTreeSum + rightSubTreeSum;
    return leftSubTreeSum + rightSubTreeSum + tmp;
}

void transformToSumTree(Node* root) {
    if (!root) {
        return;
    }
    dfs(root);
}