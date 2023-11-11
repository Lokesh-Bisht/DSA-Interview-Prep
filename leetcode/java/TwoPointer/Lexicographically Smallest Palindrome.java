/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/lexicographically-smallest-palindrome/
 * TC => O(n)
 * SC => O(n)
*/

package leetcode.java.TwoPointer;

class Solution {

    public String makeSmallestPalindrome(String str) {
        int l = 0, r = str.length() - 1;
        StringBuilder ans = new StringBuilder(str);
        while (l < r) {
            if (ans.charAt(l) == ans.charAt(r)) {
                l++;
                r--;
                continue;
            } else {
                if (ans.charAt(l) < ans.charAt(r)) {
                    ans.setCharAt(r, ans.charAt(l));
                } else {
                    ans.setCharAt(l, ans.charAt(r));
                }
            }
            l++;
            r--;
        }
        return ans.toString();
    }
}