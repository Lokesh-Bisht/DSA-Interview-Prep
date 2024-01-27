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


// Top down (Memoization) approach
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

// Bottom up (Tabulation) approach
// TC => O(n * m)
// SC => O(n * m)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0) {
                    // If the first string is empty. We've to remove all the characters of the second string
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // insert, remove, replace
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};