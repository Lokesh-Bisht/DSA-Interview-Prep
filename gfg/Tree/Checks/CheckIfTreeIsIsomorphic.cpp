/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1?page=2&category[]=Tree&sortBy=submissions
 * 
 * Two trees are called  isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes.
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
    if (root && root2 )
    if (root && root2 && root->data == root2->data) {
        return (dfs(root->left, root2->left) && dfs(root->right, root2->right))
        || (dfs(root->left, root2->right) && dfs(root->right, root2->left));
    }
    return false;
}

bool isIsomorphic(Node* root, Node* root2) {
    return dfs(root, root2);
}