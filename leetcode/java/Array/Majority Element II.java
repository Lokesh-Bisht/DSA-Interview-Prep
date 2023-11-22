/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/majority-element-ii/
 * TC => O(n)
 * SC => O(1)
*/

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class Solution {

    public List<Integer> majorityElement(int[] nums) {
        int count = 0, majorityElement = -1;
        int count2 = 0, majorityElement2 = -1;
        int n = nums.length;
        if (n < 3) {
            HashSet<Integer> ans = new HashSet<>();
            for (int i = 0; i < n; ++i) {
                ans.add(nums[i]);
            }
            return new ArrayList<>(ans);
        }
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
        System.out.println(majorityElement + " " + majorityElement2);
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
        if (count > n / 3) {
            ans.add(majorityElement);
        }
        if (count2 > n / 3 && majorityElement2 != ans.get(0)) {
            ans.add(majorityElement2);
        }
        return ans;
    }
}