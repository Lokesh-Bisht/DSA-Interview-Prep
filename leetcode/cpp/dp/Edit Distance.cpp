/**
 * Copyright (C) 2024 Lokesh Bisht
 *
 * Problem Link: https://leetcode.com/problems/edit-distance/description/
 * TC => O(n * m)
 * SC => O(n * m)
*/

#include <iostream>
#include <vector>

using namespace std;

// TC => O(3^m)
class Solution {
public:
    int calculateMinDistance(string str, string str2, int n, int m) {
        if (n == 0) {
            return m;
        }
        if (m == 0) {
            return n;
        }
        if (str[n - 1] == str2[m - 1]) {
            return calculateMinDistance(str, str2, n - 1, m - 1);
        }
        return 1 + min(calculateMinDistance(str, str2, n, m - 1), min(calculateMinDistance(str, str2, n - 1, m), calculateMinDistance(str, str2, n - 1, m - 1)));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return calculateMinDistance(word1, word2, n, m);
    }
};


// TC => O(n * m)
// SC => O(n * m)
class Solution {
public:
    int calculateMinDistance(string str, string str2, int n, int m, vector<vector<int>>& dp) {
        if (n == 0) {
            return m;
        }
        if (m == 0) {
            return n;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        if (str[n - 1] == str2[m - 1]) {
            return dp[n][m] = calculateMinDistance(str, str2, n - 1, m - 1, dp);
        }
        int insert = calculateMinDistance(str, str2, n, m - 1, dp);
        int remove = calculateMinDistance(str, str2, n - 1, m, dp);
        int replace = calculateMinDistance(str, str2, n - 1, m - 1, dp);
        return dp[n][m] = 1 + min(insert, min(remove, replace));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return calculateMinDistance(word1, word2, n, m, dp);
    }
};