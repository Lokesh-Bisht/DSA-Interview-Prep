/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1?page=1&category[]=Linked%20List&sortBy=submissions
 * 
 * TC => O(n + m)
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

int intersectionPoint(Node* head, Node* head2) {
    if (head == NULL || head2 == NULL) {
        return -1;
    }
    Node* tmp = head;
    Node* tmp2 = head2;
    while (tmp != tmp2) {
        tmp = tmp == NULL ? tmp2 : tmp->next;
        tmp2 = tmp2 == NULL ? tmp : tmp2->next;
    }
    return tmp->data;
}