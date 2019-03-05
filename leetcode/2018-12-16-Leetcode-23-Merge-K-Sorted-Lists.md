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

我们在前面做过类似的合并两个`Sorted List的题目`, 在这里, 我们先考虑两两合并`Lists`, 这就是我们的`Solution 1`,依次两两合并List, 最终得到一个合并之后完整的List. 参考另外一道题目: [Merge Two Sorted Lists](./Leetcode-21-Merge-Two-Sorted-Lists.md)

这种方式性能很不好,因为左边的List可能长度很长,而右边的`Lists`则长度很短,这就会使得每次计算的时间复杂度很高.
  
针对处理`N`个类似工作的过程,我们考虑使用分治法, 不停的对`n`个链表进行二分`n/2, n/4, n/8...`, 直到最后的元素个数为`1`或`2`个为止. 然后再向上进行合并.

------------

# Solution

## Solution 1: Brute Force, Merge two list each time

Time complexity: O(nk)
Space complexity: O(1)

```cpp
// Runtime: 300ms
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    ListNode* p = lists[0];
    for (int i = 1; i < lists.size(); ++i) {
      p = mergeKLists(p, lists[i]);
    }
    return p;
  }
  ListNode* mergeKLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    ListNode dump(-1);
    ListNode* p = &dump;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return dump.next;
  }
};
```

## Solution 2: Divide and Conquer

```cpp
// Runtime: 16ms
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    int n = lists.size();
    while (n > 1) {
      int k = (n + 1) / 2;
      for (int i = 0; i < n / 2; ++i) lists[i] = mergeKLists(lists[i], lists[i + k]);
      n = k;
    }
    return lists[0];
  }

  ListNode* mergeKLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    ListNode dump(-1);
    ListNode* p = &dump;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return dump.next;
  }
};
```

## Solution 3: priority_queue

这种方案来自于博客:[Merge k Sorted Lists 合并k个有序链表](http://www.cnblogs.com/grandyang/p/4606710.html), 使用最小堆的结构,我们可以將`k`个链表的首元素加入到最小堆当中,最小堆能够自动排好序,然后我们取出来最小的元素, 然后把取出元素的链表的下一个元素继续放入最小堆当中,循环操作,直到合并完所有链表为止, 返回首元素就好.

Time complexity: O(nlogk)
Space complexity: O(k)

```cpp
struct cmp {
  bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> q;
    for (auto& list : lists)
      if (list) q.push(list);

    ListNode *head = nullptr, *cur = nullptr, *tmp = nullptr;

    while (!q.empty()) {
      tmp = q.top();
      q.pop();

      // Save the ListNode* in the list
      cur ? cur->next = tmp : head = tmp;
      cur = tmp;
      if (tmp->next) q.push(tmp->next);
    }
    return head;
  }
};
```

### Updated

* 1/29/2019 Add the solution 2 and solution 3