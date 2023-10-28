/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1?page=1&category[]=Queue&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(n)
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string firstNonRepeatingCharacter(string str) {
    vector<int> freq(26, -1);
    queue<char> queue;
    string ans = "";
    for (int i = 0; i < str.size(); ++i) {
        if (freq[str[i] - 'a'] == -1) {
            freq[str[i] - 'a']++;
            queue.push(str[i]);
            ans += queue.front();
        } else if (freq[str[i] - 'a'] == 0) {
            freq[str[i] - 'a']++;
            queue.push(str[i]);
            while (!queue.empty() && freq[queue.front() - 'a'] > 0) {
                queue.pop();
            }
            ans += queue.empty() ? '#' : queue.front();
        } else {
            ans += queue.empty() ? '#' : queue.front();
        }
    }
    return ans;
}