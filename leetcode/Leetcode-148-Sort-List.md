---
title: Leetcode 148. Sort List
date: 2018-12-16 19:09:31
updated: 2018-12-16 19:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Sort a linked list in  _O_(_n_  log  _n_) time using constant space complexity.

**Example 1:**

> **Input:** 4->2->1->3
> **Output:** 1->2->3->4

**Example 2:**

> **Input:** -1->5->3->4->0
> **Output:** -1->0->3->4->5

**Difficulty**:Medium

**Category**:Linked-List, Sort

<!-- more -->

------------

# Analyze

# Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    fast = slow;
    slow = slow->next;
    fast->next = nullptr;

    return mergeTwoLists(sortList(head), sortList(slow));
  }

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *mergelist = new ListNode(-1), *cur = mergelist;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return mergelist->next;
  }
};
```