/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * TC => O(n2)
 * SC => O(n)
*/

import java.util.ArrayList;
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

/**
 * Sliding window
 * TC => O(n)
 * SC => O(128)
*/
class Solution2 {
    public int lengthOfLongestSubstring(String str) {
        int i = 0, n = str.length();
        ArrayList<Integer> freq = new ArrayList<Integer>(Collections.nCopies(128, -1));
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int num = (str.charAt(j) - ' ');
            i = Math.max(i, freq.get(num) + 1);
            ans = Math.max(ans, j - i + 1);
            freq.set(num, j);
        }
        return ans;
    }
}