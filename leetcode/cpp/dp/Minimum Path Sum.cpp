/**
 * Copyright (C) 2024 Lokesh Bisht
 *
 * Problem Link: https://leetcode.com/problems/minimum-path-sum/
 * TC => O(n * m)
 * SC => O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 1; i < n; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < m; ++j) {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[n - 1][m - 1];
    }
};