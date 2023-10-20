/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?page=1&category[]=Linked%20List&sortBy=submissions
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

Node* reverseListInGroups(Node* head, int k) {
    if (!head) {
        return head;
    }
    int count = 0;
    Node* tmp = head;
    Node* prev = NULL;
    Node* cur = NULL;
    while (tmp && count < k) {
        cur = tmp;
        tmp = tmp->next;
        cur->next = prev;
        prev = cur;
        count++;
    }
    if (tmp) head->next = reverseListInGroups(tmp, k);
    return cur;
}
