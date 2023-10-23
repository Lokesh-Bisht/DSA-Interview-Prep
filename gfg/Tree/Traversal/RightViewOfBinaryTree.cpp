/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1?page=1&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(n) or O(h)
*/

#include <cstdio>
#include <queue>
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

void dfs(Node* root, vector<int>& ans) {
    if (!root) {
        return;
    }
    ans.push_back(root->data);
    if (root->right) {
        dfs(root->right, ans);
    } else if (root->left) {
        dfs(root->left, ans);
    }
}

vector<int> rightView(Node* root) {
    vector<int> ans;
    if (!root) {
        return ans;
    }
    dfs(root, ans);
    return ans;
}

// Bfs
vector<int> rightView(Node* root) {
    vector<int> ans;
    if (!root) {
        return ans;
    }
    queue<Node*> queue;
    queue.push(root);
    while (!queue.empty()) {
        int n = queue.size();
        for (int i = 0; i < n; ++i) {
            Node* cur = queue.front();
            queue.pop();
            if (i == n - 1) {
                ans.push_back(cur->data);
            }
            if (cur->left) queue.push(cur->left);
            if (cur->right) queue.push(cur->right);
        }
    }
    return ans;
}
