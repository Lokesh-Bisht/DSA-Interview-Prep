/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/zigzag-conversion
 * TC => O(n)
 * SC => O(1)
*/

#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string str, int numRows) {
        if (numRows <= 1) {
            return str;
        }
        bool down = true;
        int row = 0, n = str.size();
        string zigzag[numRows];
        for (int i = 0; i < n; ++i) {
            zigzag[row] += str[i];
            if (row == 0) {
                down = true;
            }
            if (row == numRows - 1) {
                down = false;
            }
            down ? row++ : row--;
        }
        string ans = "";
        for (int i = 0 ; i < numRows; ++i) {
            ans += zigzag[i];
        }
        return ans;
    }
};