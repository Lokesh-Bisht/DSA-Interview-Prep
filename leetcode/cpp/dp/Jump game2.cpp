/**
 * Copyright (C) 2024 Lokesh Bisht
 *
 * Problem Link: https://leetcode.com/problems/jump-game-ii/
 * TC => O(n * n)
 * SC => O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = INT_MAX;
            for (int j = 0; j < i; ++j) {
                if (i <= j + nums[j] && dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};