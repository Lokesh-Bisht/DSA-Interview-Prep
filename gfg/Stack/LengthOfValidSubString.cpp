/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/valid-substring0624/1?page=1&category[]=Stack&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(1)
*/

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int findLongestValidSubstring(string str) {
    int open = 0, close = 0, ans = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') open++;
        else close++;
        if (open == close) ans = max(ans, open * 2);
        else if (open < close) open = close = 0;
    }
    open = close = 0;
    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == '(') open++;
        else close++;
        if (open == close) ans = max(ans, open * 2);
        if (open > close) open = close = 0;
    }
    return ans;
}