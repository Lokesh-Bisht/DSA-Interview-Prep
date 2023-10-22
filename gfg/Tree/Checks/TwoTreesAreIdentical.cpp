/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?page=1&category[]=Tree&sortBy=submissions
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
    if ((root == NULL && root2 != NULL) || (root != NULL && root2 == NULL)) {
        return false;
    }
    return root->data == root2->data && dfs(root->left, root2->left) && dfs(root->right, root2->right);
}

bool checkIfTreesAreIdentical(Node* root, Node* root2) {
    return dfs(root, root2);
}
