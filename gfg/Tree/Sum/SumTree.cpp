/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/sum-tree/1?page=1&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(h)
*/

#include <cstdio>
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

bool dfs(Node* root) {
    if (!root) {
        return 0;
    }
    else if (!root->left && !root->right) {
        return root->data;
    }
    int leftSubTree = dfs(root->left);
    int rightSubTree = dfs(root->right);
    if (leftSubTree == -1 || rightSubTree == -1 || (leftSubTree + rightSubTree != root->data)) {
        return -1;
    }
    return root->data + leftSubTree + rightSubTree;
}

bool isSumTree(Node* root) {
    if (!root) {
        return true;
    }
    return dfs(root) != -1;
}

