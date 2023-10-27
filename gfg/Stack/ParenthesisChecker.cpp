/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1?page=1&category[]=Tree&category[]=Stack&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(n)
*/

#include <stack>

using namespace std;

bool isPatternCorrect(string str) {
    stack<char> stack;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
            stack.push(str[i]);
        } else if (str[i] == '{') {
            if (stack.top() == '}') stack.pop();
            else return false;
        } else if (str[i] == '(') {
            if (stack.top() == ')') stack.pop();
            else return false;
        } else if (str[i] == '[') {
            if (stack.top() == ']') stack.pop();
            else return false;
        }
    }
    return stack.empty();
}