/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/container-with-most-water/description/
 * TC => O(n)
 * SC => O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int maxArea(vector<int> height, int n) {
            int l = 0, r = n - 1;
            int lMax = height[l], rMax = height[r];
            int ans = 0;
            while (l < r) {
                ans = max(ans, min(lMax, rMax) * (r - l));
                if (lMax <= rMax) {
                    if (lMax < height[l]) lMax = height[l];
                    else l++;
                } else {
                    if (rMax < height[r]) rMax = height[r];
                    else r--;
                }
            }
            return ans;
        }
};