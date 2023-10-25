/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?page=1&category[]=Stack&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(n)
*/

#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> nums) {
    stack<int> stack;
    vector<int> ans;
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!stack.empty() && nums[i] >= stack.top()) {
            stack.pop();
        }
        stack.empty() ? ans.push_back(-1) : ans.push_back(stack.top());
        stack.push(nums[i]); 
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
