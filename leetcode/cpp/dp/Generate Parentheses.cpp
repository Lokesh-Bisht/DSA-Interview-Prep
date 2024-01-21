/**
 * Copyright (C) 2024 Lokesh Bisht
 *
 * Problem Link: https://leetcode.com/problems/generate-parentheses/
 * TC => O(2 ^ n)
 * SC => O(n * 2)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void validParentheses(int pos, int n, int open, int close, vector<string>& ans, string str) {
        if (close == n) {
            ans.push_back(str);
        } else {
            if (open > close) {
                str[pos] = ')';
                validParentheses(pos + 1, n, open, close + 1, ans, str);
            }
            if (open < n) {
                str[pos] = '(';
                validParentheses(pos + 1, n, open + 1, close, ans, str);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        for (int i = 0; i < n * 2; ++i) {
            str += 'a';
        }
        if (n > 0) {
            validParentheses(0, n, 0 ,0, ans, str);
        }
        return ans;
    }
};