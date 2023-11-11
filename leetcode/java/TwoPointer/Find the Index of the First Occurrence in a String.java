/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 * TC => O(n2)
 * SC => O(1)
*/

package leetcode.java.TwoPointer;

class Solution {
    public int strStr(String haystack, String needle) {
        int i = 0, j = 0, n = haystack.length();
        while (i < n) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                j++;
            } else {
                if (j != 0) {
                    i = i - j + 1;
                    j = 0;
                }
                if (haystack.charAt(i) == needle.charAt(j)) {
                    j++;
                }
            }
            if (j == needle.length()) {
                return i - j + 1;
            }
            i++;
        }
        if (j == needle.length()) {
            return i - j + 1;
        }
        return -1;
    }
}
