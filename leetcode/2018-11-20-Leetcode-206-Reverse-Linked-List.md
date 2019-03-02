---
title: Leetcode 206. Reverse Linked List
date: 2018-11-19 06:09:31
updated: 2018-11-19 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Reverse a singly linked list.

**Example:**

> **Input:** 1->2->3->4->5->NULL
> **Output:** 5->4->3->2->1->NULL

**Difficulty**:Easy

**Category**:Linked List

<!-- more -->

------------

# Solution

Tracking prev / curr / next node
Time complexity: O(n)
Space complexity: O(1)

```cpp
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *cur = head, *next = nullptr;
    while (cur) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
};
```

## Solution 2: recursive

```cpp
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* last = head->next;
    ListNode* right = reverseList(head->next);
    last->next = head;
    head->next = nullptr;
    return right;
  }
};
```