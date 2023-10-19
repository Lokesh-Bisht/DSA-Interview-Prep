/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions
 * 
 * Use Floyd's cycle finding algorithm (slow and fast pointer technique)
 * to detect loop in a cycle.
 * 
 * TC => O(n)
 * SC => O(1)
*/

#include <cstdio>
#include <iostream>

using namespace std;

struct Node {
int data;
	Node* next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

bool detectLoop(Node* head) {
	if (head == NULL) {
		return false;
	}
	Node* slow = head;
	Node* fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		// Found Loop
		if (slow == fast) {
			return true;
		}
	}
	return false;
}

void addLoop(Node* head, Node* tail, int position) {
	if (position == 0) {
		return;
	}
	Node* tmp = head;
	for (int i = 1; i < position; ++i) {
		tmp = tmp->next;
	}
	tail->next = tmp;
}

int main() {
	int n;
	cin >> n;
	Node* head, *tail;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (i == 0) {
			head = tail = new Node(num);
		} else {
			tail->next = new Node(num);
			tail = tail->next;
		}
	}
	int loopPosition;
	cin >> loopPosition;
	addLoop(head, tail, loopPosition);
	cout << detectLoop(head) << endl;
	return 0;
}