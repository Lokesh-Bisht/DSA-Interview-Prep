/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Kadane's Algorithm
 * Problem Link: https://leetcode.com/problems/maximum-product-subarray
 * TC => O(n)
 * SC => O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, product = 1;
        for (int i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            ans = max(ans, product);
            if (product == 0) {
                product = 1;
            }
        }
        product = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            product *= nums[i];
            ans = max(ans, product);
            if (product == 0) {
                product = 1;
            }
        }
        return ans;
    }
};