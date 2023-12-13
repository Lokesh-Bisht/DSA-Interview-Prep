/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link:https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * TC => O(n)
 * SC => O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
        }
        unordered_set<int> hashSet; 
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (freq[nums[i]] == 2 && hashSet.find(nums[i]) == hashSet.end()) {
                ans.push_back(nums[i]);
            }
            hashSet.insert(nums[i]);
        }
        return ans;
    }
};