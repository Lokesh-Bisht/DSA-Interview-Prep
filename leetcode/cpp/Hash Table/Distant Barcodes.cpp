/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/distant-barcodes/
 * TC => O(n)
 * SC => O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int, int> freq;
        int maxFreq = INT_MIN, maxFreqNum;
        for (int i = 0; i < n; ++i) {
            freq[barcodes[i]]++;
            if (maxFreq <= freq[barcodes[i]]) {
                maxFreq = freq[barcodes[i]];
                maxFreqNum = barcodes[i];
            }
        }
        vector<int> ans(n, 0);
        int idx = 0;
        while (idx < n && maxFreq > 0) {
            ans[idx] = maxFreqNum;
            idx += 2;
            --maxFreq;
        }
        if (idx >= n) {
            idx = 1;
        }
        freq.erase(maxFreqNum);
        for (auto it : freq) {
            int curNumFreq = it.second;
            while (curNumFreq > 0) {
                ans[idx] = it.first;
                --curNumFreq;
                idx += 2;
                if (idx >= n) {
                    idx = 1;
                }
            }
        }
        return ans;
    }
};