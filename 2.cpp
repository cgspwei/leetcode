// Copyright (c) 2016,
// All rights reserved.
//
// Author: cgspwei <cgspwei@gmail.com>
// Created: 08/20/16
// Description:
//
// Add Two Numbers
// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *p = l1, *q = l2;
        ListNode head(0);
        ListNode *pre = &head;
        int carry = 0;
        while (p != NULL || q != NULL) {
            int val1 = 0;
            if (p != NULL) {
                val1 = p->val;
                p = p->next;
            }
            int val2 = 0;
            if (q != NULL) {
                val2 = q->val;
                q = q->next;
            }
            int tmp = val1 + val2 + carry;
            carry = tmp / 10;
            pre->next = new ListNode(tmp % 10);
            pre = pre->next;
        }
        if (carry == 1) {
            pre->next = new ListNode(1);
        }
        return head.next;
    }
}

