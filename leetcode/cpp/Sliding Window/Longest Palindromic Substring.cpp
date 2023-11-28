/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/longest-palindromic-substring/
 * TC => O(n)
 * SC => O(1)
*/

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size(), start = 0, end = 1;
        for (int i = 0; i < n; ++i) {
            int l = i - 1, r = i;
            while (l >= 0 && r < n && str[l] == str[r]) {
                if (r - l + 1 > end) {
                    start = l;
                    end = r - l + 1;
                }
                l--;
                r++;
            }
            // longest palindrome of odd length
            l = i - 1, r = i + 1;
            while (l >= 0 && r < n && str[l] == str[r]) {
                if (r - l + 1 > end) {
                    start = l;
                    end = r - l + 1;
                }
                l--;
                r++;
            }

        }
        return str.substr(start, end);
    }
};