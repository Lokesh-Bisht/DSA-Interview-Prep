/**
 * Copyright (C) 2024 Lokesh Bisht
 *
 * Problem Link: https://leetcode.com/problems/word-break/
 * TC => O(n * n)
 * SC => O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// TC => O(n ^ n)
class Solution {
public:
    bool dfs(string str, unordered_set<string> dict, int start) {
        if (str.size() == start) {
            return true;
        }
        for (int end = start + 1; end <= str.size(); ++end) {
            if (dict.find(str.substr(start, end - start)) != dict.end() && dfs(str, dict, end)) {
                return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictHashSet(wordDict.begin(), wordDict.end());
        return dfs(s, dictHashSet, 0);
    }
};