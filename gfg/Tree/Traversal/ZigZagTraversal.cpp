/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?page=2&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(n)
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

vector<int> zigZagTraversal(Node* root) {
    vector<int> ans;
    if (!root) {
        return ans;
    }
    queue<Node*> queue;
    queue.push(root);
    int level = 0;
    while (!queue.empty()) {
        int n = queue.size();
        stack<int> stack;
        for (int i = 0; i < n; ++i) {
            Node* cur = queue.front();
            queue.pop();
            level % 2 == 0 ? ans.push_back(cur->data) : stack.push(cur->data);
            if (cur->left) queue.push(cur->left);
            if (cur->right) queue.push(cur->right);
        }
        level++;
        while (!stack.empty()) {
            ans.push_back(stack.top());
            stack.pop();
        }
    }
    return ans;
}