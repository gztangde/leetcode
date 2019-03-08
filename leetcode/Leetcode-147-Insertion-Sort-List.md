---
title: Leetcode 147. Insertion Sort List
date: 2018-12-16 09:09:31
updated: 2018-12-16 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Sort a linked list using insertion sort.

![](/images/gifimage/Insertion-sort-example-300px.gif)

A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
  
Algorithm of Insertion Sort:**

1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
3. It repeats until no input elements remain.

**Difficulty**:Medium

**Category**:Linked-List, Sort

<!-- more -->

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
  ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(INT_MIN);

    for (ListNode* cur = head; cur != nullptr;) {
      auto pos = findInsertPos(&dummy, cur->val);
      ListNode* tmp = cur->next;
      cur->next = pos->next;
      pos->next = cur;
      cur = tmp;
    }
    return dummy.next;
  }

  ListNode* findInsertPos(ListNode* head, int x) {
    ListNode* prev = nullptr;
    for (ListNode* cur = head; cur != nullptr && cur->val <= x; prev = cur, cur = cur->next) {
      ;
    }
    return prev;
  }
};
```