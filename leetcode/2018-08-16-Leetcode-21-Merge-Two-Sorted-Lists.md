---
title: Leetcode 21. Merge Two Sorted Lists
date: 2018-08-16 13:42:10
updated: 2018-08-16 13:42:10
categories: Leetcode
tags: Leetcode
notshow: true
---

# Leetcode 21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
> Input: 1->2->4, 1->3->4  
> Output: 1->1->2->3->4->4  

**Difficulty**:Easy

**Category**:Linked-List

<!--more-->

# Solution

## Solution 1: Iterative

Time complexity: O(n)
Space complexity: O(1) in-place

> Runtime: 12 ms, faster than 100.00% of C++ online submissions for Merge Two Sorted Lists.
> Memory Usage: 9.9 MB, less than 90.59% of C++ online submissions for Merge Two Sorted Lists.

```c++
class Solution {
 public:
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

## Solution 2: Recursive

Time complexity: O(n)
Space complexity: O(n)

> Runtime: 12 ms, faster than 100.00% of C++ online submissions for Merge Two Sorted Lists.
> Memory Usage: 10.3 MB, less than 11.45% of C++ online submissions for Merge Two Sorted Lists.

```cpp
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // If one of the list is emptry, return the other one.
    if (!l1 || !l2) return l1 ? l1 : l2;
    // The smaller one becomes the head.
    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }
};
```