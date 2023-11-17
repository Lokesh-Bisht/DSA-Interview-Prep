/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://leetcode.com/problems/reverse-linked-list/
 * TC => O(n)
 * SC => O(1)
*/

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        next = null;
    }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode cur = null, prev = null;
        while (head != null) {
            cur = head;
            head = head.next;
            cur.next = prev;
            prev = cur;
        }
        return cur;
    }
}
