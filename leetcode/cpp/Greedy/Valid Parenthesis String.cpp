/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/valid-parenthesis-string
 * TC => O(n)
 * SC => O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkValidString(string str) {
        int left = 0, right = 0, star = 0;
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            if (str[i] == '(') ++left;
            else if (str[i] == ')') ++right;
            else ++star;
            if (right > left + star) return false;
        }
        left = right = star = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (str[i] == '(') ++left;
            else if (str[i] == ')') ++right;
            else ++star;
            if (left > right + star) return false;
        }
        return true;
    }
};