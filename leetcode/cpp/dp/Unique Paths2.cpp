/**
 * Copyright (C) 2024 Lokesh Bisht
 *
 * Problem Link: https://leetcode.com/problems/unique-paths-ii/
 * TC => O(n * m)
 * SC => O(n * m)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0 && obstacleGrid[i][j] == 0) {
                    dp[i][j] = 1;
                } else if (obstacleGrid[i][j] == 0) {
                    if (i) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};