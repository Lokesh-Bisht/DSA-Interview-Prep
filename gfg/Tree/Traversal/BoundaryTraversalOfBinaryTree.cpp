/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?page=1&category[]=Tree&sortBy=submissions
 * 
 * Traversal Order => Left boundary nodes > leaf node > reverse right boundary nodes
 * 
 * TC => O(n)
 * SC => O(H)
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

void traverseLeftBoundaryNodes(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    ans.push_back(root->data);
    if (root->left) {
        traverseLeftBoundaryNodes(root->left, ans);
    } else if (root->right) {
        traverseLeftBoundaryNodes(root->right, ans);
    }
}

void traverseLeafNodes(Node* root, vector<int>& ans) {
    if (!root) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
    }
    traverseLeafNodes(root->left, ans);
    traverseLeafNodes(root->right, ans);
}

void traverseRightBoundaryNodes(Node* root, stack<int>& stack) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    stack.push(root->data);
    if (root->right) {
        traverseRightBoundaryNodes(root->right, stack);
    } else if (root->left) {
        traverseRightBoundaryNodes(root->left, stack);
    }
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
    if (!root) {
        return ans;
    }
    traverseLeftBoundaryNodes(root, ans);
    if (root->left || root->right) {
        traverseLeafNodes(root, ans);
    }
    stack<int> stack;
    if (root->right) {
        traverseRightBoundaryNodes(root->right, stack);
    }
    while (!stack.empty()) {
        ans.push_back(stack.top());
        stack.pop();
    }
    return ans;
}
