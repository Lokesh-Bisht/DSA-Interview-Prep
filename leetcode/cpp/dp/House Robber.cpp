/**
 * Copyright (C) 2024 Lokesh Bisht
 *
 * Problem Link: https://leetcode.com/problems/house-robber/
 * TC => O(n)
 * SC => O(n)
 * dp[n][0] --> I'm going to rob this house.
 * dp[n][1] --> I'm not going to rob this house.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        dp[1][0] = nums[1];
        dp[1][1] = nums[0];
        for (int i = 2; i < n; ++i) {
            dp[i][0] = nums[i] + max(dp[i - 1][1], dp[i - 2][0]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]); 
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};