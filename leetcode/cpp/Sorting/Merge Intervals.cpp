/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/merge-intervals/
 * TC => O(n log n)
 * SC => O(n)
*/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    bool static cmp(pair<int, int> num1, pair<int, int> num2) {
        if (num1.first == num2.second) {
            return num1.second < num2.second;
        }
        return num1.first < num2.first;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> list;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            list.push_back({intervals[i][0], intervals[i][1]});
        }
        sort(list.begin(), list.end(), cmp);
        int start = list[0].first;
        int end = list[0].second;
        vector<vector<int>> ans;
        for (int i = 1; i < n; ++i) {
            if (end >= list[i].first) {
                end = max(end, list[i].second);
            } else {
                ans.push_back({ start, end });
                start = list[i].first;
                end = list[i].second;
            }
        }
        ans.push_back({ start, end });
        return ans;
    }
};