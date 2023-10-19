/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions
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

Node* removeDuplicates(Node* head) {
    if (!head) {
        return head;
    }
    Node* tmp = head;
    Node* prev = head;
    head = head->next;
    while (head) {
        if (prev->data == head->data) {
            head = head->next;
            prev->next = head;
        } else {
            prev = head;
            head = head->next;
        }
    }
    return tmp;
}
