/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?page=1&category[]=Sorting&sortBy=submissions
 * 
 * TC => O(n log n)
 * SC => O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& nums, int l, int mid, int r) {
    int invCount = 0;
    int i = l, j = mid + 1;
    vector<int> tmp;
    while (i <= mid && j <= r) {
        if (nums[i] > nums[j]) {
            invCount += mid - i + 1;
            tmp.push_back(nums[j++]);
        } else {
            tmp.push_back(nums[i++]);
        }
    }
    while (i <= mid) {
        tmp.push_back(nums[i++]);
    }
    while (j <= r) {
        tmp.push_back(nums[j++]);
    }
    for (int i = l, j = 0; i <= r;) {
        nums[i++] = tmp[j++];
    }
    return invCount;
}

int sort(vector<int>& nums, int l, int r) {
    int invCount = 0;
    if (l < r) {
        int mid = (l + r) / 2;
        invCount += sort(nums, l, mid);
        invCount += sort(nums, mid + 1, r);
        invCount += merge(nums, l, mid, r);
    }
    return invCount;
}

int inversionCount(vector<int> nums, int n) {
    return sort(nums, 0, n - 1);
}
