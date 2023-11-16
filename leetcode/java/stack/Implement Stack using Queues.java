/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/implement-stack-using-queues/
 * TC => O(n)
 * SC => O(1) for all operations
*/

package leetcode.java.stack;

import java.util.ArrayDeque;
import java.util.Deque;

class MyStack {

    private Deque<Integer> queue;

    public MyStack() {
        queue = new ArrayDeque<>();
    }
    
    public void push(int x) {
        queue.add(x);
    }
    
    public int pop() {
        int poppedElement = -1;
        if (!queue.isEmpty()) {
            poppedElement = queue.pollLast();
        }
        return poppedElement;
    }
    
    public int top() {
        return queue.getLast();
    }
    
    public boolean empty() {
        return queue.isEmpty();
    }
}
