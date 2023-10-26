/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1?page=3&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(n)
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

vector<int> diagonalTraversal(Node* root) {
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
            while(cur) {
                ans.push_back(cur->data);
                if (cur->left) {
                    queue.push_back(cur->left);
                }
                cur = cur->right;
            }
        }
    }
    return ans;
}