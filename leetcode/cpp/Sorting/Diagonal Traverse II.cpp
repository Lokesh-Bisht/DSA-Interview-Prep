/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/diagonal-traverse-ii/
 * TC => O(n log n + n * m)
 * SC => O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static bool compare(pair<int, pair<int, int>> num1, pair<int, pair<int, int>> num2) {
        if (num1.first == num2.first) {
            return num1.second.first > num2.second.first;
        }
        return num1.first < num2.first;
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int, pair<int, int>>> list;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int m = nums[i].size();
            for (int j = 0; j < m; ++j) {
                list.push_back({i + j, {i, nums[i][j]}});
            }
        }
        sort(list.begin(), list.end(), compare);
        vector<int> ans;
        n = list.size();
        for (int i = 0; i < n; ++i) {
            ans.push_back(list[i].second.second);
        }
        return ans;
    }
};