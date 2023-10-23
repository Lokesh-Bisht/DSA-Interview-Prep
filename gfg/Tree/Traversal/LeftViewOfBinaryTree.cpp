/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1?page=1&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(H)
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

void dfs(Node* root, vector<int>& ans, int level) {
    if (!root) {
        return;
    }
    if (level == ans.size()) {
        ans.push_back(root->data);
    }
    if (root->left) {
        dfs(root->left, ans, level + 1);
    } else if (root->right) {
        dfs(root->right, ans, level + 1);
    }
}

vector<int> leftView(Node* root) {
    vector<int> ans;
    if (!root) {
        return ans;
    }
    dfs(root, ans, 0);
    return ans;
}