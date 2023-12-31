/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/continuous-subarray-sum/description/
 * TC => O(n)
 * SC => O(n)
*/


import java.util.HashMap;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        hashMap.put(0, 0);
        int n = nums.length;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (!hashMap.containsKey(sum % k)) {
                hashMap.put(sum % k, i + 1);
            } else if (hashMap.get(sum % k) < i) {
                return true;
            }
        }
        return false;
    }
}