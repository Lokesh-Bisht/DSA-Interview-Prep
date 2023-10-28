/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1?page=1&category[]=Queue&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(1)
*/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> firstNegativeIntegerInEveryWindow(vector<int> nums, int n, int k) {
    deque<int> deque;
    for (int i = 0; i < k; ++i) {
        if (nums[i] < 0) deque.push_back(i);
    }
    vector<int> ans;
    deque.empty() ? ans.push_back(0) : ans.push_back(nums[deque.front()]);
    for (int i = k; i < n; ++i) {
        if (nums[i] < 0) {
            deque.push_back(i);
        }
        if (!deque.empty() && i - deque.front() + 1 > k) {
            deque.pop_front();
        }
        deque.empty() ? ans.push_back(0) : ans.push_back(nums[deque.front()]);
    }
    return ans;
}