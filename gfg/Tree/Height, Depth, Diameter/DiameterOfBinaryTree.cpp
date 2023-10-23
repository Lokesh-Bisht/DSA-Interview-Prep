/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1?page=1&category[]=Tree&sortBy=submissions
 * 
 * Diameter: Length of the longest path between two leaf nodes
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

int ans = 0;

int dfs(Node* root) {
    if (!root) {
        return 0;
    }
    int leftSubTreeHeight = dfs(root->left);
    int rightSubTreeHeight = dfs(root->right);
    ans = max(ans, leftSubTreeHeight + rightSubTreeHeight + 1);
    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
}

int getDiameter(Node* root) {
    if (!root) {
        return 0;
    }
    ans = 0;
    dfs(root);
    return ans;
}