---
title: Leetcode 19. Remove Nth Node From End of List
date: 2018-11-20 21:09:31
updated: 2018-11-20 21:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a linked list, remove the  _n_-th node from the end of list and return its head.

**Example:**

> Given linked list: **1->2->3->4->5**, and **_n_ = 2**.
> After removing the second node from the end, the linked list becomes **1->2->3->5**.

**Note:**

Given  _n_  will always be valid.

**Follow up:**

Could you do this in one pass?

**Difficulty**:Medium

**Category**:Two Points

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow = head, *fast = head;
    while (fast && n--) fast = fast->next;
    if (!fast) return head->next;

    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }

    slow->next = slow->next->next;
    return head;
  }
};
```