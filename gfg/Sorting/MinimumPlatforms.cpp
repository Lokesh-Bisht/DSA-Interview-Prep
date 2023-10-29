/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1?page=1&category[]=Sorting&sortBy=submissions
 * 
 * TC => O(n log n)
 * SC => O(1)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minPaltforms(vector<int> arrival, vector<int> departure, int n) {
    int patformsNeeded = 1, ans = 1;
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int i = 1, j = 0;
    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            i++;
            patformsNeeded++;
        } else {
            j++;
            platformsNeeded--;
        }
        ans = max(ans, platformsNeeded);
    }
    return ans;
}