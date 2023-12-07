/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/top-k-frequent-words/
 * TC => O(n log n)
 * SC => O(n)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
    struct compare {
        bool operator()(pair<int, string> num1, pair<int, string> num2) {
            if (num1.first == num2.first) {
                return num1.second > num2.second;
            } 
            return num1.first < num2.first;
        }
    };

    public:
        

        vector<string> topKFrequent(vector<string>& words, int k) {
            unordered_map<string, int> wordsFreq;
            int n = words.size();
            for (int i = 0; i < n; ++i) {
                wordsFreq[words[i]]++;
            }
            int res = 0;
            priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
            for (auto it = wordsFreq.begin(); it != wordsFreq.end(); ++it) {
                pair<string, int> wordFreqPair = *it; 
                pq.push({wordFreqPair.second, wordFreqPair.first});
            
            }
            vector<string> ans;
            while (k--) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
            return ans;
        }
};