/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1?page=1&category[]=Stack&sortBy=submissions
 * 
 * TC => Push -> O(1), Pop -> O(n)
 * SC => O(1)
*/

#include<queue>
#include <vector>

using namespace std;

class Stack {

    private:
        queue<int> queue, queue2;

    public: 
        Stack() {}

        void add(int num) {
            queue.push(num);
        }

        int pop() {
            if (queue.empty()) {
                return -1;
            }
            int num;
            while (!queue.empty()) {
                num = queue.front();
                if (queue.size() > 1) {
                    queue2.push(num);
                }
                queue.pop();
            }
            while (!queue2.empty()) {
                queue.push(queue2.front());
                queue2.pop();
            }
            return num;
        }
};