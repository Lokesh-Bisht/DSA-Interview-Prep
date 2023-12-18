/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/non-decreasing-subsequences/
 * TC => O(2^n)
 * SC => O(2^n)
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    set<vector<int>> set;

    void recursion(vector<int> nums, int cur, vector<int>& curList) {
        if (curList.size() >= 2 && set.find(curList) == set.end()) {
            ans.push_back(curList);
            set.insert(curList);
        }
        int n = nums.size();
        int m = curList.size();
        for (int i = cur; i < n; ++i) {
            if (curList.size() == 0 || curList[m - 1] <= nums[i]) {
                curList.push_back(nums[i]);
                recursion(nums, i + 1, curList);
                curList.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> list;
        recursion(nums, 0, list);
        return ans;
    }
};