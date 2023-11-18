/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/
 * TC => O(n)
 * SC => O(n)
*/


import java.util.HashSet;

class Solution {

    public int longestConsecutive(int[] nums) {
        int n = nums.length, ans = 0;
        HashSet<Integer> hashSet = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            hashSet.add(nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (!hashSet.contains(nums[i] - 1)) {
                int start = nums[i];
                while (hashSet.contains(start)) {
                    start++;
                }
                ans = Math.max(ans, start - nums[i]);
            }
        }
        return ans;
    }
}