/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1?page=1&category[]=Linked%20List&sortBy=submissions
 * 
 * Assumption: The node to be deleted is not the last node in the linked list.
 * TC => O(n)
 * SC => O(1)
*/

#include <cstdio>
#include <cstdlib>

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void deleteNode(Node* node) {
    if (node == NULL || node->next == NULL) {
        return;
    }
    Node* tmp = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    free(tmp);
}