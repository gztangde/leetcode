---
title: Leetcode 23. Merge k Sorted Lists
date: 2018-12-16 09:09:31
updated: 2018-12-16 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

![](/images/in-post/2018-12-16-Leetcode-23-Merge-K-Sorted-Lists/2018-12-16-14-24-04.png)

**Difficulty**:Hard

**Category**:Linked-List, Divide-and-Conquer, Heap

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return 0;
    ListNode* p = lists[0];
    for (int i = 1; i < lists.size(); ++i) {
      p = mergeTwoLists(p, lists[i]);
    }
    return p;
  }

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    ListNode dummy(-1);
    ListNode* p = &dummy;
    for (; l1 != nullptr && l2 != nullptr; p = p->next) {
      if (l1->val > l2->val) {
        p->next = l2;
        l2 = l2->next;
      } else {
        p->next = l1;
        l1 = l1->next;
      }
    }
    p->next = l1 != nullptr ? l1 : l2;
    return dummy.next;
  }
};
```