/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?page=1&category[]=Linked%20List&sortBy=submissions
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

bool compareLists(Node* head, Node* tail) {
    while (head != tail) {
        if (head->data != tail->data) {
            return false;
        }
        head = head->next;
        tail = tail->next;
    }
    return true;
}

Node* reverseSecondHalf(Node* head) {
    Node* cur = NULL;
    Node* prev = NULL;
    while (head) {
        cur = head;
        head = head->next;
        cur->next = prev;
        prev = cur;
    }
    return cur;
}

bool isPalindrome(Node* head) {
    if (!head) {
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    Node* tail = reverseSecondHalf(slow);
    return compareLists(head, tail);
}