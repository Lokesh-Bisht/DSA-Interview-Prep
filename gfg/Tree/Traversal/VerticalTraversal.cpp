/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1?page=1&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(n)
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node* left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

vector<int> verticalTraversal(Node* root) {
    vector<int> ans;
    if (!root) {
        return ans;
    }
    queue<pair<Node*, int>> queue;
    queue.push({root, 0});
    unordered_map<int, vector<int>> hashMap;
    int minDist = INT_MAX, maxDist = INT_MIN;
    while (!queue.empty()) {
        int n = queue.size();
        for (int i = 0; i < n; ++i) {
            Node* cur = queue.front().first;
            int dist = queue.front().second;
            queue.pop();
            minDist = min(minDist, dist);
            maxDist = max(maxDist, dist);
            hashMap[dist].push_back(cur->data);
            if (cur->left) {
                queue.push_back({cur->left, dist - 1});
            }
            if (cur->right) {
                queue.push_back({cur->right, dist + 1});
            }
        }
    }
    for (int i = INT_MIN; i <= INT_MAX; ++i) {
        for (int num : hashMap[i]) {
            ans.push_back(num);
        }
    }
    return ans;
}