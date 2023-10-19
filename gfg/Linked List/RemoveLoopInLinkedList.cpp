/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(1)
*/

#include <cstdio>

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void removeLoop(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        // loop found
        if (slow == fast) {
            break;
        }
    }
    // for full loop (from start of the list to the end)
    if (slow == head) {
        while (slow->next != fast) {
            slow = slow->next;
        }
        slow->next = NULL;
    }
    else if (slow == fast) {
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}
