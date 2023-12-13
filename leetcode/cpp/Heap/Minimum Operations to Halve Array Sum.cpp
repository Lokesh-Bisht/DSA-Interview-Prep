/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
 * TC => O(n log(n))
 * SC => O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        priority_queue<double, vector<double>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(nums[i]);
            sum += nums[i];
        }
        double sum2 = sum, count = 0;
        sum /= 2;
        while (sum2 > sum) {
            double num = pq.top();
            pq.pop();
            sum2 -= num;
            num /= 2;
            sum2 += num;
            pq.push(num);
            ++count;
        }
        return count;
    }
};