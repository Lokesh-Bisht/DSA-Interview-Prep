/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/distribute-candies/
 * TC => O(n)
 * SC => O(n)
*/

import java.util.HashSet;
import java.util.Set;

class Solution {

    public int distributeCandies(int[] candyType) {
        Set<Integer> hashSet = new HashSet<>();
        int n = candyType.length;
        for (int i = 0; i < n; ++i) {
            hashSet.add(candyType[i]);
        }
        int differentTypeOfCandies = hashSet.size();
        return differentTypeOfCandies < n / 2 ? differentTypeOfCandies : n / 2;
    }
}