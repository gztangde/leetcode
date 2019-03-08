---
title: Leetcode 2.Add Two Numbers
date: 2018-05-12 00:41:38
updated: 2018-05-12 00:41:38
categories: Leetcode 
tags: Leetcode
---

# Question

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

> Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
> Output: 7 -> 0 -> 8

**Difficulty**:Medium

**Category**:Linked List, Math

<!-- more -->

*****

# Solution

```cpp
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode preHead(0), *p = &preHead;
    int carry = 0;
    while (l1 || l2 || carry) {
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = sum / 10;
      p->next = new ListNode(sum % 10);
      p = p->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    return preHead.next;
  }
};
```
