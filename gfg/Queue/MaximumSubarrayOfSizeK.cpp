/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?page=1&category[]=Queue&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(k)
*/

#include <deque>
#include <vector>

using namespace std;

vector<int> maxOfSubarraysOfSizeK(vector<int> nums, int n, int k) {
    deque<int> deque;
    for (int i = 0; i < k; ++i) {
        while (!deque.empty() && nums[i] >= nums[deque.back()]) {
            deque.pop_back();
        }
        deque.push_back(i);
    }
    vector<int> ans;
    ans.push_back(nums[deque.front()]);
    for (int i = k; i < n; ++i) {
        while (!deque.empty() && nums[i] >= nums[deque.back()]) {
            deque.pop_back();
        }
        deque.push_back(i);
        if (i - deque.front() + 1 > k) {
            deque.pop_front();
        }
        ans.push_back(nums[deque.front()]);
    }
    return ans;
}