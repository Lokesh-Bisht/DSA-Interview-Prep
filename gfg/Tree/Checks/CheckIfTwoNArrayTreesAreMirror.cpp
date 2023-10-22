/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1?page=5&category[]=Tree&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(h)
*/

#include <cstdio>
#include <vector>

using namespace std;

bool areMirrorTrees(int n, int e, int a[], int b[]) {
    vector<int> tree[n + 1];
    vector<int> tree2[n + 1];
    for (int i = 0; i < 2 * e; i += 2) {
        tree[a[i]].push_back(a[i + 1]);
        tree2[b[i]].push_back(b[i + 1]);
    }
    for (int i = 1; i <= n; ++i) {
        reverse(tree2[i].begin(), tree2[i].end());
    }
    for (int i = 1; i <= n; ++i) {
        if (tree[i] != tree2[i]) {
            return false;
        }
    }
    return true;
}