/**
 * Copyright (C) 2024 Lokesh Bisht
 *
 * Problem Link: https://leetcode.com/problems/unique-binary-search-trees/
 * TC => O(n * n)
 * SC => O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

    class Solution {
    public:
        int numTrees(int n) {
            if (n <= 1) {
                return 1;
            }
            int ans = 0;
            for (int i = 1; i <= n; ++i) {
                ans += numTrees(i - 1) * numTrees(n - i);
            }
            return ans;
        }
    };