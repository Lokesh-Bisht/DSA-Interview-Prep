/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/car-pooling/
 * TC => O(n log n)
 * SC => O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static bool compare(vector<int> num1, vector<int> num2) {
        return num1[1] < num2[1];
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int passengers = 0;
        int n = trips.size();
        sort(trips.begin(), trips.end(), compare);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            passengers += trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];
            while (!pq.empty() && pq.top().first <= start) {
                passengers -= pq.top().second;
                pq.pop();
            }
            pq.push({end, trips[i][0]});
            if (passengers > capacity) {
                return false;
            }
        }
        return true;
    }
};