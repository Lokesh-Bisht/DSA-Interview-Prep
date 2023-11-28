/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * TC => O(n)
 * SC => O(1)
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
      int freq[190];
      memset(freq, 0, sizeof freq);
      int n = str.size();
      int l = 0, r = 0, curLen = 0, ans = 0;
      while (l <= r && r < n) {
        if (freq[str[r] - ' '] == 0) freq[str[r] - ' ']++, curLen++, r++;
        else {
          ans = max(ans, curLen);
          char currentChar = str[r];
          // If the first char pointed by 'l' is the repeated char.
          if (str[l] == str[r]) freq[str[l] - ' ']--, l++, curLen--;
          else {
            while (str[l] != str[r]) freq[str[l] - ' ']--, curLen--, l++;
          }
        }
      }
      ans = max(ans, curLen);
      return ans;
    }
};