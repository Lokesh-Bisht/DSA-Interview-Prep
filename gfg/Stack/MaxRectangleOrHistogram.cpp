/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/max-rectangle/1?page=1&category[]=Stack&sortBy=submissions
 * 
 * TC => O(n * m)
 * SC => O(m)
*/

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int findMaxArea(vector<int> height, int m) {
    vector<int> left, right;
    stack<int> stack, stack2;
    for (int i = 0; i < m; ++i) {
        while (!stack.empty() && height[i] <= height[stack.top()]) {
            stack.pop();
        }
        stack.empty() ? left.push_back(-1) : left.push_back(stack.top());
        stack.push(i);
    }
    for (int i = m - 1; i >= 0; --i) {
        while (!stack2.empty() && height[i] <= height[stack2.top()]) {
            stack2.pop();
        }
        stack2.empty() ? right.push_back(m) : right.push_back(stack2.top());
        stack2.push(i);
    }
    reverse(right.begin(), right.end());
    int maxArea = 0;
    for (int i = 0; i < m; ++i) {
        maxArea = max(maxArea, (right[i] - left[i] - 1) * height[i]);
    }
    return maxArea;
}

int maxArea(vector<vector<int>> mat, int n, int m) {
    vector<int> height;
    for (int i = 0; i < m; ++i) {
        height.push_back(mat[0][i]);
    }
    int ans = findMaxArea(height, m);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 1) {
                height[i] += mat[i][j];
            } else {
                height[i] = 0;
            }
        }
        ans = max(ans, findMaxArea(height, m));
    }
    return ans;
}