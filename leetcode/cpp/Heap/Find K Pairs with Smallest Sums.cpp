/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 * TC => O(min(k logk, m * n * log(m * n)))
 * SC => O(min(k, m * n))
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        set<pair<int, int>> visited;
        vector<vector<int>> ans;
        visited.insert({0, 0});
        pq.push({ nums1[0] + nums2[0], {0, 0}});
        while (!pq.empty() && k--) {
            pair<int, pair<int, int>> top = pq.top();
            int i = top.second.first;
            int j = top.second.second;
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (i + 1 < n && visited.find({i + 1, j}) == visited.end()) {
                visited.insert({i + 1, j});
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            }
            if (j + 1 < m && visited.find({i, j + 1}) == visited.end()) {
                visited.insert({i, j + 1});
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }
        return ans;
    }
};


