/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1?page=1&category[]=Tree&sortBy=submissions
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

vector<int> topView(Node* root) {
    vector<int> ans;
    if (!root) {
        return ans;
    }
    queue<pair<Node*, int>> queue;
    queue.push({root, 0});
    unordered_map<int, int> hashMap;
    int maxDist = INT_MIN, minDist = INT_MAX;
    while (!queue.empty()) {
        int n = queue.size();
        for (int i = 0; i < n; ++i) {
            Node* cur = queue.front().first;
            int dist = queue.front().second;
            minDist = min(minDist, dist);
            maxDist = max(maxDist, dist);
            queue.pop();
            if (hashMap.find(dist) == hashMap.end()) {
                hashMap[dist] = cur->data;
            }
            if (cur->left) {
                queue.push({cur->left, dist - 1});
            }
            if (cur->right) {
                queue.push({cur->right, dist + 1});
            }
        }
    }
    for (int i = minDist; i <= maxDist; ++i) {
        ans.push_back(hashMap[i]);
    }
    return ans;
}