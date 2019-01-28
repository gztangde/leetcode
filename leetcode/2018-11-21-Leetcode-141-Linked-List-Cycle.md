---
title: Leetcode 141. Linked List Cycle
date: 2018-11-21 06:09:31
updated: 2018-11-21 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

**Difficulty**:Easy

**Category**:Linked List, Two Points

<!-- more -->

------------

# Analyze

虽然我刷题不够多，但是还是知道这个经典的检查链表中是否有环的快慢指针方式。设置两个指针，一个快一个慢，快的指针一次走两格，慢的指针一次走一格。

> **为什么如果有环的话，快的指针一定可以追上慢的指针呢, 难道不会刚好错过么**
> 快的指针一次走两格，慢的指针一次走一格，他们的相对速度只差是1个格子，那我们这样分析。如果链表中间有环，那么快的在追到慢的之前的话，他们之间之可能相差一个格子或者两个格子：
> - 如果他们相差一个格子，那么下一步就能够追上
> - 如果他们相差两个格子，那么两步之后也可以追上。

------------

# Solution

```cpp
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true;
    }
    return false;
  }
};
```