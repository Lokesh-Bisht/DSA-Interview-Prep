/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
 * TC => O(n log n)
 * SC => O(n)
*/

package leetcode.java.TwoPointer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Solution {
    
    public int countPairs(List<Integer> nums, int target) {
        int ans = 0;
        Collections.sort(nums);
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = nums.get(l) + nums.get(r);
            if (sum < target) {
                ans += r - l;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> nums = new ArrayList<>();
        int n = scanner.nextInt();
        for (int i = 0; i < n; ++i) {
            nums.add(scanner.nextInt());
        }
        int target = scanner.nextInt();
        Solution solution = new Solution();
        System.out.println(solution.countPairs(nums, target));
        scanner.close();
    }
}