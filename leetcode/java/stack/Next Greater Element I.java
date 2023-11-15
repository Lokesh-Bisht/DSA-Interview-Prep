/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/next-greater-element-i/
 * TC => O(n)
 * SC => O(n)
*/

package leetcode.java.stack;

import java.util.HashMap;
import java.util.Stack;

class Solution {

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        int n = nums2.length;
        hashMap.put(nums2[n - 1], -1);
        Stack<Integer> stack = new Stack<>();
        stack.push(nums2[n - 1]);
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.isEmpty() && stack.peek() <= nums2[i]) {
                stack.pop();
            }
            int nextGreaterEle = stack.isEmpty() ? -1 : stack.peek(); 
            hashMap.put(nums2[i], nextGreaterEle);
            stack.push(nums2[i]);
        }
        int[] ans = new int[nums1.length];
        for (int i = 0; i < nums1.length; ++i) {
            ans[i] = hashMap.get(nums1[i]);
        }
        return ans;
    }
}
