/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/
 * TC => O(n)
 * SC => O(n)
*/

import java.util.HashMap;

class Solution {

    public int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        int sum = 0, count = 0;
        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
            if (sum == k) {
                count++;
            }
            if (hashMap.containsKey(sum - k)) {
                count += hashMap.get(sum - k);
            }
            if (hashMap.containsKey(sum)) {
                hashMap.put(sum, hashMap.get(sum) + 1);
            } else {
                hashMap.put(sum, 1);
            }
        }
        return count;
    }
}