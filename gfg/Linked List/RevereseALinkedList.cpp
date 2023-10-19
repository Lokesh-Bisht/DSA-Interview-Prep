/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions
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

Node* reverseLinkedList(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* prev = NULL;
    Node* cur = NULL;
    while (head != NULL) {
        cur = head;
        head = head->next;
        cur->next = prev;
        prev = cur;
    }
    return cur;
}
