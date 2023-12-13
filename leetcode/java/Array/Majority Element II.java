/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/majority-element-ii/
 * TC => O(n)
 * SC => O(1)
*/

import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<Integer> majorityElement(int[] nums) {
        int count = 0, majorityElement = Integer.MIN_VALUE;
        int count2 = 0, majorityElement2 = Integer.MIN_VALUE;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (count == 0 && nums[i] != majorityElement2) {
                count = 1;
                majorityElement = nums[i];
            } else if (count2 == 0 && nums[i] != majorityElement) {
                count2 = 1;
                majorityElement2 = nums[i];
            } else if (nums[i] == majorityElement) {
                count++;
            } else if (nums[i] == majorityElement2) {
                count2++;
            } else {
                count--;
                count2--;
            }
        }
        count = 0;
        count2 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == majorityElement) {
                count++;
            }
            if (nums[i] == majorityElement2) {
                count2++;
            }
        }
        List<Integer> ans = new ArrayList<>();
        if (count >= n / 3 + 1) {
            ans.add(majorityElement);
        }
        if (count2 >= n / 3 + 1) {
            ans.add(majorityElement2);
        }
        return ans;
    }
}