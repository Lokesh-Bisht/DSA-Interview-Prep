/**
 * Copyright (C) 2024 Lokesh Bisht
 *
 * Problem Link: https://leetcode.com/problems/triangle/
 * TC => O(n * n)
 * SC => O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};