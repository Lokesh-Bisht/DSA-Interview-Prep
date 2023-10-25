/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1?page=1&category[]=Stack&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(1)
*/

#include <stack>
#include <vector>

using namespace std;

int findCelebrity(vector<vector<int>> mat, int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        if (mat[j][i] == 1) {
            --j;
        } else {
            ++i;
        }
    }
    for (int k = 0; k < n; ++k) {
        if (k != i) {
            if (mat[i][k] == 1 ||  mat[k][i] == 0) {
                return -1;
            }
        }
    }
    return i;
}