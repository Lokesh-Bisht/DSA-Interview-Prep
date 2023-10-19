/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions
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

int findMiddleElement(Node* head) {
	if (!head) {
		return -1;
	}
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}
