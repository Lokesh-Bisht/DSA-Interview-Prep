/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/top-k-frequent-elements/
 * TC => O(n log n)
 * SC => O(n)
*/

import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

class Solution {

    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (hashMap.containsKey(nums[i])) {
                hashMap.put(nums[i], hashMap.get(nums[i]) + 1);
            } else {
                hashMap.put(nums[i], 1);
            }
            
        }
        List<Pair<Integer, Integer>> list = hashMap.entrySet().stream().map(ele -> new Pair<>(ele.getKey(), ele.getValue())).collect(Collectors.toList());
        
        Collections.sort(list, new Comparator<Pair<Integer, Integer>>() {
            public int compare(Pair<Integer, Integer> num1, Pair<Integer, Integer> num2) {
                if (num1.getValue() == num2.getValue()) {
                    return num1.getKey() - num2.getKey();
                }
                return num1.getValue() - num2.getValue();
            }
        });
        Collections.reverse(list);
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            ans[i] = list.get(i).getKey();
        }
        return ans;
    }
}