/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1?page=2&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(h)
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

bool hasPathSum(Node* root, int sum) {
    if (!root) {
        return false;
    }
    if (root->left == NULL && root->right == NULL && root->data == sum) {
        return true;
    }
    sum -= root->data;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}