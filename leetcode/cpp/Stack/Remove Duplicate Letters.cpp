/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/remove-duplicate-letters/
 * TC => O(n)
 * SC => O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string str) {
        unordered_map<char, int> alphabets;
        unordered_set<char> hashSet;
        stack<char> stack;
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            alphabets[str[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            alphabets[str[i]]--;
            if (hashSet.find(str[i]) == hashSet.end()) {
                while (!stack.empty() && str[i] <= stack.top() && alphabets[stack.top()] > 0) {
                    hashSet.erase(stack.top());
                    stack.pop();
                }
            }
            if (hashSet.find(str[i]) == hashSet.end()) {
                stack.push(str[i]);
                hashSet.insert(str[i]);
            }
        }
        string ans = "";
        while (!stack.empty()) {
            ans.push_back(stack.top());
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};