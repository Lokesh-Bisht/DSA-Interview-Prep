/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1?page=1&category[]=Stack&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(n)
*/

#include <stack>
#include <utility>
#include <vector>

using namespace std;

vector<int> calculateSpan(vector<int> price, int n) {
    vector<int> ans;
    stack<pair<int, int>> stack;
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (!stack.empty() && price[i] >= stack.top().first) {
            count += stack.top().second;
            stack.pop();
        }
        stack.push({price[i], count});
        ans.push_back(count);
    }
    return ans;
}
