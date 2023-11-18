/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/longest-palindrome/
 * TC => O(n)
 * SC => O(n)
*/

import java.util.HashMap;
import java.util.Map;

class Solution {
    
    public int longestPalindrome(String str) {
        HashMap<Character, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < str.length(); ++i) {
            Character ch = str.charAt(i);
            if (!hashMap.containsKey(ch)) {
                hashMap.put(ch, 1);
            } else {
                int frequency = hashMap.get(ch);
                hashMap.put(ch, frequency + 1);
            }
        }
        int ans = 0;
        for (Map.Entry<Character, Integer> entry : hashMap.entrySet()) {
            int value = entry.getValue().intValue();
            if (value > 1) {
                ans += (value % 2 == 1) ? value - 1 : value;
            }
        }
        return str.length() > ans ? ans + 1 : ans;
    }
}