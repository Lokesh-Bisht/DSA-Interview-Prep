int open = 0, ans = 0;
/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1?page=2&category[]=Stack&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(1)
*/

#include <iostream>

using namespace std;

int countReversals(string str) {
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ')') {
            if (open > 0) open--;
            else ans++, open++;
        } else {
            open++;
        }
    }
    return (open % 2) ? -1 : ans + open / 2;
}