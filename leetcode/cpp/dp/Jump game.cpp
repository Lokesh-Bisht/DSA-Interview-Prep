/**
 * Copyright (C) 2024 Lokesh Bisht
 *
 * Problem Link: https://leetcode.com/problems/jump-game/
 * TC => O(n)
 * SC => O(1)
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int destination = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (i + nums[i] >= destination) {
                destination = i;
            }
        }
        return destination == 0;
    }
};