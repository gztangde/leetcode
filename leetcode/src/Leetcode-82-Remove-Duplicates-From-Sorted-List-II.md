---
title: Leetcode 82. Remove Duplicates from Sorted List II
date: 2018-11-20 21:09:31
updated: 2018-11-20 21:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only  _distinct_  numbers from the original list.

**Example 1:**

> **Input:** 1->2->3->3->4->4->5
> **Output:** 1->2->5

**Example 2:**

> **Input:** 1->1->1->2->3
> **Output:** 2->3

**Difficulty**:Medium

**Category**:Linked List

<!-- more -->

# Analyze

这道题目要求的是删除所有的重复项，由于链表开头可能会有重复项，被删掉的头指针会改变，而最终却还需要返回链表的头指针。所以需要定义一个新的节点，然后链上原链表，然后定义一个前驱指针和一个现指针，每当前驱指针指向新建的节点，现指针从下一个位置开始往下遍历，遇到相同的则继续往下，直到遇到不同项时，把前驱指针的next指向下面那个不同的元素。如果现指针遍历的第一个元素就不相同，则把前驱指针向下移一位

# Solution

## Solution 1: No-Recursive

```cpp
class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    while (pre->next) {
      ListNode *cur = pre->next;
      while (cur->next && cur->next->val == cur->val) {
        cur = cur->next;
      }
      if (cur != pre->next)
        pre->next = cur->next;
      else
        pre = pre->next;
    }
    return dummy->next;
  }
};
```

## Solution2: Recursive

```cpp
class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return head;
    if (head->next && head->val == head->next->val) {
      while (head->next && head->val == head->next->val) {
        head = head->next;
      }
      return deleteDuplicates(head->next);
    }
    head->next = deleteDuplicates(head->next);
    return head;
  }
};
```

