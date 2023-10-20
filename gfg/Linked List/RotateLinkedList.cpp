/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions
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

Node* rotateList(Node* head, int k) {
    if (!head) {
        return;
    }
    Node* tmp = head;
    Node* prev = NULL;
    int count = 0;
    while (tmp) {
        prev = tmp;
        tmp = tmp->next;
        count++;
    }
    if (k % count == 0) {
        return head;
    }
    for (int i = 0; i < k; ++i) {
        prev->next = head;
        head = head->next;
        prev = prev->next;
        prev->next = NULL;
    }
    return head;
}