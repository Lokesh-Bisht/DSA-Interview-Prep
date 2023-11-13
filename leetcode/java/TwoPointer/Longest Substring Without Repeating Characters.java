/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters
 * TC => O(n2)
 * SC => O(n)
*/

package leetcode.java.TwoPointer;

import java.util.HashSet;

class Solution {
    public int lengthOfLongestSubstring(String str) {
        int n = str.length(), ans = 0;
        for (int i = 0; i < n; ++i) {
            HashSet<Character> hashSet = new HashSet<>();
            for (int j = i; j < n; ++j) {
                if (hashSet.contains(str.charAt(j))) {
                    break;
                }
                ans = Math.max(ans, j - i + 1);
                hashSet.add(str.charAt(j));
            }
        }
        return ans;
    }
}