/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 * TC => O(n log n)
 * SC => O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int minMoves2(vector<int>& nums) {
            int tot = 0, n = nums.size();
            for (int i = 0; i < n; ++i) {
                tot += nums[i];
            }
            int median = tot / n;

            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += abs(nums[i] - median);
            }
            return ans;
        }
};