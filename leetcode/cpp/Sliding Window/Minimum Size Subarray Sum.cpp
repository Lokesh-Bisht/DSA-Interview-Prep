/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum
 * TC => O(n)
 * SC => O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, n = nums.size();
        int l = 0, r = 0, ans = INT_MAX;
        while (r < n) {
            sum += nums[r];
            while (sum >= target) {
                sum -= nums[l];
                ans = min(ans, r - l + 1);
                ++l;
            }
            ++r;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};