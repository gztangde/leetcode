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

这道混合插入有序链表和我之前那篇混合插入有序数组非常的相似Merge Sorted Array，仅仅是数据结构由数组换成了链表而已，代码写起来反而更简洁。具体思想就是新建一个链表，然后比较两个链表中的元素值，把较小的那个链到新链表中，由于两个输入链表的长度可能不同，所以最终会有一个链表先完成插入所有元素，则直接另一个未完成的链表直接链入新链表的末尾。

## Solution 1: Iterative

Time complexity: O(n)
Space complexity: O(1) in-place

> Runtime: 12 ms, faster than 100.00% of C++ online submissions for Merge Two Sorted Lists.
> Memory Usage: 9.9 MB, less than 90.59% of C++ online submissions for Merge Two Sorted Lists.

```cpp
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

递归的写法，当某个链表为空了，就返回另一个。然后核心还是比较当前两个节点值大小，如果l1的小，那么对于l1的下一个节点和l2调用递归函数，将返回值赋值给l1.next，然后返回l1；否则就对于l2的下一个节点和l1调用递归函数，将返回值赋值给l2.next，然后返回l2

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

对上述的代码可以做一些精简：

```cpp
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1 || (l2 && l1->val > l2->val)) swap(l1, l2);
    if (l1) l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  }
};
```

另外一种解法

```cpp
// Merge Two Sorted Lists (LeetCode)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode dummy(-1);
  ListNode *p = l1, *q = l2, *r = &dummy;
  while (p && q) {
    if (p->val < q->val) {
      r->next = p;
      r = p;
      p = p->next;
    } else {
      r->next = q;
      r = q;
      q = q->next;
    }
  }
  r->next = (p ? p : q);
  return dummy.next;
}
```
