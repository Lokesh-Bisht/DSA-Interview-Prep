/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/majority-element/
 * TC => O(n)
 * SC => O(1)
*/

class Solution {
    public int majorityElement(int[] nums) {
        int votes = 1, n = nums.length;
        int majorityElement = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == majorityElement) {
                votes++;
            } else {
                votes--;
            }
            if (votes == 0) {
                votes = 1;
                majorityElement = nums[i];
            }
        }
        votes = 0;
        for (int num : nums) {
            if (num == majorityElement) {
                votes++;
            }
        }
        return (votes > n / 2) ? majorityElement : -1;
    }
}