/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/contiguous-array/description/
 * TC => O(n)
 * SC => O(n)
*/

import java.util.HashMap;

class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        int n = nums.length;
        int sum = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum == 0) {
                ans = i + 1;
            } else if (hashMap.containsKey(sum)) {
                ans = Math.max(ans, i - hashMap.get(sum));
            } else {
                hashMap.put(sum, i);
            }
        }
        return ans;
    }
}